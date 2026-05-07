# UART TX Micro-Architecture

**Version**: v1.0
**Date**: 2026-05-07
**Author**: ChipOS RTL Team

---

## Module: Uart_tx

### 1. Module Hierarchy & Decomposition
**Decision**: Two-level hierarchy — FIFO as independent sub-module, FSM embedded in top-level.

| Module | Role | Instantiation |
|--------|------|---------------|
| Uart_tx | Top-level wrapper; contains TX_Control_FSM, baud counter, shift logic, LCR latch | — |
| Uart_tx_fifo | Synchronous FIFO, 16-deep × 8-wide | Instantiated inside Uart_tx |

**Rationale**:
- FIFO has well-defined push/pop interface and is a reusable building block (P-02 pattern). Separating it enables independent verification and potential reuse.
- TX_Control_FSM is tightly coupled with baud counter, bit counter, and TXD output. Extracting it as a separate module would create excessive wiring (state → mux select, counter reload, etc.) with no reuse benefit. Embedding FSM in top-level keeps the data path compact and avoids unnecessary port explosion.
- Estimated gate count < 2000 GE, well below the 5000 GE decomposition threshold.

### 2. FSM Design
**Encoding**: Binary (sequential localparam). 14 states total — binary needs only 4 bits vs 14 bits for one-hot. Given the UART TX operates at baud rate (slow relative to PCLK), speed is not a bottleneck; area savings from binary encoding are preferred.

**State List** (localparam):
```
TX_IDLE   = 4'd0
TX_START  = 4'd1
TX_BIT0   = 4'd2
TX_BIT1   = 4'd3
TX_BIT2   = 4'd4
TX_BIT3   = 4'd5
TX_BIT4   = 4'd6
TX_BIT5   = 4'd7
TX_BIT6   = 4'd8
TX_BIT7   = 4'd9
TX_PARITY = 4'd10
TX_STOP1  = 4'd11
TX_STOP2  = 4'd12
TX_HALF   = 4'd13   // for 1.5 stop bit (5-bit data only)
```

**FSM Transition Table**:

| Current State | Condition | Next State | Output |
|---------------|-----------|------------|--------|
| TX_IDLE | !enable | TX_IDLE | TXD=1, busy=0 |
| TX_IDLE | enable && !tx_fifo_empty | TX_START | TXD=1, busy=1, pop FIFO, latch LCR |
| TX_IDLE | enable && tx_fifo_empty | TX_IDLE | TXD=1, busy=0 |
| TX_START | bit_cnt == 15 | TX_BIT0 | TXD=0, load tx_buffer from FIFO pop data |
| TX_START | bit_cnt < 15 && enable | TX_START | TXD=0 |
| TX_START | !enable (pause) | TX_START | TXD=0, bit_cnt frozen |
| TX_BIT0 | bit_cnt == 15 | TX_BIT1 (or TX_PARITY if data_bits==1) | TXD=tx_buffer[0] |
| TX_BIT0 | bit_cnt < 15 && enable | TX_BIT0 | TXD=tx_buffer[0] |
| TX_BIT0 | !enable | TX_BIT0 | TXD=tx_buffer[0], bit_cnt frozen |
| TX_BIT1..TX_BIT4 | (same pattern as TX_BIT0, advancing to next bit or skipping if data_bits limit reached) | — | TXD=tx_buffer[bit_index] |
| TX_BIT5 | bit_cnt==15, data_bits>=6 | TX_BIT6 | TXD=tx_buffer[5] |
| TX_BIT5 | bit_cnt==15, data_bits==5, parity_en | TX_PARITY | TXD=tx_buffer[4] |
| TX_BIT5 | bit_cnt==15, data_bits==5, !parity_en, stop_bits==1 | TX_STOP1 | TXD=tx_buffer[4] |
| TX_BIT5 | bit_cnt==15, data_bits==5, !parity_en, stop_bits==2 | TX_STOP1 | TXD=tx_buffer[4] |
| TX_BIT6 | bit_cnt==15, data_bits>=7 | TX_BIT7 | TXD=tx_buffer[6] |
| TX_BIT6 | bit_cnt==15, data_bits==6, parity_en | TX_PARITY | TXD=tx_buffer[5] |
| TX_BIT6 | bit_cnt==15, data_bits==6, !parity_en | TX_STOP1 | TXD=tx_buffer[5] |
| TX_BIT7 | bit_cnt==15, parity_en | TX_PARITY | TXD=tx_buffer[7] |
| TX_BIT7 | bit_cnt==15, !parity_en | TX_STOP1 | TXD=tx_buffer[7] |
| TX_PARITY | bit_cnt==15 | TX_STOP1 | TXD=parity_bit |
| TX_STOP1 | bit_cnt==15, stop_bits==1 | TX_IDLE | TXD=1, busy=0 |
| TX_STOP1 | bit_cnt==15, stop_bits==2 | TX_STOP2 | TXD=1 |
| TX_STOP1 | bit_cnt==15, stop_bits==1.5 (data_bits==5) | TX_HALF | TXD=1 |
| TX_STOP2 | bit_cnt==15 | TX_IDLE | TXD=1, busy=0 |
| TX_HALF | bit_cnt==7 (half period = 8 PCLK, done at cnt==7) | TX_IDLE | TXD=1, busy=0 |

**FSM Style**: Three-segment Mealy (next_state logic, state register, output logic). Output logic uses registered TXD to avoid glitch on serial line.

**Note on data_bits skip**: When data_bits < 8, the FSM skips unused BIT states. For example, data_bits=5 transitions: BIT0→BIT1→BIT2→BIT3→BIT4→(PARITY or STOP1). The skip logic is implemented by comparing `bit_index` with `lcr_latch[1:0]` (data_bits encoding) at each bit_cnt==15 transition.

### 3. Data Path
**Key Data Path Components**:

1. **tx_buffer** (8-bit register): Holds the current byte being transmitted. Loaded from FIFO pop at TX_START→TX_BIT0 transition. For sub-8-bit data, upper bits are zeroed at load time (LSB-aligned, per A5).

2. **bit_cnt** (4-bit counter, 0–15): Counts PCLK cycles per bit period. Reloads to 0 at each state transition (bit_cnt==15 triggers advance). Runs at 16 PCLK/bit (fixed baud divisor). Frozen when enable=0 (A4).

3. **bit_index** (3-bit internal): Tracks which data bit is being sent (0–7). Incremented as FSM advances through BIT states. Compared against data_bits to determine skip to PARITY/STOP.

4. **parity_bit** (1-bit registered): Computed at frame start (when LCR is latched) as XOR of selected data bits per parity type. Stored in register to avoid combinational path during PARITY state.

5. **lcr_latch** (8-bit register): Latched from LCR at frame start (TX_IDLE→TX_START transition). Provides stable configuration for entire frame:
   - lcr_latch[1:0] = data_bits (5/6/7/8)
   - lcr_latch[2]   = parity_enable
   - lcr_latch[3]   = parity_type (0=even, 1=odd)
   - lcr_latch[5:4] = stop_bits (0=1, 1=1.5/2)
   - lcr_latch[7:6] = Reserved (A1)

6. **TXD output register** (1-bit): Registered output to prevent combinational glitches on the serial line. Value determined by FSM state and tx_buffer/bit_index/parity_bit.

7. **FIFO pop data path**: Read-through (combinational). When FSM transitions from TX_IDLE to TX_START, `tx_fifo_pop` is asserted for one cycle. The popped data is captured into tx_buffer at the next clock edge (TX_START→TX_BIT0 transition). This avoids needing a separate "pop and hold" cycle.

**MUX Structure**:
- TXD MUX: Selects between 1 (IDLE/STOP), 0 (START), tx_buffer[bit_index] (BIT states), parity_bit (PARITY state). Controlled by FSM state.
- bit_cnt reload MUX: 0 on state transition, hold on pause, increment on normal operation.
- Next-state skip MUX: At each BIT state completion, selects next state based on {bit_index, lcr_latch[1:0], lcr_latch[2], lcr_latch[5:4]}.

### 4. Interface Protocol & Bit-Widths
**Top-Level Interface**:

| Port | Width | Direction | Protocol |
|------|-------|-----------|----------|
| PCLK | 1 | input | System clock |
| PRESETn | 1 | input | Async active-low reset |
| PWDATA | 8 | input | Parallel data, valid when tx_fifo_push=1 |
| tx_fifo_push | 1 | input | Write enable, level-sensitive |
| LCR | 8 | input | Configuration register, sampled at frame start |
| enable | 1 | input | Transmit enable, level-sensitive |
| tx_fifo_empty | 1 | output | FIFO status flag |
| tx_fifo_full | 1 | output | FIFO status flag |
| tx_fifo_count | 5 | output | FIFO occupancy (0–16) |
| busy | 1 | output | Transmit active flag |
| TXD | 1 | output | Registered serial output |

**FIFO Sub-Module Interface** (Uart_tx_fifo):

| Port | Width | Direction | Protocol |
|------|-------|-----------|----------|
| clk | 1 | input | PCLK |
| rst_n | 1 | input | PRESETn |
| wr_data | 8 | input | PWDATA |
| wr_en | 1 | input | tx_fifo_push |
| rd_en | 1 | input | tx_fifo_pop (from FSM) |
| rd_data | 8 | output | Read-through combinational (A7) |
| full | 1 | output | tx_fifo_full |
| empty | 1 | output | tx_fifo_empty |
| count | 5 | output | tx_fifo_count |

**Bit-Width Rationale**:

| Signal | Width | Rationale |
|--------|-------|-----------|
| PWDATA / wr_data / rd_data / tx_buffer | 8 | Spec: 8-bit parallel data |
| bit_cnt | 4 | Range 0–15 (16 PCLK per bit) |
| bit_index | 3 | Range 0–7 (max 8 data bits) |
| tx_state | 4 | 14 states, binary encoding needs 4 bits |
| lcr_latch | 8 | Matches LCR input width |
| tx_fifo_count | 5 | FIFO depth=16, range 0–16 (need 5 bits) |
| FIFO addr (wr_ptr/rd_ptr) | 5 | Extra bit for full/empty detection (P-02 pattern), lower 4 bits index 16 entries |

**Push Protocol**: Level-sensitive. When tx_fifo_push=1 and !full, data is written. When full, push is silently ignored (A6). No valid/ready handshake — simple enable-based protocol matching typical APB-style register interface.

**Pop Protocol**: FSM asserts tx_fifo_pop for one cycle at frame start. rd_data is available combinationally (read-through, A7) and captured into tx_buffer at the next clock edge.

### 5. Clock Domains & Reset Strategy
**Clock Domains**: Single clock domain — PCLK. All logic (FSM, FIFO, counters, TXD output) operates on PCLK. No CDC required.

**Reset Strategy**: Asynchronous active-low reset (PRESETn), synchronous release.

- All registers reset to defined initial values:
  - tx_state → TX_IDLE
  - bit_cnt → 0
  - bit_index → 0
  - tx_buffer → 0
  - lcr_latch → 0 (default: 8N1 configuration)
  - TXD → 1 (idle line level)
  - FIFO pointers → 0 (empty state)
  - parity_bit → 0

- Reset assertion: Asynchronous (immediate effect on all registers, no clock required).
- Reset deassertion: Synchronous (PRESETn must be stable before next PCLK rising edge to avoid metastability). This is standard practice for async-reset synchronous-release design.

**No CDC considerations**: UART TX is entirely within the PCLK domain. The TXD output is a registered signal within this domain. If the receiving UART RX operates in a different clock domain, that is the RX module's responsibility — TX only needs to produce a stable serial stream at the correct baud rate.

### 6. Timing Path Analysis & Trade-offs
**Critical Timing Path**: The longest combinational path is the FSM next-state logic at bit_cnt==15 transitions, which involves:
- bit_cnt comparator (4-bit == 15)
- enable check
- lcr_latch decoding (data_bits, parity_en, stop_bits)
- bit_index comparison with data_bits
- MUX select for next state

**Estimated worst-case path**: ~4-5 gate levels (comparator + decode + MUX). At typical PCLK frequencies (50–100 MHz for APB subsystems), this is easily met. UART TX operates at baud rate (max ~115200 bps = ~1.8432 MHz PCLK at 16x oversampling), so timing is not a concern.

**Trade-off Analysis**:

| Decision | Option A | Option B | Choice | Rationale |
|----------|----------|----------|--------|-----------|
| FSM encoding | One-hot (14-bit) | Binary (4-bit) | Binary | Area savings (10 fewer FFs). Speed not critical — baud rate is orders of magnitude slower than PCLK. |
| FIFO implementation | Inline registers | Separate sub-module | Separate | Reusability, cleaner interface, independent verification. Small area overhead for module boundary wiring is acceptable. |
| TXD output | Combinational | Registered | Registered | Prevents glitches on serial line. Critical for UART protocol correctness — receiver samples at mid-bit, any glitch could cause false start-bit detection. |
| parity_bit | Compute on-the-fly | Pre-compute at frame start | Pre-compute | Reduces combinational path during PARITY state. parity_bit is stable for entire frame, no need to recompute each cycle. |
| FIFO pop | Read-after-pop (1 cycle latency) | Read-through (0 cycle latency) | Read-through (A7) | Saves one PCLK cycle per frame. At 16 PCLK/bit, one cycle is negligible, but read-through simplifies the FSM (no extra POP_WAIT state). |
| enable pause | Freeze bit_cnt immediately | Complete current bit then pause | Freeze immediately (A4) | Simpler implementation. bit_cnt freezes, FSM stays in current state. When enable resumes, bit_cnt continues from where it stopped. No risk of partial bit transmission. |

**Area Estimate**: ~500–800 GE (FIFO: ~256 GE for 16×8 memory + pointer logic; FSM + data path: ~300–400 GE; TXD output + misc: ~50 GE). Well within typical UART peripheral budget.

### 7. Data Bit-Width Handling Strategy
**LCR Data Bits Encoding** (lcr_latch[1:0]):
- 00 → 5 data bits
- 01 → 6 data bits
- 10 → 7 data bits
- 11 → 8 data bits

**Sub-8-bit Data Mapping (A5)**: LSB-aligned, upper bits zeroed.

When data_bits < 8, the popped FIFO byte is masked at load time:
```
tx_buffer <= rd_data & data_mask;
```
Where data_mask is computed from lcr_latch[1:0]:
- data_bits=5: mask = 8'h1F (bits [4:0] valid, [7:5] = 0)
- data_bits=6: mask = 8'h3F (bits [5:0] valid, [7:6] = 0)
- data_bits=7: mask = 8'h7F (bits [6:0] valid, [7] = 0)
- data_bits=8: mask = 8'hFF (all bits valid)

**FSM Bit Skip Logic**: The FSM uses `bit_index` (0–7) to track which bit is being transmitted. At each bit_cnt==15 transition, the FSM checks:
```
if (bit_index < data_bits - 1) → advance to next BIT state (bit_index++)
else if (parity_enable) → advance to TX_PARITY
else → advance to TX_STOP1
```
This allows the FSM to skip unused BIT states cleanly. For data_bits=5, only BIT0–BIT4 are visited; BIT5–BIT7 are never entered.

**bit_index increment**: Incremented at each bit_cnt==15 transition within BIT states. Reset to 0 at TX_START→TX_BIT0 transition. Not incremented in START, PARITY, or STOP states.

### 8. Stop Bit Handling Strategy
**LCR Stop Bits Encoding** (lcr_latch[5:4]):
- 00 → 1 stop bit
- 01 → 1.5 stop bits (only valid when data_bits=5)
- 10 → 2 stop bits
- 11 → Reserved (treated as 2 stop bits for safety)

**1.5 Stop Bit Implementation (A2)**:

The 1.5 stop bit case requires transmitting a stop level (TXD=1) for half a bit period (8 PCLK cycles). This is handled by the dedicated TX_HALF state:

- **TX_HALF state**: Entered from TX_STOP1 when stop_bits==1.5 and data_bits==5.
- **bit_cnt behavior**: Reloads to 0 upon entering TX_HALF. The half-period completes when bit_cnt reaches 7 (8 PCLK cycles: 0→7 inclusive).
- **Transition**: TX_HALF → TX_IDLE when bit_cnt==7.

**Why a separate state instead of modifying bit_cnt reload value in TX_STOP1**:
- Using a separate TX_HALF state keeps the FSM logic clean and avoids conditional bit_cnt terminal count (15 vs 7) within the same state.
- The alternative (conditional terminal count in TX_STOP1) would require a comparator that switches between 15 and 7 based on stop_bits, adding combinational complexity and making the FSM harder to verify.
- One extra state costs only 1 additional FF bit in binary encoding (4 bits still sufficient for 14 states).

**2 Stop Bit Implementation**:
- TX_STOP1 runs for full 16 PCLK cycles (bit_cnt 0→15), then transitions to TX_STOP2.
- TX_STOP2 runs for another full 16 PCLK cycles, then transitions to TX_IDLE.
- Both states output TXD=1.

**1 Stop Bit Implementation**:
- TX_STOP1 runs for full 16 PCLK cycles, then transitions directly to TX_IDLE.

**Stop bit selection logic at TX_STOP1 exit**:
```
if (stop_bits == 1)       → TX_IDLE
else if (stop_bits == 1.5 && data_bits == 5) → TX_HALF
else                       → TX_STOP2  // covers stop_bits == 2 and reserved 11
```

### 9. Parity Calculation Strategy
**LCR Parity Encoding** (lcr_latch[3:2]):
- lcr_latch[2] = parity_enable (0=none, 1=enabled)
- lcr_latch[3] = parity_type (0=even, 1=odd) — only meaningful when parity_enable=1

**Parity Bit Computation**: Pre-computed at frame start and stored in `parity_bit` register.

Computation occurs when LCR is latched (TX_IDLE→TX_START transition), using the masked tx_buffer value:

```
// Even parity: XOR of all valid data bits
parity_xor = ^tx_buffer[data_bits-1:0];  // reduction XOR over valid bits only

// Even parity: parity_bit = parity_xor (makes total bit count even)
// Odd parity:  parity_bit = ~parity_xor (makes total bit count odd)
parity_bit = parity_enable ? (parity_type ? ~parity_xor : parity_xor) : 0;
```

**Implementation detail**: Since data_bits varies (5/6/7/8), the reduction XOR must cover only the valid bits. This is achieved by:
- For data_bits=8: `^tx_buffer` (full 8-bit XOR)
- For data_bits=7: `^tx_buffer[6:0]`
- For data_bits=6: `^tx_buffer[5:0]`
- For data_bits=5: `^tx_buffer[4:0]`

In RTL, this can be implemented as a MUX-selectable reduction XOR:
```
wire [7:0] masked = tx_buffer & data_mask;
wire parity_xor = ^masked;  // upper zero bits don't affect XOR result
```
Since masked upper bits are always 0, `^masked` equals `^masked[data_bits-1:0]`. This simplifies the implementation — no need for a variable-width XOR, just mask and reduce.

**When parity_enable=0**: The FSM skips TX_PARITY state entirely. parity_bit register is set to 0 (don't-care, never used).

**Parity bit transmission**: In TX_PARITY state, TXD output = parity_bit. The state runs for 16 PCLK cycles (bit_cnt 0→15), then transitions to TX_STOP1.

### 10. Spec Ambiguity Resolution Summary
| ID | Ambiguity | Resolution | Architecture Impact |
|----|-----------|------------|---------------------|
| A1 | LCR[7:6] undefined | Reserved, ignored by TX logic. No functional effect. | lcr_latch[7:6] stored but unused. |
| A2 | 1.5 vs 2 stop bit distinction | 5-bit data → 1.5 stop (TX_HALF state, 8 PCLK); ≥6-bit data → 2 stop (TX_STOP2 state, 16 PCLK). | Added TX_HALF state to FSM. bit_cnt terminal count = 7 for TX_HALF vs 15 for all other states. |
| A3 | LCR dynamic switching during frame | LCR latched at frame start (TX_IDLE→TX_START). Entire frame uses lcr_latch values. | Added lcr_latch register. LCR input is only sampled once per frame. |
| A4 | enable pause granularity | bit_cnt freezes immediately when enable=0. FSM stays in current state. When enable resumes, bit_cnt continues. | enable gates bit_cnt increment logic. No extra pause state needed. |
| A5 | Sub-8-bit data bit mapping | LSB-aligned, upper bits zeroed via data_mask at tx_buffer load. | data_mask MUX at FIFO pop → tx_buffer path. |
| A6 | FIFO full push behavior | Silently ignored, no error flag, no overwrite. | FIFO wr_en gated by !full. No overflow error output. |
| A7 | FIFO pop timing | Read-through (combinational rd_data). Data available same cycle as pop assertion. Captured into tx_buffer at next clock edge. | No POP_WAIT state. rd_data combinational output from FIFO memory array. |