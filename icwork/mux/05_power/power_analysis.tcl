# Power Analysis Script for mux2to1 (Nangate45)
# Using OpenSTA for power estimation

# 1. Read Liberty library with power information
read_liberty /app/backend/mcp_server/tools/platforms/nangate45/lib/NangateOpenCellLibrary_typical.lib

# 2. Read gate-level netlist
read_verilog mux2to1_gate_nangate45.v

# 3. Link design
link_design mux2to1

# 4. Read timing constraints
read_sdc mux2to1.sdc

# 5. Set switching activity for inputs (toggle rate = 0.5 transitions per clock cycle)
set_switching_activity -toggle_rate 0.5 -static_probability 0.5 [all_inputs]

# 6. Report power summary
puts "========== Power Analysis Summary =========="
report_power

# 7. Exit
exit
