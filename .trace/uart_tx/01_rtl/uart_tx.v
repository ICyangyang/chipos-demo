// =============================================================================
// UART TX Module - Top Level with FSM and FIFO
// Supports: 5/6/7/8 data bits, 1/1.5/2 stop bits, even/odd/stick parity
// Baud rate = PCLK/16 (each bit period = 16 PCLK cycles)
// =============================================================================
module uart_tx (
    input              PCLK,
    input              PRESETn,
    input      [7:0]   PWDATA,
    input              tx_fifo_push,
    input      [7:0]   LCR,
    input              enable,
    output             tx_fifo_empty,
    output             tx_fifo_full,
    output     [4:0]   tx_fifo_count,
    output reg         busy,
    output reg         TXD
);

    // =========================================================================
    // FSM State Definition
    // =========================================================================
    localparam IDLE   = 4'd0;
    localparam START  = 4'd1;
    localparam BIT0   = 4'd2;
    localparam BIT1   = 4'd3;
    localparam BIT2   = 4'd4;
    localparam BIT3   = 4'd5;
    localparam BIT4   = 4'd6;
    localparam BIT5   = 4'd7;
    localparam BIT6   = 4'd8;
    localparam BIT7   = 4'd9;
    localparam PARITY = 4'd10;
    localparam STOP1  = 4'd11;
    localparam STOP2  = 4'd12;

    // =========================================================================
    // Internal Signals
    // =========================================================================
    reg [3:0]  tx_state;
    reg [3:0]  bit_counter;
    reg [7:0]  tx_buffer;
    reg        pop_tx_fifo;
    wire [7:0] tx_fifo_out;
    wire       tx_fifo_empty_i;
    wire       tx_fifo_full_i;
    wire [4:0] tx_fifo_count_i;

    // For 1.5 stop bit support: need to count beyond 15 in STOP1 state
    // when data width is 5 bits and LCR[2]=1.
    // 1.5 stop bits = 24 PCLK cycles. We use a 5-bit counter for STOP1.
    reg [4:0]  stop_counter;  // 5-bit counter for stop bit duration

    // =========================================================================
    // FIFO Instantiation
    // =========================================================================
    uart_tx_fifo u_fifo (
        .PCLK       (PCLK),
        .PRESETn    (PRESETn),
        .data_in    (PWDATA),
        .push       (tx_fifo_push),
        .pop        (pop_tx_fifo),
        .data_out   (tx_fifo_out),
        .fifo_empty (tx_fifo_empty_i),
        .fifo_full  (tx_fifo_full_i),
        .fifo_count (tx_fifo_count_i)
    );

    assign tx_fifo_empty = tx_fifo_empty_i;
    assign tx_fifo_full  = tx_fifo_full_i;
    assign tx_fifo_count = tx_fifo_count_i;

    // =========================================================================
    // LCR Configuration - Latched at frame start to prevent mid-frame changes
    // =========================================================================
    reg [7:0]  lcr_latched;

    wire [1:0] lcr_data_bits;
    wire       lcr_stop_bits;
    wire       lcr_parity_en;
    wire [1:0] lcr_parity_type;

    assign lcr_data_bits   = lcr_latched[1:0];
    assign lcr_stop_bits   = lcr_latched[2];
    assign lcr_parity_en   = lcr_latched[3];
    assign lcr_parity_type = lcr_latched[5:4];

    // =========================================================================
    // Parity Calculation (combinational)
    // =========================================================================
    wire parity_bit;

    assign parity_bit = (lcr_parity_type == 2'b00) ? (~(^tx_buffer)) :  // Odd parity (16550 standard)
                        (lcr_parity_type == 2'b01) ? (^tx_buffer)    :  // Even parity (16550 standard)
                        (lcr_parity_type == 2'b10) ? 1'b1            :  // Stick parity high
                                                    1'b0;              // Stick parity low

    // =========================================================================
    // Determine last data bit state based on LCR[1:0]
    // =========================================================================
    wire [3:0] last_data_state;

    assign last_data_state = (lcr_data_bits == 2'b00) ? BIT4 :  // 5 data bits
                             (lcr_data_bits == 2'b01) ? BIT5 :  // 6 data bits
                             (lcr_data_bits == 2'b10) ? BIT6 :  // 7 data bits
                                                       BIT7;    // 8 data bits

    // =========================================================================
    // Determine next state after last data bit
    // =========================================================================
    wire [3:0] next_after_data;

    assign next_after_data = lcr_parity_en ? PARITY : STOP1;

    // =========================================================================
    // Stop bit duration: 1.5 stop bits for 5-bit data, 2 stop bits otherwise
    // 1 stop bit  = 16 PCLK cycles (STOP1 only)
    // 1.5 stop bits = 24 PCLK cycles (STOP1 with extended count)
    // 2 stop bits = 32 PCLK cycles (STOP1 + STOP2, each 16)
    // =========================================================================
    wire is_half_stop;  // True when 5-bit data + LCR[2]=1 (1.5 stop bits)

    assign is_half_stop = (lcr_data_bits == 2'b00) & lcr_stop_bits;

    // =========================================================================
    // TX FSM - Main State Machine
    // =========================================================================
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            tx_state      <= IDLE;
            bit_counter   <= 4'b0;
            stop_counter  <= 5'b0;
            tx_buffer     <= 8'b0;
            lcr_latched   <= 8'b0;
            pop_tx_fifo   <= 1'b0;
            busy          <= 1'b0;
            TXD           <= 1'b1;
        end else begin
            // Default: pop signal is one-cycle pulse, cleared every cycle
            pop_tx_fifo <= 1'b0;

            if (enable) begin
                case (tx_state)
                    // ---------------------------------------------------------
                    // IDLE: Wait for FIFO data
                    // ---------------------------------------------------------
                    IDLE: begin
                        busy <= 1'b0;
                        TXD  <= 1'b1;
                        if (!tx_fifo_empty_i) begin
                            pop_tx_fifo <= 1'b1;
                            tx_buffer   <= tx_fifo_out;
                            lcr_latched <= LCR;  // Latch LCR at frame start
                            busy        <= 1'b1;
                            tx_state    <= START;
                            bit_counter <= 4'b0;
                            stop_counter <= 5'b0;
                        end
                    end

                    // ---------------------------------------------------------
                    // START: Send start bit (TXD = 0), 16 PCLK cycles
                    // ---------------------------------------------------------
                    START: begin
                        TXD <= 1'b0;
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= BIT0;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT0: Send data bit 0 (LSB first)
                    // ---------------------------------------------------------
                    BIT0: begin
                        TXD <= tx_buffer[0];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= BIT1;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT1: Send data bit 1
                    // ---------------------------------------------------------
                    BIT1: begin
                        TXD <= tx_buffer[1];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= BIT2;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT2: Send data bit 2
                    // ---------------------------------------------------------
                    BIT2: begin
                        TXD <= tx_buffer[2];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= BIT3;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT3: Send data bit 3
                    // ---------------------------------------------------------
                    BIT3: begin
                        TXD <= tx_buffer[3];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= BIT4;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT4: Send data bit 4 (last bit for 5-bit data width)
                    // ---------------------------------------------------------
                    BIT4: begin
                        TXD <= tx_buffer[4];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            if (lcr_data_bits == 2'b00) begin
                                // 5-bit data: clear unused upper bits for parity
                                tx_buffer[7:5] <= 3'b000;
                                tx_state <= next_after_data;
                            end else begin
                                tx_state <= BIT5;
                            end
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT5: Send data bit 5 (last bit for 6-bit data width)
                    // ---------------------------------------------------------
                    BIT5: begin
                        TXD <= tx_buffer[5];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            if (lcr_data_bits == 2'b01) begin
                                // 6-bit data: clear unused upper bits for parity
                                tx_buffer[7:6] <= 2'b00;
                                tx_state <= next_after_data;
                            end else begin
                                tx_state <= BIT6;
                            end
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT6: Send data bit 6 (last bit for 7-bit data width)
                    // ---------------------------------------------------------
                    BIT6: begin
                        TXD <= tx_buffer[6];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            if (lcr_data_bits == 2'b10) begin
                                // 7-bit data: clear unused upper bit for parity
                                tx_buffer[7] <= 1'b0;
                                tx_state <= next_after_data;
                            end else begin
                                tx_state <= BIT7;
                            end
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // BIT7: Send data bit 7 (last bit for 8-bit data width)
                    // ---------------------------------------------------------
                    BIT7: begin
                        TXD <= tx_buffer[7];
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state <= next_after_data;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // PARITY: Send parity bit, 16 PCLK cycles
                    // ---------------------------------------------------------
                    PARITY: begin
                        TXD <= parity_bit;
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= STOP1;
                            stop_counter <= 5'b0;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    // ---------------------------------------------------------
                    // STOP1: Send first stop bit (mandatory)
                    // For 1.5 stop bits (5-bit data + LCR[2]=1): count 24 cycles
                    // For 1 stop bit (LCR[2]=0): count 16 cycles
                    // For 2 stop bits (LCR[2]=1, non-5-bit): count 16, then go to STOP2
                    // ---------------------------------------------------------
                    STOP1: begin
                        TXD <= 1'b1;
                        if (is_half_stop) begin
                            // 1.5 stop bits: need 24 PCLK cycles total
                            if (stop_counter == 5'd23) begin
                                stop_counter <= 5'b0;
                                tx_state     <= IDLE;
                            end else begin
                                stop_counter <= stop_counter + 5'b1;
                            end
                        end else begin
                            // 1 or 2 stop bits: 16 PCLK cycles for STOP1
                            if (bit_counter == 4'd15) begin
                                bit_counter <= 4'b0;
                                if (lcr_stop_bits)
                                    tx_state <= STOP2;
                                else
                                    tx_state <= IDLE;
                            end else begin
                                bit_counter <= bit_counter + 4'b1;
                            end
                        end
                    end

                    // ---------------------------------------------------------
                    // STOP2: Send second stop bit (for 2 stop bits), 16 PCLK cycles
                    // ---------------------------------------------------------
                    STOP2: begin
                        TXD <= 1'b1;
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'b0;
                            tx_state    <= IDLE;
                        end else begin
                            bit_counter <= bit_counter + 4'b1;
                        end
                    end

                    default: begin
                        tx_state      <= IDLE;
                        bit_counter   <= 4'b0;
                        stop_counter  <= 5'b0;
                        TXD           <= 1'b1;
                        busy          <= 1'b0;
                    end
                endcase
            end
            // else: enable = 0, bit_counter stops, TXD holds current value
        end
    end

endmodule