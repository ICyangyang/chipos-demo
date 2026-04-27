# MUX2TO1 芯片设计项目

## 项目概述

- **设计名称**: mux2to1 (参数化 8-bit 2-to-1 MUX)
- **工艺平台**: Nangate45 (45nm 开源标准单元库)
- **设计流程**: RTL → 综合 → 时序分析 → 功耗分析 → 形式验证 → 物理设计 → GDS

---

## 目录结构

```
/app/backend/icwork/mux/
├── 01_rtl/              # RTL 设计
│   ├── mux2to1.v            # 参数化 RTL 源码 (8-bit MUX)
│   ├── mux2to1_gate_nangate45.v  # 门级网表 (Yosys 综合)
│   └── MUX2_X1.v            # MUX2_X1 单元行为模型
│
├── 02_verification/     # 验证
│   ├── tb_equiv_check.v     # 等价验证 Testbench
│   ├── equiv_check.vvp      # 等价验证仿真二进制
│   └── equiv_check_report.md # 形式验证报告 (PASS)
│
├── 03_synthesis/        # 综合
│   ├── config.mk            # ORFS 综合配置
│   └── mux2to1_structure.dot # 综合结构图 (Graphviz)
│
├── 04_timing/           # 时序分析
│   ├── mux2to1.sdc          # 时序约束文件
│   ├── mux2to1_orfs.sdc     # ORFS 时序约束
│   ├── sta_cmd.tcl          # OpenSTA TCL 脚本
│   └── timing_report_nangate45.md # 时序分析报告
│
├── 05_power/            # 功耗分析
│   ├── power_analysis.tcl   # OpenSTA 功耗分析脚本
│   └── power_report_nangate45.md # 功耗分析报告
│
├── 06_physical/         # 物理设计 (OpenROAD)
│   ├── 6_final.gds          # 最终 GDS 版图
│   ├── 6_final.def          # DEF 物理设计文件
│   ├── 6_final.v            # 布线后网表
│   ├── 6_final.spef         # 寄生参数文件
│   ├── 6_final.sdf          # SDF 时序反标文件
│   ├── generate_sdf.tcl     # SDF 生成脚本
│   ├── physical_design_report.md # 物理设计报告
│   ├── final_*.webp         # 版图可视化图像
│   └── *.odb/*.log/*.rpt    # 各阶段中间文件
│
├── 07_simulation/       # 仿真
│   ├── rtl_sim/              # RTL 级仿真
│   │   ├── tb_mux2to1.sv         # SystemVerilog Testbench
│   │   ├── mux2to1.v             # RTL 源码
│   │   ├── run_rtl_sim.sh        # 仿真脚本 (iverilog)
│   │   ├── mux2to1_rtl.vcd       # RTL 波形文件
│   │   └── report_rtl_sim.txt    # RTL 仿真报告
│   │
│   ├── netlist_sim/          # 门级网表仿真
│   │   ├── tb_mux2to1_gate.sv    # 门级 Testbench
│   │   ├── mux2to1_gate.v        # 门级网表
│   │   ├── mux2to1_gate.sdf      # SDF 时序反标文件
│   │   ├── MUX2_X1.v             # 单元行为模型
│   │   ├── run_netlist_sim.sh    # 仿真脚本 (iverilog)
│   │   ├── mux2to1_gate.vcd      # 门级波形文件
│   │   └── report_netlist_sim.txt # 门级仿真报告
│   │
│   ├── obj_dir/             # Verilator 编译产物 (历史)
│   └── coverage_obj/        # 覆盖率数据 (历史)
│
└── .trace/              # 工具执行追踪日志
```

---

## PPA 结果摘要

| 指标 | 值 |
|------|-----|
| **面积** | 64.64 μm² |
| **功耗** | 2.25 μW (Internal 45.6%, Leakage 36.6%) |
| **最大频率** | 857.52 MHz |
| **Setup Slack** | 8.83 ns |
| **Hold Slack** | 1.08 ns |
| **DRC 违规** | 0 |

---

## 关键文件说明

### RTL 设计 (`01_rtl/`)

| 文件 | 说明 |
|------|------|
| `mux2to1.v` | 参数化 2-to-1 MUX，默认 8-bit，可配置 WIDTH |
| `mux2to1_gate_nangate45.v` | Yosys 综合后的门级网表，使用 Nangate45 单元 |
| `MUX2_X1.v` | MUX2_X1 标准单元行为模型，用于门级仿真 |

### 验证 (`02_verification/`)

| 文件 | 说明 |
|------|------|
| `tb_mux2to1.sv` | SystemVerilog Testbench，包含功能测试和覆盖率收集 |
| `tb_equiv_check.v` | RTL 与门级网表等价验证 Testbench |
| `equiv_check_report.md` | 形式验证结果：106 测试向量全部通过 |

### 物理设计 (`06_physical/`)

| 文件 | 说明 |
|------|------|
| `6_final.gds` | 最终 GDSII 版图文件，可用于流片 |
| `6_final.def` | DEF 格式物理设计交换文件 |
| `6_final.spef` | SPEF 格式寄生参数文件 |
| `final_all.webp` | 最终版图可视化图像 |

---

## 工具链

| 工具 | 用途 |
|------|------|
| **Yosys** | 逻辑综合 |
| **OpenSTA** | 静态时序分析 + 功耗估算 |
| **OpenROAD** | 物理设计 (Floorplan → Place → Route → GDS) |
| **Verilator** | RTL 仿真 + 覆盖率收集 |
| **iverilog** | 等价验证仿真 |

---

## 使用方法

### 查看 RTL
```bash
cat 01_rtl/mux2to1.v
```

### 查看 GDS 版图
```bash
# 使用 KLayout
klayout 06_physical/6_final.gds
```

### 运行仿真
```bash
cd 07_simulation
./obj_dir/sim_bin
```

### 查看波形
```bash
gtkwave 07_simulation/mux2to1.vcd
```

---

## 设计流程时间线

1. **RTL 设计** → 参数化 8-bit MUX
2. **功能验证** → Verilator 仿真通过
3. **逻辑综合** → Yosys 综合到 Nangate45 门级
4. **时序分析** → OpenSTA 静态时序分析
5. **功耗分析** → OpenSTA 功耗估算
6. **形式验证** → RTL 与门级网表等价验证通过
7. **物理设计** → OpenROAD 完整流程 (Synth → Floorplan → Place → Route → Finish)
8. **GDS 生成** → 最终版图输出

---

生成时间: 2026-04-27