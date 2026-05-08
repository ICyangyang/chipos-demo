// =============================================================================
// UART TX Simple Verilog Testbench
// Tests all major configurations: 8-N-1, 5-N-1, parity, stop bits, FIFO, enable, reset
// =============================================================================

`timescale 1ns / 1ps

module uart_tx_tb;

    // =========================================================================
    // Signals
    // =========================================================================
    reg        PCLK;
    reg        PRESETn;
    reg  [7:0] PWDATA;
    reg        tx_fifo_push;
    reg  [7:0] LCR;
    reg        enable;

    wire       tx_fifo_empty;
    wire       tx_fifo_full;
    wire [4:0] tx_fifo_count;
    wire       busy;
    wire       TXD;

    // =========================================================================
    // DUT Instantiation
    // =========================================================================
    uart_tx dut (
        .PCLK          (PCLK),
        .PRESETn       (PRESETn),
        .PWDATA        (PWDATA),
        .tx_fifo_push  (tx_fifo_push),
        .LCR           (LCR),
        .enable        (enable),
        .tx_fifo_empty (tx_fifo_empty),
        .tx_fifo_full  (tx_fifo_full),
        .tx_fifo_count (tx_fifo_count),
        .busy          (busy),
        .TXD           (TXD)
    );

    // =========================================================================
    // Clock Generation: 10ns period (100MHz)
    // =========================================================================
    initial begin
        PCLK = 0;
        forever #5 PCLK = ~PCLK;
    end

    // =========================================================================
    // Test Variables
    // =========================================================================
    integer pass_count;
    integer fail_count;
    integer test_num;
    integer i;
    integer bit_idx;
    integer cycle_count;
    reg [7:0] expected_bits;
    reg [15:0] expected_frame;
    integer frame_len;
    reg [15:0] sampled_txd;
    integer errors_in_test;

    // =========================================================================
    // Helper Tasks
    // =========================================================================
    task apply_reset;
        begin
            PRESETn = 0;
            tx_fifo_push = 0;
            PWDATA = 0;
            LCR = 0;
            enable = 0;
            repeat(5) @(posedge PCLK);
            PRESETn = 1;
            enable = 1;
            @(posedge PCLK);
        end
    endtask

    task push_byte;
        input [7:0] data;
        input [7:0] lcr_val;
        begin
            LCR = lcr_val;
            PWDATA = data;
            tx_fifo_push = 1;
            @(posedge PCLK);
            tx_fifo_push = 0;
            PWDATA = 0;
        end
    endtask

    task wait_not_busy;
        input integer max_wait;
        begin
            cycle_count = 0;
            while (busy && cycle_count < max_wait) begin
                @(posedge PCLK);
                cycle_count = cycle_count + 1;
            end
        end
    endtask

    task check_signal;
        input [255:0] name;
        input expected;
        input actual;
        begin
            if (expected !== actual) begin
                $display("  FAIL: %0s expected=%0d actual=%0d", name, expected, actual);
                fail_count = fail_count + 1;
                errors_in_test = errors_in_test + 1;
            end else begin
                pass_count = pass_count + 1;
            end
        end
    endtask

    // Sample TXD at midbit (8th cycle of each 16-cycle bit period)
    // After sampling at midbit, wait 9 cycles to reach next bit's first cycle,
    // then 7 cycles to next midbit. Total interval = 16 cycles per bit period.
    task sample_frame;
        input integer num_bits;
        output [15:0] frame_samples;
        begin
            frame_samples = 0;
            for (bit_idx = 0; bit_idx < num_bits; bit_idx = bit_idx + 1) begin
                // Wait 7 cycles to reach midbit
                repeat(7) @(posedge PCLK);
                // Sample at midbit
                frame_samples[bit_idx] = TXD;
                // Wait 9 cycles to reach next bit period start
                // (8 remaining in current bit + 1 to next bit start)
                repeat(9) @(posedge PCLK);
            end
        end
    endtask

    // =========================================================================
    // Main Test Sequence
    // =========================================================================
    initial begin
        pass_count = 0;
        fail_count = 0;
        test_num = 0;
        errors_in_test = 0;

        $display("========================================");
        $display("UART TX Testbench Starting");
        $display("========================================");

        // -----------------------------------------------------------------
        // Test 1: Basic 8-N-1 transmission
        // -----------------------------------------------------------------
        test_num = 1;
        errors_in_test = 0;
        $display("\nTest %0d: 8-N-1 transmission (0x55, 0xAA)", test_num);
        apply_reset;

        // Send 0x55 with LCR=0x03 (8-N-1)
        push_byte(8'h55, 8'h03);
        wait_not_busy(2000);

        // Verify TXD returns to idle (1)
        check_signal("TXD_idle_after_0x55", 1, TXD);

        // Send 0xAA
        push_byte(8'hAA, 8'h03);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_0xAA", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 2: 5-bit data width
        // -----------------------------------------------------------------
        test_num = 2;
        errors_in_test = 0;
        $display("\nTest %0d: 5-bit data width", test_num);
        apply_reset;

        // LCR=0x00: 5 data bits, 1 stop, no parity
        push_byte(8'h1F, 8'h00);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_5bit", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 3: Even parity (8-E-1)
        // -----------------------------------------------------------------
        test_num = 3;
        errors_in_test = 0;
        $display("\nTest %0d: 8-E-1 (even parity)", test_num);
        apply_reset;

        // LCR=0x1B: 8 data, 1 stop, parity en, even (LCR[5:4]=01)
        push_byte(8'h55, 8'h1B);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_even_parity", 1, TXD);

        push_byte(8'h01, 8'h1B);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_even_parity_0x01", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 4: Odd parity (8-O-1)
        // -----------------------------------------------------------------
        test_num = 4;
        errors_in_test = 0;
        $display("\nTest %0d: 8-O-1 (odd parity)", test_num);
        apply_reset;

        // LCR=0x0B: 8 data, 1 stop, parity en, odd (LCR[5:4]=00)
        push_byte(8'h55, 8'h0B);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_odd_parity", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 5: Stick parity
        // -----------------------------------------------------------------
        test_num = 5;
        errors_in_test = 0;
        $display("\nTest %0d: Stick parity (high and low)", test_num);
        apply_reset;

        // Stick high: LCR=0x2B (LCR[5:4]=10)
        push_byte(8'h55, 8'h2B);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_stick_high", 1, TXD);

        // Stick low: LCR=0x3B (LCR[5:4]=11)
        push_byte(8'h55, 8'h3B);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_stick_low", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 6: 2 stop bits (8-N-2)
        // -----------------------------------------------------------------
        test_num = 6;
        errors_in_test = 0;
        $display("\nTest %0d: 8-N-2 (2 stop bits)", test_num);
        apply_reset;

        // LCR=0x07: 8 data, 2 stop, no parity
        push_byte(8'h55, 8'h07);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_2stop", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 7: 1.5 stop bits (5-N-1.5)
        // -----------------------------------------------------------------
        test_num = 7;
        errors_in_test = 0;
        $display("\nTest %0d: 5-N-1.5 (1.5 stop bits)", test_num);
        apply_reset;

        // LCR=0x04: 5 data, 1.5 stop, no parity
        push_byte(8'h15, 8'h04);
        wait_not_busy(2000);
        check_signal("TXD_idle_after_1.5stop", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 8: FIFO operation - push multiple bytes
        // -----------------------------------------------------------------
        test_num = 8;
        errors_in_test = 0;
        $display("\nTest %0d: FIFO operation (3 bytes)", test_num);
        apply_reset;

        // Push 3 bytes
        for (i = 0; i < 3; i = i + 1) begin
            push_byte(8'h10 + i, 8'h03);
        end

        // Wait for all 3 frames to complete
        wait_not_busy(6000);
        check_signal("TXD_idle_after_fifo", 1, TXD);
        check_signal("fifo_empty_after_tx", 1, tx_fifo_empty);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 9: FIFO full protection
        // -----------------------------------------------------------------
        test_num = 9;
        errors_in_test = 0;
        $display("\nTest %0d: FIFO full protection", test_num);
        apply_reset;

        // Disable transmission to fill FIFO
        enable = 0;
        LCR = 8'h03;

        // Push 16 bytes
        for (i = 0; i < 16; i = i + 1) begin
            PWDATA = i;
            tx_fifo_push = 1;
            @(posedge PCLK);
            tx_fifo_push = 0;
        end

        // Check FIFO full
        check_signal("fifo_full", 1, tx_fifo_full);
        check_signal("fifo_count_16", 16, tx_fifo_count);

        // Try overflow push
        PWDATA = 8'hFF;
        tx_fifo_push = 1;
        @(posedge PCLK);
        tx_fifo_push = 0;
        check_signal("fifo_count_after_overflow", 16, tx_fifo_count);

        // Re-enable and drain - wait for both busy=0 AND fifo_empty=1
        enable = 1;
        cycle_count = 0;
        while ((busy || !tx_fifo_empty) && cycle_count < 6000) begin
            @(posedge PCLK);
            cycle_count = cycle_count + 1;
        end
        // Extra cycles to ensure FSM returns to IDLE
        repeat(2) @(posedge PCLK);
        check_signal("fifo_empty_after_drain", 1, tx_fifo_empty);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 10: Enable pause during transmission
        // -----------------------------------------------------------------
        test_num = 10;
        errors_in_test = 0;
        $display("\nTest %0d: Enable pause during TX", test_num);
        apply_reset;

        push_byte(8'h55, 8'h03);

        // Let it run for 5 cycles
        repeat(5) @(posedge PCLK);

        // Pause
        enable = 0;
        repeat(20) @(posedge PCLK);

        // Resume
        enable = 1;
        wait_not_busy(2000);
        check_signal("TXD_idle_after_pause_resume", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 11: Reset during transmission
        // -----------------------------------------------------------------
        test_num = 11;
        errors_in_test = 0;
        $display("\nTest %0d: Reset during TX", test_num);
        apply_reset;

        push_byte(8'h55, 8'h03);
        repeat(10) @(posedge PCLK);

        // Apply reset mid-transmission
        apply_reset;
        check_signal("TXD_after_reset", 1, TXD);
        check_signal("busy_after_reset", 0, busy);
        check_signal("fifo_empty_after_reset", 1, tx_fifo_empty);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 12: LCR dynamic switch
        // -----------------------------------------------------------------
        test_num = 12;
        errors_in_test = 0;
        $display("\nTest %0d: LCR dynamic switch", test_num);
        apply_reset;

        // First frame: 8-N-1
        push_byte(8'h55, 8'h03);
        wait_not_busy(2000);
        check_signal("TXD_idle_8N1", 1, TXD);

        // Second frame: 8-E-1
        push_byte(8'hAA, 8'h1B);
        wait_not_busy(2000);
        check_signal("TXD_idle_8E1", 1, TXD);

        // Third frame: 5-N-1
        push_byte(8'h15, 8'h00);
        wait_not_busy(2000);
        check_signal("TXD_idle_5N1", 1, TXD);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 13: TXD bit sequence verification for 8-N-1
        // -----------------------------------------------------------------
        test_num = 13;
        errors_in_test = 0;
        $display("\nTest %0d: TXD bit sequence 8-N-1 (0x55)", test_num);
        apply_reset;

        // 0x55 = 01010101, LSB first: 1,0,1,0,1,0,1,0
        // Expected frame: Start(0), D0(1), D1(0), D2(1), D3(0), D4(1), D5(0), D6(1), D7(0), Stop(1)
        // = 0,1,0,1,0,1,0,1,0,1

        push_byte(8'h55, 8'h03);

        // Wait for busy to go high and TXD to go low (START bit begins)
        while (!busy) @(posedge PCLK);
        while (TXD) @(posedge PCLK);

        // Now TXD is low = START bit. Sample from midbit of START.
        // We're at the beginning of START bit period. Wait 7 cycles to midbit.
        repeat(7) @(posedge PCLK);
        // Sample START at midbit
        check_signal("Start_bit", 0, TXD);
        // Wait 9 cycles to reach next bit period start
        // (8 remaining in current bit + 1 to next bit start)
        repeat(9) @(posedge PCLK);

        // Now at beginning of D0. Sample each data bit at midbit.
        // D0 = 1 (LSB of 0x55)
        repeat(7) @(posedge PCLK);
        check_signal("D0", 1, TXD);
        repeat(9) @(posedge PCLK);

        // D1 = 0
        repeat(7) @(posedge PCLK);
        check_signal("D1", 0, TXD);
        repeat(9) @(posedge PCLK);

        // D2 = 1
        repeat(7) @(posedge PCLK);
        check_signal("D2", 1, TXD);
        repeat(9) @(posedge PCLK);

        // D3 = 0
        repeat(7) @(posedge PCLK);
        check_signal("D3", 0, TXD);
        repeat(9) @(posedge PCLK);

        // D4 = 1
        repeat(7) @(posedge PCLK);
        check_signal("D4", 1, TXD);
        repeat(9) @(posedge PCLK);

        // D5 = 0
        repeat(7) @(posedge PCLK);
        check_signal("D5", 0, TXD);
        repeat(9) @(posedge PCLK);

        // D6 = 1
        repeat(7) @(posedge PCLK);
        check_signal("D6", 1, TXD);
        repeat(9) @(posedge PCLK);

        // D7 = 0
        repeat(7) @(posedge PCLK);
        check_signal("D7", 0, TXD);
        repeat(9) @(posedge PCLK);

        // Stop = 1
        repeat(7) @(posedge PCLK);
        check_signal("Stop_bit", 1, TXD);

        wait_not_busy(2000);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Test 14: TXD bit sequence with even parity (0x01)
        // -----------------------------------------------------------------
        test_num = 14;
        errors_in_test = 0;
        $display("\nTest %0d: TXD bit sequence 8-E-1 (0x01)", test_num);
        apply_reset;

        // 0x01 = 00000001, LSB first: 1,0,0,0,0,0,0,0
        // Even parity: 1 one -> parity = 1 (to make total even)
        // Expected: Start(0), D0(1), D1-D7(0), Parity(1), Stop(1)
        // = 0,1,0,0,0,0,0,0,0,1,1

        push_byte(8'h01, 8'h1B);

        // Wait for busy to go high and TXD to go low (START bit begins)
        while (!busy) @(posedge PCLK);
        while (TXD) @(posedge PCLK);

        // Now at START bit first cycle. Use sample_frame to sample all 11 bits.
        sample_frame(11, sampled_txd);

        check_signal("Start_bit", 0, sampled_txd[0]);
        check_signal("D0", 1, sampled_txd[1]);
        check_signal("D1", 0, sampled_txd[2]);
        check_signal("D2", 0, sampled_txd[3]);
        check_signal("D3", 0, sampled_txd[4]);
        check_signal("D4", 0, sampled_txd[5]);
        check_signal("D5", 0, sampled_txd[6]);
        check_signal("D6", 0, sampled_txd[7]);
        check_signal("D7", 0, sampled_txd[8]);
        check_signal("Parity_even", 1, sampled_txd[9]);
        check_signal("Stop_bit", 1, sampled_txd[10]);

        wait_not_busy(2000);

        if (errors_in_test == 0) $display("  Test %0d: PASS", test_num);
        else $display("  Test %0d: FAIL (%0d errors)", test_num, errors_in_test);

        // -----------------------------------------------------------------
        // Final Summary
        // -----------------------------------------------------------------
        $display("\n========================================");
        $display("UART TX Testbench Summary");
        $display("  Total checks passed: %0d", pass_count);
        $display("  Total checks failed: %0d", fail_count);
        if (fail_count == 0)
            $display("  RESULT: ALL TESTS PASSED");
        else
            $display("  RESULT: SOME TESTS FAILED");
        $display("========================================");

        #100;
        $finish;
    end

endmodule