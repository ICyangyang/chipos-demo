// =============================================================================
// UART TX FIFO - 16x8-bit Synchronous FIFO Buffer
// =============================================================================
module uart_tx_fifo (
    input              PCLK,
    input              PRESETn,
    input      [7:0]   data_in,
    input              push,
    input              pop,
    output     [7:0]   data_out,
    output             fifo_empty,
    output             fifo_full,
    output     [4:0]   fifo_count
);

    // Storage array
    reg [7:0] data_fifo [15:0];

    // Pointer and count registers
    reg [3:0] ip_count;  // Write pointer
    reg [3:0] op_count;  // Read pointer
    reg [4:0] count;     // Data count (0-16)

    // Sequential logic: pointer and count management
    always @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            ip_count   <= 4'b0;
            op_count   <= 4'b0;
            count      <= 5'b0;
        end else begin
            case ({push, pop})
                2'b00: ; // No operation - state unchanged
                2'b01: begin // Read only
                    if (count > 0) begin
                        count    <= count - 5'b1;
                        op_count <= op_count + 4'b1;
                    end
                end
                2'b10: begin // Write only
                    if (count <= 15) begin
                        data_fifo[ip_count] <= data_in;
                        count    <= count + 5'b1;
                        ip_count <= ip_count + 4'b1;
                    end
                end
                2'b11: begin // Simultaneous read and write
                    if (count == 5'd0) begin
                        // Empty: push succeeds, pop rejected
                        data_fifo[ip_count] <= data_in;
                        ip_count <= ip_count + 4'b1;
                        count    <= count + 5'b1;
                    end else if (count == 5'd16) begin
                        // Full: pop succeeds, push rejected
                        op_count <= op_count + 4'b1;
                        count    <= count - 5'b1;
                    end else begin
                        // Normal: both succeed, count unchanged
                        data_fifo[ip_count] <= data_in;
                        ip_count <= ip_count + 4'b1;
                        op_count <= op_count + 4'b1;
                    end
                end
            endcase
        end
    end

    // Combinational output: Read-through design
    assign data_out   = data_fifo[op_count];
    assign fifo_empty = ~(|count);
    assign fifo_full  = (count == 5'b10000);
    assign fifo_count = count;

endmodule