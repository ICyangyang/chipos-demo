# UART_TX OpenROAD 物理实现全流程报告

> **设计**: uart_tx (UART 发送器 + 16-entry FIFO)  
> **工艺库**: NangateOpenCellLibrary (Nangate45, 45nm)  
> **时钟约束**: PCLK 周期 10.0ns (100MHz)  
> **日期**: 2025-05  

---

## 流程总览

```
RTL (.v) → [1.Synthesis] → [2.Floorplan] → [3.Placement] → [4.CTS] → [5.Global Route] → [6.Detailed Route] → [7.Finish] → GDSII
```

| 阶段 | 工具 | 耗时 | 状态 |
|------|------|------|------|
| 1. 逻辑综合 | Yosys | ~3s | ✅ |
| 2. 布图规划 | OpenROAD (ifp) | 0.8s | ✅ |
| 3. 布局 | OpenROAD (gpl+dpl+rsz) | 32s | ✅ |
| 4. 时钟树综合 | OpenROAD (cts) | 2.4s | ✅ |
| 5. 全局布线 | OpenROAD (grt+rsz) | 18.5s | ✅ |
| 6. 详细布线 | OpenROAD (drt) | 51.4s | ✅ |
| 7. 完成 | OpenROAD (fill+rcx+psm) | 3.3s | ✅ |

---

## 阶段 1：逻辑综合 (Logic Synthesis)

### 做什么
将 RTL 代码（Verilog 行为级）转换为门级网表（标准单元连接图）。这是从"代码"到"电路"的第一步转换。

### 工具
- **Yosys 0.63** (OpenROAD 内置版本)

### 策略与选项
```bash
# Yosys 综合流程（ORFS 默认脚本）
read_verilog uart_tx.v uart_tx_fifo.v    # 读入 RTL
hierarchy -check                          # 层次检查
synth -top uart_tx                        # 顶层综合
  ├── proc          # 将 always 块转为多路选择器+触发器
  ├── flatten       # 展平层次
  ├── opt           # 常量折叠+合并+死代码消除（迭代3轮）
  ├── fsm_detect → fsm_extract → fsm_opt → fsm_recode → fsm_map  # FSM 提取与优化
  ├── opt           # 再次优化
  ├── abc -script +speed                 # ABC 逻辑优化（速度优先脚本）
  ├── clean        # 清理冗余
  └── check        # 一致性检查

# ABC 使用 speed 脚本（而非 area 脚本），即速度优先综合
# 时钟周期从 SDC 提取: 10000 (10ns = 100ps 单位)
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `uart_tx.v` | UART 发送器 RTL |
| `uart_tx_fifo.v` | TX FIFO RTL |
| `uart_tx.sdc` | 时钟约束 (PCLK 10ns) |
| `NangateOpenCellLibrary_typical.lib` | 标准单元库 |

### 输出文件
| 文件 | 说明 |
|------|------|
| `1_1_yosys_canonicalize.rtlil` | RTLIL 中间表示 |
| `1_2_yosys.v` | 门级网表 (Verilog) |
| `1_2_yosys.sdc` | 传递给后端的 SDC |
| `1_synth.odb` | OpenROAD 数据库 |
| `1_synth.sdc` | 综合后 SDC |

### 关键指标
| 指标 | 数值 |
|------|------|
| **总标准单元数** | **765** |
| **芯片面积** | **1742.83 μm²** |
| **时序单元面积** | 936.32 μm² (53.72%) |
| **DFF 触发器** | 174× DFFR_X1 + 2× DFFS_X1 = **176** |
| **MUX2** | 164 |
| **AOI22** | 26 |
| **NAND2/NAND3** | 43/34 |
| **BUF** | 45+9+1 = 55 |
| **综合检查** | 0 problems ✅ |

### 阶段间约束
> ⚠️ **必须条件**: 门级网表必须通过 `check` 检查（0 problems），且所有单元必须在目标库中存在。SDC 约束必须正确传递。

---

## 阶段 2：布图规划 (Floorplan)

### 做什么
确定芯片的物理形状和大小：定义 Die（芯片边界）和 Core（可用布线区域），放置 IO 引脚，插入 Tap Cell（体连接单元），构建电源分配网络（PDN）。

### 工具
- **OpenROAD** `ifp` (Initialize Floorplan) 模块
- **OpenROAD** `pdn` 模块（PDN 生成）

### 策略与选项
```tcl
# config.mk 中的策略参数
CORE_UTILIZATION = 55     # 核心利用率 55%（面积 = 单元面积 / 利用率）
CORE_ASPECT_RATIO = 1     # 长宽比 1:1（正方形）

# OpenROAD 命令
initialize_floorplan
  -utilization 55          # 55% 利用率
  -aspect_ratio 1          # 正方形
  -core_margins {1.0 1.0 1.0 1.0}  # Core 到 Die 边距 1μm

# 修复 tie cell 扇出
repair_tie_fanout          # 将 tie_hi/tie_lo 连接到多负载

# 时序修复（使用 wire load model 估计）
repair_timing
  -setup_margin 0
  -hold_margin 0
  -repair_tns 100          # 修复 100% 的 TNS
  -setup
  -skip_last_gasp
  -sequence unbuffer,sizeup,swap,vt_swap  # 修复动作序列
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `1_synth.odb` | 综合后数据库 |
| `1_synth.sdc` | 综合后 SDC |
| `NangateOpenCellLibrary_typical.lib` | 标准单元库 |
| `setRC.tcl` | 互连线 RC 参数设置 |

### 输出文件
| 文件 | 说明 |
|------|------|
| `2_1_floorplan.odb` | 布图规划后数据库 |
| `2_1_floorplan.sdc` | 布图规划后 SDC |
| `2_2_floorplan_macro.odb` | 宏单元放置后 |
| `2_3_floorplan_tapcell.odb` | Tap Cell 插入后 |
| `2_4_floorplan_pdn.odb` | PDN 构建后 |

### 关键指标
| 指标 | 数值 |
|------|------|
| **Die 面积** | 58.29 × 58.29 = **3397.72 μm²** |
| **Core 面积** | **3060.33 μm²** |
| **有效利用率** | **56.9%** |
| **标准单元面积** | 1742.83 μm² |
| **实例数** | 765 |
| **行数** | 39 行 × 295 site |
| **Setup WNS** | 0.00 (无违例) |
| **Setup TNS** | 0.00 |
| **最坏 Setup Slack** | **9.50 ns (MET)** |
| **最坏 Hold Slack** | **0.11 ns (MET)** |
| **fmax** | **1992.46 MHz** |
| **功耗** | 547 μW (Internal 70.8% + Switching 23.2% + Leakage 6.0%) |

### 阶段间约束
> ⚠️ **必须条件**: Core 面积必须 ≥ 标准单元总面积 / 目标利用率。PDN 必须连通（VDD/VSS 无断路）。利用率过高（>80%）会导致后续布线拥塞。

---

## 阶段 3：布局 (Placement)

### 做什么
将每个标准单元放到 Core 区域内的合法位置。分两步：**全局布局**（粗略位置，允许重叠）→ **详细布局**（消除重叠，对齐到 site 网格）。

### 工具
- **OpenROAD** `gpl` (Global Placement) — 基于 RePlAce 算法
- **OpenROAD** `dpl` (Detailed Placement) — 基于 Simulated Annealing
- **OpenROAD** `rsz` (Resizer) — 时序修复（插 buffer/换大 cell）

### 策略与选项
```tcl
# 全局布局
global_placement
  -density 0.659           # 目标布局密度 65.9%
  -routability_driven      # 布线驱动（考虑拥塞调整密度）
  -timing_driven           # 时序驱动（关键路径优先缩短）
  -force_center_initial_place  # 初始位置居中
  -min_phi_coef 0.95       # 惩罚系数下限
  -max_phi_coef 1.05       # 惩罚系数上限

# 时序修复（在全局布局中迭代 2 次）
repair_design
  -sequence unbuffer,sizeup,swap,buffer,clone,split_load

# 详细布局
detailed_placement
  -max_displacement {500,100}  # 最大位移: 500 sites 水平, 100 rows 垂直
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `2_floorplan.odb` | 布图规划后数据库 |
| `2_floorplan.sdc` | 布图规划后 SDC |

### 输出文件
| 文件 | 说明 |
|------|------|
| `3_1_place_gp_skip_io.odb` | 跳过 IO 的全局布局 |
| `3_2_place_iop.odb` | IO 引脚放置后 |
| `3_3_place_gp.odb` | 全局布局完成 |
| `3_4_place_resized.odb` | 时序修复后 |
| `3_5_place_dp.odb` | 详细布局完成 |
| `3_place.odb` | 最终布局数据库 |
| `3_place.sdc` | 布局后 SDC |

### 关键指标
| 指标 | 全局布局后 | 详细布局后 |
|------|-----------|-----------|
| **面积** | 1740 μm² | 1740 μm² |
| **利用率** | 60.1% | 60.1% |
| **实例数** | 804 (含修复 buffer) | 804 |
| **最坏 Setup Slack** | **9.33 ns (MET)** | **9.34 ns (MET)** |
| **最坏 Hold Slack** | **0.10 ns (MET)** | **0.10 ns (MET)** |
| **fmax** | **1496.41 MHz** | **1507.47 MHz** |
| **关键路径延迟** | 0.63 ns | 0.63 ns |
| **HPWL** | 5100 μm | 6168 μm (合法化后+3%) |
| **Slew 违例** | 0 | 0 |
| **Cap 违例** | 0 | 0 |
| **功耗** | 568 μW | 570 μW |

**关键路径 (Setup worst)**:
```
u_fifo.op_count[1] → HA_X1 → BUF_X1 → NOR3_X1 → NAND2_X1 → NOR2_X1 → OR4_X1 → OAI22_X1 → tx_buffer[5]
延迟: 0.63ns, Slack: 9.34ns
```

**关键路径 (Hold worst)**:
```
tx_state[0] → NOR3_X2 → pop_tx_fifo
延迟: 0.10ns, Slack: 0.10ns
```

### 阶段间约束
> ⚠️ **必须条件**: 全局布局后 overflow < 1%（本设计 0.1%）。详细布局后 0 overlaps。Slew/Cap/Fanout 无违例。时序修复后 Setup/Hold 无违例。

---

## 阶段 4：时钟树综合 (Clock Tree Synthesis, CTS)

### 做什么
构建从时钟输入端口到所有触发器时钟端的平衡树状缓冲器网络。目标是**最小化时钟偏斜（skew）**并满足**插入延迟（insertion delay）**约束。

### 工具
- **OpenROAD** `cts` (Clock Tree Synthesis) — 基于 TritonCTS

### 策略与选项
```tcl
# CTS 配置
clock_tree_synthesis
  -root_buf CLKBUF_X3       # 根节点 buffer 类型
  -buf_list CLKBUF_X1       # 可用 buffer 列表
  -sink_clustering_enable    # 启用 sink 聚类
  -sink_clustering_max_cap  # 基于 buffer 最大电容聚类

# TNS 修复
TNS_END_PERCENT = 100       # 修复 100% 的负 slack

# CTS 后时序修复
repair_timing
  -setup_margin 0
  -hold_margin 0
  -repair_tns 100
  -verbose

# CTS 后详细布局合法化
detailed_placement
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `3_place.odb` | 布局后数据库 |
| `3_place.sdc` | 布局后 SDC |

### 输出文件
| 文件 | 说明 |
|------|------|
| `4_1_cts.odb` | CTS 后数据库 |
| `4_cts.sdc` | CTS 后 SDC（含实际时钟延迟） |
| `4_before_rsz_lec.v` | 修复前网表（LEC 对比用） |
| `4_after_rsz_lec.v` | 修复后网表 |

### 关键指标
| 指标 | 数值 |
|------|------|
| **时钟 buffer 数** | **17** |
| **时钟网络数** | 17 |
| **Sink 总数** | 176 (触发器) + 15 (dummy load) = 191 |
| **时钟树层级** | **4 层** (H-Tree) |
| **Buffer 路径深度** | 2~2 (所有 sink 等深度) |
| **时钟偏斜 (Setup)** | **0.00 ns** |
| **Sink 线长 (平均)** | 86.53 μm |
| **Fanout 分布** | 8:1, 9:3, 10:4, 11:2, 12:1, 13:4, 15:1 |
| **最坏 Setup Slack** | **9.33 ns (MET)** |
| **最坏 Hold Slack** | **0.10 ns (MET)** |
| **fmax** | **1496.56 MHz** |
| **面积** | 1778 μm² (增加 38 μm², +2.2%) |
| **功耗** | 638 μW (Clock 10.6% = 67.9 μW) |

**H-Tree 拓扑**:
```
Level 1: Horizontal, 88 sinks/sub-region
Level 2: Vertical, 44 sinks/sub-region
Level 3: Horizontal, 22 sinks/sub-region
Level 4: Vertical, 11 sinks/sub-region → Stop (max 15 sinks)
```

**关键路径 (Setup worst, 含 CTS 延迟)**:
```
PCLK → clkbuf_0_PCLK (0.06ns) → clkbuf_4_9_0_PCLK (0.05ns) → u_fifo.op_count[1]/CK
数据路径: 0.63ns → 总到达时间: 0.74ns
Slack: 9.33ns (MET)
```

### 阶段间约束
> ⚠️ **必须条件**: 时钟偏斜必须满足 setup/hold 约束。所有 sink 必须被覆盖（176/176）。CTS 后需重新合法化布局（0 failures）。Setup/Hold 无违例。

---

## 阶段 5：全局布线 (Global Routing)

### 做什么
在粗粒度网格（GCell Grid）上为每条信号网分配布线通道（routing track），估计布线拥塞，修复时序违例和天线违例。**不产生实际金属线**，只产生布线引导（routing guide）。

### 工具
- **OpenROAD** `grt` (Global Router) — 基于 FastRoute
- **OpenROAD** `rsz` (Resizer) — 布线后时序修复
- **OpenROAD** `ant` (Antenna Checker) — 天线效应检查

### 策略与选项
```tcl
# 全局布线
global_route
  -congestion_report_file congestion.rpt  # 输出拥塞报告

# 布线后时序修复（使用全局布线估计的寄生参数）
estimate_parasitics -global_routing     # 估计 RC 寄生参数
repair_timing
  -setup_margin 0
  -hold_margin 0
  -repair_tns 100
  -verbose
  -sequence unbuffer,sizeup,swap,buffer,clone,split_load

# 天线修复
repair_antennas                          # 插入二极管修复天线违例
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `4_1_cts.odb` | CTS 后数据库 |
| `4_cts.sdc` | CTS 后 SDC |

### 输出文件
| 文件 | 说明 |
|------|------|
| `5_1_grt.odb` | 全局布线后数据库 |
| `5_1_grt.sdc` | 全局布线后 SDC |
| `route.guide` | 布线引导文件（给详细布线用） |
| `congestion_post_repair_design.rpt` | 拥塞报告 |
| `congestion_post_repair_timing.rpt` | 时序修复后拥塞报告 |

### 关键指标
| 指标 | 数值 |
|------|------|
| **最坏 Setup Slack** | **9.31 ns (MET)** |
| **最坏 Hold Slack** | **0.10 ns (MET)** |
| **fmax** | **1446.21 MHz** |
| **时钟偏斜** | **-0.00 ns** (几乎完美平衡) |
| **关键路径延迟** | 0.77 ns (比 CTS 后增加 0.03ns，布线 RC 贡献) |
| **天线违例 (Net)** | **0** |
| **天线违例 (Pin)** | **0** |
| **Slew 违例** | 0 |
| **Cap 违例** | 0 |
| **面积** | 1778 μm² |
| **功耗** | 654 μW (Clock 10.7%) |

**关键路径 (Setup worst, 含布线 RC)**:
```
PCLK → clkbuf_0 (0.06ns) → clkbuf_4_9_0 (0.05ns) → u_fifo.op_count[1]/CK
数据: 0.13→0.12→0.11→0.02→0.09→0.02→0.12→0.05 = 0.66ns
总到达: 0.77ns, Slack: 9.31ns
```

### 阶段间约束
> ⚠️ **必须条件**: 全局布线拥塞必须可解（无 overflow > 100% 的 GCell）。天线违例必须修复。Setup/Hold 无违例。`route.guide` 必须完整覆盖所有信号网。

---

## 阶段 6：详细布线 (Detailed Routing)

### 做什么
根据全局布线的引导，在金属层上画出实际的金属线、通孔（via），连接所有信号网。修复设计规则违例（DRC: 间距、宽度、通孔覆盖等）。

### 工具
- **OpenROAD** `drt` (Detailed Router) — 基于 TritonRoute

### 策略与选项
```tcl
# 详细布线
detailed_route
  -output_drc 5_route_drc.rpt    # DRC 报告
  -output_maze maze.log           # 迷宫布线日志
  -droute_end_iter 64             # 最大迭代次数 64
  -verbose 1                      # 详细输出
  -drc_report_iter_step 5         # 每 5 次迭代报告 DRC

# 布线后天线检查
repair_antennas
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `5_1_grt.odb` | 全局布线后数据库 |
| `route.guide` | 布线引导文件 |

### 输出文件
| 文件 | 说明 |
|------|------|
| `5_2_route.odb` | 详细布线后数据库 |
| `5_route.sdc` | 布线后 SDC |
| `5_route_drc.rpt` | DRC 报告 |
| `maze.log` | 迷宫布线日志 |

### 关键指标
| 指标 | 数值 |
|------|------|
| **DRC 违例** | **0** ✅ |
| **天线违例 (Net)** | **0** |
| **天线违例 (Pin)** | **0** |
| **总布线长度** | **8318 μm** |
| **Metal2 布线** | 3839 μm (46.1%) |
| **Metal3 布线** | 3787 μm (45.5%) |
| **Metal4 布线** | 549 μm (6.6%) |
| **Metal5 布线** | 125 μm (1.5%) |
| **Metal6 布线** | 15 μm (0.2%) |
| **总通孔数** | **5859** |
| **Via1** | 2941 |
| **Via2** | 2705 |
| **Via3** | 152 |
| **DRC 修复过程** | 48→26→7→0 (3 轮迭代) |

### 阶段间约束
> ⚠️ **必须条件**: DRC 违例必须为 0。天线违例必须为 0。所有信号网必须完整连接（无 dangling pin，除设计本身未连接的端口外）。

---

## 阶段 7：完成 (Finish)

### 做什么
插入填充单元（Fill Cell）使每行完整，提取精确寄生参数（SPEF），执行静态时序分析（STA），计算功耗和 IR Drop，生成最终版图（GDSII/DEF）。

### 工具
- **OpenROAD** `dpl` — 插入 Fill Cell + Tap Cell
- **OpenROAD** `rcx` (OpenRCX) — 寄生参数提取
- **OpenROAD** `psm` (PDNSim) — IR Drop 分析
- **OpenROAD** `sta` — 静态时序分析
- **KLayout** (可选) — GDS 合并

### 策略与选项
```tcl
# 填充单元插入
detailed_placement              # 插入 fill cell 填满每行

# 寄生参数提取 (OpenRCX)
extract_parasitics
  -ext_model_index 0           # 使用 corner 0 的 RC 模型
  -max_merge_res 50.0          # 最大合并电阻 50kΩ
  -coupling_threshold 0.1      # 耦合电容阈值 0.1fF（低于此接地）

# IR Drop 分析
analyze_power_grid
  -vsrc_net VDD                # VDD 网络
  -gnd_net VSS                 # VSS 网络
```

### 输入文件
| 文件 | 说明 |
|------|------|
| `5_2_route.odb` | 详细布线后数据库 |
| `5_route.sdc` | 布线后 SDC |
| `rcx_patterns.rules` | RC 提取规则文件 |

### 输出文件
| 文件 | 说明 |
|------|------|
| `6_1_fill.odb` | 填充后数据库 |
| `6_final.odb` | 最终数据库 |
| `6_final.v` | 最终门级网表 |
| `6_final.def` | 最终物理设计 (DEF) |
| **`6_final.gds`** | **最终版图 (GDSII)** 🎯 |
| `6_final.spef` | 精确寄生参数 (SPEF) |
| `6_final.sdc` | 最终 SDC |

### 关键指标

#### 时序
| 指标 | 数值 |
|------|------|
| **最坏 Setup Slack** | **9.33 ns (MET)** ✅ |
| **最坏 Hold Slack** | **0.10 ns (MET)** ✅ |
| **Setup TNS** | 0.00 |
| **Setup WNS** | 0.00 |
| **fmax** | **1489.11 MHz** |
| **时钟偏斜** | **0.00 ns** |
| **关键路径延迟** | 0.74 ns |
| **Setup 违例数** | 0 |
| **Hold 违例数** | 0 |
| **Slew 违例数** | 0 |
| **Cap 违例数** | 0 |
| **Fanout 违例数** | 0 |

#### 面积
| 指标 | 数值 |
|------|------|
| **设计面积** | **1778 μm²** |
| **利用率** | **58%** |
| **Die 面积** | 3060.33 μm² |

#### 单元分布
| 类型 | 数量 | 面积 (μm²) |
|------|------|-----------|
| Fill Cell | 836 | 1282.65 |
| Tap Cell | 78 | 20.75 |
| Clock Buffer | 17 | 22.61 |
| Timing Repair Buffer | 36 | 30.59 |
| Inverter | 42 | 22.34 |
| Clock Inverter | 15 | 15.16 |
| Sequential (DFF) | 176 | 936.32 |
| Combinational | 482 | 729.90 |
| **Total** | **1682** | **3060.33** |

#### 功耗
| 类型 | Internal | Switching | Leakage | Total | 占比 |
|------|----------|-----------|---------|-------|------|
| Sequential | 241 μW | 51.4 μW | 15.0 μW | 308 μW | 48.3% |
| Combinational | 140 μW | 106 μW | 16.9 μW | 262 μW | 41.2% |
| Clock | 25.5 μW | 40.3 μW | 1.12 μW | 67.0 μW | 10.5% |
| **Total** | **407 μW** | **197 μW** | **33.0 μW** | **637 μW** | 100% |

功耗构成: Internal 63.9% + Switching 31.0% + Leakage 5.2%

#### IR Drop
| 网络 | 总功耗 | 供电电压 | 最坏电压 | 平均 IR Drop | 最坏 IR Drop | 百分比 |
|------|--------|---------|---------|-------------|-------------|--------|
| VDD | 637 μW | 1.10 V | 1.10 V | 0.985 mV | **1.50 mV** | **0.14%** |
| VSS | 637 μW | 0.00 V | 2.65 mV | 1.59 mV | **2.65 mV** | **0.24%** |

> ✅ IR Drop 远小于 5% 阈值，PDN 设计充分。

---

## 全流程时序演进

| 阶段 | Setup Slack | Hold Slack | fmax (MHz) | 关键路径延迟 |
|------|------------|------------|------------|-------------|
| Floorplan | 9.50 ns | 0.11 ns | 1992 | 0.46 ns |
| Global Place | 9.33 ns | 0.10 ns | 1496 | 0.63 ns |
| Detailed Place | 9.34 ns | 0.10 ns | 1507 | 0.63 ns |
| CTS | 9.33 ns | 0.10 ns | 1497 | 0.74 ns |
| Global Route | 9.31 ns | 0.10 ns | 1446 | 0.77 ns |
| **Finish** | **9.33 ns** | **0.10 ns** | **1489** | **0.74 ns** |

> 📊 **观察**: 
> - Floorplan 阶段 fmax 最高（1992 MHz），因为此时使用 wire load model 估计，偏乐观
> - Place 阶段 fmax 降至 ~1500 MHz，因为引入了实际布局的 RC 估计
> - CTS 阶段关键路径增加 0.11ns（时钟 buffer 延迟），但偏斜为 0
> - Global Route 阶段 fmax 降至 1446 MHz，布线 RC 使路径变长
> - Finish 阶段 fmax 回升至 1489 MHz，因为精确 SPEF 提取修正了过估

---

## 全流程功耗演进

| 阶段 | Internal | Switching | Leakage | Total |
|------|----------|-----------|---------|-------|
| Floorplan | 387 μW | 127 μW | 32.6 μW | 547 μW |
| Global Place | 382 μW | 154 μW | 31.9 μW | 568 μW |
| Detailed Place | 382 μW | 156 μW | 31.9 μW | 570 μW |
| CTS | 407 μW | 198 μW | 33.0 μW | 638 μW |
| Global Route | 408 μW | 213 μW | 33.0 μW | 654 μW |
| **Finish** | **407 μW** | **197 μW** | **33.0 μW** | **637 μW** |

> 📊 **观察**: CTS 阶段功耗跳增 ~70 μW，因为插入了 17 个时钟 buffer + 15 个 dummy load。

---

## 全流程面积演进

| 阶段 | 面积 (μm²) | 利用率 | 实例数 | 增量 |
|------|-----------|--------|--------|------|
| Synth | 1743 | — | 765 | — |
| Floorplan | 1743 | 57% | 765 | — |
| Place | 1740 | 60% | 804 | +39 (timing buffers) |
| CTS | 1778 | 58% | 768 | +38 (clock buffers + dummy) |
| Route | 1778 | 58% | 768 | — |
| **Finish** | **1778** | **58%** | **1682** | +914 (fill + tap cells) |

---

## 文件依赖关系图

```
RTL (.v) + SDC + Liberty
    │
    ▼
[1. Synth (Yosys)]
    │ → 1_2_yosys.v (门级网表)
    │ → 1_synth.odb + 1_synth.sdc
    ▼
[2. Floorplan (OpenROAD ifp+pdn)]
    │ → 2_floorplan.odb + 2_floorplan.sdc
    ▼
[3. Placement (OpenROAD gpl+dpl+rsz)]
    │ → 3_place.odb + 3_place.sdc
    ▼
[4. CTS (OpenROAD cts)]
    │ → 4_1_cts.odb + 4_cts.sdc
    ▼
[5. Global Route (OpenROAD grt+rsz+ant)]
    │ → 5_1_grt.odb + 5_1_grt.sdc + route.guide
    ▼
[6. Detailed Route (OpenROAD drt)]
    │ → 5_2_route.odb + 5_route.sdc
    ▼
[7. Finish (OpenROAD fill+rcx+psm+sta)]
    │ → 6_final.gds  ← 🎯 最终版图
    │ → 6_final.v    ← 最终网表
    │ → 6_final.def  ← 最终物理设计
    │ → 6_final.spef ← 精确寄生参数
    ▼
  ✅ 完成
```

---

## 配置参数总结 (config.mk)

```makefile
export DESIGN_NAME = uart_tx
export PLATFORM    = nangate45

export VERILOG_FILES = $(DESIGN_HOME)/src/$(DESIGN_NAME)/uart_tx.v \
                       $(DESIGN_HOME)/src/$(DESIGN_NAME)/uart_tx_fifo.v
export SDC_FILE      = $(DESIGN_HOME)/$(PLATFORM)/$(DESIGN_NAME)/uart_tx.sdc

export CLOCK_PERIOD ?= 10.0          # 100MHz 目标
export CORE_UTILIZATION ?= 55        # 55% 核心利用率
export PLACE_DENSITY_LB_ADDON = 0.10 # 布局密度附加 10%
export TNS_END_PERCENT = 100         # 修复 100% TNS
```

---

## SDC 约束

```tcl
create_clock -name PCLK -period 10 [get_ports PCLK]
set_input_delay  -max 2   [get_ports {PWDATA tx_fifo_push LCR enable}]
set_input_delay  -min 0.5 [get_ports {PWDATA tx_fifo_push LCR enable}]
set_output_delay -max 2   [get_ports {TXD busy tx_fifo_empty tx_fifo_full tx_fifo_count}]
set_output_delay -min 0.5 [get_ports {TXD busy tx_fifo_empty tx_fifo_full tx_fifo_count}]
```

---

## 最终 PPA 总结

| 维度 | 数值 | 评价 |
|------|------|------|
| **fmax** | **1489 MHz** | 远超 100MHz 目标 (14.9× margin) |
| **Setup Slack** | **9.33 ns (MET)** | 极其宽松 |
| **Hold Slack** | **0.10 ns (MET)** | 满足，但余量较小 |
| **时钟偏斜** | **0.00 ns** | 完美平衡 |
| **面积** | **1778 μm²** | 合理 (58% 利用率) |
| **总功耗** | **637 μW** | 低功耗 |
| **IR Drop (VDD)** | **1.50 mV (0.14%)** | 远小于 5% 阈值 |
| **IR Drop (VSS)** | **2.65 mV (0.24%)** | 远小于 5% 阈值 |
| **DRC** | **0** | 完全干净 |
| **天线违例** | **0** | 完全干净 |

---

## 产出文件清单

| 文件 | 路径 | 说明 |
|------|------|------|
| 🎯 GDSII | `6_final.gds` | 最终版图，可送交晶圆厂 |
| 门级网表 | `6_final.v` | 含所有标准单元实例 |
| DEF | `6_final.def` | 物理设计交换格式 |
| SPEF | `6_final.spef` | 精确寄生参数 |
| SDC | `6_final.sdc` | 最终时序约束 |
| ODB | `6_final.odb` | OpenROAD 数据库 |

---

*报告生成时间: 2025-05 | 工具链: OpenROAD-flow-scripts (Yosys + OpenROAD 26Q1) | 工艺: Nangate45*
