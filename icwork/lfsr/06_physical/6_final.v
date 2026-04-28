module lfsr_4bit (clk,
    res,
    y);
 input clk;
 input res;
 output y;

 wire _0_;
 wire _1_;
 wire _2_;
 wire _3_;
 wire _4_;
 wire \d[1] ;
 wire \d[2] ;
 wire \d[3] ;
 wire net1;
 wire net2;
 wire clknet_0_clk;
 wire clknet_1_0__leaf_clk;
 wire clknet_1_1__leaf_clk;

 XOR2_X1 _5_ (.A(\d[3] ),
    .B(net2),
    .Z(_0_));
 CLKBUF_X3 clkbuf_0_clk (.A(clk),
    .Z(clknet_0_clk));
 CLKBUF_X3 clkbuf_1_0__f_clk (.A(clknet_0_clk),
    .Z(clknet_1_0__leaf_clk));
 CLKBUF_X3 clkbuf_1_1__f_clk (.A(clknet_0_clk),
    .Z(clknet_1_1__leaf_clk));
 DFFS_X1 \d[0]$_DFF_PN1_  (.D(\d[1] ),
    .SN(net1),
    .CK(clknet_1_1__leaf_clk),
    .Q(net2),
    .QN(_2_));
 DFFS_X1 \d[1]$_DFF_PN1_  (.D(\d[2] ),
    .SN(net1),
    .CK(clknet_1_0__leaf_clk),
    .Q(\d[1] ),
    .QN(_3_));
 DFFS_X1 \d[2]$_DFF_PN1_  (.D(\d[3] ),
    .SN(net1),
    .CK(clknet_1_0__leaf_clk),
    .Q(\d[2] ),
    .QN(_1_));
 DFFS_X1 \d[3]$_DFF_PN1_  (.D(_0_),
    .SN(net1),
    .CK(clknet_1_1__leaf_clk),
    .Q(\d[3] ),
    .QN(_4_));
 BUF_X1 input1 (.A(res),
    .Z(net1));
 BUF_X1 output2 (.A(net2),
    .Z(y));
endmodule
