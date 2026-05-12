//============================================================================
// Testbench: tb_uart_tx
// Description: Direct Verilog testbench for uart_tx module
//   - 14 test cases covering FIFO, frame format, parity, stop bits, enable, reset
//   - Midbit sampling (8th cycle of each 16-cycle bit period)
//   - Self-checking with expected vs actual comparison
//============================================================================

`timescale 1ns/1ps

module tb_uart_tx;

    //------------------------------------------------------------------------
    // Parameters
    //------------------------------------------------------------------------
    parameter CLK_PERIOD = 10;  // 10ns per PCLK cycle

    //------------------------------------------------------------------------
    // DUT Signals
    //------------------------------------------------------------------------
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

    //------------------------------------------------------------------------
    // DUT Instance
    //------------------------------------------------------------------------
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

    //------------------------------------------------------------------------
    // Clock Generation
    //------------------------------------------------------------------------
    initial PCLK = 0;
    always #(CLK_PERIOD/2) PCLK = ~PCLK;

    //------------------------------------------------------------------------
    // Test Variables
    //------------------------------------------------------------------------
    integer test_num;
    integer pass_count;
    integer fail_count;
    integer err_flag;
    integer i;

    reg [15:0] sampled_frame;  // Captured frame bits
    reg [15:0] expected_frame;

    //------------------------------------------------------------------------
    // Helper Tasks
    //------------------------------------------------------------------------

    // Reset sequence
    task do_reset;
        begin
            PRESETn = 0;
            PWDATA  = 0;
            tx_fifo_push = 0;
            LCR    = 8'h03;  // Default: 8N1
            enable = 1;
            #(CLK_PERIOD * 5);
            PRESETn = 1;
            #(CLK_PERIOD * 2);
        end
    endtask

    // Push one byte into FIFO
    task push_byte;
        input [7:0] data;
        input [7:0] lcr_val;
        begin
            LCR = lcr_val;
            @(posedge PCLK);
            PWDATA = data;
            tx_fifo_push = 1;
            @(posedge PCLK);
            tx_fifo_push = 0;
            PWDATA = 0;
        end
    endtask

    // Wait for busy to go low (with timeout)
    task wait_not_busy;
        input integer max_cycles;
        integer i;
        begin
            for (i = 0; i < max_cycles; i = i + 1) begin
                @(posedge PCLK);
                if (!busy) i = max_cycles;  // Break out
            end
        end
    endtask

    // Sample a complete UART frame at midbit (8th cycle of each 16-cycle period)
    // Returns sampled bits in sampled_frame[15:0]
    // Format: [Start, D0, D1, D2, D3, D4, D5, D6, D7, Parity, Stop1, Stop2, ...]
    task sample_frame;
        input [7:0] lcr_val;
        integer num_data_bits;
        integer num_bits_to_sample;
        integer i;
        reg [15:0] frame;
        begin
            // Wait for busy to go high
            while (!busy) @(posedge PCLK);
            // Wait for TXD to go low (start bit begins)
            while (TXD) @(posedge PCLK);
            // Now at the first cycle of start bit
            // Wait 7 more cycles to reach midbit of start bit
            repeat(7) @(posedge PCLK);

            frame = 0;
            num_data_bits = (lcr_val[1:0] == 2'b00) ? 5 :
                           (lcr_val[1:0] == 2'b01) ? 6 :
                           (lcr_val[1:0] == 2'b10) ? 7 : 8;

            // Total bits to sample: start + data + parity(if enabled) + stop1
            num_bits_to_sample = 1 + num_data_bits;
            if (lcr_val[3]) num_bits_to_sample = num_bits_to_sample + 1;  // parity
            num_bits_to_sample = num_bits_to_sample + 1;  // at least 1 stop bit

            // Sample each bit at midbit
            for (i = 0; i < num_bits_to_sample; i = i + 1) begin
                frame[i] = TXD;
                // Move to midbit of next bit period (16 cycles)
                repeat(16) @(posedge PCLK);
            end

            sampled_frame = frame;
        end
    endtask

    // Compute expected frame from data and LCR
    task compute_expected_frame;
        input [7:0] data;
        input [7:0] lcr_val;
        integer num_data_bits;
        integer i;
        reg [15:0] frame;
        reg parity_bit;
        begin
            frame = 0;
            frame[0] = 0;  // Start bit = 0

            num_data_bits = (lcr_val[1:0] == 2'b00) ? 5 :
                           (lcr_val[1:0] == 2'b01) ? 6 :
                           (lcr_val[1:0] == 2'b10) ? 7 : 8;

            // Data bits (LSB first)
            for (i = 0; i < num_data_bits; i = i + 1) begin
                frame[i + 1] = data[i];
            end

            // Parity bit — must match RTL: ^tx_buffer where unused high bits are zeroed
            if (lcr_val[3]) begin
                reg [7:0] masked_data;
                // Zero out unused high bits, same as RTL does in BIT states
                masked_data = data;
                if (num_data_bits == 5) masked_data[7:5] = 3'b000;
                else if (num_data_bits == 6) masked_data[7:6] = 2'b00;
                else if (num_data_bits == 7) masked_data[7] = 1'b0;
                // num_data_bits == 8: no masking needed
                case (lcr_val[5:4])
                    2'b00: parity_bit = ^masked_data;   // Even parity
                    2'b01: parity_bit = ~(^masked_data); // Odd parity
                    2'b10: parity_bit = 1;               // Stick '1'
                    2'b11: parity_bit = 0;               // Stick '0'
                    default: parity_bit = ^masked_data;
                endcase
                frame[num_data_bits + 1] = parity_bit;
                frame[num_data_bits + 2] = 1;  // Stop bit = 1
            end else begin
                frame[num_data_bits + 1] = 1;  // Stop bit = 1
            end

            expected_frame = frame;
        end
    endtask

    // Check sampled frame against expected
    task check_frame;
        input [7:0] data;
        input [7:0] lcr_val;
        integer num_data_bits;
        integer num_bits_to_check;
        integer i;
        integer bit_errors;
        begin
            compute_expected_frame(data, lcr_val);

            num_data_bits = (lcr_val[1:0] == 2'b00) ? 5 :
                           (lcr_val[1:0] == 2'b01) ? 6 :
                           (lcr_val[1:0] == 2'b10) ? 7 : 8;

            num_bits_to_check = 1 + num_data_bits;
            if (lcr_val[3]) num_bits_to_check = num_bits_to_check + 1;
            num_bits_to_check = num_bits_to_check + 1;

            bit_errors = 0;
            for (i = 0; i < num_bits_to_check; i = i + 1) begin
                if (sampled_frame[i] !== expected_frame[i]) begin
                    $display("  [FAIL] Bit %0d: expected=%0d actual=%0d",
                             i, expected_frame[i], sampled_frame[i]);
                    bit_errors = bit_errors + 1;
                end
            end

            if (bit_errors == 0) begin
                $display("  [PASS] Frame matches expected");
                pass_count = pass_count + 1;
            end else begin
                fail_count = fail_count + 1;
            end
        end
    endtask

    //------------------------------------------------------------------------
    // Main Test Sequence
    //------------------------------------------------------------------------
    initial begin
        pass_count = 0;
        fail_count = 0;
        $dumpfile("test5_8n1_0x55.vcd");
        $dumpvars(0, dut);
        $display("============================================");
        $display("  UART TX Testbench - Start");
        $display("============================================");

        //=============================================================
        // Test 1: Reset verification
        //=============================================================
        test_num = 1;
        $display("\n--- Test %0d: Reset ---", test_num);
        do_reset;
        if (TXD !== 1'b1 || busy !== 1'b0 || tx_fifo_empty !== 1'b1) begin
            $display("  [FAIL] After reset: TXD=%b busy=%b empty=%b (expected: 1,0,1)",
                     TXD, busy, tx_fifo_empty);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] Reset state correct");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Test 2: FIFO push & count
        //=============================================================
        test_num = 2;
        $display("\n--- Test %0d: FIFO Push & Count ---", test_num);
        do_reset;
        enable = 0;  // Disable FSM to prevent it from consuming FIFO data
        push_byte(8'hAA, 8'h03);
        #(CLK_PERIOD * 2);
        if (tx_fifo_count !== 5'd1 || tx_fifo_empty !== 1'b0) begin
            $display("  [FAIL] After 1 push: count=%0d empty=%b (expected: 1,0)",
                     tx_fifo_count, tx_fifo_empty);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] FIFO count=1, empty=0");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Test 3: FIFO full
        //=============================================================
        test_num = 3;
        $display("\n--- Test %0d: FIFO Full ---", test_num);
        do_reset;
        enable = 0;  // Disable FSM to prevent it from consuming FIFO data
        for (i = 0; i < 16; i = i + 1) begin
            push_byte(i[7:0], 8'h03);
            #(CLK_PERIOD);
        end
        #(CLK_PERIOD * 2);
        if (tx_fifo_full !== 1'b1 || tx_fifo_count !== 5'd16) begin
            $display("  [FAIL] After 16 pushes: full=%b count=%0d (expected: 1,16)",
                     tx_fifo_full, tx_fifo_count);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] FIFO full=1, count=16");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Test 4: FIFO overflow protection
        //=============================================================
        test_num = 4;
        $display("\n--- Test %0d: FIFO Overflow ---", test_num);
        do_reset;
        enable = 0;  // Disable FSM to prevent it from consuming FIFO data
        for (i = 0; i < 16; i = i + 1) begin
            push_byte(i[7:0], 8'h03);
            #(CLK_PERIOD);
        end
        // Try to push when full
        push_byte(8'hFF, 8'h03);
        #(CLK_PERIOD * 2);
        if (tx_fifo_count !== 5'd16) begin
            $display("  [FAIL] After overflow push: count=%0d (expected: 16)",
                     tx_fifo_count);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] Overflow protected, count still 16");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Test 5: 8N1 frame (8 data, no parity, 1 stop)
        //=============================================================
        test_num = 5;
        $display("\n--- Test %0d: 8N1 Frame (0x55) ---", test_num);
        do_reset;
        push_byte(8'h55, 8'h03);  // LCR=0x03: 8-bit, 1 stop, no parity
        sample_frame(8'h03);
        check_frame(8'h55, 8'h03);

        //=============================================================
        // Test 6: 8E1 frame (8 data, even parity, 1 stop)
        //=============================================================
        test_num = 6;
        $display("\n--- Test %0d: 8E1 Frame (0x55) ---", test_num);
        do_reset;
        push_byte(8'h55, 8'h1B);  // LCR=0x1B: 8-bit, 1 stop, even parity
        sample_frame(8'h1B);
        check_frame(8'h55, 8'h1B);

        //=============================================================
        // Test 7: 8O1 frame (8 data, odd parity, 1 stop)
        //=============================================================
        test_num = 7;
        $display("\n--- Test %0d: 8O1 Frame (0x55) ---", test_num);
        do_reset;
        push_byte(8'h55, 8'h2B);  // LCR=0x2B: 8-bit, 1 stop, odd parity
        sample_frame(8'h2B);
        check_frame(8'h55, 8'h2B);

        //=============================================================
        // Test 8: 5N1 frame (5 data, no parity, 1 stop)
        //=============================================================
        test_num = 8;
        $display("\n--- Test %0d: 5N1 Frame (0x1F) ---", test_num);
        do_reset;
        push_byte(8'h1F, 8'h00);  // LCR=0x00: 5-bit, 1 stop, no parity
        sample_frame(8'h00);
        check_frame(8'h1F, 8'h00);

        //=============================================================
        // Test 9: FIFO drain — push 2 bytes, wait for both to send
        //=============================================================
        test_num = 9;
        $display("\n--- Test %0d: FIFO Drain (2 bytes) ---", test_num);
        do_reset;
        push_byte(8'hAA, 8'h03);
        push_byte(8'hBB, 8'h03);
        // Wait for both frames to complete
        wait_not_busy(6000);
        #(CLK_PERIOD * 5);
        if (tx_fifo_empty !== 1'b1) begin
            $display("  [FAIL] After drain: empty=%b (expected: 1)", tx_fifo_empty);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] FIFO empty after drain");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Test 10: Enable pause/resume
        //=============================================================
        test_num = 10;
        $display("\n--- Test %0d: Enable Pause/Resume ---", test_num);
        do_reset;
        push_byte(8'h55, 8'h03);
        // Wait for busy to go high
        while (!busy) @(posedge PCLK);
        // Wait 5 bit periods into the frame
        repeat(5 * 16) @(posedge PCLK);
        // Pause
        enable = 0;
        #(CLK_PERIOD * 50);
        // Resume
        enable = 1;
        // Wait for frame to complete
        wait_not_busy(6000);
        #(CLK_PERIOD * 5);
        if (tx_fifo_empty !== 1'b1) begin
            $display("  [FAIL] After pause/resume: empty=%b", tx_fifo_empty);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] Frame completed after pause/resume");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Test 11: 6N1 frame
        //=============================================================
        test_num = 11;
        $display("\n--- Test %0d: 6N1 Frame (0x3F) ---", test_num);
        do_reset;
        push_byte(8'h3F, 8'h01);  // LCR=0x01: 6-bit, 1 stop, no parity
        sample_frame(8'h01);
        check_frame(8'h3F, 8'h01);

        //=============================================================
        // Test 12: 7N1 frame
        //=============================================================
        test_num = 12;
        $display("\n--- Test %0d: 7N1 Frame (0x7F) ---", test_num);
        do_reset;
        push_byte(8'h7F, 8'h02);  // LCR=0x02: 7-bit, 1 stop, no parity
        sample_frame(8'h02);
        check_frame(8'h7F, 8'h02);

        //=============================================================
        // Test 13: 8N1 frame with 0x00 (all zeros)
        //=============================================================
        test_num = 13;
        $display("\n--- Test %0d: 8N1 Frame (0x00) ---", test_num);
        do_reset;
        push_byte(8'h00, 8'h03);
        sample_frame(8'h03);
        check_frame(8'h00, 8'h03);

        //=============================================================
        // Test 14: 8E1.5 frame (even parity, 1.5 stop bits)
        //=============================================================
        test_num = 14;
        $display("\n--- Test %0d: 5E1.5 Frame (0x1F) ---", test_num);
        do_reset;
        push_byte(8'h1F, 8'h07);  // LCR=0x07: 5-bit, 1.5 stop, even parity
        sample_frame(8'h07);
        check_frame(8'h1F, 8'h07);

        //=============================================================
        // Test 15: Mid-frame reset
        //=============================================================
        test_num = 15;
        $display("\n--- Test %0d: Mid-Frame Reset ---", test_num);
        do_reset;
        push_byte(8'h55, 8'h03);
        while (!busy) @(posedge PCLK);
        repeat(40) @(posedge PCLK);  // Mid-frame
        PRESETn = 0;
        #(CLK_PERIOD * 5);
        PRESETn = 1;
        #(CLK_PERIOD * 2);
        if (TXD !== 1'b1 || busy !== 1'b0) begin
            $display("  [FAIL] After mid-frame reset: TXD=%b busy=%b", TXD, busy);
            fail_count = fail_count + 1;
        end else begin
            $display("  [PASS] Reset recovered correctly");
            pass_count = pass_count + 1;
        end

        //=============================================================
        // Summary
        //=============================================================
        $display("\n============================================");
        $display("  UART TX Testbench - Summary");
        $display("  PASS: %0d  FAIL: %0d  Total: %0d",
                 pass_count, fail_count, pass_count + fail_count);
        $display("============================================");

        if (fail_count > 0)
            $display("  *** SOME TESTS FAILED ***");
        else
            $display("  *** ALL TESTS PASSED ***");

        #(CLK_PERIOD * 10);
        $finish;
    end

    endmodule