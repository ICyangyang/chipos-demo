# STA SDF Generation Script
# 使用独立 STA 工具从网表和 SPEF 生成 SDF

# 设置路径
set design_name "mux2to1"
set work_dir "/app/backend/icwork/mux/06_physical"
set lib_dir "/opt/OpenROAD-flow-scripts/flow/platforms/nangate45/lib"

puts "步骤 1: 读取工艺库"
read_liberty "$lib_dir/NangateOpenCellLibrary_typical.lib"

puts "步骤 2: 读取门级网表"
read_verilog "$work_dir/6_final.v"

puts "步骤 3: 链接设计"
link_design $design_name

puts "步骤 4: 读取 SPEF 文件（寄生参数）"
read_spef "$work_dir/6_final.spef"

puts "步骤 5: 生成 SDF 文件"
write_sdf "$work_dir/6_final.sdf"

puts "✅ SDF 文件已生成: $work_dir/6_final.sdf"
