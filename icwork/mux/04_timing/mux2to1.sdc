# 时序约束 - 2GHz 时钟
create_clock -name clk -period 500 [get_ports sel]
set_input_delay -clock clk 0 [get_ports in0*]
set_input_delay -clock clk 0 [get_ports in1*]
set_output_delay -clock clk 0 [get_ports out*]
