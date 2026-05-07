#!/bin/bash
#===============================================================================
# File: run_netlist_sim.sh
# Purpose: Gate-level netlist simulation for mux2to1_gate using iverilog
# Usage: ./run_netlist_sim.sh
#===============================================================================

set -e

# Directories
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Files
TB_FILE="tb_mux2to1_gate.sv"
GATE_FILE="mux2to1_gate.v"
CELL_LIB="MUX2_X1.v"
VVP_FILE="netlist_sim.vvp"
VCD_FILE="mux2to1_gate.vcd"
REPORT_FILE="report_netlist_sim.txt"

echo "============================================================"
echo "  Gate-Level Netlist Simulation for mux2to1_gate"
echo "============================================================"

# Step 1: Check required files
echo ""
echo "[Step 1] Checking required files..."
MISSING=0
for f in "$TB_FILE" "$GATE_FILE" "$CELL_LIB"; do
    if [ -f "$f" ]; then
        echo "  ✓ Found: $f"
    else
        echo "  ✗ Missing: $f"
        MISSING=1
    fi
done

if [ $MISSING -eq 1 ]; then
    echo ""
    echo "Error: Missing required files"
    exit 1
fi

# Step 2: Compile
echo ""
echo "[Step 2] Compiling Gate-Level Netlist and Testbench..."
iverilog -g2012 -o "$VVP_FILE" "$TB_FILE" "$GATE_FILE" "$CELL_LIB"
if [ $? -eq 0 ]; then
    echo "  ✓ Compilation successful"
else
    echo "  ✗ Compilation failed"
    exit 1
fi

# Step 3: Run simulation
echo ""
echo "[Step 3] Running simulation..."
vvp "$VVP_FILE" | tee "$REPORT_FILE"
SIM_EXIT_CODE=${PIPESTATUS[0]}

# Step 4: Check results
echo ""
echo "[Step 4] Checking results..."
if [ -f "$VCD_FILE" ]; then
    echo "  ✓ Waveform generated: $VCD_FILE"
else
    echo "  ⚠ No waveform file generated"
fi

# Summary
echo ""
echo "============================================================"
echo "  Gate-Level Simulation Complete"
echo "  Report: $REPORT_FILE"
echo "  Waveform: $VCD_FILE"
echo "============================================================"

exit $SIM_EXIT_CODE