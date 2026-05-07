# LFSR 4-bit Design Configuration for ORFS
# ===========================================

# Design name
export DESIGN_NAME = lfsr_4bit

# Verilog source files
export VERILOG_FILES = $(DESIGN_HOME)/src/$(DESIGN_NAME)/$(DESIGN_NAME).v

# Clock configuration
export CLOCK_PORT = clk
export CLOCK_PERIOD = 10.0
export CLOCK_NET = $(CLOCK_PORT)

# Reset configuration (active-low asynchronous reset)
export RESET_PORT = res

# Floorplan configuration
export CORE_UTILIZATION = 70
export CORE_ASPECT_RATIO = 1.0
export CORE_MARGIN = 2.0

# Placement configuration
export PLACE_DENSITY = 0.70

# CTS configuration
export CTS_BUF_CELL = BUF_X1
export CTS_NUM_SOLS = 4

# Target density for global routing
export TARGET_DENSITY = 0.75

# Additional options
export REMOVE_CELLS_FOR_EQUIVALENCE_CHECK = 
export REMOVE_CELLS_FOR_TIMING = 

# SDC constraints file
export SDC_FILE = $(DESIGN_HOME)/$(PLATFORM)/$(DESIGN_NAME)/constraint.sdc
