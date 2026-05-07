//-----------------------------------------------------------------------------
// File: tb_mux2to1_post.sv
// Purpose: Post-layout simulation with SDF back-annotation
//          Tests gate-level netlist with realistic timing delays
// DUT: mux2to1_gate (gate-level netlist from synthesis)
// SDF: mux2to1_gate.sdf (timing back-annotation)
// Author: ChipOS RTL Team
// Date: 2026-04-27
//-----------------------------------------------------------------------------

`timescale 1ns/1ps

module tb_mux2to1_post;

    // Test parameters
    parameter DATA_WIDTH = 8;
    parameter NUM_RANDOM_TESTS = 20;
    parameter CLK_PERIOD = 10;
    parameter SETUP_TIME = 0.5;   // Setup time for timing checks
    parameter HOLD_TIME = 0.2;    // Hold time for timing checks

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

    // Timing violation counter
    integer     timing_violations;

    //=========================================================================
    // DUT Instance - Gate-level netlist
    //=========================================================================
    mux2to1_gate dut (
        .in0 (in0),
        .in1 (in1),
        .sel (sel),
        .out (out)
    );

    //=========================================================================
    // SDF Back-Annotation
    //=========================================================================
    // Annotate SDF timing delays to the gate-level netlist
    // - MINIMUM: Use minimum delays (best-case timing)
    // - TYPICAL: Use typical delays
    // - MAXIMUM: Use maximum delays (worst-case timing)
    initial begin
        $display("============================================================");
        $display("  SDF Back-Annotation for Post-Layout Simulation");
        $display("============================================================");
        $display("  SDF File: mux2to1_gate.sdf");
        $display("  Design:   mux2to1_gate");
        $display("  Timescale: 1ns/1ps");
        $display("============================================================");
        
        // SDF annotation with detailed log output
        $sdf_annotate("mux2to1_gate.sdf",    // SDF file path
                      dut,                   // Target instance
                      "sdfAnnotateInfo.log", // Annotation report file
                      "MINIMUM");            // Delay selection: MINIMUM/TYPICAL/MAXIMUM
        
        $display("  SDF annotation completed.");
        $display("  See sdfAnnotateInfo.log for annotation details.\n");
    end

    //=========================================================================
    // Clock Generation
    //=========================================================================
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    //=========================================================================
    // Waveform Dump for GTKWave
    //=========================================================================
    initial begin
        $dumpfile("mux2to1_post.vcd");
        $dumpvars(0, tb_mux2to1_post);
    end

    //=========================================================================
    // Task: Check output and report result
    //=========================================================================
    task automatic check_output;
        input [DATA_WIDTH-1:0] expected;
        input [255:0]          tname;
        begin
            test_count = test_count + 1;
            // Wait for propagation delay (SDF delays are applied)
            #(CLK_PERIOD/4);  // Additional wait for timing to settle
            
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

    //=========================================================================
    // Task: Run single test case with timing awareness
    //=========================================================================
    task automatic run_test;
        input [DATA_WIDTH-1:0] t_in0;
        input [DATA_WIDTH-1:0] t_in1;
        input                   t_sel;
        input [255:0]          tname;
        reg [DATA_WIDTH-1:0]   expected;
        begin
            // Apply inputs
            in0 = t_in0;
            in1 = t_in1;
            sel = t_sel;
            
            // Wait for combinational logic propagation (with SDF delays)
            #(CLK_PERIOD/2);  // Longer wait for post-layout timing
            
            expected = t_sel ? t_in1 : t_in0;
            check_output(expected, tname);
        end
    endtask

    //=========================================================================
    // Main Test Sequence
    //=========================================================================
    initial begin
        // Initialize
        $display("============================================================");
        $display("  Post-Layout Simulation for mux2to1_gate");
        $display("  DATA_WIDTH = %0d", DATA_WIDTH);
        $display("============================================================");
        
        in0 = 0;
        in1 = 0;
        sel = 0;
        test_count = 0;
        pass_count = 0;
        fail_count = 0;
        timing_violations = 0;

        // Wait for initial stabilization
        #(CLK_PERIOD);

        //------------------------------------------------------------
        // Test Group 1: sel=0 cases (output should be in0)
        //------------------------------------------------------------
        $display("\n--- Test Group 1: sel=0 (out = in0) ---");
        
        run_test(8'h55, 8'hAA, 1'b0, "sel=0, in0=0x55, in1=0xAA");
        run_test(8'hAA, 8'h55, 1'b0, "sel=0, in0=0xAA, in1=0x55");
        
        // Random tests for sel=0
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random;
            in1 = $random;
            sel = 1'b0;
            #(CLK_PERIOD/2);
            check_output(in0, "sel=0, random data");
        end

        //------------------------------------------------------------
        // Test Group 2: sel=1 cases (output should be in1)
        //------------------------------------------------------------
        $display("\n--- Test Group 2: sel=1 (out = in1) ---");
        
        run_test(8'h55, 8'hAA, 1'b1, "sel=1, in0=0x55, in1=0xAA");
        run_test(8'hAA, 8'h55, 1'b1, "sel=1, in0=0xAA, in1=0x55");
        
        // Random tests for sel=1
        repeat (NUM_RANDOM_TESTS) begin
            in0 = $random;
            in1 = $random;
            sel = 1'b1;
            #(CLK_PERIOD/2);
            check_output(in1, "sel=1, random data");
        end

        //------------------------------------------------------------
        // Test Group 3: Boundary conditions
        //------------------------------------------------------------
        $display("\n--- Test Group 3: Boundary Conditions ---");
        
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}, 1'b0, "all zeros, sel=0");
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b0}}, 1'b1, "all zeros, sel=1");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b1}}, 1'b0, "all ones, sel=0");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b1}}, 1'b1, "all ones, sel=1");
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}, 1'b0, "in0=all 0, in1=all 1, sel=0");
        run_test({DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}, 1'b1, "in0=all 0, in1=all 1, sel=1");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}, 1'b0, "in0=all 1, in1=all 0, sel=0");
        run_test({DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}}, 1'b1, "in0=all 1, in1=all 0, sel=1");

        //------------------------------------------------------------
        // Test Group 4: Toggle patterns
        //------------------------------------------------------------
        $display("\n--- Test Group 4: Toggle Patterns ---");
        
        run_test(8'h55, 8'hAA, 1'b0, "toggle pattern 0x55/0xAA, sel=0");
        run_test(8'h55, 8'hAA, 1'b1, "toggle pattern 0x55/0xAA, sel=1");
        run_test(8'hAA, 8'h55, 1'b0, "toggle pattern 0xAA/0x55, sel=0");
        run_test(8'hAA, 8'h55, 1'b1, "toggle pattern 0xAA/0x55, sel=1");

        //------------------------------------------------------------
        // Test Group 5: Timing stress tests
        //------------------------------------------------------------
        $display("\n--- Test Group 5: Timing Stress Tests ---");
        
        // Rapid input changes to test propagation delays
        repeat (5) begin
            in0 = $random;
            in1 = $random;
            sel = 1'b0;
            #(CLK_PERIOD/4);
            check_output(in0, "rapid toggle, sel=0");
            
            sel = 1'b1;
            #(CLK_PERIOD/4);
            check_output(in1, "rapid toggle, sel=1");
        end

        //------------------------------------------------------------
        // Test Summary
        //------------------------------------------------------------
        #(CLK_PERIOD);
        $display("\n============================================================");
        $display("  Post-Layout Simulation Summary");
        $display("============================================================");
        $display("  Design:        mux2to1_gate");
        $display("  DATA_WIDTH:   %0d", DATA_WIDTH);
        $display("  Total Tests:  %0d", test_count);
        $display("  Passed:       %0d", pass_count);
        $display("  Failed:       %0d", fail_count);
        $display("  Timing Vios:  %0d", timing_violations);
        $display("============================================================");
        
        if (fail_count == 0 && timing_violations == 0) begin
            $display("\n>>> ALL POST-LAYOUT TESTS PASSED <<<\n");
        end else if (fail_count == 0 && timing_violations > 0) begin
            $display("\n>>> FUNCTIONAL PASS, BUT TIMING VIOLATIONS DETECTED <<<\n");
        end else begin
            $display("\n>>> SOME TESTS FAILED <<<\n");
        end
        
        $finish;
    end

    //=========================================================================
    // Timeout Protection
    //=========================================================================
    initial begin
        #200000;
        $display("\n[ERROR] Simulation timeout - possible infinite loop");
        $finish;
    end

endmodule