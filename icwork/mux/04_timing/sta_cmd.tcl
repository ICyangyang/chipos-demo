read_liberty /opt/OpenROAD-flow-scripts/flow/platforms/nangate45/lib/NangateOpenCellLibrary_typical.lib
read_verilog mux2to1_gate_nangate45.v
link_design mux2to1
read_sdc mux2to1.sdc
report_checks -path_delay min_max -format full
report_tns
report_wns
