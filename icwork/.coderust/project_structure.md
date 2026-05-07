# ChipOS 项目目录结构规范

> 本文件为 ChipOS 记忆文件，定义项目目录结构和文件命名规范
>
> **位置**: `/app/backend/icwork/.coderust/` — 适用于 icwork 下所有项目

---

## 一、顶层目录（编号规范）

| 编号 | 目录 | 阶段 | 说明 |
|------|------|------|------|
| 01 | `rtl` | 设计 | RTL 源代码 |
| 02 | `verification` | 验证 | Testbench、等价检查 |
| 03 | `synthesis` | 综合 | Yosys/ORFS 综合配置 |
| 04 | `timing` | 时序 | SDC 约束、STA 报告 |
| 05 | `power` | 功耗 | 功耗分析脚本与报告 |
| 06 | `physical` | 后端 | OpenROAD 物理设计 |
| 07 | `simulation` | 仿真 | RTL/门级/后仿真 |

---

## 二、子目录规范

### 01_rtl/
```
├── <module>.v              # RTL 设计源文件
├── <module>_gate.v         # 门级网表（软链接 → 06_physical/）
└── cell_lib/               # 单元行为模型库
    └── <cell>_X1.v         # 标准单元行为模型
```

### 02_verification/
```
├── tb_<module>.sv          # 功能验证 Testbench
├── tb_equiv_check.v        # 等价检查 Testbench
└── equiv_check_report.md   # 等价检查报告
```

### 03_synthesis/
```
├── config.mk               # ORFS 配置
├── <module>_structure.dot  # 综合结构图
└── synth_report.txt        # 综合报告
```

### 04_timing/
```
├── <module>.sdc            # 时序约束
├── <module>_orfs.sdc       # ORFS 专用约束
└── timing_report_<pdk>.md  # 时序分析报告
```

### 05_power/
```
├── power_analysis.tcl      # 功耗分析脚本
└── power_report_<pdk>.md   # 功耗报告
```

### 06_physical/
```
├── 1_synth.*               # 综合阶段产物
├── 2_floorplan.*           # 布局规划
├── 3_place.*               # 单元放置
├── 4_cts.*                 # 时钟树综合
├── 5_route.*               # 布线
├── 6_final.*               # 最终结果（网表、DEF、SDF、GDS）
├── *.rpt                   # 报告文件
└── *.webp                  # 可视化图片
```

### 07_simulation/
```
├── rtl_sim/                # RTL 功能仿真
│   ├── tb_<module>.sv
│   ├── <module>.v          # 软链接 → ../../01_rtl/<module>.v
│   └── report_rtl_sim.txt
├── netlist_sim/            # 门级网表仿真（零延迟）
│   ├── tb_<module>_gate.sv
│   ├── <module>_gate.v     # 软链接 → 06_physical/6_final.v
│   └── report_netlist_sim.txt
├── post_sim/               # 后仿真（SDF 反标）
│   ├── tb_<module>_post.sv
│   ├── <module>_gate.v     # 软链接 → 06_physical/6_final.v
│   ├── <module>_gate.sdf   # 软链接 → 06_physical/6_final.sdf
│   └── sdfAnnotateInfo.log # SDF 反标率报告
├── coverage_obj/           # 覆盖率数据
└── obj_dir/                # Verilator 编译产物
```

---

## 三、文件命名规范

| 类型 | 格式 | 示例 |
|------|------|------|
| RTL 源码 | `<module>.v` | `mux2to1.v` |
| Testbench | `tb_<module>.sv` | `tb_mux2to1.sv` |
| 门级网表 | `<module>_gate.v` | `mux2to1_gate.v` |
| SDC 约束 | `<module>.sdc` | `mux2to1.sdc` |
| SDF 时序 | `<module>_gate.sdf` | `mux2to1_gate.sdf` |
| 仿真报告 | `report_<stage>.txt` | `report_rtl_sim.txt` |
| 反标日志 | `sdfAnnotateInfo.log` | `sdfAnnotateInfo.log` |
| 单元模型 | `<cell>_X1.v` | `MUX2_X1.v` |

---

## 四、文件共享规范（软链接）

### 4.1 软链接使用原则

- **源文件**：放在产出阶段目录
- **链接文件**：使用阶段用软链接指向源文件
- **相对路径**：`../../<source_dir>/<file>`

### 4.2 软链接映射表

| 文件类型 | 源路径 | 链接路径 |
|---------|--------|---------|
| 门级网表 | `06_physical/6_final.v` | `07_simulation/netlist_sim/mux2to1_gate.v` |
| 门级网表 | `06_physical/6_final.v` | `07_simulation/post_sim/mux2to1_gate.v` |
| SDF 文件 | `06_physical/6_final.sdf` | `07_simulation/post_sim/mux2to1_gate.sdf` |
| 单元模型 | `01_rtl/cell_lib/MUX2_X1.v` | `07_simulation/netlist_sim/MUX2_X1.v` |
| 单元模型 | `01_rtl/cell_lib/MUX2_X1.v` | `07_simulation/post_sim/MUX2_X1.v` |

### 4.3 软链接命令模板

```bash
# 创建软链接
ln -s ../../<source_dir>/<file> <link_name>

# 示例：在 post_sim/ 中链接门级网表
cd 07_simulation/post_sim/
ln -s ../../06_physical/6_final.v mux2to1_gate.v
ln -s ../../06_physical/6_final.sdf mux2to1_gate.sdf
ln -s ../../01_rtl/cell_lib/MUX2_X1.v MUX2_X1.v
```

---

## 五、物理设计阶段产物

| 阶段 | 编号 | 产物文件 | 说明 |
|------|------|---------|------|
| 综合 | 1 | `1_synth.v`, `1_synth.odb` | 综合后网表 |
| 布局规划 | 2 | `2_floorplan.def`, `2_floorplan.odb` | 芯片面积、IO 位置 |
| 放置 | 3 | `3_place.def`, `3_place.odb` | 单元位置 |
| 时钟树 | 4 | `4_cts.def`, `4_cts.odb` | 时钟网络 |
| 布线 | 5 | `5_route.def`, `5_route.odb`, `5_route.spef` | 信号布线 + 寄生参数 |
| 最终 | 6 | `6_final.v`, `6_final.def`, `6_final.sdf`, `6_final.gds` | 最终交付产物 |

---

## 六、仿真类型对比

| 项目 | rtl_sim | netlist_sim | post_sim |
|------|---------|-------------|----------|
| DUT | RTL 源码 | 门级网表 | 门级网表 |
| 延迟 | 零延迟 | 零延迟 | SDF 反标 |
| 时序精度 | 无 | 无 | ps 级 |
| 验证目标 | 功能正确 | 功能正确 | 功能 + 时序 |
| 仿真器 | iverilog/Verilator | iverilog/Verilator | ModelSim/VCS/Xcelium |

---

## 七、工具兼容性

| 工具 | 软链接支持 | SDF 支持 | 说明 |
|------|-----------|---------|------|
| iverilog | ✅ | ❌ | 开源仿真器，不支持 SDF |
| Verilator | ✅ | ❌ | 高速仿真器，不支持 SDF |
| ModelSim | ✅ | ✅ | 商业仿真器，完整支持 |
| VCS | ✅ | ✅ | Synopsys 商业仿真器 |
| OpenROAD | ✅ | N/A | 物理设计工具 |

---

## 八、版本记录

| 日期 | 版本 | 说明 |
|------|------|------|
| 2025-01-XX | v1.0 | 初始版本，定义目录结构规范 |
