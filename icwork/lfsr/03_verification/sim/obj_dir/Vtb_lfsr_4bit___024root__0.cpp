// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_lfsr_4bit.h for the primary calling header

#include "Vtb_lfsr_4bit__pch.h"

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_initial__TOP(Vtb_lfsr_4bit___024root* vlSelf);
VlCoroutine Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__0(Vtb_lfsr_4bit___024root* vlSelf);
VlCoroutine Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__1(Vtb_lfsr_4bit___024root* vlSelf);
VlCoroutine Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__2(Vtb_lfsr_4bit___024root* vlSelf);

void Vtb_lfsr_4bit___024root___eval_initial(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_initial\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_lfsr_4bit___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__0(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lfsr_4bit__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                             20);
        vlSelfRef.tb_lfsr_4bit__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk)));
    }
    co_return;
}

VlCoroutine Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__1(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                         27);
    VL_WRITEF_NX("[ERROR] Simulation timeout at %0t\n",0,
                 64,VL_TIME_UNITED_Q(1),-12);
    VL_FINISH_MT("/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 30, "");
    co_return;
}

void Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(Vtb_lfsr_4bit___024root* vlSelf, const char* __VeventDescription);
void Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afde3__0(Vtb_lfsr_4bit___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__2(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    // Body
    VL_WRITEF_NX("\n========================================\n4-bit LFSR TestBench\nCharacteristic Polynomial: x^4 + x + 1\nMaximum Period: 15 cycles\n========================================\nStart time: %0t\n",0,
                 64,VL_TIME_UNITED_Q(1),-12);
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[0U] = 0x0fU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[1U] = 7U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[1U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[2U] = 0x0bU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[2U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[3U] = 5U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[3U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[4U] = 0x0aU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[4U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[5U] = 0x0dU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[5U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[6U] = 6U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[6U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[7U] = 3U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[7U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[8U] = 9U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[8U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[9U] = 4U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[9U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[10U] = 2U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[10U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[11U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[11U] = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[12U] = 8U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[12U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[13U] = 0x0cU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[13U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[14U] = 0x0eU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[14U] = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_d[15U] = 0x0fU;
    vlSelfRef.tb_lfsr_4bit__DOT__expected_y[15U] = 1U;
    VL_WRITEF_NX("\n========================================\nTEST 1: Reset Initialization\n========================================\n",0);
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    VL_WRITEF_NX("[INFO] Applying reset...\n",0);
    vlSelfRef.tb_lfsr_4bit__DOT__res = 0U;
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                        "@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         72);
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afde3__0(vlSelf, 
                                                        "@(negedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afde3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         74);
    vlSelfRef.tb_lfsr_4bit__DOT__res = 1U;
    VL_WRITEF_NX("[INFO] Reset released at time %0t\n",0,
                 64,VL_TIME_UNITED_Q(1),-12);
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                        "@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         88);
    if ((1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d))) {
        VL_WRITEF_NX("[PASS] Reset test: y=%b (expected 1)\n",0,
                     1,(1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)));
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Reset test: y=%b (expected 1)\n",0,
                     1,(1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)));
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    VL_WRITEF_NX("----------------------------------------\n",0);
    VL_WRITEF_NX("\n========================================\nTEST 2: Full Sequence Verification\n========================================\n",0);
    VL_WRITEF_NX("[INFO] Applying reset...\n",0);
    vlSelfRef.tb_lfsr_4bit__DOT__res = 0U;
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                        "@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         72);
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afde3__0(vlSelf, 
                                                        "@(negedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afde3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         74);
    vlSelfRef.tb_lfsr_4bit__DOT__res = 1U;
    VL_WRITEF_NX("[INFO] Reset released at time %0t\n",0,
                 64,VL_TIME_UNITED_Q(1),-12);
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0U;
    while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle)) {
        Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                            "@(posedge tb_lfsr_4bit.clk)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_lfsr_4bit.clk)", 
                                                             "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                             113);
        vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[(0x0000000fU 
                                                                           & vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle)] 
            = (1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d));
        VL_WRITEF_NX("[INFO] Cycle %2d: y=%b (expected y=%b)\n",0,
                     32,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle,
                     1,(1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)),
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y
                     [(0x0000000fU & vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle)]);
        vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle 
            = ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle);
    }
    VL_WRITEF_NX("\nSequence Comparison:\n----------------------------------------\n",0);
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[0U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0U])) {
        VL_WRITEF_NX("[PASS] Cycle  0: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[0U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  0: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[0U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 1U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[1U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[1U])) {
        VL_WRITEF_NX("[PASS] Cycle  1: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[1U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  1: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[1U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[1U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 2U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[2U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[2U])) {
        VL_WRITEF_NX("[PASS] Cycle  2: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[2U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  2: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[2U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[2U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 3U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[3U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[3U])) {
        VL_WRITEF_NX("[PASS] Cycle  3: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[3U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  3: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[3U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[3U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 4U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[4U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[4U])) {
        VL_WRITEF_NX("[PASS] Cycle  4: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[4U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  4: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[4U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[4U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 5U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[5U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[5U])) {
        VL_WRITEF_NX("[PASS] Cycle  5: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[5U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  5: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[5U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[5U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 6U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[6U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[6U])) {
        VL_WRITEF_NX("[PASS] Cycle  6: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[6U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  6: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[6U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[6U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 7U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[7U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[7U])) {
        VL_WRITEF_NX("[PASS] Cycle  7: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[7U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  7: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[7U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[7U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 8U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[8U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[8U])) {
        VL_WRITEF_NX("[PASS] Cycle  8: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[8U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  8: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[8U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[8U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 9U;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[9U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[9U])) {
        VL_WRITEF_NX("[PASS] Cycle  9: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[9U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle  9: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[9U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[9U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0x0000000aU;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[10U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[10U])) {
        VL_WRITEF_NX("[PASS] Cycle 10: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[10U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle 10: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[10U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[10U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0x0000000bU;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[11U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[11U])) {
        VL_WRITEF_NX("[PASS] Cycle 11: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[11U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle 11: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[11U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[11U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0x0000000cU;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[12U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[12U])) {
        VL_WRITEF_NX("[PASS] Cycle 12: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[12U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle 12: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[12U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[12U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0x0000000dU;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[13U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[13U])) {
        VL_WRITEF_NX("[PASS] Cycle 13: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[13U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle 13: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[13U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[13U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0x0000000eU;
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if ((vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[14U] 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[14U])) {
        VL_WRITEF_NX("[PASS] Cycle 14: y=%b matches expected\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[14U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Cycle 14: y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[14U],
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[14U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = 0x0000000fU;
    VL_WRITEF_NX("----------------------------------------\n",0);
    __Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    VL_WRITEF_NX("\n========================================\nTEST 3: Periodicity Verification\n========================================\n",0);
    VL_WRITEF_NX("[INFO] Applying reset...\n",0);
    vlSelfRef.tb_lfsr_4bit__DOT__res = 0U;
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                        "@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         72);
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afde3__0(vlSelf, 
                                                        "@(negedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afde3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         74);
    vlSelfRef.tb_lfsr_4bit__DOT__res = 1U;
    VL_WRITEF_NX("[INFO] Reset released at time %0t\n",0,
                 64,VL_TIME_UNITED_Q(1),-12);
    __Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0x0000000fU;
    while (VL_LTS_III(32, 0U, __Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                            "@(posedge tb_lfsr_4bit.clk)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_lfsr_4bit.clk)", 
                                                             "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                             145);
        __Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_lfsr_4bit__DOT__test_periodicity__5__tb_lfsr_4bit__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_15 
        = (1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d));
    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                        "@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_lfsr_4bit.clk)", 
                                                         "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                         148);
    vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16 
        = (1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d));
    VL_WRITEF_NX("[INFO] y at cycle 15: %b\n[INFO] y at cycle 16: %b\n",0,
                 1,vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_15,
                 1,(IData)(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16));
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = ((IData)(1U) 
                                                + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
    if (((IData)(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16) 
         == vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0U])) {
        VL_WRITEF_NX("[PASS] Periodicity: cycle 16 y=%b matches cycle 0 y=%b\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0U]);
        vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
    } else {
        VL_WRITEF_NX("[FAIL] Periodicity: cycle 16 y=%b (expected %b)\n",0,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16,
                     1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0U]);
        vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    }
    VL_WRITEF_NX("\nExtended Periodicity Check (cycles 16-30):\n----------------------------------------\n",0);
    vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle = 0x00000010U;
    while (VL_GTS_III(32, 0x0000001eU, vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle)) {
        Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(vlSelf, 
                                                            "@(posedge tb_lfsr_4bit.clk)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_ha65afd0f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_lfsr_4bit.clk)", 
                                                             "/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 
                                                             169);
        vlSelfRef.tb_lfsr_4bit__DOT__total_tests = 
            ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__total_tests);
        if (((1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)) 
             == vlSelfRef.tb_lfsr_4bit__DOT__expected_y
             [(0x0000000fU & VL_MODDIVS_III(32, vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle, (IData)(0x0000000fU)))])) {
            VL_WRITEF_NX("[PASS] Cycle %2d: y=%b matches expected y[%0d]=%b\n",0,
                         32,vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle,
                         1,(1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)),
                         32,VL_MODDIVS_III(32, vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle, (IData)(0x0000000fU)),
                         1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y
                         [(0x0000000fU & VL_MODDIVS_III(32, vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle, (IData)(0x0000000fU)))]);
            vlSelfRef.tb_lfsr_4bit__DOT__passed_tests 
                = ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__passed_tests);
        } else {
            VL_WRITEF_NX("[FAIL] Cycle %2d: y=%b (expected y[%0d]=%b)\n",0,
                         32,vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle,
                         1,(1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)),
                         32,VL_MODDIVS_III(32, vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle, (IData)(0x0000000fU)),
                         1,vlSelfRef.tb_lfsr_4bit__DOT__expected_y
                         [(0x0000000fU & VL_MODDIVS_III(32, vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle, (IData)(0x0000000fU)))]);
            vlSelfRef.tb_lfsr_4bit__DOT__failed_tests 
                = ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
        }
        vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle 
            = ((IData)(1U) + vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle);
    }
    VL_WRITEF_NX("----------------------------------------\n",0);
    VL_WRITEF_NX("\n========================================\nTEST SUMMARY\n========================================\n  Total Tests:  %0d\n  Passed:       %0d\n  Failed:       %0d\n----------------------------------------\n",0,
                 32,vlSelfRef.tb_lfsr_4bit__DOT__total_tests,
                 32,vlSelfRef.tb_lfsr_4bit__DOT__passed_tests,
                 32,vlSelfRef.tb_lfsr_4bit__DOT__failed_tests);
    if ((0U == vlSelfRef.tb_lfsr_4bit__DOT__failed_tests)) {
        VL_WRITEF_NX("\n  ==============================\n  ALL TESTS PASSED\n  ==============================\n\n",0);
    } else {
        VL_WRITEF_NX("\n  ==============================\n  SOME TESTS FAILED\n  ==============================\n\n",0);
    }
    VL_WRITEF_NX("End time: %0t\n========================================\n",0,
                 64,VL_TIME_UNITED_Q(1),-12);
    VL_FINISH_MT("/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 226, "");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_return;
}

void Vtb_lfsr_4bit___024root___eval_triggers_vec__act(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_triggers_vec__act\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((((~ (IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk)) 
                                                        & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0)) 
                                                       << 3U) 
                                                      | (vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                         << 2U)) 
                                                     | ((((~ (IData)(vlSelfRef.tb_lfsr_4bit__DOT__res)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__res__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0 
        = vlSelfRef.tb_lfsr_4bit__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__res__0 
        = vlSelfRef.tb_lfsr_4bit__DOT__res;
}

bool Vtb_lfsr_4bit___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_lfsr_4bit___024root___nba_sequent__TOP__0(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___nba_sequent__TOP__0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d = ((IData)(vlSelfRef.tb_lfsr_4bit__DOT__res)
                                                 ? 
                                                ((8U 
                                                  & ((((IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d) 
                                                       >> 3U) 
                                                      + (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d)) 
                                                     << 3U)) 
                                                 | (7U 
                                                    & ((IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d) 
                                                       >> 1U)))
                                                 : 0x0fU);
}

void Vtb_lfsr_4bit___024root___eval_nba(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_nba\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_lfsr_4bit___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtb_lfsr_4bit___024root___timing_ready(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___timing_ready\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready("@(posedge tb_lfsr_4bit.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_ha65afde3__0.ready("@(negedge tb_lfsr_4bit.clk)");
    }
}

void Vtb_lfsr_4bit___024root___timing_resume(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___timing_resume\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_ha65afd0f__0.moveToResumeQueue(
                                                          "@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__VtrigSched_ha65afde3__0.moveToResumeQueue(
                                                          "@(negedge tb_lfsr_4bit.clk)");
    vlSelfRef.__VtrigSched_ha65afd0f__0.resume("@(posedge tb_lfsr_4bit.clk)");
    vlSelfRef.__VtrigSched_ha65afde3__0.resume("@(negedge tb_lfsr_4bit.clk)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_lfsr_4bit___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lfsr_4bit___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_lfsr_4bit___024root___eval_phase__act(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_phase__act\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_lfsr_4bit___024root___eval_triggers_vec__act(vlSelf);
    Vtb_lfsr_4bit___024root___timing_ready(vlSelf);
    Vtb_lfsr_4bit___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_lfsr_4bit___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_lfsr_4bit___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_lfsr_4bit___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_lfsr_4bit___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_lfsr_4bit___024root___eval_phase__inact(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_phase__inact\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 1, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_lfsr_4bit___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_lfsr_4bit___024root___eval_phase__nba(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_phase__nba\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_lfsr_4bit___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_lfsr_4bit___024root___eval_nba(vlSelf);
        Vtb_lfsr_4bit___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_lfsr_4bit___024root___eval(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_lfsr_4bit___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 1, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_lfsr_4bit___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/chipos_verilator_88nb6lsx/temp_tb_lfsr_4bit.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_lfsr_4bit___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_lfsr_4bit___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_lfsr_4bit___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0(Vtb_lfsr_4bit___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afd0f__0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0)) 
                                   << 3U) | ((IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0 
        = vlSelfRef.tb_lfsr_4bit__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
    }
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_ha65afde3__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afde3__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afde3__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afde3__0(Vtb_lfsr_4bit___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root____VbeforeTrig_ha65afde3__0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0)) 
                                   << 3U) | ((IData)(vlSelfRef.tb_lfsr_4bit__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0 
        = vlSelfRef.tb_lfsr_4bit__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afd0f__0.ready(__VeventDescription);
    }
    if ((8ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_ha65afde3__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afde3__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_ha65afde3__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_lfsr_4bit___024root___eval_debug_assertions(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_debug_assertions\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
