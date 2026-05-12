# ORFS PPA 完整流程策略 — uart_tx（v2.0）

## 一、流程总览

```
orfs_setup → orfs_init_design → synth → floorplan → place → cts → grt → route → finish → get_metrics
```

每步完成后 `orfs_read_report` 检查结果，有错则 `orfs_update_config` + `orfs_clean_stage` 重跑。

---

## 二、输入文件清单

| 文件 | 路径 | 角色 |
|------|------|------|
| `uart_tx.v` | `/workspace/work/uart_tx_study/uart_tx.v` | 顶层模块 RTL |
| `uart_tx_fifo.v` | `/workspace/work/uart_tx_study/uart_tx_fifo.v` | FIFO 子模块 RTL |
| `uart_tx.sdc` | `/workspace/work/uart_tx_study/uart_tx.sdc` | 时序约束（10ns PCLK） |
| `config.mk` | 需新建 | ORFS 设计配置 |

### config.mk 关键参数（需新建）

```makefile
DESIGN_NAME = uart_tx
PLATFORM = nangate45
VERILOG_FILES = /workspace/work/uart_tx_study/uart_tx.v /workspace/work/uart_tx_study/uart_tx_fifo.v
SDC_FILE = /workspace/work/uart_tx_study/uart_tx.sdc
# 面积/时序/功耗参数将在各阶段调优
CORE_UTILIZATION = 55      # 小模块，利用率适中
PLACE_DENSITY = 0.7        # 折中密度
CLOCK_PERIOD = 10.0        # 100MHz（与 SDC 一致）
```

---

## 三、各阶段策略与关键检查点

### Step 1: orfs_setup
- **参数**: `design_name=uart_tx`, `platform=nangate45`, `flow_home=/opt/OpenROAD-flow-scripts/flow`
- **检查**: 确认 ORFS 目录结构正确，PDK 库文件可访问

### Step 2: orfs_init_design
- **参数**: `verilog_files=[uart_tx.v, uart_tx_fifo.v]`, `config_mk=新建的config.mk`, `sdc_file=uart_tx.sdc`
- **检查**: 确认 RTL/config/SDC 已拷贝到 ORFS 设计目录

### Step 3: orfs_synth（逻辑综合）
- **参数**: `clock_period_ps=10000`（10ns = 10000ps），`abc_area=false`（速度优先）
- **日志关键检查点**:
  - ✅ 无 `error` / `multiple drivers` / `inferring latch`
  - ✅ `hierarchy` 正确展开 `uart_tx_fifo`
  - ✅ Chip area 数值合理（预期 500-1500 μm²）
  - ✅ 无 unconnected ports
- **如果失败**: 读取 synth log，定位 ERROR 行，修复 RTL 后重跑

### Step 4: orfs_floorplan（布图规划）
- **参数**: `core_utilization=55`, `core_aspect_ratio=1.0`, `core_margins=默认`
- **日志关键检查点**:
  - ✅ Die/Core area 合理（Core ≈ 综合面积 / utilization）
  - ✅ IO pin 位置合理（PCLK/PRESETn 左侧，TXD 右侧）
  - ✅ PDN 生成成功（M1/M2 电源网格）
  - ✅ Tapcell 放置完成
- **调优**: 如果面积过大/过小，调整 `CORE_UTILIZATION`

### Step 5: orfs_place（布局）
- **参数**: `place_density=0.7`（折中）
- **日志关键检查点**:
  - ✅ Global placement overflow < 20%
  - ✅ Detailed placement 无 overlap
  - ✅ 无 HPWL 暴增（说明布局合理）
- **调优**: 如果 overflow > 30%，降低 `PLACE_DENSITY` 到 0.6

### Step 6: orfs_cts（时钟树综合）
- **参数**: `tns_end_percent=30`（时序较宽松，30% 即可）
- **日志关键检查点**:
  - ✅ CTS buffer 数量合理（小模块预期 < 10）
  - ✅ Clock skew < 0.5ns
  - ✅ Setup slack > 0（无违例）
  - ✅ Hold slack > 0（无违例）
- **如果 hold 违例**: ORFS 会自动修复，检查修复后 slack

### Step 7: orfs_global_route（全局布线）
- **日志关键检查点**:
  - ✅ Routing congestion < 5%（小模块预期无拥塞）
  - ✅ 无 overflow routing regions
  - ✅ 预估线长合理

### Step 8: orfs_detail_route（详细布线）
- **日志关键检查点**:
  - ✅ DRC violations = 0（最关键！）
  - ✅ Routing completion rate = 100%
  - ✅ 无 open/short/spacing violations

### Step 9: orfs_finish（最终完成）
- **日志关键检查点**:
  - ✅ Density fill 完成
  - ✅ Antenna check 通过
  - ✅ GDS/DEF/netlist 生成成功
  - ✅ Final DRC violations = 0

### Step 10: orfs_get_metrics（读取最终 PPA）
- **关注指标**:
  - **时序**: WNS/TNS/WS/TNS（Setup + Hold）
  - **面积**: Total area / Core area / Utilization
  - **功耗**: Internal / Switching / Leakage / Total
  - **频率**: Max operating frequency

---

## 四、预期 PPA 结果

| 指标 | 预期范围 | 说明 |
|------|----------|------|
| 总面积 | 500-2000 μm² | 167 FF + 281 组合逻辑 |
| 核心利用率 | 55% | 初始设定，可调 |
| 最大频率 | ≥ 100MHz | 10ns period，逻辑简单 |
| Setup slack | > 2ns | 逻辑深度浅 |
| Hold slack | > 0 | CTS 后应自动满足 |
| DRC | 0 violations | 小模块，布线宽松 |
| 功耗 | < 1mW | 低频小模块 |

---

## 五、失败回退策略

| 阶段 | 可能失败 | 回退操作 |
|------|----------|----------|
| synth | Latch/多驱动 | 修复 RTL → `orfs_clean_stage synth` → 重跑 |
| floorplan | 面积不合理 | 调 `CORE_UTILIZATION` → `orfs_clean_stage floorplan` → 重跑 |
| place | overflow > 30% | 调 `PLACE_DENSITY` → `orfs_clean_stage place` → 重跑 |
| cts | hold 违例 | 检查修复结果，必要时调 `tns_end_percent` |
| route | DRC > 0 | 检查 violation 类型，调整 density/margin |
| finish | antenna | 加 antenna diode → 重跑 |

---

## 六、产出文件

| 文件 | 路径 | 说明 |
|------|------|------|
| GDS | `results/nangate45/uart_tx/6_final.gds` | 最终版图 |
| DEF | `results/nangate45/uart_tx/6_final.def` | 详细布线结果 |
| Netlist | `results/nangate45/uart_tx/6_final.v` | 最终门级网list |
| SDC | `results/nangate45/uart_tx/6_final.sdc` | 最终时序约束 |
| Log | `log/nangate45/uart_tx/*.log` | 各阶段日志 |
| Report | `reports/nangate45/uart_tx/*.rpt` | 各阶段报告 |

完成后用 `orfs_collect_results` 拷贝到 `/workspace/work/uart_tx_study/orfs_results/`。

---

## 七、日志阅读指南 — 你需要看的关键点

### synth 阶段
```
1. "Printing statistics" → Chip area 总值
2. "Number of cells" → 各类型单元数量
3. "Removed unused cells" → 确认无悬空逻辑
```

### floorplan 阶段
```
1. "Core area" → 核心面积
2. "Die area" → 芯片面积
3. "PDN generation" → 电源网格是否成功
```

### place 阶段
```
1. "Global placement overflow" → 布局拥挤度
2. "HPWL" → 半周长线长（越小越好）
```

### cts 阶段
```
1. "Clock tree summary" → buffer/skew
2. "Setup slack" → 必须为正
3. "Hold slack" → 必须为正
```

### route 阶段
```
1. "DRC violations" → 必须为 0
2. "Routing completion" → 必须 100%
```

### finish 阶段
```
1. "Total DRC violations" → 必须为 0
2. "Antenna violations" → 必须为 0
3. "Final area" → 最终面积
```