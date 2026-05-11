# Test 5 (8N1 帧 0x55) 波形仿真方案

## 1. 需要的 RTL 文件

| 文件 | 路径 | 作用 |
|---|---|---|
| `uart_tx.v` | `/workspace/work/uart_tx_study/uart_tx.v` | 顶层模块，FSM + FIFO 实例化 |
| `uart_tx_fifo.v` | `/workspace/work/uart_tx_study/uart_tx_fifo.v` | FIFO 子模块 |

## 2. 需要的 TB 文件

| 文件 | 路径 | 作用 |
|---|---|---|
| `tb_uart_tx.v` | `/workspace/work/uart_tx/02_verification/tb_uart_tx.v` | 15 个 test case 的 direct TB |

## 3. 编译与仿真脚本

**编译命令**（iverilog）：
```bash
iverilog -o sim_out \
  -g2005 \
  /workspace/work/uart_tx_study/uart_tx_fifo.v \
  /workspace/work/uart_tx_study/uart_tx.v \
  /workspace/work/uart_tx/02_verification/tb_uart_tx.v
```

**仿真命令**（vvp + VCD dump）：
```bash
vvp sim_out +test5_only
```

**⚠️ 问题**：当前 TB 没有 `+test5_only` 的 plusarg 过滤机制，它会跑全部 15 个 case。需要做以下修改之一：

- **方案 A（推荐）**：在 TB 中添加 plusarg 支持，只跑 Test 5
- **方案 B**：写一个独立的 mini TB，只测 8N1 帧 0x55，专门用于波形分析
- **方案 C**：跑全部 15 个 case，VCD 文件会很大，但可以只看 Test 5 对应的时间窗口

## 4. VCD dump 方案

在 TB 中添加 `$dumpfile` / `$dumpvars`，需要 dump 的信号层级：

```verilog
initial begin
    $dumpfile("test5_8n1_0x55.vcd");
    $dumpvars(0, dut);          // dump DUT 下所有信号
end
```

**关键信号列表**（看波形时必须关注的）：

| 信号 | 层级路径 | 为什么看 |
|---|---|---|
| `PCLK` | `dut.PCLK` | 时钟基准，确认每个 bit period = 16 cycles |
| `TXD` | `dut.TXD` | **核心输出**，验证串行帧波形 |
| `busy` | `dut.busy` | 发送忙标志，确认 busy 覆盖 START→STOP1 |
| `tx_state` | `dut.tx_state` | FSM 状态跳转：IDLE→START→BIT0..7→STOP1→IDLE |
| `bit_counter` | `dut.bit_counter` | 每个 bit period 内的 0→15 计数 |
| `pop_tx_fifo` | `dut.pop_tx_fifo` | pop 一拍脉冲，确认只在 IDLE→START 时拉高 |
| `tx_buffer` | `dut.tx_buffer` | 锁存的数据 = 0x55，确认 LSB-first 输出 |
| `lcr_latched` | `dut.lcr_latched` | LCR 锁存值 = 0x03，确认帧格式配置 |
| `tx_fifo_empty` | `dut.tx_fifo_empty` | push 后 empty=0，pop 后 empty=1 |
| `tx_fifo_count` | `dut.tx_fifo_count` | count 从 1→0 的变化 |
| `u_fifo.ip_count` | `dut.u_fifo.ip_count` | FIFO 写指针 |
| `u_fifo.op_count` | `dut.u_fifo.op_count` | FIFO 读指针 |
| `u_fifo.count` | `dut.u_fifo.count` | FIFO 内部 count |

## 5. 看波形时的关键检查点

**0x55 = 01010101b，LSB-first 发送顺序：1→0→1→0→1→0→1→0**

| 时间窗口 | 检查内容 | 期望值 |
|---|---|---|
| **复位阶段** | TXD=1, busy=0, empty=1, count=0 | 全部初始状态正确 |
| **push 阶段** | push=1 一拍, PWDATA=0x55, count→1, empty→0 | FIFO 写入成功 |
| **IDLE→START 跳转** | pop_tx_fifo=1 一拍, busy→1, tx_state→S_START(1), tx_buffer=0x55 | FSM 启动条件满足 |
| **START bit (16 cycles)** | TXD=0, bit_counter 0→15, tx_state=S_START | 起始位持续 16 勋clk |
| **BIT0 (16 cycles)** | TXD=tx_buffer[0]=1, bit_counter 0→15 | 0x55 的 bit0=1 |
| **BIT1 (16 cycles)** | TXD=tx_buffer[1]=0 | 0x55 的 bit1=0 |
| **BIT2 (16 cycles)** | TXD=tx_buffer[2]=1 | 0x55 的 bit2=1 |
| **BIT3 (16 cycles)** | TXD=tx_buffer[3]=0 | 0x55 的 bit3=0 |
| **BIT4 (16 cycles)** | TXD=tx_buffer[4]=1 | 0x55 的 bit4=1 |
| **BIT5 (16 cycles)** | TXD=tx_buffer[5]=0 | 0x55 的 bit5=0 |
| **BIT6 (16 cycles)** | TXD=tx_buffer[6]=1 | 0x55 的 bit6=1 |
| **BIT7 (16 cycles)** | TXD=tx_buffer[7]=0 | 0x55 的 bit7=0 |
| **STOP1 (16 cycles)** | TXD=1, tx_state=S_STOP1(11) | 停止位=1 |
| **STOP1→IDLE 跳转** | busy→0, tx_state→S_IDLE(0), empty→1 | 发送结束，恢复空闲 |

**总帧长度**：1(START) + 8(DATA) + 1(STOP) = 10 bit periods = 160 PCLK cycles

## 6. 日志中的关键检查点

仿真日志（console output）中应关注：

| 日志行 | 检查内容 |
|---|---|
| `Test 5: 8N1 Frame (0x55)` | 确认进入 Test 5 |
| `[PASS] Frame matches expected` | 帧比对通过 |
| `sampled_frame` vs `expected_frame` | 如果 FAIL，看具体哪一位不匹配 |
| `FIFO count` 变化 | push 后 count=1, pop 后 count=0 |
| `busy` 覆盖范围 | 从 START 到 STOP1 结束 |

## 7. 实施步骤（待确认后执行）

1. **修改 TB**：添加 `$dumpfile/$dumpvars` + plusarg 过滤（只跑 Test 5）
2. **编译**：iverilog 编译 study 版 RTL + 修改后的 TB
3. **仿真**：vvp 运行，生成 VCD
4. **波形分析**：用 `vcd_info` + `vcd_waveform` 提取关键信号波形数据
5. **日志分析**：读取仿真日志，确认 PASS/FAIL

## 8. 方案选择（待确认）

- **方案 A（推荐）**：修改现有 TB，添加 plusarg 过滤 + VCD dump（改动小，但 TB 变复杂）
- **方案 B**：写一个独立的 mini TB，只测 8N1 帧 0x55（干净，波形文件小）
- **方案 C**：跑全部 15 case，只看 Test 5 时间窗口（最简单，但 VCD 大）