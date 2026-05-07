#========================================
# SDC Constraints for mux2to1 (Combinational Logic)
#========================================

# Virtual clock for IO timing constraints
create_clock -name clk -period 10.0

# Set input/output delay relative to virtual clock
set_input_delay -clock clk 0.5 [all_inputs]
set_output_delay -clock clk 0.5 [all_outputs]

# Set load on outputs
set_load 0.01 [all_outputs]

# Set driving cell for inputs
set_driving_cell -lib_cell INV_X1 -pin Z [all_inputs]