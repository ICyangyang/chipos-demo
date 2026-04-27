# OpenROAD 物理设计报告

## 设计信息

| 项目 | 值 |
|------|-----|
| **设计名称** | mux2to1 (8-bit 参数化 MUX) |
| **工艺平台** | Nangate45 (45nm 开源 PDK) |
| **设计类型** | 纯组合逻辑 |

---

## 物理设计流程

| 阶段 | 状态 | 耗时 |
|------|------|------|
| 1. Synthesis (Yosys) | ✅ PASS | 0s |
| 2. Floorplan | ✅ PASS | 0s |
| 3. Placement | ✅ PASS | 1s |
| 4. CTS | ⏭️ Skipped (组合逻辑) | - |
| 5. Global Route | ✅ PASS | 0s |
| 6. Detail Route | ✅ PASS | 1s |
| 7. Finish | ✅ PASS | 1s |
| **总计** | **✅ 成功** | **~5s** |

---

## 面积结果

| 指标 | 值 |
|------|-----|
| **Die 面积** | 100 × 100 = 10,000 μm² |
| **Core 面积** | 80 × 80 = 6,400 μm² |
| **设计面积** | 64.64 μm² |
| **利用率** | 1.03% |
| **标准单元数** | 145 |
| **填充单元数** | 799 |
| **Tapcell 数** | 112 |

---

## 时序结果

| 指标 | 值 |
|------|-----|
| **Setup TNS** | 0 ns |
| **Setup WNS** | 8.83 ns (MET) |
| **Hold TNS** | 0 ns |
| **Hold WNS** | 1.08 ns (MET) |
| **关键路径延迟** | 0.67 ns |
| **最大频率** | 857.52 MHz |
| **时钟周期** | 10 ns (约束) |

### 关键路径

```
sel → input17/BUF_X1 → _5_/MUX2_X1 → output20/BUF_X1 → out[2]
```

---

## 功耗结果

| 类型 | 功耗 | 占比 |
|------|------|------|
| **Internal Power** | 1.03 μW | 45.6% |
| **Switching Power** | 0.40 μW | 17.8% |
| **Leakage Power** | 0.82 μW | 36.6% |
| **Total Power** | 2.25 μW | 100% |

---

## 布线结果

| 指标 | 值 |
|------|-----|
| **总绕线长度** | 460 μm |
| **Via 总数** | 216 |
| **DRC 违规** | 0 |
| **Antenna 违规** | 0 |

### 绕线层分布

| 层 | 长度 |
|----|------|
| metal2 | 131 μm |
| metal3 | 71 μm |
| metal4 | 111 μm |
| metal5 | 43 μm |
| metal6 | 102 μm |

---

## IR Drop 分析

| 网络 | 最差电压 | 平均压降 | 最差压降 |
|------|---------|---------|---------|
| VDD | 1.10 V | 1.1 mV | 32.7 μV |
| VSS | 31.1 μV | 4.3 μV | 31.1 μV |

---

## 输出文件

| 文件 | 路径 | 用途 |
|------|------|------|
| **GDS** | `orfs_results/6_final.gds` | 最终版图 |
| **DEF** | `orfs_results/6_final.def` | 物理设计交换格式 |
| **Verilog** | `orfs_results/6_final.v` | 布线后网表 |
| **SPEF** | `orfs_results/6_final.spef` | 寄生参数 |
| **ODB** | `orfs_results/6_final.odb` | OpenROAD 数据库 |

---

## 可视化

| 图像 | 文件 |
|------|------|
| 最终版图 | `orfs_results/final_all.webp` |
| 布局 | `orfs_results/final_placement.webp` |
| 布线 | `orfs_results/final_routing.webp` |
| 拥塞 | `orfs_results/final_congestion.webp` |
| IR Drop | `orfs_results/final_ir_drop.webp` |

---

## 总结

✅ **物理设计成功完成**

- 所有阶段通过，无 DRC 违规
- 时序满足约束（Setup/Hold 均有余量）
- 功耗 2.25 μW，面积 64.64 μm²
- GDS 版图已生成，可用于流片

---

生成时间: 2025-01-XX
工具: OpenROAD-flow-scripts + Nangate45
