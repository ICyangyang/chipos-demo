//============================================================================
// Module: uart_tx
// Description: UART Transmitter with integrated 16x8-bit FIFO
//   - Fully configurable frame format via LCR register
//   - Data bits: 5/6/7/8 (LCR[1:0])
//   - Stop bits: 1, 1.5, 2 (LCR[2])
//   - Parity: even/odd/stick-1/stick-0/none (LCR[3], LCR[5:4])
//   - 16 PCLK cycles per bit period (baud = PCLK/16)
//   - LCR latched at frame start to prevent mid-frame glitches
//   - 1.5 stop bits: 24 PCLK cycles for 5-bit data, 32 for 6/7/8-bit
//============================================================================

module uart_tx (
    input  wire        PCLK,
    input  wire        PRESETn,
    input  wire [7:0]  PWDATA,
    input  wire        tx_fifo_push,
    input  wire [7:0]  LCR,
    input  wire        enable,
    output wire        tx_fifo_empty,
    output wire        tx_fifo_full,
    output wire [4:0]  tx_fifo_count,
    output reg         busy,
    output reg         TXD
);

    //------------------------------------------------------------------------
    // Parameters — FSM State Encoding
    //------------------------------------------------------------------------
    localparam S_IDLE    = 4'd0;
    localparam S_START   = 4'd1;
    localparam S_BIT0    = 4'd2;
    localparam S_BIT1    = 4'd3;
    localparam S_BIT2    = 4'd4;
    localparam S_BIT3    = 4'd5;
    localparam S_BIT4    = 4'd6;
    localparam S_BIT5    = 4'd7;
    localparam S_BIT6    = 4'd8;
    localparam S_BIT7    = 4'd9;
    localparam S_PARITY  = 4'd10;
    localparam S_STOP1   = 4'd11;
    localparam S_STOP2   = 4'd12;

    //------------------------------------------------------------------------
    // Internal Signals
    //------------------------------------------------------------------------
    reg  [3:0]  tx_state;
    reg  [3:0]  bit_counter;
    reg  [7:0]  tx_buffer;
    reg         pop_tx_fifo;
    reg  [7:0]  lcr_latched;       // LCR snapshot at frame start
    reg         half_stop_flag;     // Flag for 1.5 stop-bit counting

    wire [7:0]  tx_fifo_out;
    wire        tx_fifo_empty_w;
    wire        tx_fifo_full_w;
    wire [4:0]  tx_fifo_count_w;

    //------------------------------------------------------------------------
    // FIFO Instance
    //------------------------------------------------------------------------
    uart_tx_fifo u_fifo (
        .clk          (PCLK),
        .rst_n        (PRESETn),
        .wr_data      (PWDATA),
        .push         (tx_fifo_push),
        .pop          (pop_tx_fifo),
        .rd_data      (tx_fifo_out),
        .tx_fifo_empty(tx_fifo_empty_w),
        .tx_fifo_full (tx_fifo_full_w),
        .count_out    (tx_fifo_count_w)
    );

    assign tx_fifo_empty = tx_fifo_empty_w;
    assign tx_fifo_full  = tx_fifo_full_w;
    assign tx_fifo_count = tx_fifo_count_w;

    //------------------------------------------------------------------------
    // Main FSM — Sequential Logic
    // Note: pop_tx_fifo default assignment (<= 1'b0) is inside this FSM block
    //------------------------------------------------------------------------
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            tx_state       <= S_IDLE;
            bit_counter    <= 4'd0;
            tx_buffer      <= 8'd0;
            lcr_latched    <= 8'd0;
            half_stop_flag <= 1'b0;
            pop_tx_fifo    <= 1'b0;
            busy           <= 1'b0;
            TXD            <= 1'b1;  // Idle high
        end else begin
            pop_tx_fifo <= 1'b0;  // Default: one-cycle pulse

            case (tx_state)
                //------------------------------------------------------------
                // IDLE: Wait for FIFO data and enable
                //------------------------------------------------------------
                S_IDLE: begin
                    busy <= 1'b0;
                    TXD  <= 1'b1;
                    if (!tx_fifo_empty_w && enable) begin
                        pop_tx_fifo <= 1'b1;
                        tx_buffer   <= tx_fifo_out;
                        lcr_latched <= LCR;       // Latch LCR at frame start
                        busy        <= 1'b1;
                        tx_state    <= S_START;
                        bit_counter <= 4'd0;
                    end
                end

                //------------------------------------------------------------
                // START: Send start bit (0) for 16 PCLK cycles
                //------------------------------------------------------------
                S_START: begin
                    TXD <= 1'b0;
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            tx_state    <= S_BIT0;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT0: Send data bit 0 (LSB first)
                //------------------------------------------------------------
                S_BIT0: begin
                    TXD <= tx_buffer[0];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            // Check if we need more data bits or move on
                            if (lcr_latched[1:0] == 2'b00)  // 5-bit data
                                tx_state <= next_after_data(5);
                            else
                                tx_state <= S_BIT1;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT1: Send data bit 1
                //------------------------------------------------------------
                S_BIT1: begin
                    TXD <= tx_buffer[1];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b01)  // 6-bit data
                                tx_state <= next_after_data(6);
                            else
                                tx_state <= S_BIT2;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT2: Send data bit 2
                //------------------------------------------------------------
                S_BIT2: begin
                    TXD <= tx_buffer[2];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b10)  // 7-bit data
                                tx_state <= next_after_data(7);
                            else
                                tx_state <= S_BIT3;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT3: Send data bit 3
                //------------------------------------------------------------
                S_BIT3: begin
                    TXD <= tx_buffer[3];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            // 8-bit data always continues to BIT4
                            tx_state <= S_BIT4;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT4: Send data bit 4
                //   - For 5-bit mode: clear unused bits [7:5] for parity calc
                //------------------------------------------------------------
                S_BIT4: begin
                    TXD <= tx_buffer[4];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b00) begin  // 5-bit data
                                tx_buffer[7:5] <= 3'b000;  // Clear unused bits
                                tx_state <= next_after_data(5);
                            end else
                                tx_state <= S_BIT5;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT5: Send data bit 5
                //   - For 6-bit mode: clear unused bits [7:6] for parity calc
                //------------------------------------------------------------
                S_BIT5: begin
                    TXD <= tx_buffer[5];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b01) begin  // 6-bit data
                                tx_buffer[7:6] <= 2'b00;  // Clear unused bits
                                tx_state <= next_after_data(6);
                            end else
                                tx_state <= S_BIT6;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT6: Send data bit 6
                //   - For 7-bit mode: clear unused bit [7] for parity calc
                //------------------------------------------------------------
                S_BIT6: begin
                    TXD <= tx_buffer[6];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b10) begin  // 7-bit data
                                tx_buffer[7] <= 1'b0;  // Clear unused bit
                                tx_state <= next_after_data(7);
                            end else
                                tx_state <= S_BIT7;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // BIT7: Send data bit 7 (MSB, only for 8-bit data)
                //------------------------------------------------------------
                S_BIT7: begin
                    TXD <= tx_buffer[7];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            tx_state <= next_after_data(8);
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // PARITY: Send parity bit (if enabled)
                //   - Even parity: ^tx_buffer
                //   - Odd parity:  ~(^tx_buffer)
                //   - Stick-1:     always 1
                //   - Stick-0:     always 0
                //------------------------------------------------------------
                S_PARITY: begin
                    case (lcr_latched[5:4])
                        2'b00: TXD <= ^tx_buffer;          // Even parity
                        2'b01: TXD <= ~(^tx_buffer);        // Odd parity
                        2'b10: TXD <= 1'b1;                 // Stick parity '1'
                        2'b11: TXD <= 1'b0;                 // Stick parity '0'
                        default: TXD <= ^tx_buffer;
                    endcase
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter    <= 4'd0;
                            half_stop_flag <= 1'b0;
                            tx_state       <= S_STOP1;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // STOP1: First stop bit (always sent)
                //   - TXD = 1 for 16 cycles
                //   - If LCR[2]=0: single stop bit, return to IDLE
                //   - If LCR[2]=1: proceed to STOP2 for 1.5/2 stop bits
                //------------------------------------------------------------
                S_STOP1: begin
                    TXD <= 1'b1;
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            if (lcr_latched[2]) begin
                                // Need additional stop bit(s)
                                half_stop_flag <= 1'b0;
                                bit_counter    <= 4'd0;
                                tx_state       <= S_STOP2;
                            end else begin
                                // Single stop bit — frame complete
                                bit_counter <= 4'd0;
                                tx_state    <= S_IDLE;
                            end
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                //------------------------------------------------------------
                // STOP2: Additional stop bit(s) for 1.5 or 2 stop bits
                //   - 5-bit data + LCR[2]=1: 1.5 stop bits (24 PCLK cycles total)
                //     STOP1=16 cycles + STOP2=8 cycles (half_stop_flag mechanism)
                //   - 6/7/8-bit data + LCR[2]=1: 2 stop bits (32 PCLK cycles total)
                //     STOP1=16 cycles + STOP2=16 cycles
                //------------------------------------------------------------
                S_STOP2: begin
                    TXD <= 1'b1;
                    if (enable) begin
                        // 1.5 stop-bit case: 5-bit data, need 8 more cycles
                        if (lcr_latched[1:0] == 2'b00 && !half_stop_flag) begin
                            half_stop_flag <= 1'b1;  // Mark that we're in half-stop phase
                            if (bit_counter == 4'd7) begin
                                // 8 cycles done (half stop bit complete)
                                bit_counter    <= 4'd0;
                                half_stop_flag <= 1'b0;
                                tx_state       <= S_IDLE;
                            end else begin
                                bit_counter <= bit_counter + 4'd1;
                            end
                        end else begin
                            // 2 stop-bit case: full 16 cycles
                            if (bit_counter == 4'd15) begin
                                bit_counter    <= 4'd0;
                                half_stop_flag <= 1'b0;
                                tx_state       <= S_IDLE;
                            end else begin
                                bit_counter <= bit_counter + 4'd1;
                            end
                        end
                    end
                end

                //------------------------------------------------------------
                // Default: Return to IDLE (safe state)
                //------------------------------------------------------------
                default: begin
                    tx_state <= S_IDLE;
                    busy     <= 1'b0;
                    TXD      <= 1'b1;
                end
            endcase
        end
    end

    //------------------------------------------------------------------------
    // Function: next_after_data
    //   Determines the next state after the last data bit
    //   - If parity enabled (LCR[3]=1): go to PARITY
    //   - Otherwise: go to STOP1
    //------------------------------------------------------------------------
    function [3:0] next_after_data;
        input integer num_bits;
        begin
            if (lcr_latched[3])
                next_after_data = S_PARITY;
            else
                next_after_data = S_STOP1;
        end
    endfunction

endmodule