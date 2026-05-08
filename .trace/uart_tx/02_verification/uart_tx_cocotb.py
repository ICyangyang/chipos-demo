"""Cocotb Testbench for UART TX Module.

Uses golden_model.py for bit-exact verification.
All comparisons are exact — no tolerance/容差 allowed.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer, FallingEdge
from cocotb.result import TestFailure, TestSuccess

import sys
import os

# Add tb directory to path for golden model import
sys.path.insert(0, os.path.join(os.path.dirname(__file__)))
from golden_model import UartTxGolden, generate_expected_frame


class UartTxTB:
    """Testbench helper class for UART TX."""

    def __init__(self, dut):
        self.dut = dut
        self.golden = UartTxGolden()
        self.golden.reset()
        self.errors = []

    def start_clock(self, period_ns=10):
        """Start PCLK with given period in ns."""
        self.clock = Clock(self.dut.PCLK, period_ns, units="ns")
        cocotb.fork(self.clock.start())

    async def reset(self):
        """Apply async reset for 5 clock cycles."""
        self.dut.PRESETn <= 0
        for _ in range(5):
            await RisingEdge(self.dut.PCLK)
        self.dut.PRESETn <= 1
        await RisingEdge(self.dut.PCLK)
        self.golden.reset()

    async def tick_and_compare(self, push=0, pwdata=0, enable=1, lcr=0, check=True):
        """Advance one clock cycle and compare with golden model."""
        self.dut.tx_fifo_push <= push
        self.dut.PWDATA <= pwdata
        self.dut.enable <= enable
        self.dut.LCR <= lcr

        await RisingEdge(self.dut.PCLK)

        # Tick golden model
        golden_result = self.golden.tick(push=push, pwdata=pwdata, enable=enable, lcr=lcr)

        if check:
            self._compare_signals(golden_result)

        return golden_result

    def _compare_signals(self, golden_result):
        """Compare RTL signals with golden model (bit-exact)."""
        rtl_txd = int(self.dut.TXD)
        rtl_busy = int(self.dut.busy)
        rtl_empty = int(self.dut.tx_fifo_empty)
        rtl_full = int(self.dut.tx_fifo_full)
        rtl_count = int(self.dut.tx_fifo_count)

        g_txd = golden_result['txd']
        g_busy = golden_result['busy']
        g_empty = golden_result['tx_fifo_empty']
        g_full = golden_result['tx_fifo_full']
        g_count = golden_result['tx_fifo_count']

        if rtl_txd != g_txd:
            self.errors.append(f"TXD mismatch: RTL={rtl_txd}, Golden={g_txd}")
        if rtl_busy != g_busy:
            self.errors.append(f"busy mismatch: RTL={rtl_busy}, Golden={g_busy}")
        if rtl_empty != g_empty:
            self.errors.append(f"tx_fifo_empty mismatch: RTL={rtl_empty}, Golden={g_empty}")
        if rtl_full != g_full:
            self.errors.append(f"tx_fifo_full mismatch: RTL={rtl_full}, Golden={g_full}")
        if rtl_count != g_count:
            self.errors.append(f"tx_fifo_count mismatch: RTL={rtl_count}, Golden={g_count}")

    async def push_data(self, data, lcr=0x03):
        """Push one byte into FIFO."""
        await self.tick_and_compare(push=1, pwdata=data, lcr=lcr)

    async def wait_idle(self, max_cycles=2000):
        """Wait until TX FSM returns to IDLE (busy=0)."""
        for _ in range(max_cycles):
            result = await self.tick_and_compare(push=0, lcr=self.dut.LCR)
            if not result['busy']:
                return True
        return False

    async def send_frame(self, data, lcr, max_cycles=2000):
        """Push data and wait for complete frame transmission."""
        # Push data
        await self.tick_and_compare(push=1, pwdata=data, lcr=lcr)
        # Wait for frame to complete
        for _ in range(max_cycles):
            result = await self.tick_and_compare(push=0, lcr=lcr)
            if not result['busy']:
                return True
        return False

    async def sample_txd_at_midbit(self, num_bits, lcr_value):
        """Sample TXD at the middle of each bit period (8th PCLK cycle).

        Returns list of sampled TXD values.
        """
        samples = []
        for _ in range(num_bits):
            # Wait 7 cycles to reach midbit, then sample
            for i in range(7):
                await self.tick_and_compare(push=0, lcr=lcr_value, check=False)
            # Sample at midbit (8th cycle)
            await RisingEdge(self.dut.PCLK)
            samples.append(int(self.dut.TXD))
            # Wait remaining 8 cycles to complete the bit period
            for i in range(8):
                await self.tick_and_compare(push=0, lcr=lcr_value, check=False)
        return samples

    def check_errors(self):
        """Raise TestFailure if any mismatches were recorded."""
        if self.errors:
            msg = f"{len(self.errors)} mismatches found:\n" + "\n".join(self.errors[:10])
            raise TestFailure(msg)


# =============================================================================
# Test Cases
# =============================================================================

@cocotb.test()
async def test_basic_8n1(dut):
    """Test 1: Basic 8-N-1 transmission (8 data, no parity, 1 stop)."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # LCR = 0x03: 8 data bits, 1 stop, no parity
    lcr = 0x03

    # Send 0x55
    await tb.send_frame(0x55, lcr)
    tb.check_errors()

    # Send 0xAA
    await tb.send_frame(0xAA, lcr)
    tb.check_errors()


@cocotb.test()
async def test_5bit_data(dut):
    """Test 2: 5-bit data width transmission."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # LCR = 0x00: 5 data bits, 1 stop, no parity
    lcr = 0x00

    # Send 0x1F (only bits 0-4 used)
    await tb.send_frame(0x1F, lcr)
    tb.check_errors()

    # Send 0x15
    await tb.send_frame(0x15, lcr)
    tb.check_errors()


@cocotb.test()
async def test_even_parity(dut):
    """Test 3: 8-E-1 transmission (even parity)."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # LCR = 0x1B: 8 data bits, 1 stop, parity enabled, even parity (LCR[5:4]=01)
    lcr = 0x1B

    # Send 0x55 (5 ones -> even parity bit = 1)
    await tb.send_frame(0x55, lcr)
    tb.check_errors()

    # Send 0x01 (1 one -> even parity bit = 0)
    await tb.send_frame(0x01, lcr)
    tb.check_errors()


@cocotb.test()
async def test_odd_parity(dut):
    """Test 4: 8-O-1 transmission (odd parity)."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # LCR = 0x0B: 8 data bits, 1 stop, parity enabled, odd parity (LCR[5:4]=00)
    lcr = 0x0B

    # Send 0x55 (5 ones -> odd parity bit = 0)
    await tb.send_frame(0x55, lcr)
    tb.check_errors()

    # Send 0x01 (1 one -> odd parity bit = 1)
    await tb.send_frame(0x01, lcr)
    tb.check_errors()


@cocotb.test()
async def test_stick_parity(dut):
    """Test 5: Stick parity (fixed high and low)."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # Stick parity high: LCR = 0x2B (LCR[5:4]=10)
    lcr = 0x2B
    await tb.send_frame(0x55, lcr)
    tb.check_errors()

    # Stick parity low: LCR = 0x3B (LCR[5:4]=11)
    lcr = 0x3B
    await tb.send_frame(0x55, lcr)
    tb.check_errors()


@cocotb.test()
async def test_2_stop_bits(dut):
    """Test 6: 8-N-2 transmission (2 stop bits)."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # LCR = 0x07: 8 data bits, 2 stop bits, no parity
    lcr = 0x07

    await tb.send_frame(0x55, lcr)
    tb.check_errors()


@cocotb.test()
async def test_1_5_stop_bits(dut):
    """Test 7: 5-N-1.5 transmission (1.5 stop bits for 5-bit data)."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # LCR = 0x04: 5 data bits, 1.5 stop bits, no parity
    lcr = 0x04

    await tb.send_frame(0x15, lcr)
    tb.check_errors()

    # Verify stop bit duration: 1.5 stop = 24 PCLK cycles
    # After data bits, TXD should be high for exactly 24 cycles
    # This is implicitly verified by golden model comparison


@cocotb.test()
async def test_fifo_operation(dut):
    """Test 8: FIFO operation - push multiple bytes and verify count."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x03  # 8-N-1

    # Push 3 bytes without enabling transmission initially
    for i in range(3):
        await tb.tick_and_compare(push=1, pwdata=0x10 + i, lcr=lcr)

    # Verify FIFO count = 3
    assert int(dut.tx_fifo_count) == 3, f"Expected count=3, got {int(dut.tx_fifo_count)}"

    # Now enable and wait for all 3 frames
    for i in range(3):
        await tb.wait_idle()
        # The first byte should auto-start since FIFO was non-empty
        # Wait for transmission to complete
        for _ in range(200):
            result = await tb.tick_and_compare(push=0, lcr=lcr)
            if not result['busy']:
                break

    tb.check_errors()


@cocotb.test()
async def test_fifo_full(dut):
    """Test 9: FIFO full protection - push 16 bytes then try overflow."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x03

    # Disable transmission to fill FIFO
    # Push 16 bytes
    for i in range(16):
        await tb.tick_and_compare(push=1, pwdata=i, enable=0, lcr=lcr)

    # Verify FIFO is full
    assert int(dut.tx_fifo_full) == 1, "FIFO should be full"
    assert int(dut.tx_fifo_count) == 16, f"Expected count=16, got {int(dut.tx_fifo_count)}"

    # Try to push one more - should be rejected
    await tb.tick_and_compare(push=1, pwdata=0xFF, enable=0, lcr=lcr)
    assert int(dut.tx_fifo_count) == 16, "Count should remain 16 after overflow push"
    assert int(dut.tx_fifo_full) == 1, "FIFO should still be full"

    tb.check_errors()


@cocotb.test()
async def test_fifo_simultaneous_rw(dut):
    """Test 10: FIFO simultaneous push and pop."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x03

    # Push one byte first
    await tb.tick_and_compare(push=1, pwdata=0x42, enable=0, lcr=lcr)
    assert int(dut.tx_fifo_count) == 1

    # Now do simultaneous push and pop (push=1, pop will come from FSM)
    # Enable transmission and push at the same time
    await tb.tick_and_compare(push=1, pwdata=0x43, enable=1, lcr=lcr)

    tb.check_errors()


@cocotb.test()
async def test_enable_pause(dut):
    """Test 11: Enable signal pause during transmission."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x03

    # Push data and start transmission
    await tb.tick_and_compare(push=1, pwdata=0x55, lcr=lcr)

    # Let it run for a few cycles
    for _ in range(5):
        await tb.tick_and_compare(push=0, lcr=lcr)

    # Pause by disabling
    txd_before_pause = int(dut.TXD)
    for _ in range(20):
        await tb.tick_and_compare(push=0, enable=0, lcr=lcr)

    # TXD should remain unchanged during pause
    assert int(dut.TXD) == txd_before_pause, \
        f"TXD changed during pause: before={txd_before_pause}, after={int(dut.TXD)}"

    # Resume
    for _ in range(200):
        result = await tb.tick_and_compare(push=0, enable=1, lcr=lcr)
        if not result['busy']:
            break

    tb.check_errors()


@cocotb.test()
async def test_reset_during_tx(dut):
    """Test 12: Reset during active transmission."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x03

    # Push data and start transmission
    await tb.tick_and_compare(push=1, pwdata=0x55, lcr=lcr)

    # Let it run for a few cycles
    for _ in range(10):
        await tb.tick_and_compare(push=0, lcr=lcr)

    # Apply reset mid-transmission
    await tb.reset()

    # Verify TXD is high (idle state)
    assert int(dut.TXD) == 1, f"TXD should be 1 after reset, got {int(dut.TXD)}"
    assert int(dut.busy) == 0, "busy should be 0 after reset"
    assert int(dut.tx_fifo_empty) == 1, "FIFO should be empty after reset"


@cocotb.test()
async def test_lcr_dynamic_switch(dut):
    """Test 13: LCR dynamic switch between frames."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    # First frame: 8-N-1 (LCR=0x03)
    await tb.send_frame(0x55, 0x03)
    tb.check_errors()

    # Second frame: 8-E-1 (LCR=0x1B) - even parity
    await tb.send_frame(0xAA, 0x1B)
    tb.check_errors()

    # Third frame: 5-N-1 (LCR=0x00)
    await tb.send_frame(0x15, 0x00)
    tb.check_errors()


@cocotb.test()
async def test_txd_bit_sequence_8n1(dut):
    """Verify exact TXD bit sequence for 8-N-1 frame."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x03  # 8-N-1
    data = 0x55  # 01010101 in binary

    # Expected frame: Start(0), D0(1), D1(0), D2(1), D3(0), D4(1), D5(0), D6(1), D7(0), Stop(1)
    expected = generate_expected_frame(data, lcr)

    # Push data
    await tb.tick_and_compare(push=1, pwdata=data, lcr=lcr)

    # Sample TXD at midbit for each bit period
    # Total bits: 1 start + 8 data + 1 stop = 10
    samples = await tb.sample_txd_at_midbit(len(expected), lcr)

    # Compare
    for i, (sample, exp) in enumerate(zip(samples, expected)):
        assert sample == exp, \
            f"Bit {i}: TXD={sample}, expected={exp} (frame bit index {i})"

    # Wait for frame to complete
    await tb.wait_idle()
    tb.check_errors()


@cocotb.test()
async def test_txd_bit_sequence_with_parity(dut):
    """Verify exact TXD bit sequence for 8-E-1 frame."""
    tb = UartTxTB(dut)
    tb.start_clock()
    await tb.reset()

    lcr = 0x1B  # 8-E-1
    data = 0x01  # 00000001

    # Expected: Start(0), D0(1), D1-D7(0), Parity(even=1), Stop(1)
    expected = generate_expected_frame(data, lcr)

    await tb.tick_and_compare(push=1, pwdata=data, lcr=lcr)
    samples = await tb.sample_txd_at_midbit(len(expected), lcr)

    for i, (sample, exp) in enumerate(zip(samples, expected)):
        assert sample == exp, \
            f"Bit {i}: TXD={sample}, expected={exp}"

    await tb.wait_idle()
    tb.check_errors()