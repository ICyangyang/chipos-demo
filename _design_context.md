# UART TX 设计上下文

## 模块概述
- **模块名**: Uart_tx
- **功能**: UART 发送器，将 8-bit 并行数据转为串行 UART 帧，内置 16x8 FIFO
- **时钟域**: 单一 PCLK 域，无 CDC
- **复位**: 低电平异步复位 PRESETn，同步释放

## 模块层次
```
Uart_tx (顶层)
├── Uart_tx_fifo (独立子模块: 16x8 同步 FIFO)
└── TX_Control_FSM (内嵌在顶层: 14 状态 FSM)
```

## 顶层接口
| Port | Dir | Width | Description |
|------|-----|-------|-------------|
| PCLK | in | 1 | 系统时钟 |
| PRESETn | in | 1 | 低电平异步复位 |
| PWDATA | in | 8 | 并行数据输入 |
| tx_fifo_push | in | 1 | FIFO 写使能 |
| LCR | in | 8 | 线控制寄存器 |
| enable | in | 1 | 发送使能 |
| tx_fifo_empty | out | 1 | FIFO 空标志 |
| tx_fifo_full | out | 1 | FIFO 满标志 |
| tx_fifo_count | out | 5 | FIFO 数据计数 |
| busy | out | 1 | 发送忙标志 |
| TXD | out | 1 | 串行输出 |

## FIFO 子模块接口
| Port | Dir | Width | Description |
|------|-----|-------|-------------|
| clk | in | 1 | PCLK |
| rst_n | in | 1 | PRESETn |
| wr_data | in | 8 | PWDATA |
| wr_en | in | 1 | tx_fifo_push |
| rd_en | in | 1 | tx_fifo_pop |
| rd_data | out | 8 | Read-Through 组合逻辑 |
| full | out | 1 | 满标志 |
| empty | out | 1 | 空标志 |
| count | out | 5 | 数据计数 |

## FSM 状态 (Binary 编码, 4-bit)
| State | Value | Description |
|-------|-------|-------------|
| TX_IDLE | 0 | 空闲 |
| TX_START | 1 | 起始位 |
| TX_BIT0 | 2 | 数据位0 |
| TX_BIT1 | 3 | 数据位1 |
| TX_BIT2 | 4 | 数据位2 |
| TX_BIT3 | 5 | 数据位3 |
| TX_BIT4 | 6 | 数据位4 |
| TX_BIT5 | 7 | 数据位5 |
| TX_BIT6 | 8 | 数据位6 |
| TX_BIT7 | 9 | 数据位7 |
| TX_PARITY | 10 | 校验位 |
| TX_STOP1 | 11 | 停止位1 |
| TX_STOP2 | 12 | 停止位2 |
| TX_HALF | 13 | 半停止位 (1.5 stop, 5-bit data) |

## 关键寄存器
| Register | Width | Description |
|----------|-------|-------------|
| tx_state | 4 | FSM 状态 |
| bit_cnt | 4 | 位周期计数器 (0-15) |
| bit_index | 3 | 数据位索引 (0-7) |
| tx_buffer | 8 | 待发送数据锁存器 |
| lcr_latch | 8 | LCR 锁存 (帧开始采样) |
| parity_bit | 1 | 预计算校验位 |
| TXD_reg | 1 | TXD 输出寄存器 |

## LCR 编码
| Field | Bits | Values |
|-------|------|--------|
| data_bits | [1:0] | 00=5, 01=6, 10=7, 11=8 |
| stop_bits | [2] | 0=1 stop, 1=1.5/2 stop |
| parity_en | [3] | 0=disabled, 1=enabled |
| parity_type | [5:4] | 00=even, 01=odd, 10=stick_1, 11=stick_0 |
| reserved | [7:6] | 保留 |

## 架构决策
- FSM 编码: Binary (面积优先，速度非瓶颈)
- FSM 风格: 三段式 Mealy，TXD 寄存器输出防毛刺
- FIFO: 独立子模块 (可复用)
- FSM: 内嵌顶层 (避免端口爆炸)
- LCR: 帧开始锁存到 lcr_latch
- enable 暂停: bit_cnt 立即冻结
- 数据位映射: LSB 对齐，高位清零 (data_mask)
- FIFO 满时 push: 静默忽略
- FIFO pop: Read-Through 组合逻辑
- 校验位: 帧开始预计算，存入 parity_bit
- 1.5 stop bit: TX_HALF 状态，bit_cnt 终止值=7
- 波特率分频: 16 PCLK/bit

## 功能点 (28 个)
FP-001~FP-028: FIFO 操作(8), FSM 控制(10), 协议发送(10)

## 面积估算: 500-800 GE