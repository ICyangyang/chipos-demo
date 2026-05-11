//============================================================================
// uart_tx_fifo.v — UART TX FIFO 模板（填空练习版）
//============================================================================
//
// 模块功能：16×8 同步 FIFO，用于缓冲 CPU 写入的待发送数据
//
// 核心设计要点（你之前学过的）：
//   - ip_count：写入指针，push 时 +1
//   - op_count：读取指针，pop 时 +1
//   - count：当前有效数据个数，push+1 / pop-1 / 同时不变
//   - 4-bit 指针（0~15），自动绕回
//   - count==0 → 空，count==16 → 满
//
// ⚠️ 每个标记为 【TODO】 的地方，你需要填写关键逻辑
//   提示会告诉你需要写什么，但不会直接给答案
//
//============================================================================

module uart_tx_fifo (
    input  wire        clk,          // 系统时钟（PCLK）
    input  wire        rst_n,        // 异步复位，低有效

    // CPU 写入侧（push 接口）
    input  wire        push,         // CPU 写入请求
    input  wire [7:0]  wr_data,     // CPU 写入的数据
    output wire        tx_fifo_full, // FIFO 满标志（CPU 应检查此信号）

    // FSM 读取侧（pop 接口）
    input  wire        pop,          // FSM 取出请求
    output wire [7:0]  rd_data,     // FIFO 输出的数据（读穿透）
    output wire        tx_fifo_empty,// FIFO 空标志（FSM 应检查此信号）
    output wire [4:0]  count_out     // 当前 FIFO 中有效数据个数
);

    //------------------------------------------------------------------------
    // 参数定义
    //------------------------------------------------------------------------
    parameter FIFO_DEPTH = 16;       // FIFO 深度：16个字节
    parameter DATA_WIDTH = 8;        // 数据宽度：8位
    parameter ADDR_WIDTH = 4;        // 地址宽度：4位（log2(16)=4）

    //------------------------------------------------------------------------
    // 内部寄存器
    //------------------------------------------------------------------------
    reg [DATA_WIDTH-1:0] data_fifo [0:FIFO_DEPTH-1]; // 存储阵列：16×8
    reg [ADDR_WIDTH-1:0] ip_count;   // 写入指针（0~15，自动绕回）
    reg [ADDR_WIDTH-1:0] op_count;   // 读取指针（0~15，自动绕回）
    reg [4:0]            count;      // 有效数据计数（0~16，需要5位！）
    integer              i;          // for 循环变量

    //------------------------------------------------------------------------
    // 输出信号赋值（组合逻辑）
    //------------------------------------------------------------------------

    // 【TODO-1】tx_fifo_full：FIFO 满标志
    // 提示：count 等于多少时表示 FIFO 满了？
    assign tx_fifo_full = count == FIFO_DEPTH/* 你的答案 */;

    // 【TODO-2】tx_fifo_empty：FIFO 空标志
    // 提示：count 等于多少时表示 FIFO 空了？
    assign tx_fifo_empty = count == 0 /* 你的答案 */;

    // 【TODO-3】rd_data：读穿透输出
    // 提示：FSM 读取时，应该输出 data_fifo 的哪个位置？
    //       用哪个指针来索引？注意：是 op_count，不是 ip_count
    assign rd_data = data_fifo[op_count]/* 你的答案 */;

    // 【TODO-4】count_out：输出 count 给 FSM
    // 提示：直接把 count 寄存器输出即可
    assign count_out = count/* 你的答案 */;

    //------------------------------------------------------------------------
    // 核心时序逻辑：push / pop / count 更新
    //------------------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            //------------------------------------------------------------
            // 复位：所有寄存器归零
            //------------------------------------------------------------
            ip_count   <= 4'd0;
            op_count   <= 4'd0;
            count      <= 5'd0;

            // 【TODO-5】复位时清空 data_fifo
            // 提示：用 for 循环把 16 个位置都设为 0
            //       格式：for (i = 0; i < FIFO_DEPTH; i = i + 1) data_fifo[i] <= ...
            /* 你的答案 */
            for (i = 0; i < FIFO_DEPTH; i = i + 1) 
            begin
                data_fifo[i] <= 0;
            end

        end else begin
            //------------------------------------------------------------
            // 正常运行：4种情况组合
            //
            //   push=1, pop=0 → 只写入：ip_count+1, count+1, 写入数据
            //   push=0, pop=1 → 只读取：op_count+1, count-1
            //   push=1, pop=1 → 同时：ip_count+1, op_count+1, count不变, 写入数据
            //   push=0, pop=0 → 无操作：什么都不变
            //
            //   ⚠️ 保护条件：
            //     push 只有在 !tx_fifo_full 时才生效
            //     pop  只有在 !tx_fifo_empty 时才生效
            //------------------------------------------------------------

            // ====== 情况1：只 push（写入），不 pop ======
            if (push && !pop && !tx_fifo_full) begin

                // 【TODO-6】写入数据到 data_fifo
                // 提示：数据应该写到 data_fifo 的哪个位置？
                //       wr_data 写入到 data_fifo[ip_count]
                /* 你的答案 */
                data_fifo[ip_count] <= wr_data;
                

                // 【TODO-7】ip_count 加1
                // 提示：ip_count 是 4-bit，加到 15 后自动绕回到 0
                //       直接写 ip_count <= ip_count + 1 即可（4-bit自动溢出绕回）
                /* 你的答案 */
                ip_count <= ip_count +1;
                // 【TODO-8】count 加1
                // 提示：push 让 FIFO 多了一个数据
                /* 你的答案 */
                count <= count + 1;

            end

            // ====== 情况2：只 pop（读取），不 push ======
            else if (!push && pop && !tx_fifo_empty) begin

                // 【TODO-9】op_count 加1
                // 提示：pop 让读取指针前进一格
                //       同样 4-bit 自动绕回
                /* 你的答案 */
                op_count <= op_count+1;
                // 【TODO-10】count 减1
                // 提示：pop 让 FIFO 少了一个数据
                /* 你的答案 */
                count <= count -1 ;
                // 注意：pop 时不需要修改 data_fifo！
                //       数据还在那里，只是 op_count 前进了，逻辑上"已取出"
                //       新的 push 会覆盖旧位置（写覆盖机制）

            end

            // ====== 情况3：push 和 pop 同时发生 ======
            else if (push && pop && !tx_fifo_full && !tx_fifo_empty) begin

                // 【TODO-11】写入数据到 data_fifo
                // 提示：和情况1一样，写到 ip_count 位置
                /* 你的答案 */
                data_fifo[ip_count] <= wr_data;
                // 【TODO-12】ip_count 加1
                // 提示：和情况1一样
                /* 你的答案 */
                ip_count <= ip_count +1;
                // 【TODO-13】op_count 加1
                // 提示：和情况2一样
                /* 你的答案 */
                op_count <= op_count +1;
                // 【TODO-14】count 不变！
                // 提示：push+1 和 pop-1 抵消，count 保持原值
                //       直接写 count <= count; 即可（或者不写，默认保持）
                /* 你的答案 */
                count <= count;

            end

            // ====== 情况4：FIFO 满时 push + pop 同时发生 ======
            //   满（count=16）时 push 被拒绝，但如果同时 pop，
            //   pop 先腾出空间，push 可以成功写入
            else if (push && pop && tx_fifo_full && !tx_fifo_empty) begin

                // 【TODO-15】写入数据到 data_fifo
                // 提示：pop 腾出了空间，push 可以写入
                //       写到 ip_count 位置
                /* 你的答案 */
                data_fifo[ip_count] <= wr_data;
                // 【TODO-16】ip_count 加1
                /* 你的答案 */
                ip_count <= ip_count +1;
                // 【TODO-17】op_count 加1
                /* 你的答案 */
                op_count <= op_count +1;
                // 【TODO-18】count 不变（还是16）
                // 提示：pop-1 + push+1 = 不变，count 还是 16
                //       FIFO 仍然是满的，但内容更新了（旧数据被取走，新数据写入）
                /* 你的答案 */
                count <= count;
            end

            // ====== 情况5：FIFO 空时 push + pop 同时发生 ======
            //   空（count=0）时 pop 无意义（没有数据可取），
            //   但 push 应该正常写入
            else if (push && pop && !tx_fifo_full && tx_fifo_empty) begin

                data_fifo[ip_count] <= wr_data;
                ip_count <= ip_count + 1;
                count <= count + 1;    // push 生效，pop 被忽略，count+1

            end

            // ====== 其他情况：无操作 ======
            // push=0, pop=0 → 什么都不做
            // push=1, full=1, pop=0 → 拒绝写入（数据丢失）
            // pop=1, empty=1, push=0 → 拒绝读取（无意义）
            // 这些情况不需要写代码，寄存器默认保持原值

        end
    end

endmodule