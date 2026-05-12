//============================================================================
// Combined file for Yosys synthesis
// Contains: uart_tx_fifo + uart_tx
//============================================================================

//============================================================================
// uart_tx_fifo.v — UART TX FIFO
//============================================================================

module uart_tx_fifo (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        push,
    input  wire [7:0]  wr_data,
    output wire        tx_fifo_full,
    input  wire        pop,
    output wire [7:0]  rd_data,
    output wire        tx_fifo_empty,
    output wire [4:0]  count_out
);

    parameter FIFO_DEPTH = 16;
    parameter DATA_WIDTH = 8;
    localparam ADDR_WIDTH = $clog2(FIFO_DEPTH);

    reg [DATA_WIDTH-1:0] data_fifo [0:FIFO_DEPTH-1];
    reg [ADDR_WIDTH-1:0] ip_count;
    reg [ADDR_WIDTH-1:0] op_count;
    reg [4:0]            count;
    integer              i;

    assign tx_fifo_full  = (count == 5'd16);
    assign tx_fifo_empty = (count == 5'd0);
    assign rd_data       = data_fifo[op_count];
    assign count_out     = count;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ip_count   <= 4'd0;
            op_count   <= 4'd0;
            count      <= 5'd0;
            for (i = 0; i < FIFO_DEPTH; i = i + 1) begin
                data_fifo[i] <= 8'd0;
            end
        end else begin
            if (push && !pop && !tx_fifo_full) begin
                data_fifo[ip_count] <= wr_data;
                ip_count <= ip_count + 4'd1;
                count <= count + 5'd1;
            end
            else if (!push && pop && !tx_fifo_empty) begin
                op_count <= op_count + 4'd1;
                count <= count - 5'd1;
            end
            else if (push && pop && !tx_fifo_full && !tx_fifo_empty) begin
                data_fifo[ip_count] <= wr_data;
                ip_count <= ip_count + 4'd1;
                op_count <= op_count + 4'd1;
                count <= count;
            end
            else if (push && pop && tx_fifo_full && !tx_fifo_empty) begin
                data_fifo[ip_count] <= wr_data;
                ip_count <= ip_count + 4'd1;
                op_count <= op_count + 4'd1;
                count <= count;
            end
            else if (push && pop && !tx_fifo_full && tx_fifo_empty) begin
                data_fifo[ip_count] <= wr_data;
                ip_count <= ip_count + 4'd1;
                count <= count + 5'd1;
            end
        end
    end

endmodule

//============================================================================
// Module: uart_tx
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

    reg  [3:0]  tx_state;
    reg  [3:0]  bit_counter;
    reg  [7:0]  tx_buffer;
    reg         pop_tx_fifo;
    reg  [7:0]  lcr_latched;
    reg         half_stop_flag;

    wire [7:0]  tx_fifo_out;
    wire        tx_fifo_empty_w;
    wire        tx_fifo_full_w;
    wire [4:0]  tx_fifo_count_w;

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

    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            tx_state       <= S_IDLE;
            bit_counter    <= 4'd0;
            tx_buffer      <= 8'd0;
            lcr_latched    <= 8'd0;
            half_stop_flag <= 1'b0;
            pop_tx_fifo    <= 1'b0;
            busy           <= 1'b0;
            TXD            <= 1'b1;
        end else begin
            pop_tx_fifo <= 1'b0;

            case (tx_state)
                S_IDLE: begin
                    busy <= 1'b0;
                    TXD  <= 1'b1;
                    if (!tx_fifo_empty_w && enable) begin
                        pop_tx_fifo <= 1'b1;
                        tx_buffer   <= tx_fifo_out;
                        lcr_latched <= LCR;
                        busy        <= 1'b1;
                        tx_state    <= S_START;
                        bit_counter <= 4'd0;
                    end
                end

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

                S_BIT0: begin
                    TXD <= tx_buffer[0];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b00)
                                tx_state <= next_after_data(5);
                            else
                                tx_state <= S_BIT1;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_BIT1: begin
                    TXD <= tx_buffer[1];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b01)
                                tx_state <= next_after_data(6);
                            else
                                tx_state <= S_BIT2;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_BIT2: begin
                    TXD <= tx_buffer[2];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b10)
                                tx_state <= next_after_data(7);
                            else
                                tx_state <= S_BIT3;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_BIT3: begin
                    TXD <= tx_buffer[3];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            tx_state <= S_BIT4;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_BIT4: begin
                    TXD <= tx_buffer[4];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b00) begin
                                tx_buffer[7:5] <= 3'b000;
                                tx_state <= next_after_data(5);
                            end else
                                tx_state <= S_BIT5;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_BIT5: begin
                    TXD <= tx_buffer[5];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b01) begin
                                tx_buffer[7:6] <= 2'b00;
                                tx_state <= next_after_data(6);
                            end else
                                tx_state <= S_BIT6;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_BIT6: begin
                    TXD <= tx_buffer[6];
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            bit_counter <= 4'd0;
                            if (lcr_latched[1:0] == 2'b10) begin
                                tx_buffer[7] <= 1'b0;
                                tx_state <= next_after_data(7);
                            end else
                                tx_state <= S_BIT7;
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

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

                S_PARITY: begin
                    case (lcr_latched[5:4])
                        2'b00: TXD <= ^tx_buffer;
                        2'b01: TXD <= ~(^tx_buffer);
                        2'b10: TXD <= 1'b1;
                        2'b11: TXD <= 1'b0;
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

                S_STOP1: begin
                    TXD <= 1'b1;
                    if (enable) begin
                        if (bit_counter == 4'd15) begin
                            if (lcr_latched[2]) begin
                                half_stop_flag <= 1'b0;
                                bit_counter    <= 4'd0;
                                tx_state       <= S_STOP2;
                            end else begin
                                bit_counter <= 4'd0;
                                tx_state    <= S_IDLE;
                            end
                        end else begin
                            bit_counter <= bit_counter + 4'd1;
                        end
                    end
                end

                S_STOP2: begin
                    TXD <= 1'b1;
                    if (enable) begin
                        if (lcr_latched[1:0] == 2'b00 && !half_stop_flag) begin
                            half_stop_flag <= 1'b1;
                            if (bit_counter == 4'd7) begin
                                bit_counter    <= 4'd0;
                                half_stop_flag <= 1'b0;
                                tx_state       <= S_IDLE;
                            end else begin
                                bit_counter <= bit_counter + 4'd1;
                            end
                        end else begin
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

                default: begin
                    tx_state <= S_IDLE;
                    busy     <= 1'b0;
                    TXD      <= 1'b1;
                end
            endcase
        end
    end

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