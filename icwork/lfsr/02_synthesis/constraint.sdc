# SDC Constraints for LFSR 4-bit Design
# ======================================
# Compatible with OpenROAD

# Create clock with 10ns period (100 MHz)
create_clock [get_ports clk] -name clk -period 10.0

# Set clock uncertainty (setup/hold margin)
set_clock_uncertainty -setup 0.1 [get_clocks clk]
set_clock_uncertainty -hold 0.05 [get_clocks clk]

# Set input delay for reset (exclude clock port)
set_input_delay -clock clk -max 1.0 [get_ports res]
set_input_delay -clock clk -min 0.1 [get_ports res]

# Set output delay
set_output_delay -clock clk -max 1.0 [get_ports y]
set_output_delay -clock clk -min 0.1 [get_ports y]

# Set driving cell for input
set_driving_cell -lib_cell BUF_X1 -pin Z [get_ports res]

# Set load for output
set_load 0.01 [get_ports y]

# Reset is asynchronous, set false path
set_false_path -from [get_ports res]
