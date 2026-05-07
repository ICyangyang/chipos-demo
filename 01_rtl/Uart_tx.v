//============================================================================
// Module: Uart_tx
// Description: UART Transmitter with 16x8 FIFO buffer
//              Converts 8-bit parallel data to serial UART frame
//              Supports configurable data bits (5/6/7/8), parity, stop bits
//              Single PCLK clock domain, async reset PRESETn
//============================================================================

module Uart_tx (
    input              PCLK,           // System clock
    input              PRESETn,        // Async reset, active-low
    input      [7:0]   PWDATA,         // Parallel input data
    input              tx_fifo_push,   // FIFO write enable
    input      [7:0]   LCR,            // Line Control Register
    input              enable,         // Transmit enable
    output             tx_fifo_empty,  // FIFO empty flag
    output             tx_fifo_full,   // FIFO full flag
    output     [4:0]   tx_fifo_count,  // FIFO data count (0-16)
    output             busy,           // Transmit busy flag
    output reg         TXD             // Serial data output (registered)
);

    //========================================================================
    // FSM State Definitions (Binary encoding, 4-bit)
    //========================================================================
    localparam TX_IDLE   = 4'd0;
    localparam TX_START  = 4'd1;
    localparam TX_BIT0   = 4'd2;
    localparam TX_BIT1   = 4'd3;
    localparam TX_BIT2   = 4'd4;
    localparam TX_BIT3   = 4'd5;
    localparam TX_BIT4   = 4'd6;
    localparam TX_BIT5   = 4'd7;
    localparam TX_BIT6   = 4'd8;
    localparam TX_BIT7   = 4'd9;
    localparam TX_PARITY = 4'd10;
    localparam TX_STOP1  = 4'd11;
    localparam TX_STOP2  = 4'd12;
    localparam TX_HALF   = 4'd13;

    //========================================================================
    // Internal Signals
    //========================================================================
    reg [3:0]  tx_state;      // FSM state register
    reg [3:0]  bit_cnt;       // Bit period counter (0-15)
    reg [2:0]  bit_index;     // Data bit index (0-7)
    reg [7:0]  tx_buffer;     // Current byte being transmitted
    reg [7:0]  lcr_latch;     // LCR latched at frame start
    reg        parity_bit;    // Pre-computed parity bit
    reg        tx_fifo_pop;   // FIFO read request (1-cycle pulse)
    wire [7:0]  fifo_rd_data;  // FIFO read data
    wire        fifo_empty;    // FIFO empty flag (from sub-module)
    wire        fifo_full;     // FIFO full flag (from sub-module)
    wire [4:0]  fifo_count;   // FIFO data count (from sub-module)
    reg [7:0]  data_mask;     // Mask for sub-8-bit data
    wire        parity_en;     // Parity enable (from lcr_latch[3])
    wire        parity_xor;    // XOR reduction of masked tx_buffer
    wire [1:0]  data_bits_enc; // Data bits encoding (lcr_latch[1:0])
    wire        stop_bits_en;  // Stop bits enable (lcr_latch[2])
    wire [1:0]  parity_type;   // Parity type (lcr_latch[5:4])

    //========================================================================
    // FIFO Sub-Module Instantiation
    //========================================================================
    Uart_tx_fifo u_fifo (
        .clk     (PCLK),
        .rst_n   (PRESETn),
        .wr_data (PWDATA),
        .wr_en   (tx_fifo_push),
        .rd_en   (tx_fifo_pop),
        .rd_data (fifo_rd_data),
        .full    (fifo_full),
        .empty   (fifo_empty),
        .count   (fifo_count)
    );

    // Connect FIFO outputs to top-level outputs
    assign tx_fifo_empty = fifo_empty;
    assign tx_fifo_full  = fifo_full;
    assign tx_fifo_count = fifo_count;

    //========================================================================
    // LCR Latch Decoding
    //========================================================================
    assign data_bits_enc = lcr_latch[1:0];
    assign parity_en     = lcr_latch[3];
    assign stop_bits_en  = lcr_latch[2];
    assign parity_type   = lcr_latch[5:4];

    // Data mask: LSB-aligned, upper bits zeroed for sub-8-bit data
    always @(*) begin
        case (data_bits_enc)
            2'b00: data_mask = 8'h1F; // 5-bit: bits [4:0] valid
            2'b01: data_mask = 8'h3F; // 6-bit: bits [5:0] valid
            2'b10: data_mask = 8'h7F; // 7-bit: bits [6:0] valid
            2'b11: data_mask = 8'hFF; // 8-bit: all bits valid
            default: data_mask = 8'hFF;
        endcase
    end

    // Parity XOR: reduction XOR of masked tx_buffer
    // Upper zero bits don't affect XOR result
    assign parity_xor = ^(tx_buffer & data_mask);

    //========================================================================
    // Busy Flag
    //========================================================================
    assign busy = (tx_state != TX_IDLE);

    //========================================================================
    // FSM: Next State Logic
    //========================================================================
    reg [3:0] next_state;

    always @(*) begin
        next_state = tx_state;

        case (tx_state)
            TX_IDLE: begin
                if (enable && !fifo_empty)
                    next_state = TX_START;
                else
                    next_state = TX_IDLE;
            end

            TX_START: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_BIT0;
                else
                    next_state = TX_START;
            end

            TX_BIT0: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_BIT1;
                else
                    next_state = TX_BIT0;
            end

            TX_BIT1: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_BIT2;
                else
                    next_state = TX_BIT1;
            end

            TX_BIT2: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_BIT3;
                else
                    next_state = TX_BIT2;
            end

            TX_BIT3: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_BIT4;
                else
                    next_state = TX_BIT3;
            end

            TX_BIT4: begin
                if (bit_cnt == 4'd15 && enable) begin
                    if (data_bits_enc == 2'b00) // 5-bit: BIT4 is last data bit
                        next_state = parity_en ? TX_PARITY : TX_STOP1;
                    else
                        next_state = TX_BIT5;
                end else
                    next_state = TX_BIT4;
            end

            TX_BIT5: begin
                if (bit_cnt == 4'd15 && enable) begin
                    if (data_bits_enc == 2'b01) // 6-bit: BIT5 is last data bit
                        next_state = parity_en ? TX_PARITY : TX_STOP1;
                    else
                        next_state = TX_BIT6;
                end else
                    next_state = TX_BIT5;
            end

            TX_BIT6: begin
                if (bit_cnt == 4'd15 && enable) begin
                    if (data_bits_enc == 2'b10) // 7-bit: BIT6 is last data bit
                        next_state = parity_en ? TX_PARITY : TX_STOP1;
                    else
                        next_state = TX_BIT7;
                end else
                    next_state = TX_BIT6;
            end

            TX_BIT7: begin // 8-bit: BIT7 is always last data bit
                if (bit_cnt == 4'd15 && enable)
                    next_state = parity_en ? TX_PARITY : TX_STOP1;
                else
                    next_state = TX_BIT7;
            end

            TX_PARITY: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_STOP1;
                else
                    next_state = TX_PARITY;
            end

            TX_STOP1: begin
                if (bit_cnt == 4'd15 && enable) begin
                    if (!stop_bits_en)
                        next_state = TX_IDLE; // 1 stop bit
                    else if (data_bits_enc == 2'b00) // 5-bit data: 1.5 stop bits
                        next_state = TX_HALF;
                    else
                        next_state = TX_STOP2; // 2 stop bits
                end else
                    next_state = TX_STOP1;
            end

            TX_STOP2: begin
                if (bit_cnt == 4'd15 && enable)
                    next_state = TX_IDLE;
                else
                    next_state = TX_STOP2;
            end

            TX_HALF: begin // 1.5 stop bit: half period (8 PCLK cycles)
                if (bit_cnt == 4'd7 && enable)
                    next_state = TX_IDLE;
                else
                    next_state = TX_HALF;
            end

            default: next_state = TX_IDLE;
        endcase
    end

    //========================================================================
    // FSM: State Register + Data Path Registers
    //========================================================================
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            // Async reset: all registers to initial values
            tx_state   <= TX_IDLE;
            bit_cnt    <= 4'b0;
            bit_index  <= 3'b0;
            tx_buffer  <= 8'b0;
            lcr_latch  <= 8'b0;
            parity_bit <= 1'b0;
            TXD        <= 1'b1;  // Idle line level
            tx_fifo_pop <= 1'b0;
        end else begin
            // Default: pop signal is one-cycle pulse, clear after assertion
            tx_fifo_pop <= 1'b0;

            case (tx_state)
                TX_IDLE: begin
                    bit_cnt <= 4'b0;
                    if (enable && !fifo_empty) begin
                        // Frame start: latch LCR, pop FIFO, load tx_buffer
                        lcr_latch  <= LCR;
                        tx_fifo_pop <= 1'b1;
                        // Use LCR directly (not lcr_latch) since lcr_latch hasn't been updated yet
                        case (LCR[1:0])
                            2'b00: tx_buffer <= fifo_rd_data & 8'h1F; // 5-bit
                            2'b01: tx_buffer <= fifo_rd_data & 8'h3F; // 6-bit
                            2'b10: tx_buffer <= fifo_rd_data & 8'h7F; // 7-bit
                            2'b11: tx_buffer <= fifo_rd_data & 8'hFF; // 8-bit
                            default: tx_buffer <= fifo_rd_data & 8'hFF;
                        endcase
                        // Pre-compute parity bit using LCR directly
                        case (LCR[5:4])
                            2'b00: parity_bit <= ^(fifo_rd_data & ((LCR[1:0] == 2'b00) ? 8'h1F : (LCR[1:0] == 2'b01) ? 8'h3F : (LCR[1:0] == 2'b10) ? 8'h7F : 8'hFF)); // Even parity
                            2'b01: parity_bit <= ~^(fifo_rd_data & ((LCR[1:0] == 2'b00) ? 8'h1F : (LCR[1:0] == 2'b01) ? 8'h3F : (LCR[1:0] == 2'b10) ? 8'h7F : 8'hFF)); // Odd parity
                            2'b10: parity_bit <= 1'b1; // Stick parity 1
                            2'b11: parity_bit <= 1'b0; // Stick parity 0
                            default: parity_bit <= 1'b0;
                        endcase
                    end
                end

                TX_START: begin
                    if (enable) begin
                        if (bit_cnt == 4'd15) begin
                            bit_cnt   <= 4'b0;
                            bit_index <= 3'b0;
                        end else begin
                            bit_cnt <= bit_cnt + 4'b1;
                        end
                    end
                    // bit_cnt frozen when enable=0
                end

                TX_BIT0, TX_BIT1, TX_BIT2, TX_BIT3,
                TX_BIT4, TX_BIT5, TX_BIT6, TX_BIT7: begin
                    if (enable) begin
                        if (bit_cnt == 4'd15) begin
                            bit_cnt    <= 4'b0;
                            bit_index  <= bit_index + 3'b1;
                        end else begin
                            bit_cnt <= bit_cnt + 4'b1;
                        end
                    end
                    // bit_cnt frozen when enable=0
                end

                TX_PARITY: begin
                    if (enable) begin
                        if (bit_cnt == 4'd15)
                            bit_cnt <= 4'b0;
                        else
                            bit_cnt <= bit_cnt + 4'b1;
                    end
                end

                TX_STOP1: begin
                    if (enable) begin
                        if (bit_cnt == 4'd15)
                            bit_cnt <= 4'b0;
                        else
                            bit_cnt <= bit_cnt + 4'b1;
                    end
                end

                TX_STOP2: begin
                    if (enable) begin
                        if (bit_cnt == 4'd15)
                            bit_cnt <= 4'b0;
                        else
                            bit_cnt <= bit_cnt + 4'b1;
                    end
                end

                TX_HALF: begin
                    if (enable) begin
                        if (bit_cnt == 4'd7)
                            bit_cnt <= 4'b0;
                        else
                            bit_cnt <= bit_cnt + 4'b1;
                    end
                end

                default: ;
            endcase

            // Update state register
            tx_state <= next_state;
        end
    end

    //========================================================================
    // TXD Output Logic (Registered to prevent glitches)
    //========================================================================
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            TXD <= 1'b1; // Idle line level
        end else begin
            case (next_state)
                TX_IDLE:   TXD <= 1'b1;
                TX_START:  TXD <= 1'b0;
                TX_BIT0:   TXD <= tx_buffer[0];
                TX_BIT1:   TXD <= tx_buffer[1];
                TX_BIT2:   TXD <= tx_buffer[2];
                TX_BIT3:   TXD <= tx_buffer[3];
                TX_BIT4:   TXD <= tx_buffer[4];
                TX_BIT5:   TXD <= tx_buffer[5];
                TX_BIT6:   TXD <= tx_buffer[6];
                TX_BIT7:   TXD <= tx_buffer[7];
                TX_PARITY: TXD <= parity_bit;
                TX_STOP1:  TXD <= 1'b1;
                TX_STOP2:  TXD <= 1'b1;
                TX_HALF:   TXD <= 1'b1;
                default:   TXD <= 1'b1;
            endcase
        end
    end

endmodule