#========================================
# mux2to1 Design Configuration
#========================================

# Design name
export DESIGN_NAME = mux2to1

# Verilog files
export VERILOG_FILES = $(sort $(wildcard ./designs/src/$(DESIGN_NAME)/*.v))

# Clock configuration (virtual clock for combinational logic)
export CLOCK_PORT = clk
export CLOCK_PERIOD = 10.0

# Area configuration (aggressive optimization)
export CORE_UTILIZATION = 95
export CORE_ASPECT_RATIO = 1.0
export CORE_MARGIN = 0.5

# Placement configuration (aggressive density)
export PLACE_DENSITY = 0.95

# Skip CTS for combinational logic
export SKIP_CTS = 1

# SDC constraints
export SDC_FILE = ./designs/$(PLATFORM)/$(DESIGN_NAME)/constraint.sdc
