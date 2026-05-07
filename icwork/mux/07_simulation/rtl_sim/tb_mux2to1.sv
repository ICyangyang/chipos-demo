//-----------------------------------------------------------------------------
// File: tb_mux2to1.sv
// Purpose: SystemVerilog testbench for 2-to-1 MUX (mux2to1)
//          Tests all select cases, boundary conditions, and parameterized widths
// DUT Interface:
//   - in0  : DATA_WIDTH-bit data input 0
//   - in1  : DATA_WIDTH-bit data input 1
//   - sel  : 1-bit select (0->in0, 1->in1)
//   - out  : DATA_WIDTH-bit data output
// Author: ChipOS RTL Team
// Date: 2026-04-27
//-----------------------------------------------------------------------------

`timescale 1ns/1ps

// Testbench for DATA_WIDTH = 8 (default)
module tb_mux2to1;

    // Test parameters
    parameter DATA_WIDTH = 8;
    parameter NUM_RANDOM_TESTS = 20;
    parameter CLK_PERIOD = 10;

    // Test signals
    reg  [DATA_WIDTH-1:0] in0;
    reg  [DATA_WIDTH-1:0] in1;
    reg                   sel;
    wire [DATA_WIDTH-1:0] out;

    // Test control
    reg         clk;
    integer     test_count;
    integer     pass_count;
    integer     fail_count;
    reg [255:0] test_name;

    // Instantiate DUT
    mux2to1 #(
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .in0 (in0),
        .in1 (in1),
        .sel (sel),
        .out (out)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // Waveform dump for GTKWave
    initial begin
        $dumpfile("mux2to1_rtl.vcd");
        $dumpvars(0, tb_mux2to1);
    end

    // Task: check output and report result
    task automatic check_output;
        input [DATA_WIDTH-1:0] expected;
        input [255:0]          tname;
        begin
            test_count = test_count + 1;
            if (out === expected) begin
                pass_count = pass_count + 1;
                $display("[PASS] Test %0d: %s", test_count, tname);
            end else begin
                fail_count = fail_count + 1;
                $display("[FAIL] Test %0d: %s - Expected: 0x%h, Got: 0x%h", 
                         test_count, tname, expected, out);
            end
        end
    endtask

    // Task: run single test case
    task automatic run_test;
        input [DATA_WIDTH-1:0] t_in0;
        input [DATA_WIDTH-1:0] t_in1;
        input                   t_sel;
        input [255:0]          tname;
        reg [DATA_WIDTH-1:0]   expected;
        begin
            in0 = t_in0;
            in1 = t_in1;
            sel = t_sel;
            #(1); // Wait for combinational logic to settle
            expected = t_sel ? t_in1 : t_in0;
            check_output(expected, tname);
        end
    endtask

    // Main test sequence
    initial begin
        // Initialize
        $display("============================================================");
        $display("  Testbench for mux2to1 (DATA_WIDTH = %0d)", DATA_WIDTH);
        $display("============================================================");
        
        in0 = 0;
        in1 = 0;
        sel = 0;
        test_count = 0;
        pass_count = 0;
        fail_count = 0;

        // Wait for initial stabilization
        #(CLK_PERIOD);

        //------------------------------------------------------------
        // Test Group 1: sel=0 cases (output should be in0)
        //------------------------------------------------------------
        $display("\n--- Test Group 1: sel=0 (out = in0) ---");
        
        // COVERS: CK-MUX.1.1 - sel=0 with random data
        run_test(8'h55, 8'hAA, 1'b0, "sel=0, in0=0x55, in1=0xAA");
        run_test(8'hAA, 8'h55, 1'b0, "sel=0, in0=0xAA, in1=0x55");
        
        // Random tests for sel=0
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random;
            in1 = $random;
            sel = 1'b0;
            #(1);
            check_output(in0, "sel=0, random data");
        end

        //------------------------------------------------------------
        // Test Group 2: sel=1 cases (output should be in1)
        //------------------------------------------------------------
        $display("\n--- Test Group 2: sel=1 (out = in1) ---");
        
        // COVERS: CK-MUX.1.2 - sel=1 with random data
        run_test(8'h55, 8'hAA, 1'b1, "sel=1, in0=0x55, in1=0xAA");
        run_test(8'hAA, 8'h55, 1'b1, "sel=1, in0=0xAA, in1=0x55");
        
        // Random tests for sel=1
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random;
            in1 = $random;
            sel = 1'b1;
            #(1);
            check_output(in1, "sel=1, random data");
        end

        //------------------------------------------------------------
        // Test Group 3: Boundary conditions
        //------------------------------------------------------------
        $display("\n--- Test Group 3: Boundary Conditions ---");
        
        // COVERS: CK-MUX.2.1 - All zeros
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}, 1'b0, "all zeros, sel=0");
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}, 1'b1, "all zeros, sel=1");
        
        // COVERS: CK-MUX.2.2 - All ones
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b1}}, 1'b0, "all ones, sel=0");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b1}}, 1'b1, "all ones, sel=1");
        
        // COVERS: CK-MUX.2.3 - Mixed boundary
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}, 1'b0, "in0=all 0, in1=all 1, sel=0");
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}, 1'b1, "in0=all 0, in1=all 1, sel=1");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}, 1'b0, "in0=all 1, in1=all 0, sel=0");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}, 1'b1, "in0=all 1, in1=all 0, sel=1");

        //------------------------------------------------------------
        // Test Group 4: Toggle patterns
        //------------------------------------------------------------
        $display("\n--- Test Group 4: Toggle Patterns ---");
        
        // COVERS: CK-MUX.3.1 - Alternating patterns
        run_test(8'h55, 8'hAA, 1'b0, "toggle pattern 0x55/0xAA, sel=0");
        run_test(8'h55, 8'hAA, 1'b1, "toggle pattern 0x55/0xAA, sel=1");
        run_test(8'hAA, 8'h55, 1'b0, "toggle pattern 0xAA/0x55, sel=0");
        run_test(8'hAA, 8'h55, 1'b1, "toggle pattern 0xAA/0x55, sel=1");

        //------------------------------------------------------------
        // Test Summary
        //------------------------------------------------------------
        #(CLK_PERIOD);
        $display("\n============================================================");
        $display("  Test Summary: DATA_WIDTH = %0d", DATA_WIDTH);
        $display("  Total Tests:  %0d", test_count);
        $display("  Passed:       %0d", pass_count);
        $display("  Failed:       %0d", fail_count);
        $display("============================================================");
        
        if (fail_count == 0) begin
            $display("\n>>> ALL TESTS PASSED <<<\n");
        end else begin
            $display("\n>>> SOME TESTS FAILED <<<\n");
        end
        
        $finish;
    end

    // Timeout protection
    initial begin
        #100000;
        $display("\n[ERROR] Simulation timeout - possible infinite loop");
        $finish;
    end

endmodule


//-----------------------------------------------------------------------------
// Testbench for DATA_WIDTH = 4
//-----------------------------------------------------------------------------
module tb_mux2to1_width4;

    parameter DATA_WIDTH = 4;
    parameter NUM_RANDOM_TESTS = 10;
    parameter CLK_PERIOD = 10;

    reg  [DATA_WIDTH-1:0] in0;
    reg  [DATA_WIDTH-1:0] in1;
    reg                   sel;
    wire [DATA_WIDTH-1:0] out;

    reg         clk;
    integer     test_count;
    integer     pass_count;
    integer     fail_count;

    mux2to1 #(.DATA_WIDTH(DATA_WIDTH)) dut (.in0(in0), .in1(in1), .sel(sel), .out(out));

    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    task automatic check_output;
        input [DATA_WIDTH-1:0] expected;
        input [255:0]          tname;
        begin
            test_count = test_count + 1;
            if (out === expected) begin
                pass_count = pass_count + 1;
                $display("[PASS] Test %0d: %s", test_count, tname);
            end else begin
                fail_count = fail_count + 1;
                $display("[FAIL] Test %0d: %s - Expected: 0x%h, Got: 0x%h", 
                         test_count, tname, expected, out);
            end
        end
    endtask

    initial begin
        $display("\n============================================================");
        $display("  Testbench for mux2to1 (DATA_WIDTH = %0d)", DATA_WIDTH);
        $display("============================================================");
        
        in0 = 0; in1 = 0; sel = 0;
        test_count = 0; pass_count = 0; fail_count = 0;
        #(CLK_PERIOD);

        // COVERS: CK-MUX.4.1 - Width=4, sel=0
        $display("\n--- sel=0 tests (DATA_WIDTH=4) ---");
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random; in1 = $random; sel = 1'b0;
            #(1);
            check_output(in0, "sel=0, random");
        end

        // COVERS: CK-MUX.4.2 - Width=4, sel=1
        $display("\n--- sel=1 tests (DATA_WIDTH=4) ---");
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random; in1 = $random; sel = 1'b1;
            #(1);
            check_output(in1, "sel=1, random");
        end

        // COVERS: CK-MUX.4.3 - Width=4, boundary
        $display("\n--- Boundary tests (DATA_WIDTH=4) ---");
        in0 = 4'h0; in1 = 4'hF; sel = 1'b0; #(1);
        check_output(4'h0, "in0=0x0, in1=0xF, sel=0");
        in0 = 4'h0; in1 = 4'hF; sel = 1'b1; #(1);
        check_output(4'hF, "in0=0x0, in1=0xF, sel=1");

        #(CLK_PERIOD);
        $display("\n============================================================");
        $display("  Summary (DATA_WIDTH=%0d): Total=%0d, Pass=%0d, Fail=%0d", 
                 DATA_WIDTH, test_count, pass_count, fail_count);
        $display("============================================================");
        if (fail_count == 0) $display("\n>>> ALL TESTS PASSED <<<\n");
        else $display("\n>>> SOME TESTS FAILED <<<\n");
        $finish;
    end

    initial begin #50000; $display("[ERROR] Timeout"); $finish; end

endmodule


//-----------------------------------------------------------------------------
// Testbench for DATA_WIDTH = 16
//-----------------------------------------------------------------------------
module tb_mux2to1_width16;

    parameter DATA_WIDTH = 16;
    parameter NUM_RANDOM_TESTS = 10;
    parameter CLK_PERIOD = 10;

    reg  [DATA_WIDTH-1:0] in0;
    reg  [DATA_WIDTH-1:0] in1;
    reg                   sel;
    wire [DATA_WIDTH-1:0] out;

    reg         clk;
    integer     test_count;
    integer     pass_count;
    integer     fail_count;

    mux2to1 #(.DATA_WIDTH(DATA_WIDTH)) dut (.in0(in0), .in1(in1), .sel(sel), .out(out));

    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    task automatic check_output;
        input [DATA_WIDTH-1:0] expected;
        input [255:0]          tname;
        begin
            test_count = test_count + 1;
            if (out === expected) begin
                pass_count = pass_count + 1;
                $display("[PASS] Test %0d: %s", test_count, tname);
            end else begin
                fail_count = fail_count + 1;
                $display("[FAIL] Test %0d: %s - Expected: 0x%h, Got: 0x%h", 
                         test_count, tname, expected, out);
            end
        end
    endtask

    initial begin
        $display("\n============================================================");
        $display("  Testbench for mux2to1 (DATA_WIDTH = %0d)", DATA_WIDTH);
        $display("============================================================");
        
        in0 = 0; in1 = 0; sel = 0;
        test_count = 0; pass_count = 0; fail_count = 0;
        #(CLK_PERIOD);

        // COVERS: CK-MUX.5.1 - Width=16, sel=0
        $display("\n--- sel=0 tests (DATA_WIDTH=16) ---");
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random; in1 = $random; sel = 1'b0;
            #(1);
            check_output(in0, "sel=0, random");
        end

        // COVERS: CK-MUX.5.2 - Width=16, sel=1
        $display("\n--- sel=1 tests (DATA_WIDTH=16) ---");
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random; in1 = $random; sel = 1'b1;
            #(1);
            check_output(in1, "sel=1, random");
        end

        // COVERS: CK-MUX.5.3 - Width=16, boundary
        $display("\n--- Boundary tests (DATA_WIDTH=16) ---");
        in0 = 16'h0000; in1 = 16'hFFFF; sel = 1'b0; #(1);
        check_output(16'h0000, "in0=0x0000, in1=0xFFFF, sel=0");
        in0 = 16'h0000; in1 = 16'hFFFF; sel = 1'b1; #(1);
        check_output(16'hFFFF, "in0=0x0000, in1=0xFFFF, sel=1");
        in0 = 16'h1234; in1 = 16'h5678; sel = 1'b0; #(1);
        check_output(16'h1234, "in0=0x1234, in1=0x5678, sel=0");
        in0 = 16'h1234; in1 = 16'h5678; sel = 1'b1; #(1);
        check_output(16'h5678, "in0=0x1234, in1=0x5678, sel=1");

        #(CLK_PERIOD);
        $display("\n============================================================");
        $display("  Summary (DATA_WIDTH=%0d): Total=%0d, Pass=%0d, Fail=%0d", 
                 DATA_WIDTH, test_count, pass_count, fail_count);
        $display("============================================================");
        if (fail_count == 0) $display("\n>>> ALL TESTS PASSED <<<\n");
        else $display("\n>>> SOME TESTS FAILED <<<\n");
        $finish;
    end

    initial begin #50000; $display("[ERROR] Timeout"); $finish; end

endmodule


//-----------------------------------------------------------------------------
// Top-level test wrapper - runs all width configurations
//-----------------------------------------------------------------------------
module tb_mux2to1_all;

    initial begin
        $display("\n");
        $display("############################################################");
        $display("#                                                          #");
        $display("#        mux2to1 Comprehensive Test Suite                  #");
        $display("#        Testing DATA_WIDTH = 4, 8, 16                     #");
        $display("#                                                          #");
        $display("############################################################");
        $display("\n");
    end

endmodule
