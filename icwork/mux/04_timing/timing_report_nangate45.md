# mux2to1 时序分析报告

## 设计信息
- **模块**: mux2to1 (8-bit 2:1 MUX)
- **工艺库**: Nangate45 (NangateOpenCellLibrary_typical)
- **工具**: Yosys 0.56 + OpenSTA 3.1.0

## 综合结果

| 指标 | 值 |
|------|-----|
| 工艺库单元 | 135 cells (127 imported, 8 ignored) |
| 映射单元 | **8 × MUX2_X1** |
| 芯片面积 | **14.896 μm²** |
| 时序单元 | 0 (纯组合逻辑) |

### 跳过的单元
- 8 个时钟门控单元 (CLKGATETST_X1/2/4/8, CLKGATE_X1/2/4/8) - 无逻辑函数定义
- 21 个时序单元 (DFF/DFFR/DFFS/DFFRS/SDFF*/DLH/DLL/TLAT)
- 6 个三态单元 (TBUF/TINV)
- 10 个 dont_use 单元 (ANTENNA/FILLCELL/TAPCELL/LOGIC0/LOGIC1)

## 时序分析

### 时序约束
```sdc
create_clock -name clk -period 500 [get_ports sel]  # 2 GHz
```

### 时序结果

| 检查类型 | Slack | 状态 |
|---------|-------|------|
| Setup (max) | **249.96 ps** | ✅ MET |
| Hold (min) | **0.02 ps** | ✅ MET |
| TNS | 0.00 ps | ✅ |
| WNS | 0.00 ps | ✅ |

### 关键路径

**Setup Path (max)**:
```
sel (clock source) → out[0]
  Delay: 0.04 ps (clock network delay)
  Arrival: 250.04 ps
  Required: 500.00 ps
  Slack: 249.96 ps (MET)
```

**Hold Path (min)**:
```
sel (clock source) → out[0]
  Delay: 0.02 ps (clock network delay)
  Arrival: 0.02 ps
  Required: 0.00 ps
  Slack: 0.02 ps (MET)
```

## 结论

设计在 **2 GHz** 时钟下满足所有时序约束：
- Setup 裕量充足 (249.96 ps)
- Hold 满足要求 (0.02 ps)
- 纯组合逻辑，无时序单元

## 生成文件
- `mux2to1_gate_nangate45.v` - 门级网表 (Nangate45)
- `mux2to1.sdc` - 时序约束
- `timing_report_nangate45.md` - 本报告
