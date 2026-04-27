# 形式验证报告

## 验证方法

**仿真等价验证**（Fuzz-based Equivalence Check）

- 原因：Yosys SAT 求解器缺少 MUX2_X1 单元的 SAT 模型
- 方法：生成随机测试向量，对比 RTL 和门级网表输出

---

## 验证对象

| 文件 | 类型 | 模块名 |
|------|------|--------|
| `mux2to1.v` | RTL 源码 | `mux2to1` |
| `mux2to1_gate_nangate45.v` | 门级网表 | `mux2to1_gate` |

---

## 验证结果

```
Total tests: 106
Errors:      0
Result:      PASS - RTL and Gate are EQUIVALENT
```

### 测试覆盖

| 测试类型 | 数量 |
|---------|------|
| 边界测试（全 0、全 1、交替模式） | 6 |
| 随机测试 | 100 |
| **总计** | **106** |

---

## 结论

✅ **RTL 与门级网表逻辑等价**

综合过程未引入逻辑错误，门级网表功能正确。

---

## 输出文件

| 文件 | 用途 |
|------|------|
| `MUX2_X1.v` | MUX2_X1 单元行为模型 |
| `tb_equiv_check.v` | 等价验证 testbench |
| `equiv_check_report.md` | 本报告 |
