# UART TX Module Design Context

## Module Overview
- **Module Name**: `uart_tx`
- **Description**: UART Transmitter with integrated 16x8-bit FIFO, configurable frame format via LCR, standard UART protocol compliance
- **Clock Domain**: PCLK (single synchronous domain)
- **Reset**: PRESETn (active-low asynchronous)

## Interface Ports

| Signal | Width | Direction | Type | Description |
|--------|-------|-----------|------|-------------|
| PCLK | 1 | input | clock | System main clock, rising edge triggered |
| PRESETn | 1 | input | reset | Active-low asynchronous reset |
| PWDATA | 8 | input | data | Parallel input data, written to FIFO on push |
| tx_fifo_push | 1 | input | control | FIFO write enable, active high, one cycle |
| LCR | 8 | input | config | Line Control Register for frame format |
| enable | 1 | input | control | TX process enable, pauses bit_counter when low |
| tx_fifo_empty | 1 | output | status | FIFO empty flag |
| tx_fifo_full | 1 | output | status | FIFO full flag |
| tx_fifo_count | 5 | output | status | FIFO data count (0-16) |
| busy | 1 | output | status | TX busy flag (START to last STOP) |
| TXD | 1 | output | data | Serial output, idle=high |

## Sub-Module: uart_tx_fifo

- **Type**: 16x8-bit synchronous FIFO
- **Storage**: `logic[7:0] data_fifo[15:0]`
- **Pointers**: ip_count (4-bit write), op_count (4-bit read), count (5-bit data counter)
- **Read-Through**: data_out = data_fifo[op_count] (combinational)
- **Concurrent RW**: Supported via case({push,pop}) — all 4 scenarios handled
- **Empty**: `~(|count)`, **Full**: `count == 5'b10000`

## TX Control FSM

### States
IDLE → START → BIT0..BIT7 → PARITY → STOP1 → STOP2 → IDLE

### Key Registers
- `tx_state`: FSM state enum
- `bit_counter` (4-bit): Bit period counter, 0-15 (16 PCLK cycles per bit)
- `tx_buffer` (8-bit): Latched data byte from FIFO

### State Transitions
- **IDLE**: When FIFO non-empty & enable=1 → pop FIFO, latch data, set busy, go START
- **START**: TXD=0, count 16 cycles → go BIT0
- **BIT0-BIT7**: Send LSB first, skip unused bits per LCR[1:0], zero unused high bits before parity
- **PARITY**: If LCR[3]=1 → send parity per LCR[5:4] → go STOP1
- **STOP1**: TXD=1, mandatory stop bit. If LCR[2]=0 → go IDLE, else → go STOP2
- **STOP2**: TXD=1, extra stop bit → go IDLE

## LCR Configuration

| Bits | Field | Values |
|------|-------|--------|
| [1:0] | Data width | 00=5bit, 01=6bit, 10=7bit, 11=8bit |
| [2] | Stop bits | 0=1 stop, 1=1.5/2 stop |
| [3] | Parity enable | 0=disabled, 1=enabled |
| [5:4] | Parity type | 00=even, 01=odd, 10=stick-1, 11=stick-0 (when [3]=1) |

## Functional Points

| FP-ID | Name | Description |
|-------|------|-------------|
| FP-001 | FIFO write | Write PWDATA to FIFO when push=1 & not full |
| FP-002 | FIFO read | Pop data from FIFO on FSM request, read-through |
| FP-003 | FIFO concurrent RW | Simultaneous push+pop: count unchanged |
| FP-004 | FIFO status | Output empty/full/count correctly |
| FP-005 | IDLE to START | Detect FIFO non-empty + enable, pop & latch |
| FP-006 | START bit | TXD=0 for 16 PCLK cycles |
| FP-007 | Data bits LSB | Send LSB first, 5-8 bits per LCR[1:0] |
| FP-008 | Unused bits zero | Zero tx_buffer high bits before parity calc |
| FP-009 | Parity bit | Send parity per LCR[5:4] when LCR[3]=1 |
| FP-010 | Stop bits | Send 1 or 1.5/2 stop bits per LCR[2] |
| FP-011 | Enable pause | Pause bit_counter when enable=0 |
| FP-012 | Async reset | Reset all states, TXD→high |
| FP-013 | Busy flag | busy=1 from START to last STOP |
| FP-014 | TXD idle high | TXD=1 when idle or in stop bits |

## Constraints
- FIFO depth: 16, width: 8
- Bit period: 16 PCLK cycles (fixed oversampling)
- Baud rate: PCLK/16
- Data width range: 5-8 bits