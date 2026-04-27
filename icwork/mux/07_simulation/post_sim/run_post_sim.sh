#!/bin/bash
#===============================================================================
# File: run_post_sim.sh
# Purpose: Run post-layout simulation with SDF back-annotation
# Author: ChipOS RTL Team
# Date: 2026-04-27
#===============================================================================

echo "================================================================================"
echo "                    Post-Layout Simulation with SDF Back-Annotation"
echo "================================================================================"
echo ""
echo "Design: mux2to1_gate (gate-level netlist)"
echo "SDF:    mux2to1_gate.sdf (timing back-annotation)"
echo "TB:     tb_mux2to1_post.sv"
echo ""

# Clean up previous simulation files
rm -f post_sim.vvp mux2to1_post.vcd report_post_sim.txt sdfAnnotateInfo.log

#-------------------------------------------------------------------------------
# Step 1: Compile gate-level netlist and testbench
#-------------------------------------------------------------------------------
echo "================================================================================"
echo "  Step 1: Compiling gate-level design with testbench"
echo "================================================================================"

iverilog -g2012 \
    -o post_sim.vvp \
    -Wall \
    tb_mux2to1_post.sv \
    mux2to1_gate.v \
    MUX2_X1.v

if [ $? -ne 0 ]; then
    echo ""
    echo "[ERROR] Compilation failed!"
    exit 1
fi

echo "[OK] Compilation successful"
echo ""

#-------------------------------------------------------------------------------
# Step 2: Run simulation with SDF back-annotation
#-------------------------------------------------------------------------------
echo "================================================================================"
echo "  Step 2: Running post-layout simulation"
echo "================================================================================"

vvp post_sim.vvp 2>&1 | tee report_post_sim.txt

if [ $? -ne 0 ]; then
    echo ""
    echo "[ERROR] Simulation failed!"
    exit 1
fi

echo ""

#-------------------------------------------------------------------------------
# Step 3: Display SDF Annotation Report
#-------------------------------------------------------------------------------
echo "================================================================================"
echo "  Step 3: SDF Annotation Report"
echo "================================================================================"

if [ -f sdfAnnotateInfo.log ]; then
    echo ""
    cat sdfAnnotateInfo.log
    echo ""
else
    echo "[WARNING] sdfAnnotateInfo.log not found"
    echo "          SDF annotation may not have been performed"
    echo ""
fi

#-------------------------------------------------------------------------------
# Step 4: Extract annotation statistics
#-------------------------------------------------------------------------------
echo "================================================================================"
echo "  Step 4: Annotation Statistics"
echo "================================================================================"

# Count IOPATH entries in SDF (cell delays)
IOPATH_COUNT=$(grep -c "IOPATH" mux2to1_gate.sdf 2>/dev/null || echo "0")

# Count INTERCONNECT entries in SDF (wire delays)
INTERCONNECT_COUNT=$(grep -c "INTERCONNECT" mux2to1_gate.sdf 2>/dev/null || echo "0")

# Total delay entries
TOTAL_DELAYS=$((IOPATH_COUNT + INTERCONNECT_COUNT))

echo ""
echo "SDF File Analysis:"
echo "  IOPATH entries (cell delays):     $IOPATH_COUNT"
echo "  INTERCONNECT entries (wire delays): $INTERCONNECT_COUNT"
echo "  Total delay entries:              $TOTAL_DELAYS"
echo ""

#-------------------------------------------------------------------------------
# Step 5: Simulation Summary
#-------------------------------------------------------------------------------
echo "================================================================================"
echo "  Simulation Summary"
echo "================================================================================"

# Check if all tests passed
if grep -q "ALL POST-LAYOUT TESTS PASSED" report_post_sim.txt; then
    echo ""
    echo ">>> SIMULATION RESULT: PASS <<<"
    echo ""
    echo "Files generated:"
    echo "  - mux2to1_post.vcd     (waveform file)"
    echo "  - report_post_sim.txt  (simulation report)"
    echo "  - sdfAnnotateInfo.log  (SDF annotation report)"
    echo ""
    exit 0
elif grep -q "FUNCTIONAL PASS, BUT TIMING VIOLATIONS" report_post_sim.txt; then
    echo ""
    echo ">>> SIMULATION RESULT: PASS (with timing warnings) <<<"
    echo ""
    exit 0
else
    echo ""
    echo ">>> SIMULATION RESULT: FAIL <<<"
    echo ""
    echo "Check report_post_sim.txt for details"
    echo ""
    exit 1
fi
