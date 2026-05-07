#!/bin/bash
#===============================================================================
# File: run_rtl_sim.sh
# Purpose: RTL simulation script for mux2to1 using iverilog
# Usage: ./run_rtl_sim.sh
#===============================================================================

set -e

# Directories
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

# Files
TB_FILE="tb_mux2to1.sv"
RTL_FILE="mux2to1.v"
VVP_FILE="rtl_sim.vvp"
VCD_FILE="mux2to1_rtl.vcd"
REPORT_FILE="report_rtl_sim.txt"

echo "============================================================"
echo "  RTL Simulation for mux2to1"
echo "============================================================"

# Step 1: Compile
echo ""
echo "[Step 1] Compiling RTL and Testbench..."
iverilog -g2012 -o "$VVP_FILE" "$TB_FILE" "$RTL_FILE"
if [ $? -eq 0 ]; then
    echo "  ✓ Compilation successful"
else
    echo "  ✗ Compilation failed"
    exit 1
fi

# Step 2: Run simulation
echo ""
echo "[Step 2] Running simulation..."
vvp "$VVP_FILE" | tee "$REPORT_FILE"
SIM_EXIT_CODE=${PIPESTATUS[0]}

# Step 3: Check results
echo ""
echo "[Step 3] Checking results..."
if [ -f "$VCD_FILE" ]; then
    echo "  ✓ Waveform generated: $VCD_FILE"
else
    echo "  ⚠ No waveform file generated"
fi

# Summary
echo ""
echo "============================================================"
echo "  Simulation Complete"
echo "  Report: $REPORT_FILE"
echo "  Waveform: $VCD_FILE"
echo "============================================================"

exit $SIM_EXIT_CODE