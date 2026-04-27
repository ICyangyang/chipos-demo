// MUX2_X1 behavioral model for gate-level simulation
// Function: Z = S ? B : A
module MUX2_X1 (
    input  wire A,
    input  wire B,
    input  wire S,
    output wire Z
);
    assign Z = S ? B : A;
endmodule