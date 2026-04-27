###############################################################################
# Created by write_sdc
###############################################################################
current_design mux2to1
###############################################################################
# Timing Constraints
###############################################################################
create_clock -name clk -period 1.1196 
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[0]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[1]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[2]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[3]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[4]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[5]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[6]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in0[7]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[0]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[1]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[2]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[3]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[4]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[5]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[6]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {in1[7]}]
set_input_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {sel}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[0]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[1]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[2]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[3]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[4]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[5]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[6]}]
set_output_delay 0.5000 -clock [get_clocks {clk}] -add_delay [get_ports {out[7]}]
###############################################################################
# Environment
###############################################################################
set_load -pin_load 0.0100 [get_ports {out[7]}]
set_load -pin_load 0.0100 [get_ports {out[6]}]
set_load -pin_load 0.0100 [get_ports {out[5]}]
set_load -pin_load 0.0100 [get_ports {out[4]}]
set_load -pin_load 0.0100 [get_ports {out[3]}]
set_load -pin_load 0.0100 [get_ports {out[2]}]
set_load -pin_load 0.0100 [get_ports {out[1]}]
set_load -pin_load 0.0100 [get_ports {out[0]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {sel}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[7]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[6]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[5]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[4]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[3]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[2]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[1]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in0[0]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[7]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[6]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[5]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[4]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[3]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[2]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[1]}]
set_driving_cell -lib_cell INV_X1 -pin {ZN} -input_transition_rise 0.0000 -input_transition_fall 0.0000 [get_ports {in1[0]}]
###############################################################################
# Design Rules
###############################################################################
