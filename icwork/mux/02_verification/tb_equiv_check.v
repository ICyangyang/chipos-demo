//-----------------------------------------------------------------------------
// Equivalence Check Testbench: RTL vs Gate-Level Netlist
// Module: mux2to1 (8-bit)
//-----------------------------------------------------------------------------

`timescale 1ns/1ps

module tb_equiv_check;

    // Test signals
    reg  [7:0] in0;
    reg  [7:0] in1;
    reg        sel;
    wire [7:0] out_rtl;
    wire [7:0] out_gate;

    // Error counter
    integer error_count = 0;
    integer test_count = 0;

    // RTL instance (parameterized)
    mux2to1 #(.DATA_WIDTH(8)) u_rtl (
        .in0(in0),
        .in1(in1),
        .sel(sel),
        .out(out_rtl)
    );

    // Gate-level instance
    mux2to1_gate u_gate (
        .in0(in0),
        .in1(in1),
        .sel(sel),
        .out(out_gate)
    );

    // Check equivalence
    task check_equiv;
        input [7:0] expected;
        input [7:0] actual;
        input integer test_id;
        begin
            test_count = test_count + 1;
            if (expected !== actual) begin
                $display("[FAIL] Test %0d: in0=%h, in1=%h, sel=%b, RTL=%h, Gate=%h",
                         test_id, in0, in1, sel, expected, actual);
                error_count = error_count + 1;
            end
        end
    endtask

    // Stimulus
    initial begin
        $display("==========================================");
        $display("Equivalence Check: RTL vs Gate-Level");
        $display("==========================================");

        // Test 1: sel=0, select in0
        in0 = 8'hAA; in1 = 8'h55; sel = 0;
        #1;
        check_equiv(out_rtl, out_gate, 1);

        // Test 2: sel=1, select in1
        in0 = 8'hAA; in1 = 8'h55; sel = 1;
        #1;
        check_equiv(out_rtl, out_gate, 2);

        // Test 3: All zeros
        in0 = 8'h00; in1 = 8'h00; sel = 0;
        #1;
        check_equiv(out_rtl, out_gate, 3);

        // Test 4: All ones
        in0 = 8'hFF; in1 = 8'hFF; sel = 1;
        #1;
        check_equiv(out_rtl, out_gate, 4);

        // Test 5: Alternating patterns
        in0 = 8'h55; in1 = 8'hAA; sel = 0;
        #1;
        check_equiv(out_rtl, out_gate, 5);

        in0 = 8'h55; in1 = 8'hAA; sel = 1;
        #1;
        check_equiv(out_rtl, out_gate, 6);

        // Random tests
        repeat(100) begin
            in0 = $random;
            in1 = $random;
            sel = $random & 1;
            #1;
            check_equiv(out_rtl, out_gate, test_count);
        end

        // Summary
        $display("==========================================");
        $display("Total tests: %0d", test_count);
        $display("Errors:      %0d", error_count);
        
        if (error_count == 0) begin
            $display("Result:      PASS - RTL and Gate are EQUIVALENT");
            $display("==========================================");
            $finish;
        end else begin
            $display("Result:      FAIL - RTL and Gate are NOT EQUIVALENT");
            $display("==========================================");
            $finish;
        end
    end

endmodule