###############################################################################
# Created by write_sdc
###############################################################################
current_design uart_tx
###############################################################################
# Timing Constraints
###############################################################################
create_clock -name PCLK -period 0.6569 [get_ports {PCLK}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[0]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[0]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[1]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[1]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[2]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[2]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[3]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[3]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[4]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[4]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[5]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[5]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[6]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[6]}]
set_input_delay 0.5000 -min -add_delay [get_ports {LCR[7]}]
set_input_delay 2.0000 -max -add_delay [get_ports {LCR[7]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[0]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[0]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[1]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[1]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[2]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[2]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[3]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[3]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[4]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[4]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[5]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[5]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[6]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[6]}]
set_input_delay 0.5000 -min -add_delay [get_ports {PWDATA[7]}]
set_input_delay 2.0000 -max -add_delay [get_ports {PWDATA[7]}]
set_input_delay 0.5000 -min -add_delay [get_ports {enable}]
set_input_delay 2.0000 -max -add_delay [get_ports {enable}]
set_input_delay 0.5000 -min -add_delay [get_ports {tx_fifo_push}]
set_input_delay 2.0000 -max -add_delay [get_ports {tx_fifo_push}]
set_output_delay 0.5000 -min -add_delay [get_ports {TXD}]
set_output_delay 2.0000 -max -add_delay [get_ports {TXD}]
set_output_delay 0.5000 -min -add_delay [get_ports {busy}]
set_output_delay 2.0000 -max -add_delay [get_ports {busy}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_count[0]}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_count[0]}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_count[1]}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_count[1]}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_count[2]}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_count[2]}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_count[3]}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_count[3]}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_count[4]}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_count[4]}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_empty}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_empty}]
set_output_delay 0.5000 -min -add_delay [get_ports {tx_fifo_full}]
set_output_delay 2.0000 -max -add_delay [get_ports {tx_fifo_full}]
###############################################################################
# Environment
###############################################################################
###############################################################################
# Design Rules
###############################################################################
