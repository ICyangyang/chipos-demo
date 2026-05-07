module mux2to1 (sel,
    in0,
    in1,
    out);
 input sel;
 input [7:0] in0;
 input [7:0] in1;
 output [7:0] out;

 wire net1;
 wire net2;
 wire net3;
 wire net4;
 wire net5;
 wire net6;
 wire net7;
 wire net8;
 wire net9;
 wire net10;
 wire net11;
 wire net12;
 wire net13;
 wire net14;
 wire net15;
 wire net16;
 wire net18;
 wire net19;
 wire net20;
 wire net21;
 wire net22;
 wire net23;
 wire net24;
 wire net25;
 wire net17;

 MUX2_X1 _2_ (.A(net7),
    .B(net15),
    .S(net17),
    .Z(net24));
 MUX2_X1 _3_ (.A(net5),
    .B(net13),
    .S(net17),
    .Z(net22));
 MUX2_X1 _4_ (.A(net4),
    .B(net12),
    .S(net17),
    .Z(net21));
 MUX2_X1 _5_ (.A(net3),
    .B(net11),
    .S(net17),
    .Z(net20));
 MUX2_X1 _6_ (.A(net2),
    .B(net10),
    .S(net17),
    .Z(net19));
 MUX2_X1 _7_ (.A(net1),
    .B(net9),
    .S(net17),
    .Z(net18));
 MUX2_X1 _8_ (.A(net8),
    .B(net16),
    .S(net17),
    .Z(net25));
 MUX2_X1 _9_ (.A(net6),
    .B(net14),
    .S(net17),
    .Z(net23));
 BUF_X1 input1 (.A(in0[0]),
    .Z(net1));
 BUF_X1 input10 (.A(in1[1]),
    .Z(net10));
 BUF_X1 input11 (.A(in1[2]),
    .Z(net11));
 BUF_X1 input12 (.A(in1[3]),
    .Z(net12));
 BUF_X1 input13 (.A(in1[4]),
    .Z(net13));
 BUF_X1 input14 (.A(in1[5]),
    .Z(net14));
 BUF_X1 input15 (.A(in1[6]),
    .Z(net15));
 BUF_X1 input16 (.A(in1[7]),
    .Z(net16));
 BUF_X1 input17 (.A(sel),
    .Z(net17));
 BUF_X1 input2 (.A(in0[1]),
    .Z(net2));
 BUF_X1 input3 (.A(in0[2]),
    .Z(net3));
 BUF_X1 input4 (.A(in0[3]),
    .Z(net4));
 BUF_X1 input5 (.A(in0[4]),
    .Z(net5));
 BUF_X1 input6 (.A(in0[5]),
    .Z(net6));
 BUF_X1 input7 (.A(in0[6]),
    .Z(net7));
 BUF_X1 input8 (.A(in0[7]),
    .Z(net8));
 BUF_X1 input9 (.A(in1[0]),
    .Z(net9));
 BUF_X1 output18 (.A(net18),
    .Z(out[0]));
 BUF_X1 output19 (.A(net19),
    .Z(out[1]));
 BUF_X1 output20 (.A(net20),
    .Z(out[2]));
 BUF_X1 output21 (.A(net21),
    .Z(out[3]));
 BUF_X1 output22 (.A(net22),
    .Z(out[4]));
 BUF_X1 output23 (.A(net23),
    .Z(out[5]));
 BUF_X1 output24 (.A(net24),
    .Z(out[6]));
 BUF_X1 output25 (.A(net25),
    .Z(out[7]));
endmodule
