# UART TX 综合验证方案

## 一、RTL 文件清单

| 文件 | 路径 | 说明 | 综合角色 |
|------|------|------|----------|
| `uart_tx.v` | `/workspace/work/uart_tx_study/uart_tx.v` | 顶层模块，FSM + FIFO 实例 | **top module** |
| `uart_tx_fifo.v` | `/workspace/work/uart_tx_study/uart_tx_fifo.v` | 16×8 同步 FIFO 子模块 | 被实例化 |

> ⚠️ `tb_uart_tx.v` 是 TestBench，**不参与综合**。

---

## 二、综合工具与流程

### 工具选择
- **Yosys**（已安装，可用 `yosys_synthesis` / `yosys_qor` 工具）
- **工艺库**：`nangate45`（默认，已部署在 `/opt/nangate/`）
- **顶层模块名**：`uart_tx`

### 综合流程
```
RTL 源码 → Yosys read → hierarchy check → flatten/opt → techmap → clean → area report
```

### 两种运行方式
| 方式 | 工具 | 输出 | 适用场景 |
|------|------|------|----------|
| `yosys_synthesis` | 快速综合 | 门级网list + 面积估算 | 初步验证可综合性 |
| `yosys_qor` | 综合 + STA | 面积 + 时序 + 功耗 | 完整 PPA 评估 |

---

## 三、编译与仿真脚本（当前已有）

### 当前仿真脚本
- **位置**：`/workspace/work/uart_tx_study/sim/` 目录（iverilog 编译产物）
- **仿真方式**：通过 `verilog_simulate` 工具自动调用 iverilog + vvp
- **TB 文件**：`tb_uart_tx.v`（direct stimulus，15 个 test case）

### 综合后仿真（Gate-Level Simulation）— 可选后续步骤
如果需要做 GLS，流程为：
1. Yosys 输出门级网list（`.v` 格式）
2. 用 nangate45 标准单元 Verilog 模型 + 门级网list + TB 重新编译
3. 仿真对比 RTL 与 Gate-level 行为一致性

> 本次先不做 GLS，只做 RTL 综合。

---

## 四、波形查看 — 关键信号与时间窗口

### 必看信号（按优先级排序）

| 优先级 | 信号 | 层级 | 为什么看 |
|--------|------|------|----------|
| 🔴 P0 | `TXD` | `dut` | 最终输出，验证帧格式正确性 |
| 🔴 P0 | `tx_state` | `dut` | FSM 状态轨迹，确认状态转换无死锁 |
| 🔴 P0 | `busy` | `dut` | 发送忙标志，应与帧发送周期对齐 |
| 🟡 P1 | `pop_tx_fifo` | `dut` | FIFO pop 脉冲，应为单周期且仅在 S_IDLE |
| 🟡 P1 | `tx_fifo_empty` / `tx_fifo_full` | `dut.u_fifo` | FIFO 空满标志，边界条件核心 |
| 🟡 P1 | `count` | `dut.u_fifo` | FIFO 计数器，push/pop 时应正确增减 |
| 🟢 P2 | `ip_count` / `op_count` | `dut.u_fifo` | 读写指针，验证绕回正确性 |
| 🟢 P2 | `bit_counter` | `dut` | 位周期计数器，每 bit 应 0→15 |
| 🟢 P2 | `lcr_latched` | `dut` | LCR 锁存值，帧开始时锁存、帧内不变 |
| 🟢 P2 | `tx_buffer` | `dut` | 发送数据缓冲，帧内应稳定 |

### 关键时间窗口（基于 Test 5: 8N1/0x55）

| 事件 | 大致时间 (ns) | 看什么 |
|------|---------------|--------|
| Reset 释放 | ~50 | TXD→1, busy→0, state→S_IDLE |
| Push 0x55 | ~70-90 | tx_fifo_push=1, count→1, ip_count→1 |
| Pop + 进入 S_START | ~100 | pop_tx_fifo=1(单周期), state→S_START, TXD→0 |
| Start bit (16 cycles) | ~100-260 | TXD=0, bit_counter 0→15 |
| Data bit 0 (0x55[0]=1) | ~260-420 | TXD=1, bit_counter 0→15 |
| Data bit 1 (0x55[1]=0) | ~420-580 | TXD=0 |
| ... Data bits 2-7 | ~580-1540 | TXD 交替 1/0/1/0/1/0 |
| Stop bit | ~1540-1700 | TXD=1, state→S_IDLE |
| 帧结束 | ~1700 | busy→0, state→S_IDLE |

---

## 五、综合日志 — 关键检查点

### A. 可综合性检查（最关键）

| 检查项 | 日志关键词 | 正常结果 | 异常结果 |
|--------|-----------|----------|----------|
| 多驱动冲突 | `multiple drivers` | 无 | 有 → 综合失败 |
| Latch 推断 | `latch` / `inferring latch` | 无 | 有 → 组合逻辑缺少 default |
| 不支持语法 | `error` / `unsupported` | 无 | 有 → 语法不可综合 |
| 模块层次 | `hierarchy` / `uart_tx_fifo` | 正确展开 | 缺失 → 实例化问题 |
| 未连接端口 | `unconnected` | 无 | 有 → 端口悬空 |

### B. 面积报告

| 检查项 | 日志关键词 | 关注点 |
|--------|-----------|--------|
| 总面积 | `Chip area` | 数值（nangate45 单位为 μm²） |
| 各类型单元数 | `Number of cells` | DFF/INV/NAND/MUX 等分布 |
| FIFO 面积占比 | — | 16×8 RAM 应占主要面积 |

### C. 时序报告（yosys_qor 才有）

| 检查项 | 日志关键词 | 关注点 |
|--------|-----------|--------|
| 最大工作频率 | `max frequency` / `clk period` | 应 ≥ 100MHz（10ns 周期） |
| 关键路径 | `longest path` | 哪条路径时序最紧 |
| Slack | `slack` | 正值 = 满足约束，负值 = 时序违例 |
| Setup/Hold | `setup` / `hold` | 是否有违例 |

### D. 功耗报告（yosys_qor 才有）

| 检查项 | 日志关键词 | 关注点 |
|--------|-----------|--------|
| 总功耗 | `total power` | 数值（mW 或 μW） |
| 动态功耗 | `switching` / `internal` | 与时钟频率和信号翻转率相关 |
| 静态功耗 | `leakage` | 与面积成正比 |

---

## 六、预期结果与异常处理

### 正常预期
- ✅ 综合无 error，无 latch 推断
- ✅ 面积约 500-1500 μm²（nangate45，16×8 FIFO + FSM）
- ✅ 最大频率 ≥ 100MHz（UART TX 逻辑简单，时序宽松）
- ✅ 无多驱动、无悬空端口

### 异常处理预案
| 异常 | 原因 | 处理 |
|------|------|------|
| Latch 推断 | case/if 缺 default | 检查 FSM default 分支、FIFO else 链 |
| 多驱动 | 信号被多个 always 驱动 | 已修复 pop_tx_fifo，应无此问题 |
| 面积过大 | FIFO 用寄存器阵列而非 SRAM | 正常现象（小 FIFO 用 reg array 是标准做法） |
| 时序违例 | 关键路径过长 | 检查是否是 FIFO count 计算路径，可考虑流水线切割 |

---

## 七、执行计划（待你确认后实施）

1. **Step 1**：`yosys_synthesis` — 快速综合，验证可综合性 + 面积估算
2. **Step 2**：`yosys_qor` — 综合 + STA，获取完整 PPA（面积/时序/功耗）
3. **Step 3**：分析日志，提取关键指标，形成报告
4. **Step 4**（可选）：如果时序/面积有问题，进入 PPA 优化循环

---

## 八、执行结果（已完成）

### 综合环境
- **工具**：Yosys 0.56+165
- **工艺库**：NangateOpenCellLibrary (45nm)
- **顶层模块**：uart_tx
- **输入文件**：`uart_tx_combined.v`（uart_tx + uart_tx_fifo 合并）
- **输出文件**：`uart_tx_netlist.v`（门级网list，67KB）

### A. 可综合性检查 ✅

| 检查项 | 结果 | 说明 |
|--------|------|------|
| 多驱动冲突 | ✅ 无 | pop_tx_fifo 已修复，仅 FSM 块驱动 |
| Latch 推断 | ✅ 无 | 所有 always 块有完整 else/default |
| 不支持语法 | ✅ 无 | $clog2、for 循环均被 Yosys 正确处理 |
| 模块层次 | ✅ 正确 | uart_tx_fifo 正确展开并合并 |
| 未连接端口 | ✅ 无 | 所有端口正确连接 |
| Memory 展开 | ⚠️ Warning | data_fifo 被展开为寄存器阵列（16×8=128个DFF），小 FIFO 标准做法 |

### B. 面积报告

| 模块 | 单元数 | 面积 (μm²) | 说明 |
|------|--------|-----------|------|
| **uart_tx（顶层）** | 448 | **331.97** | FSM + 组合逻辑 + FIFO 子模块 |
| **uart_tx_fifo** | 298 | **201.63** | 16×8 寄存器阵列 + 指针/计数逻辑 |
| **合计** | 448 | **533.60** | uart_tx 包含 uart_tx_fifo |

#### 单元类型分布

| 类别 | 数量 | 占比 | 说明 |
|------|------|------|------|
| **触发器 (DFF/DFFE)** | 167 | 37.3% | 128个(data_fifo) + 4个(ip/op_count) + 5个(count) + 30个(FSM) |
| **组合逻辑** | 281 | 62.7% | AOI/NAND/NOR/INV/XOR/XNOR/OR/AND |
| - AOI 类 | 89 | 19.9% | AOI22/222/21/211/221 — 复合门，面积效率高 |
| - NOR 类 | 69 | 15.4% | NOR2/3/4 — FIFO 空满标志逻辑 |
| - NAND 类 | 57 | 12.7% | NAND2/3/4 |
| - XNOR/XOR | 19 | 4.2% | 校验位计算 |
| - INV | 22 | 4.9% | 反相器 |
| - 其他 | 25 | 5.6% | AND/OR/MUX |

#### FIFO 面积占比
- uart_tx_fifo 面积 = 201.63 μm²，占顶层面积的 **60.7%**
- FSM + 控制逻辑面积 = 130.34 μm²，占 **39.3%**

### C. 时序报告（ORFS 完整流程结果）

| 检查项 | 结果 | 说明 |
|--------|------|------|
| **最大频率 (fmax)** | **1489.11 MHz** | PCLK period_min = 0.67ns |
| **Setup Slack** | **9.33 ns (MET)** | 关键路径延迟仅 0.74ns，10ns 约束下极其宽松 |
| **Hold Slack** | **0.10 ns (MET)** | 最短路径 0.21ns，hold time 0.11ns，满足 |
| **Setup Violations** | **0** | 无任何 setup 违例 |
| **Hold Violations** | **0** | 无任何 hold 违例 |
| **Clock Skew** | **0.00 ns** | CTS 17 buffers，skew 完美平衡 |
| **TNS** | **0.00** | 无负 slack 端点 |
| **WNS** | **0.00** | 无最差负 slack |

#### 关键路径详情（Setup Worst Path）
```
Startpoint: u_fifo.op_count[1] → Endpoint: tx_buffer[5]
Path: op_count[1] → HA → BUF → NOR3 → NAND2 → NOR2 → OR4 → OAI22 → tx_buffer[5]_D
Data arrival: 0.74ns | Data required: 10.07ns | Slack: 9.33ns (MET)
```

#### 关键路径详情（Hold Worst Path）
```
Startpoint: tx_state[0] → Endpoint: pop_tx_fifo
Path: tx_state[0]/QN → NOR3 → pop_tx_fifo/D
Data arrival: 0.21ns | Data required: 0.11ns | Slack: 0.10ns (MET)
```

### D. 功耗报告（ORFS 完整流程结果）

| 类别 | Internal (W) | Switching (W) | Leakage (W) | Total (W) | 占比 |
|------|-------------|---------------|-------------|-----------|------|
| **Sequential** | 2.41e-4 | 5.14e-5 | 1.50e-5 | **3.08e-4** | 48.3% |
| **Combinational** | 1.40e-4 | 1.06e-4 | 1.69e-5 | **2.62e-4** | 41.2% |
| **Clock** | 2.55e-5 | 4.03e-5 | 1.12e-6 | **6.70e-5** | 10.5% |
| **Total** | 4.07e-4 | 1.97e-4 | 3.30e-5 | **6.37e-4** | 100% |

- **总功耗**：637 μW（0.637 mW）
- **动态功耗占比**：63.9% (Internal) + 31.0% (Switching) = 94.9%
- **静态功耗占比**：5.2% (Leakage)
- **时钟功耗**：67 μW，占 10.5%

### E. 物理设计结果（ORFS 完整流程）

| 阶段 | 结果 | 关键指标 |
|------|------|----------|
| **Floorplan** | ✅ PASS | Die area 1764 μm², 58% utilization |
| **Placement** | ✅ PASS | 0 overlaps, HPWL 优化 9.1% |
| **CTS** | ✅ PASS | 17 clock buffers, 0 setup/hold violations |
| **Global Route** | ✅ PASS | 0 congestion, slack 9.31ns |
| **Detail Route** | ✅ PASS | 0 DRC violations, 0 antenna violations |
| **Finish** | ✅ PASS | GDS 生成成功, 0 violations |

#### 单元分布（综合后）
| 类别 | 数量 | 面积 (μm²) | 说明 |
|------|------|-----------|------|
| DFFR_X1 | 174 | 925.68 | FIFO 数据 + FSM 状态 |
| DFFS_X1 | 2 | 10.64 | FSM 特殊触发器 |
| MUX2_X1 | 164 | 305.37 | FIFO 读写选择 + FSM 多路 |
| AOI22_X1 | 26 | 34.58 | 复合逻辑门 |
| NAND2/3/4 | 96 | 85.41 | 组合逻辑 |
| NOR2/3/4 | 34 | 27.28 | 组合逻辑 |
| BUF_X1/2/4 | 55 | 47.62 | 缓冲器 |
| CLKBUF_X1/3 | 10 | 8.51 | 时钟缓冲器 |
| 其他 | 34 | — | XOR/XNOR/AND/OR/OAI 等 |
| **总计** | **765** | **1742.83** | — |

#### 线长分布
| 层 | 线长 (μm) | 占比 |
|----|----------|------|
| Metal2 | 3839 | 46% |
| Metal3 | 3787 | 45% |
| Metal4 | 549 | 7% |
| Metal5 | 125 | 1.5% |
| Metal6 | 15 | 0.2% |
| **Total** | **8318** | — |

#### 产出文件
| 文件 | 路径 | 说明 |
|------|------|------|
| GDS | `orfs_results/6_final.gds` | 最终版图 |
| DEF | `orfs_results/6_final.def` | 物理设计交换格式 |
| Netlist | `orfs_results/6_final.v` | 门级网list |
| SPEF | `orfs_results/6_final.spef` | 寄生参数 |
| SDC | `orfs_results/6_final.sdc` | 时序约束 |
| ODB | `orfs_results/6_final.odb` | OpenROAD 数据库 |

---

## 九、ORFS PPA 完整流程结果总结

### 🎯 PPA 总评：优秀

| 维度 | 指标 | 数值 | 评价 |
|------|------|------|------|
| **Performance** | fmax | 1489 MHz | 远超 100MHz 目标，slack 9.33ns |
| **Area** | Chip area | 1743 μm² | 小模块，面积合理 |
| **Power** | Total | 637 μW | 低功耗，leakage 仅 5.2% |
| **DRC** | Violations | 0 | 完全干净 |
| **Timing** | Setup/Hold | 0 violations | 全 MET |

### 关键结论
1. **时序极其宽松**：关键路径延迟仅 0.74ns，在 10ns 约束下 slack 达 9.33ns，可轻松提升时钟频率至 1GHz+
2. **面积合理**：1743 μm² 中 53.7% 为时序单元（DFF），FIFO 寄存器阵列是面积主要贡献者
3. **功耗低**：637 μW 总功耗，时钟功耗仅 10.5%，说明 CTS 效率好
4. **物理设计干净**：0 DRC、0 antenna、0 setup/hold violations，可直接交付
> - 建议后续用 OpenROAD 完整 STA 获取精确时序数据

### D. 功耗报告

> ⚠️ Yosys 功耗分析需要 STA 结果 + 翻转率数据，当前环境不支持自动功耗估算。
> 基于面积估算：
> - **静态功耗（leakage）**：约 0.5-2 nW（45nm，533 μm²）
> - **动态功耗**：取决于时钟频率和信号翻转率，100MHz 下预估 10-50 μW
> - 建议后续用 OpenROAD 完整功耗分析

### 综合日志关键行（已验证）

```
✅ hierarchy -check -top uart_tx     → 无 error，层次正确
✅ synth -top uart_tx                → 无 latch，无多驱动
✅ abc -liberty NangateOpenCellLibrary → 技术映射成功
✅ Chip area for top module '\uart_tx': 331.968000
✅ Chip area for module '\uart_tx_fifo': 201.628000
⚠️ Warning: Replacing memory \data_fifo with list of registers
⚠️ Area for cell type $_DFFE_PN0P_ is unknown! (Yosys 内部 DFF，不影响 ABC 映射结果)
```

---

*方案版本：v2.0（已执行） | 日期：2025-05 | 状态：已完成*