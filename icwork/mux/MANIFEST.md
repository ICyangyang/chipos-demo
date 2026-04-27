# MUX2TO1 项目文件清单

## 目录结构规范

详见 `../.coderust/project_structure.md`

## 软链接说明

| 链接位置 | 指向源文件 | 说明 |
|---------|-----------|------|
| `01_rtl/mux2to1_gate.v` | `06_physical/6_final.v` | 门级网表 |
| `07_simulation/rtl_sim/mux2to1.v` | `01_rtl/mux2to1.v` | RTL 源码 |
| `07_simulation/netlist_sim/mux2to1_gate.v` | `06_physical/6_final.v` | 门级网表 |
| `07_simulation/netlist_sim/MUX2_X1.v` | `01_rtl/cell_lib/MUX2_X1.v` | 单元模型 |
| `07_simulation/post_sim/mux2to1_gate.v` | `06_physical/6_final.v` | 门级网表 |
| `07_simulation/post_sim/mux2to1_gate.sdf` | `06_physical/6_final.sdf` | SDF 时序 |
| `07_simulation/post_sim/MUX2_X1.v` | `01_rtl/cell_lib/MUX2_X1.v` | 单元模型 |

## 01_rtl (RTL 设计)

| 文件 | 大小 | 说明 |
|------|------|------|
| `mux2to1.v` | 733 B | 参数化 RTL 源码 |
| `mux2to1_gate_nangate45.v` | 918 B | 门级网表（Yosys 综合） |
| `mux2to1_gate.v` → | `06_physical/6_final.v` | 门级网表（软链接） |

### cell_lib (单元库)

| 文件 | 大小 | 说明 |
|------|------|------|
| `MUX2_X1.v` | 211 B | MUX2 单元行为模型 |

## 02_verification (验证) - 3 个文件

| 文件 | 大小 | 说明 |
|------|------|------|
| `tb_equiv_check.v` | 3.0 KB | 等价验证 Testbench |
| `equiv_check.vvp` | 13.5 KB | 仿真二进制 |
| `equiv_check_report.md` | 1.0 KB | 验证报告 |

## 03_synthesis (综合) - 2 个文件

| 文件 | 大小 | 说明 |
|------|------|------|
| `config.mk` | 671 B | ORFS 配置 |
| `mux2to1_structure.dot` | 7.8 KB | 结构图 |

## 04_timing (时序分析) - 4 个文件

| 文件 | 大小 | 说明 |
|------|------|------|
| `mux2to1.sdc` | 219 B | 时序约束 |
| `mux2to1_orfs.sdc` | 492 B | ORFS 约束 |
| `sta_cmd.tcl` | 252 B | STA 脚本 |
| `timing_report_nangate45.md` | 1.6 KB | 时序报告 |

## 05_power (功耗分析) - 2 个文件

| 文件 | 大小 | 说明 |
|------|------|------|
| `power_analysis.tcl` | 667 B | 功耗脚本 |
| `power_report_nangate45.md` | 2.8 KB | 功耗报告 |

## 06_physical (物理设计) - 70+ 个文件

### 关键输出文件

| 文件 | 大小 | 说明 |
|------|------|------|
| `6_final.gds` | 117 KB | **GDS 版图** |
| `6_final.def` | 128 KB | DEF 物理设计 |
| `6_final.v` | 2.1 KB | 布线后网表 |
| `6_final.spef` | 35 KB | 寄生参数 |
| `physical_design_report.md` | 3.0 KB | 物理设计报告 |

### 可视化图像

| 文件 | 大小 | 说明 |
|------|------|------|
| `final_all.webp` | 41 KB | 最终版图 |
| `final_routing.webp` | 37 KB | 布线图 |
| `final_worst_path.webp` | 29 KB | 关键路径 |
| `final_congestion.webp` | 19 KB | 拥塞图 |
| `final_placement.webp` | 6.7 KB | 布局图 |
| `final_ir_drop.webp` | 11 KB | IR Drop |
| `final_clocks.webp` | 2.5 KB | 时钟图 |
| `final_resizer.webp` | 5.6 KB | Resizer |

### 中间文件 (各阶段)

| 阶段 | 文件数 | 说明 |
|------|--------|------|
| 1_synth | 10 | 综合阶段 |
| 2_floorplan | 15 | 布局规划 |
| 3_place | 15 | 布局 |
| 4_cts | 8 | 时钟树综合 |
| 5_route | 12 | 布线 |
| 6_finish | 10 | 完成 |

## 07_simulation (仿真) - 两个子目录

### rtl_sim (RTL 级仿真) - 5 个文件

| 文件 | 大小 | 说明 |
|------|------|------|
| `tb_mux2to1.sv` | 14.3 KB | SystemVerilog Testbench |
| `mux2to1.v` | 733 B | RTL 源码 |
| `run_rtl_sim.sh` | 1.2 KB | 仿真脚本 (iverilog) |
| `mux2to1_rtl.vcd` | ~10 KB | RTL 波形文件 |
| `report_rtl_sim.txt` | ~5 KB | RTL 仿真报告 |

### netlist_sim (门级网表仿真)

| 文件 | 大小 | 说明 |
|------|------|------|
| `tb_mux2to1_gate.sv` | 7.5 KB | 门级 Testbench |
| `mux2to1_gate.v` → | `06_physical/6_final.v` | 门级网表（软链接） |
| `MUX2_X1.v` → | `01_rtl/cell_lib/MUX2_X1.v` | 单元模型（软链接） |
| `mux2to1_gate.sdf` | 12 KB | SDF 时序文件 |
| `run_netlist_sim.sh` | 1.5 KB | 仿真脚本 (iverilog) |
| `mux2to1_gate.vcd` | ~15 KB | 门级波形文件 |
| `report_netlist_sim.txt` | ~3 KB | 门级仿真报告 |

### post_sim (后仿真 - SDF 反标)

| 文件 | 大小 | 说明 |
|------|------|------|
| `tb_mux2to1_post.sv` | 10.9 KB | 后仿真 Testbench（含 SDF 反标） |
| `mux2to1_gate.v` → | `06_physical/6_final.v` | 门级网表（软链接） |
| `mux2to1_gate.sdf` → | `06_physical/6_final.sdf` | SDF 时序（软链接） |
| `MUX2_X1.v` → | `01_rtl/cell_lib/MUX2_X1.v` | 单元模型（软链接） |
| `run_post_sim.sh` | 4.8 KB | 仿真脚本 |
| `mux2to1_post.vcd` | ~11 KB | 后仿真波形 |
| `report_post_sim.txt` | ~4 KB | 后仿真报告 |
| `sdfAnnotateInfo.log` | 3.6 KB | SDF 反标率报告 |

### 历史文件

| 文件/目录 | 说明 |
|-----------|------|
| `obj_dir/` | Verilator 编译产物 (历史) |
| `coverage_obj/` | 覆盖率数据 (历史) |

---

## 统计

| 类别 | 文件数 |
|------|--------|
| RTL 设计 | 3 |
| 验证 | 3 |
| 综合 | 2 |
| 时序分析 | 4 |
| 功耗分析 | 2 |
| 物理设计 | 70+ |
| 仿真 (rtl_sim) | 5 |
| 仿真 (netlist_sim) | 6 |
| **总计** | **95+** |
| **总计** | **105+** |
## SDF 时序反标文件

### 生成方法
```bash
cd /app/backend/icwork/mux/06_physical
/opt/OpenROAD-flow-scripts/tools/install/OpenROAD/bin/sta -exit generate_sdf.tcl
```

### 文件位置
- **源文件**: `06_physical/6_final.sdf` (12 KB, 463 行)
- **仿真用**: `07_simulation/netlist_sim/mux2to1_gate.sdf`

### SDF 内容
- **版本**: SDF 3.0
- **时序路径**: 73 条 IOPATH
- **时间单位**: 1 ns
- **延迟类型**: INTERCONNECT (互连延迟)
