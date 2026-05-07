# Author: ChipOS RTL Team
# Date: 2026-04-28
# Description: Golden Reference Model for 4-bit LFSR (x^4 + x + 1)
# Circuit Type: Single-cycle Sequential (FSM with 15 states)
# Pipeline Delay: 1 cycle (state update on posedge clk)

"""
4位线性反馈移位寄存器（LFSR）伪随机码发生器 Golden Model

特征多项式: x^4 + x + 1 (最大周期 15)
初始状态: d = 0b1111 (15)
状态转移: d_next[3] = d[3] ^ d[0], d_next[2:0] = d[3:1]
输出: y = d[0] (LSB)

注意: LFSR 状态 0 是吸收态，设计中初始化为 15 避免进入死锁
"""


def lfsr_next_state(d: int) -> int:
    """计算 LFSR 下一状态（单周期转移）
    
    Args:
        d: 当前状态，4位无符号整数 (0-15)
    
    Returns:
        下一状态，4位无符号整数
    """
    # 提取各位 (bit-exact 操作)
    d3 = (d >> 3) & 1
    d2 = (d >> 2) & 1
    d1 = (d >> 1) & 1
    d0 = d & 1
    
    # 状态转移方程
    # d_next[3] = d[3] ^ d[0] (反馈位)
    # d_next[2] = d[3]
    # d_next[1] = d[2]
    # d_next[0] = d[1]
    d_next_3 = d3 ^ d0  # XOR: 模2加
    d_next_2 = d3
    d_next_1 = d2
    d_next_0 = d1
    
    # 组合成4位状态
    d_next = (d_next_3 << 3) | (d_next_2 << 2) | (d_next_1 << 1) | d_next_0
    
    return d_next


def lfsr_output(d: int) -> int:
    """计算 LFSR 输出
    
    Args:
        d: 当前状态，4位无符号整数
    
    Returns:
        输出值 y = d[0] (LSB)
    """
    return d & 1


def simulate_lfsr(initial_state: int = 15, num_cycles: int = 15) -> list:
    """仿真 LFSR 产生完整序列
    
    Args:
        initial_state: 初始状态，默认 15 (4'b1111)
        num_cycles: 仿真周期数
    
    Returns:
        列表，每个元素为 {'cycle': int, 'd': int, 'y': int}
    """
    results = []
    d = initial_state & 0xF  # 确保4位
    
    for cycle in range(num_cycles):
        y = lfsr_output(d)
        results.append({
            'cycle': cycle,
            'd': d,
            'y': y
        })
        d = lfsr_next_state(d)
    
    return results


def get_expected_sequence() -> list:
    """获取标准 15 周期 LFSR 序列（从初始状态 15 开始）
    
    Returns:
        完整 15 周期状态和输出序列
    """
    return simulate_lfsr(initial_state=15, num_cycles=15)


def run_golden_compare(testcase_results: list) -> dict:
    """Golden Model 比较函数
    
    将仿真结果与 Golden Model 计算的期望值进行 bit-exact 比较。
    
    Args:
        testcase_results: 仿真结果列表，每个元素为字典:
            {
                'cycle': int,    # 周期号
                'd': int,        # RTL 状态值
                'y': int         # RTL 输出值
            }
    
    Returns:
        {
            'success': bool,           # 全部匹配为 True
            'total_cases': int,        # 总测试用例数
            'passed_cases': int,       # 通过用例数
            'failed_cases': int,       # 失败用例数
            'failures': [              # 失败详情列表
                {
                    'case_name': str,
                    'expected': str,
                    'actual': str,
                    'diff_bits': int
                }
            ],
            'summary': str             # 结果摘要
        }
    """
    if not testcase_results:
        return {
            'success': False,
            'total_cases': 0,
            'passed_cases': 0,
            'failed_cases': 0,
            'failures': [{'case_name': 'empty_input', 'expected': 'non-empty', 'actual': 'empty', 'diff_bits': 0}],
            'summary': 'ERROR: Empty testcase results'
        }
    
    # 生成期望序列
    expected_seq = get_expected_sequence()
    
    failures = []
    passed = 0
    
    for i, tc in enumerate(testcase_results):
        cycle = tc.get('cycle', i)
        actual_d = tc.get('d')
        actual_y = tc.get('y')
        
        # 查找对应周期的期望值
        if cycle < len(expected_seq):
            expected = expected_seq[cycle]
            expected_d = expected['d']
            expected_y = expected['y']
        else:
            # 超出标准序列，动态计算
            # 从周期 0 开始仿真到当前周期
            extended_seq = simulate_lfsr(initial_state=15, num_cycles=cycle + 1)
            expected_d = extended_seq[cycle]['d']
            expected_y = extended_seq[cycle]['y']
        
        # Bit-exact 比较
        d_match = (actual_d == expected_d)
        y_match = (actual_y == expected_y)
        
        if d_match and y_match:
            passed += 1
        else:
            # 计算差异位数
            d_diff_bits = bin(actual_d ^ expected_d).count('1') if actual_d is not None else 4
            y_diff_bits = 1 if not y_match else 0
            
            failures.append({
                'case_name': f'cycle_{cycle}',
                'expected': f'd={expected_d}(0b{expected_d:04b}), y={expected_y}',
                'actual': f'd={actual_d}(0b{actual_d:04b}), y={actual_y}' if actual_d is not None else 'None',
                'diff_bits': d_diff_bits + y_diff_bits
            })
    
    total = len(testcase_results)
    failed = len(failures)
    success = (failed == 0)
    
    summary = f"Golden Compare: {passed}/{total} passed"
    if not success:
        summary += f", {failed} mismatches"
    
    return {
        'success': success,
        'total_cases': total,
        'passed_cases': passed,
        'failed_cases': failed,
        'failures': failures,
        'summary': summary
    }


def verify_full_sequence() -> dict:
    """独立验证函数：运行完整 15 周期序列验证
    
    验证 LFSR 的数学特性：
    1. 周期性：状态 15 应在第 15 周期回归
    2. 最大周期：遍历所有 15 个非零状态
    3. 输出序列正确性
    
    Returns:
        验证结果字典
    """
    sequence = get_expected_sequence()
    
    # 提取状态序列
    states = [s['d'] for s in sequence]
    outputs = [s['y'] for s in sequence]
    
    # 验证 1: 周期性 - 状态 15 应在第 15 周期回归
    # 注意：第 15 周期是 sequence[14] 的下一状态
    d_after_15 = lfsr_next_state(states[-1])
    periodic = (d_after_15 == 15)
    
    # 验证 2: 最大周期 - 遍历所有 15 个非零状态
    unique_states = set(states)
    max_period = (len(unique_states) == 15) and (0 not in unique_states)
    
    # 验证 3: 状态转移正确性
    transition_correct = True
    for i in range(len(states) - 1):
        if lfsr_next_state(states[i]) != states[i + 1]:
            transition_correct = False
            break
    
    # 验证 4: 输出正确性
    output_correct = True
    for s in sequence:
        if s['y'] != (s['d'] & 1):
            output_correct = False
            break
    
    all_passed = periodic and max_period and transition_correct and output_correct
    
    return {
        'success': all_passed,
        'periodicity_check': periodic,
        'max_period_check': max_period,
        'transition_check': transition_correct,
        'output_check': output_correct,
        'sequence': sequence,
        'states_visited': states,
        'outputs': outputs,
        'summary': f"Full sequence verification: {'PASSED' if all_passed else 'FAILED'}"
    }


# ============================================================================
# 独立运行验证
# ============================================================================
if __name__ == '__main__':
    print("=" * 60)
    print("4-bit LFSR Golden Model Verification")
    print("Characteristic Polynomial: x^4 + x + 1")
    print("=" * 60)
    
    # 运行完整序列验证
    result = verify_full_sequence()
    
    print(f"\n[Verification Results]")
    print(f"  Periodicity (state 15 returns): {'PASS' if result['periodicity_check'] else 'FAIL'}")
    print(f"  Max Period (15 unique states):  {'PASS' if result['max_period_check'] else 'FAIL'}")
    print(f"  State Transition Correctness:    {'PASS' if result['transition_check'] else 'FAIL'}")
    print(f"  Output Correctness:              {'PASS' if result['output_check'] else 'FAIL'}")
    print(f"\n  Overall: {result['summary']}")
    
    # 打印完整序列
    print(f"\n[Complete 15-Cycle Sequence]")
    print(f"{'Cycle':>6} | {'State (d)':>12} | {'Binary':>8} | {'Output (y)':>10}")
    print("-" * 50)
    for s in result['sequence']:
        print(f"{s['cycle']:>6} | {s['d']:>12} | {s['d']:>08b} | {s['y']:>10}")
    
    # 验证下一周期回归初始状态
    next_state = lfsr_next_state(result['states_visited'][-1])
    print(f"\n[Period Verification]")
    print(f"  State at cycle 14: {result['states_visited'][-1]} (0b{result['states_visited'][-1]:04b})")
    print(f"  Next state:        {next_state} (0b{next_state:04b})")
    print(f"  Expected:          15 (0b1111)")
    print(f"  Period verified:   {'YES' if next_state == 15 else 'NO'}")
