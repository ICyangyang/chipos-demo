###############################################################################
# Created by write_sdc
###############################################################################
current_design lfsr_4bit
###############################################################################
# Timing Constraints
###############################################################################
create_clock -name clk -period 1.2137 [get_ports {clk}]
set_clock_uncertainty -setup 0.1000 clk
set_clock_uncertainty -hold 0.0500 clk
set_input_delay 0.1000 -clock [get_clocks {clk}] -min -add_delay [get_ports {res}]
set_input_delay 1.0000 -clock [get_clocks {clk}] -max -add_delay [get_ports {res}]
set_output_delay 0.1000 -clock [get_clocks {clk}] -min -add_delay [get_ports {y}]
set_output_delay 1.0000 -clock [get_clocks {clk}] -max -add_delay [get_ports {y}]
set_false_path\
    -from [get_ports {res}]
###############################################################################
# Environment
###############################################################################
set_load -pin_load 0.0100 [get_ports {y}]
set_driving_cell -lib_cell BUF_X1 -pin {Z} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {res}]
###############################################################################
# Design Rules
###############################################################################
