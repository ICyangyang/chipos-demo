#!/usr/bin/env python3
"""Golden Reference Model for UART TX Module - Bit-exact verification model.

All calculations are integer-based. No floating-point approximations.
Follows 16550 UART standard LCR bit mapping.
"""

class UartTxFifoGolden:
    """Golden model for 16x8-bit synchronous FIFO."""

    def __init__(self):
        self.data_fifo = [0] * 16
        self.ip_count = 0  # Write pointer (4-bit)
        self.op_count = 0  # Read pointer (4-bit)
        self.count = 0     # Data count (0-16)

    def push(self, data_in):
        """Attempt to push data. Returns True if successful."""
        if self.count < 16:
            self.data_fifo[self.ip_count] = data_in & 0xFF
            self.ip_count = (self.ip_count + 1) % 16
            self.count += 1
            return True
        return False

    def pop(self):
        """Attempt to pop data. Returns (success, data)."""
        if self.count > 0:
            data = self.data_fifo[self.op_count]
            self.op_count = (self.op_count + 1) % 16
            self.count -= 1
            return True, data
        return False, 0

    def push_pop_simultaneous(self, data_in):
        """Handle simultaneous push and pop."""
        if self.count == 0:
            # Empty: push succeeds, pop rejected
            self.data_fifo[self.ip_count] = data_in & 0xFF
            self.ip_count = (self.ip_count + 1) % 16
            self.count += 1
            return 0  # pop returns invalid data
        elif self.count == 16:
            # Full: pop succeeds, push rejected
            data = self.data_fifo[self.op_count]
            self.op_count = (self.op_count + 1) % 16
            self.count -= 1
            return data
        else:
            # Normal: both succeed, count unchanged
            data = self.data_fifo[self.op_count]
            self.data_fifo[self.ip_count] = data_in & 0xFF
            self.ip_count = (self.ip_count + 1) % 16
            self.op_count = (self.op_count + 1) % 16
            return data

    @property
    def data_out(self):
        """Read-through: current output data."""
        if self.count > 0:
            return self.data_fifo[self.op_count]
        return 0

    @property
    def fifo_empty(self):
        return self.count == 0

    @property
    def fifo_full(self):
        return self.count == 16

    def reset(self):
        self.data_fifo = [0] * 16
        self.ip_count = 0
        self.op_count = 0
        self.count = 0


class UartTxGolden:
    """Golden model for UART TX module with FSM and FIFO."""

    # FSM states
    IDLE = 0
    START = 1
    BIT0 = 2
    BIT1 = 3
    BIT2 = 4
    BIT3 = 5
    BIT4 = 6
    BIT5 = 7
    BIT6 = 8
    BIT7 = 9
    PARITY = 10
    STOP1 = 11
    STOP2 = 12

    def __init__(self):
        self.fifo = UartTxFifoGolden()
        self.tx_state = self.IDLE
        self.bit_counter = 0
        self.stop_counter = 0
        self.tx_buffer = 0
        self.lcr_latched = 0
        self.pop_tx_fifo = 0
        self.busy = 0
        self.txd = 1
        self.cycle_count = 0

    def reset(self):
        """Async reset: all state cleared, TXD=1."""
        self.fifo.reset()
        self.tx_state = self.IDLE
        self.bit_counter = 0
        self.stop_counter = 0
        self.tx_buffer = 0
        self.lcr_latched = 0
        self.pop_tx_fifo = 0
        self.busy = 0
        self.txd = 1
        self.cycle_count = 0

    @property
    def lcr_data_bits(self):
        return self.lcr_latched & 0x03

    @property
    def lcr_stop_bits(self):
        return (self.lcr_latched >> 2) & 0x01

    @property
    def lcr_parity_en(self):
        return (self.lcr_latched >> 3) & 0x01

    @property
    def lcr_parity_type(self):
        return (self.lcr_latched >> 4) & 0x03

    def compute_parity(self):
        """Compute parity bit based on latched LCR[5:4]."""
        if self.lcr_parity_type == 0:  # Odd parity (16550 standard)
            return 1 if (bin(self.tx_buffer).count('1') % 2 == 0) else 0
        elif self.lcr_parity_type == 1:  # Even parity (16550 standard)
            return 1 if (bin(self.tx_buffer).count('1') % 2 == 1) else 0
        elif self.lcr_parity_type == 2:  # Stick parity high
            return 1
        else:  # Stick parity low
            return 0

    def get_data_bit_count(self):
        """Return number of data bits based on LCR[1:0]."""
        return {0: 5, 1: 6, 2: 7, 3: 8}[self.lcr_data_bits]

    def is_half_stop(self):
        """True when 5-bit data + LCR[2]=1 (1.5 stop bits)."""
        return self.lcr_data_bits == 0 and self.lcr_stop_bits == 1

    def tick(self, push=0, pwdata=0, enable=1, lcr=0):
        """Advance one PCLK cycle.

        Args:
            push: tx_fifo_push signal
            pwdata: PWDATA[7:0]
            enable: enable signal
            lcr: LCR[7:0] (only latched at frame start)

        Returns:
            dict with current output signals
        """
        self.cycle_count += 1

        # Handle FIFO push/pop
        if push and self.pop_tx_fifo:
            # Simultaneous push and pop
            self.fifo.push_pop_simultaneous(pwdata)
        elif push:
            self.fifo.push(pwdata)
        elif self.pop_tx_fifo:
            self.fifo.pop()

        # Clear pop signal (one-cycle pulse)
        self.pop_tx_fifo = 0

        if not enable:
            # enable=0: bit_counter stops, TXD holds, state holds
            result = {
                'txd': self.txd,
                'busy': self.busy,
                'tx_fifo_empty': self.fifo.fifo_empty,
                'tx_fifo_full': self.fifo.fifo_full,
                'tx_fifo_count': self.fifo.count,
                'tx_state': self.tx_state,
            }
            return result

        # FSM
        if self.tx_state == self.IDLE:
            self.busy = 0
            self.txd = 1
            if not self.fifo.fifo_empty:
                self.pop_tx_fifo = 1
                self.tx_buffer = self.fifo.data_out
                self.lcr_latched = lcr  # Latch LCR at frame start
                self.busy = 1
                self.tx_state = self.START
                self.bit_counter = 0
                self.stop_counter = 0

        elif self.tx_state == self.START:
            self.txd = 0
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.BIT0
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT0:
            self.txd = (self.tx_buffer >> 0) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.BIT1
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT1:
            self.txd = (self.tx_buffer >> 1) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.BIT2
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT2:
            self.txd = (self.tx_buffer >> 2) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.BIT3
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT3:
            self.txd = (self.tx_buffer >> 3) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.BIT4
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT4:
            self.txd = (self.tx_buffer >> 4) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                if self.lcr_data_bits == 0:  # 5-bit data
                    # Clear unused upper bits for parity calculation
                    self.tx_buffer = self.tx_buffer & 0x1F
                    if self.lcr_parity_en:
                        self.tx_state = self.PARITY
                    else:
                        self.tx_state = self.STOP1
                else:
                    self.tx_state = self.BIT5
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT5:
            self.txd = (self.tx_buffer >> 5) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                if self.lcr_data_bits == 1:  # 6-bit data
                    self.tx_buffer = self.tx_buffer & 0x3F
                    if self.lcr_parity_en:
                        self.tx_state = self.PARITY
                    else:
                        self.tx_state = self.STOP1
                else:
                    self.tx_state = self.BIT6
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT6:
            self.txd = (self.tx_buffer >> 6) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                if self.lcr_data_bits == 2:  # 7-bit data
                    self.tx_buffer = self.tx_buffer & 0x7F
                    if self.lcr_parity_en:
                        self.tx_state = self.PARITY
                    else:
                        self.tx_state = self.STOP1
                else:
                    self.tx_state = self.BIT7
            else:
                self.bit_counter += 1

        elif self.tx_state == self.BIT7:
            self.txd = (self.tx_buffer >> 7) & 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                if self.lcr_parity_en:
                    self.tx_state = self.PARITY
                else:
                    self.tx_state = self.STOP1
            else:
                self.bit_counter += 1

        elif self.tx_state == self.PARITY:
            self.txd = self.compute_parity()
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.STOP1
            else:
                self.bit_counter += 1

        elif self.tx_state == self.STOP1:
            self.txd = 1
            if self.is_half_stop():
                # 1.5 stop bits: need 24 total cycles in stop phase
                # STOP1 handles all 24 cycles using stop_counter
                if self.stop_counter == 23:
                    self.stop_counter = 0
                    self.tx_state = self.IDLE
                    self.busy = 0
                else:
                    self.stop_counter += 1
            else:
                # Normal 1 stop bit (16 cycles)
                if self.bit_counter == 15:
                    self.bit_counter = 0
                    if self.lcr_stop_bits:
                        self.tx_state = self.STOP2
                    else:
                        self.tx_state = self.IDLE
                        self.busy = 0
                else:
                    self.bit_counter += 1

        elif self.tx_state == self.STOP2:
            self.txd = 1
            if self.bit_counter == 15:
                self.bit_counter = 0
                self.tx_state = self.IDLE
                self.busy = 0
            else:
                self.bit_counter += 1

        else:
            # Default: recover to IDLE
            self.tx_state = self.IDLE
            self.bit_counter = 0
            self.txd = 1

        result = {
            'txd': self.txd,
            'busy': self.busy,
            'tx_fifo_empty': self.fifo.fifo_empty,
            'tx_fifo_full': self.fifo.fifo_full,
            'tx_fifo_count': self.fifo.count,
            'tx_state': self.tx_state,
        }
        return result


def run_golden_compare(testcase_results):
    """Compare RTL simulation results with golden model.

    Args:
        testcase_results: dict mapping testcase name to list of dicts,
            each dict containing 'cycle', 'txd', 'busy', 'tx_fifo_empty',
            'tx_fifo_full', 'tx_fifo_count', and optionally 'tx_state'.

    Returns:
        dict mapping testcase name to 'PASS' or 'FAIL' with details.
    """
    results = {}
    for name, cycles in testcase_results.items():
        # Parse testcase config from name or use defaults
        golden = UartTxGolden()
        golden.reset()

        all_match = True
        mismatches = []

        for entry in cycles:
            cycle_num = entry['cycle']
            rtl_txd = entry.get('txd')
            rtl_busy = entry.get('busy')
            rtl_empty = entry.get('tx_fifo_empty')
            rtl_full = entry.get('tx_fifo_full')
            rtl_count = entry.get('tx_fifo_count')

            # Tick golden model
            push = entry.get('push', 0)
            pwdata = entry.get('pwdata', 0)
            enable = entry.get('enable', 1)
            lcr = entry.get('lcr', 0)
            golden.tick(push=push, pwdata=pwdata, enable=enable, lcr=lcr)

            # Compare
            if rtl_txd is not None and rtl_txd != golden.txd:
                all_match = False
                mismatches.append(
                    f"Cycle {cycle_num}: TXD mismatch (RTL={rtl_txd}, Golden={golden.txd})")
            if rtl_busy is not None and rtl_busy != golden.busy:
                all_match = False
                mismatches.append(
                    f"Cycle {cycle_num}: busy mismatch (RTL={rtl_busy}, Golden={golden.busy})")
            if rtl_empty is not None and int(rtl_empty) != int(golden.fifo.fifo_empty):
                all_match = False
                mismatches.append(
                    f"Cycle {cycle_num}: empty mismatch (RTL={rtl_empty}, Golden={golden.fifo.fifo_empty})")
            if rtl_full is not None and int(rtl_full) != int(golden.fifo.fifo_full):
                all_match = False
                mismatches.append(
                    f"Cycle {cycle_num}: full mismatch (RTL={rtl_full}, Golden={golden.fifo.fifo_full})")
            if rtl_count is not None and int(rtl_count) != golden.fifo.count:
                all_match = False
                mismatches.append(
                    f"Cycle {cycle_num}: count mismatch (RTL={rtl_count}, Golden={golden.fifo.count})")

        if all_match:
            results[name] = 'PASS'
        else:
            results[name] = f'FAIL: {"; ".join(mismatches[:5])}'

    return results


def generate_expected_frame(data, lcr_value):
    """Generate expected TXD bit sequence for a complete UART frame.

    Args:
        data: 8-bit data value (will be masked based on LCR data bits)
        lcr_value: 8-bit LCR register value

    Returns:
        list of expected TXD values (one per bit period, LSB first for data)
    """
    data_bits = lcr_value & 0x03
    stop_bits = (lcr_value >> 2) & 0x01
    parity_en = (lcr_value >> 3) & 0x01
    parity_type = (lcr_value >> 4) & 0x03

    num_data_bits = {0: 5, 1: 6, 2: 7, 3: 8}[data_bits]

    # Mask data to configured width
    mask = (1 << num_data_bits) - 1
    masked_data = data & mask

    frame = []

    # Start bit
    frame.append(0)

    # Data bits (LSB first)
    for i in range(num_data_bits):
        frame.append((masked_data >> i) & 1)

    # Parity bit
    if parity_en:
        if parity_type == 0:  # Odd
            ones = bin(masked_data).count('1')
            frame.append(1 if ones % 2 == 0 else 0)
        elif parity_type == 1:  # Even
            ones = bin(masked_data).count('1')
            frame.append(1 if ones % 2 == 1 else 0)
        elif parity_type == 2:  # Stick high
            frame.append(1)
        else:  # Stick low
            frame.append(0)

    # Stop bits
    if stop_bits == 0:
        frame.append(1)  # 1 stop bit
    elif data_bits == 0:  # 5-bit data + 1.5 stop bits
        frame.append(1)  # 1.5 stop bits (represented as 1)
    else:
        frame.append(1)  # First stop bit
        frame.append(1)  # Second stop bit

    return frame