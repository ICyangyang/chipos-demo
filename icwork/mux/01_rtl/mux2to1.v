//-----------------------------------------------------------------------------
// Module: mux2to1
// Description: 2-to-1 Multiplexer (parameterized data width)
//              sel=0 -> out=in0, sel=1 -> out=in1
// Author: ChipOS
//-----------------------------------------------------------------------------

module mux2to1 #(
    parameter DATA_WIDTH = 8  // Default 8-bit data width
) (
    input  wire [DATA_WIDTH-1:0] in0,  // Data input 0
    input  wire [DATA_WIDTH-1:0] in1,  // Data input 1
    input  wire                   sel,  // Select signal (0: in0, 1: in1)
    output wire [DATA_WIDTH-1:0] out   // Data output
);

    // Combinational multiplexer using ternary operator
    assign out = sel ? in1 : in0;

endmodule