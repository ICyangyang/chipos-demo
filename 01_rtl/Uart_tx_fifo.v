//============================================================================
// Module: Uart_tx_fifo
// Description: 16x8-bit Synchronous FIFO buffer for UART TX module
//              Read-Through combinational output
//              Uses count-based empty/full detection
//============================================================================

module Uart_tx_fifo (
    input              clk,        // Clock (PCLK)
    input              rst_n,      // Async reset, active-low (PRESETn)
    input      [7:0]   wr_data,    // Write data (PWDATA)
    input              wr_en,      // Write enable (tx_fifo_push)
    input              rd_en,      // Read enable (tx_fifo_pop from FSM)
    output     [7:0]   rd_data,    // Read data (combinational, Read-Through)
    output             full,       // FIFO full flag
    output             empty,      // FIFO empty flag
    output     [4:0]   count       // Data count (0-16)
);

    // Storage array: 16 entries, 8-bit wide
    reg [7:0] data_fifo [15:0];

    // Pointers and counter
    reg [3:0] ip_count;   // Write pointer (0-15)
    reg [3:0] op_count;   // Read pointer (0-15)
    reg [4:0] cnt;        // Data counter (0-16)

    // Assign outputs
    assign count  = cnt;
    assign empty  = ~(|cnt);            // Empty when count == 0
    assign full   = (cnt == 5'b10000);  // Full when count == 16
    assign rd_data = data_fifo[op_count]; // Read-Through: combinational output

    // Read/Write logic
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // Async reset: clear all pointers and counter
            ip_count <= 4'b0;
            op_count <= 4'b0;
            cnt      <= 5'b0;
        end else begin
            case ({wr_en, rd_en})
                2'b00: // No operation
                    ; // Hold state

                2'b01: // Read only
                    if (cnt > 0) begin
                        op_count <= op_count + 4'b1;
                        cnt      <= cnt - 5'b1;
                    end

                2'b10: // Write only
                    if (cnt < 5'b10000) begin
                        data_fifo[ip_count] <= wr_data;
                        ip_count <= ip_count + 4'b1;
                        cnt      <= cnt + 5'b1;
                    end

                2'b11: // Simultaneous read and write
                    if (cnt > 0 && cnt < 5'b10000) begin
                        data_fifo[ip_count] <= wr_data;
                        ip_count <= ip_count + 4'b1;
                        op_count <= op_count + 4'b1;
                        // cnt unchanged (one in, one out)
                    end else if (cnt == 5'b0) begin
                        // Empty: only write, no read possible
                        data_fifo[ip_count] <= wr_data;
                        ip_count <= ip_count + 4'b1;
                        cnt      <= cnt + 5'b1;
                    end else if (cnt == 5'b10000) begin
                        // Full: only read, no write possible
                        op_count <= op_count + 4'b1;
                        cnt      <= cnt - 5'b1;
                    end

                default: ;
            endcase
        end
    end

endmodule