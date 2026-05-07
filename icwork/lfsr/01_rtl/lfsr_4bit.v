// 4位线性反馈移位寄存器（LFSR）伪随机码发生器
module lfsr_4bit(
    input        clk,   // 时钟信号，上升沿触发
    input        res,   // 异步复位信号，低电平有效
    output       y      // 伪随机序列输出
);

// 定义4位移位寄存器
reg [3:0] d;
assign y = d[0];

// 异步复位 + 时钟上升沿触发的LFSR逻辑
always @(posedge clk or negedge res) begin
    if(!res) begin
        // 异步低电平复位：寄存器初始化为非全0状态（LFSR不能全0）
        d <= 4'b1111;
    end
    else begin
        d[2:0] <= d[3:1];//右移
        d[3] <= d[3] + d[0];//模2加   
    end
end

endmodule
