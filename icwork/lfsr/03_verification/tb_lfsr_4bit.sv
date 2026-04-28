// =============================================================================
// File: tb_lfsr_4bit.sv
// Purpose: SystemVerilog TestBench for 4-bit LFSR (x^4 + x + 1)
// Author: ChipOS RTL Team
// Date: 2026-04-28
// =============================================================================
// DUT Interface:
//   clk - input, clock signal (posedge trigger)
//   res - input, async reset (active-low)
//   y   - output, pseudo-random sequence (d[0])
// =============================================================================
// Test Strategy:
//   1. Reset Test: Verify d initialized to 1111 when res=0
//   2. Sequence Test: Run 15 cycles, compare y with expected values
//   3. Periodicity Test: Verify cycle 16 returns to initial state
// =============================================================================

`timescale 1ns/1ps

module tb_lfsr_4bit;

    // -------------------------------------------------------------------------
    // Parameters
    // -------------------------------------------------------------------------
    parameter CLK_PERIOD = 10;           // Clock period: 10ns (100MHz)
    parameter LFSR_PERIOD = 15;          // LFSR maximum period
    parameter TIMEOUT_CYCLES = 100;      // Simulation timeout

    // -------------------------------------------------------------------------
    // DUT Signals
    // -------------------------------------------------------------------------
    logic clk;
    logic res;
    logic y;

    // -------------------------------------------------------------------------
    // Test Statistics
    // -------------------------------------------------------------------------
    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;

    // -------------------------------------------------------------------------
    // Expected Sequence (from Golden Model)
    // -------------------------------------------------------------------------
    // Cycle 0:  d=15, y=1
    // Cycle 1:  d=7,  y=1
    // Cycle 2:  d=11, y=1
    // Cycle 3:  d=5,  y=1
    // Cycle 4:  d=10, y=0
    // Cycle 5:  d=13, y=1
    // Cycle 6:  d=6,  y=0
    // Cycle 7:  d=3,  y=1
    // Cycle 8:  d=9,  y=1
    // Cycle 9:  d=4,  y=0
    // Cycle 10: d=2,  y=0
    // Cycle 11: d=1,  y=1
    // Cycle 12: d=8,  y=0
    // Cycle 13: d=12, y=0
    // Cycle 14: d=14, y=0
    // Cycle 15: d=15, y=1 (returns to initial)
    
    logic [3:0] expected_d [0:15];
    logic       expected_y [0:15];
    
    // -------------------------------------------------------------------------
    // DUT Instance
    // -------------------------------------------------------------------------
    lfsr_4bit dut (
        .clk(clk),
        .res(res),
        .y(y)
    );

    // -------------------------------------------------------------------------
    // Clock Generation
    // -------------------------------------------------------------------------
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // -------------------------------------------------------------------------
    // VCD Dump for Waveform Analysis
    // -------------------------------------------------------------------------
    initial begin
        $dumpfile("tb_lfsr_4bit.vcd");
        $dumpvars(0, tb_lfsr_4bit);
    end

    // -------------------------------------------------------------------------
    // Timeout Protection
    // -------------------------------------------------------------------------
    initial begin
        #(CLK_PERIOD * TIMEOUT_CYCLES);
        $display("[ERROR] Simulation timeout at %0t", $time);
        $finish;
    end

    // -------------------------------------------------------------------------
    // Initialize Expected Sequence
    // -------------------------------------------------------------------------
    function void init_expected_sequence();
        expected_d[0]  = 4'd15; expected_y[0]  = 1'b1;
        expected_d[1]  = 4'd7;  expected_y[1]  = 1'b1;
        expected_d[2]  = 4'd11; expected_y[2]  = 1'b1;
        expected_d[3]  = 4'd5;  expected_y[3]  = 1'b1;
        expected_d[4]  = 4'd10; expected_y[4]  = 1'b0;
        expected_d[5]  = 4'd13; expected_y[5]  = 1'b1;
        expected_d[6]  = 4'd6;  expected_y[6]  = 1'b0;
        expected_d[7]  = 4'd3;  expected_y[7]  = 1'b1;
        expected_d[8]  = 4'd9;  expected_y[8]  = 1'b1;
        expected_d[9]  = 4'd4;  expected_y[9]  = 1'b0;
        expected_d[10] = 4'd2;  expected_y[10] = 1'b0;
        expected_d[11] = 4'd1;  expected_y[11] = 1'b1;
        expected_d[12] = 4'd8;  expected_y[12] = 1'b0;
        expected_d[13] = 4'd12; expected_y[13] = 1'b0;
        expected_d[14] = 4'd14; expected_y[14] = 1'b0;
        expected_d[15] = 4'd15; expected_y[15] = 1'b1;
    endfunction

    // -------------------------------------------------------------------------
    // Task: Apply Reset
    // -------------------------------------------------------------------------
    task apply_reset();
        $display("[INFO] Applying reset...");
        res = 1'b0;
        @(posedge clk);
        @(negedge clk);  // Wait for async reset to take effect
        res = 1'b1;
        $display("[INFO] Reset released at time %0t", $time);
    endtask

    // -------------------------------------------------------------------------
    // Task: Test Reset Initialization
    // COVERS: Verify d=1111 after reset
    // -------------------------------------------------------------------------
    task test_reset();
        $display("");
        $display("========================================");
        $display("TEST 1: Reset Initialization");
        $display("========================================");
        
        total_tests++;
        
        // Apply reset
        apply_reset();
        
        // Wait one clock cycle for state to stabilize
        @(posedge clk);
        
        // Check internal state via output y
        // After reset, d=1111, so y=d[0]=1
        if (y === 1'b1) begin
            $display("[PASS] Reset test: y=%b (expected 1)", y);
            passed_tests++;
        end else begin
            $display("[FAIL] Reset test: y=%b (expected 1)", y);
            failed_tests++;
        end
        
        $display("----------------------------------------");
    endtask

    // -------------------------------------------------------------------------
    // Task: Test Full Sequence (15 cycles)
    // COVERS: Verify output sequence matches Golden Model
    // -------------------------------------------------------------------------
    task test_sequence();
        int cycle;
        logic [3:0] state_trace [0:15];
        logic       output_trace [0:15];
        
        $display("");
        $display("========================================");
        $display("TEST 2: Full Sequence Verification");
        $display("========================================");
        
        // Apply reset to start from known state
        apply_reset();
        
        // Run 15 cycles and capture outputs
        for (cycle = 0; cycle < LFSR_PERIOD; cycle++) begin
            @(posedge clk);
            output_trace[cycle] = y;
            // Note: Cannot directly observe internal state d in TB
            // We verify via output y and infer state
            $display("[INFO] Cycle %2d: y=%b (expected y=%b)", 
                     cycle, y, expected_y[cycle]);
        end
        
        // Compare with expected sequence
        $display("");
        $display("Sequence Comparison:");
        $display("----------------------------------------");
        
        for (cycle = 0; cycle < LFSR_PERIOD; cycle++) begin
            total_tests++;
            if (output_trace[cycle] === expected_y[cycle]) begin
                $display("[PASS] Cycle %2d: y=%b matches expected", cycle, output_trace[cycle]);
                passed_tests++;
            end else begin
                $display("[FAIL] Cycle %2d: y=%b (expected %b)", 
                         cycle, output_trace[cycle], expected_y[cycle]);
                failed_tests++;
            end
        end
        
        $display("----------------------------------------");
    endtask

    // -------------------------------------------------------------------------
    // Task: Test Periodicity (Cycle 16 returns to initial state)
    // COVERS: Verify LFSR period is exactly 15
    // -------------------------------------------------------------------------
    task test_periodicity();
        logic y_at_cycle_15;
        logic y_at_cycle_16;
        
        $display("");
        $display("========================================");
        $display("TEST 3: Periodicity Verification");
        $display("========================================");
        
        // Apply reset
        apply_reset();
        
        // Run 15 full cycles
        repeat(LFSR_PERIOD) @(posedge clk);
        y_at_cycle_15 = y;
        
        // Run one more cycle
        @(posedge clk);
        y_at_cycle_16 = y;
        
        $display("[INFO] y at cycle 15: %b", y_at_cycle_15);
        $display("[INFO] y at cycle 16: %b", y_at_cycle_16);
        
        // Verify cycle 16 output matches cycle 0 (y=1)
        total_tests++;
        if (y_at_cycle_16 === expected_y[0]) begin
            $display("[PASS] Periodicity: cycle 16 y=%b matches cycle 0 y=%b", 
                     y_at_cycle_16, expected_y[0]);
            passed_tests++;
        end else begin
            $display("[FAIL] Periodicity: cycle 16 y=%b (expected %b)", 
                     y_at_cycle_16, expected_y[0]);
            failed_tests++;
        end
        
        // Run additional cycles to verify continued periodicity
        $display("");
        $display("Extended Periodicity Check (cycles 16-30):");
        $display("----------------------------------------");
        
        for (int cycle = 16; cycle < 30; cycle++) begin
            @(posedge clk);
            total_tests++;
            // Expected y at cycle N = expected y at cycle (N % 15)
            if (y === expected_y[cycle % 15]) begin
                $display("[PASS] Cycle %2d: y=%b matches expected y[%0d]=%b", 
                         cycle, y, cycle % 15, expected_y[cycle % 15]);
                passed_tests++;
            end else begin
                $display("[FAIL] Cycle %2d: y=%b (expected y[%0d]=%b)", 
                         cycle, y, cycle % 15, expected_y[cycle % 15]);
                failed_tests++;
            end
        end
        
        $display("----------------------------------------");
    endtask

    // -------------------------------------------------------------------------
    // Task: Print Test Summary
    // -------------------------------------------------------------------------
    task print_summary();
        $display("");
        $display("========================================");
        $display("TEST SUMMARY");
        $display("========================================");
        $display("  Total Tests:  %0d", total_tests);
        $display("  Passed:       %0d", passed_tests);
        $display("  Failed:       %0d", failed_tests);
        $display("----------------------------------------");
        
        if (failed_tests == 0) begin
            $display("");
            $display("  ==============================");
            $display("  ALL TESTS PASSED");
            $display("  ==============================");
            $display("");
        end else begin
            $display("");
            $display("  ==============================");
            $display("  SOME TESTS FAILED");
            $display("  ==============================");
            $display("");
        end
    endtask

    // -------------------------------------------------------------------------
    // Main Test Sequence
    // -------------------------------------------------------------------------
    initial begin
        $display("");
        $display("========================================");
        $display("4-bit LFSR TestBench");
        $display("Characteristic Polynomial: x^4 + x + 1");
        $display("Maximum Period: 15 cycles");
        $display("========================================");
        $display("Start time: %0t", $time);
        
        // Initialize expected sequence
        init_expected_sequence();
        
        // Run all tests
        test_reset();
        test_sequence();
        test_periodicity();
        
        // Print summary
        print_summary();
        
        $display("End time: %0t", $time);
        $display("========================================");
        
        // Finish simulation
        $finish;
    end

endmodule
