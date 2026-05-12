# Design configuration for uart_tx
DESIGN_NAME = uart_tx
PLATFORM = nangate45

# Verilog source files
VERILOG_FILES = /workspace/work/uart_tx_study/uart_tx.v /workspace/work/uart_tx_study/uart_tx_fifo.v

# SDC constraints
SDC_FILE = /workspace/work/uart_tx_study/uart_tx.sdc

# Clock period (10ns = 100MHz)
CLOCK_PERIOD = 10.0

# Core utilization (small module, moderate)
CORE_UTILIZATION = 55

# Placement density (balanced)
PLACE_DENSITY = 0.70

# Die aspect ratio (square)
CORE_ASPECT_RATIO = 1.0