// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_initial__TOP(Vtb_uart_tx___024root* vlSelf);
VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_tx___024root* vlSelf);
VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1(Vtb_uart_tx___024root* vlSelf);

void Vtb_uart_tx___024root___eval_initial(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_uart_tx___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(Vtb_uart_tx___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_uart_tx__DOT__unnamedblk1_3__DOT____Vrepeat2;
    tb_uart_tx__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ tb_uart_tx__DOT__unnamedblk1_4__DOT____Vrepeat3;
    tb_uart_tx__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__2__data;
    __Vtask_tb_uart_tx__DOT__push_byte__2__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__2__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__2__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__4__data;
    __Vtask_tb_uart_tx__DOT__push_byte__4__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__4__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__4__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__6__data;
    __Vtask_tb_uart_tx__DOT__push_byte__6__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__6__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__6__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__7__data;
    __Vtask_tb_uart_tx__DOT__push_byte__7__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__7__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__7__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__9__data;
    __Vtask_tb_uart_tx__DOT__push_byte__9__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__9__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__9__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__11__data;
    __Vtask_tb_uart_tx__DOT__check_frame__11__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__14__data;
    __Vtask_tb_uart_tx__DOT__push_byte__14__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__14__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__14__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__16__data;
    __Vtask_tb_uart_tx__DOT__check_frame__16__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__19__data;
    __Vtask_tb_uart_tx__DOT__push_byte__19__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__19__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__19__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__21__data;
    __Vtask_tb_uart_tx__DOT__check_frame__21__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__24__data;
    __Vtask_tb_uart_tx__DOT__push_byte__24__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__24__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__24__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__26__data;
    __Vtask_tb_uart_tx__DOT__check_frame__26__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__29__data;
    __Vtask_tb_uart_tx__DOT__push_byte__29__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__29__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__29__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__30__data;
    __Vtask_tb_uart_tx__DOT__push_byte__30__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__30__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__30__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__wait_not_busy__31__max_cycles;
    __Vtask_tb_uart_tx__DOT__wait_not_busy__31__max_cycles = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__33__data;
    __Vtask_tb_uart_tx__DOT__push_byte__33__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__33__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__33__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__wait_not_busy__34__max_cycles;
    __Vtask_tb_uart_tx__DOT__wait_not_busy__34__max_cycles = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__36__data;
    __Vtask_tb_uart_tx__DOT__push_byte__36__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__36__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__36__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__38__data;
    __Vtask_tb_uart_tx__DOT__check_frame__38__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__41__data;
    __Vtask_tb_uart_tx__DOT__push_byte__41__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__41__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__41__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__43__data;
    __Vtask_tb_uart_tx__DOT__check_frame__43__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__46__data;
    __Vtask_tb_uart_tx__DOT__push_byte__46__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__46__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__46__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__48__data;
    __Vtask_tb_uart_tx__DOT__check_frame__48__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__51__data;
    __Vtask_tb_uart_tx__DOT__push_byte__51__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__51__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__51__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val;
    __Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__53__data;
    __Vtask_tb_uart_tx__DOT__check_frame__53__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val;
    __Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__data;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__56__data;
    __Vtask_tb_uart_tx__DOT__push_byte__56__data = 0;
    CData/*7:0*/ __Vtask_tb_uart_tx__DOT__push_byte__56__lcr_val;
    __Vtask_tb_uart_tx__DOT__push_byte__56__lcr_val = 0;
    // Body
    vlSelfRef.tb_uart_tx__DOT__pass_count = 0U;
    vlSelfRef.tb_uart_tx__DOT__fail_count = 0U;
    VL_WRITEF_NX("============================================\n  UART TX Testbench - Start\n============================================\n",0);
    vlSelfRef.tb_uart_tx__DOT__test_num = 1U;
    VL_WRITEF_NX("\n--- Test 1: Reset ---\n",0);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    if ((1U & (((~ (IData)(vlSelfRef.tb_uart_tx__DOT__TXD)) 
                | (IData)(vlSelfRef.tb_uart_tx__DOT__busy)) 
               | (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))))) {
        VL_WRITEF_NX("  [FAIL] After reset: TXD=%b busy=%b empty=%b (expected: 1,0,1)\n",0,
                     1,vlSelfRef.tb_uart_tx__DOT__TXD,
                     1,(IData)(vlSelfRef.tb_uart_tx__DOT__busy),
                     1,(0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)));
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    } else {
        VL_WRITEF_NX("  [PASS] Reset state correct\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 2U;
    VL_WRITEF_NX("\n--- Test %0d: FIFO Push & Count ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    vlSelfRef.tb_uart_tx__DOT__enable = 0U;
    __Vtask_tb_uart_tx__DOT__push_byte__2__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__2__data = 0xaaU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__2__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__2__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         268);
    if (((1U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)) 
         | (0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
        VL_WRITEF_NX("  [FAIL] After 1 push: count=%0# empty=%b (expected: 1,0)\n",0,
                     5,vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count,
                     1,(0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)));
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    } else {
        VL_WRITEF_NX("  [PASS] FIFO count=1, empty=0\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 3U;
    VL_WRITEF_NX("\n--- Test %0d: FIFO Full ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    vlSelfRef.tb_uart_tx__DOT__enable = 0U;
    vlSelfRef.tb_uart_tx__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.tb_uart_tx__DOT__i)) {
        __Vtask_tb_uart_tx__DOT__push_byte__4__lcr_val = 3U;
        __Vtask_tb_uart_tx__DOT__push_byte__4__data 
            = (0x000000ffU & vlSelfRef.tb_uart_tx__DOT__i);
        vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__4__lcr_val;
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             91);
        vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__4__data;
        vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             94);
        vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
        vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                             287);
        vlSelfRef.tb_uart_tx__DOT__i = ((IData)(1U) 
                                        + vlSelfRef.tb_uart_tx__DOT__i);
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         289);
    if ((IData)((0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
        VL_WRITEF_NX("  [FAIL] After 16 pushes: full=%b count=%0# (expected: 1,16)\n",0,
                     1,(0x10U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)),
                     5,(IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count));
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    } else {
        VL_WRITEF_NX("  [PASS] FIFO full=1, count=16\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 4U;
    VL_WRITEF_NX("\n--- Test %0d: FIFO Overflow ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    vlSelfRef.tb_uart_tx__DOT__enable = 0U;
    vlSelfRef.tb_uart_tx__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00000010U, vlSelfRef.tb_uart_tx__DOT__i)) {
        __Vtask_tb_uart_tx__DOT__push_byte__6__lcr_val = 3U;
        __Vtask_tb_uart_tx__DOT__push_byte__6__data 
            = (0x000000ffU & vlSelfRef.tb_uart_tx__DOT__i);
        vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__6__lcr_val;
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             91);
        vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__6__data;
        vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             94);
        vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
        vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                             308);
        vlSelfRef.tb_uart_tx__DOT__i = ((IData)(1U) 
                                        + vlSelfRef.tb_uart_tx__DOT__i);
    }
    __Vtask_tb_uart_tx__DOT__push_byte__7__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__7__data = 0xffU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__7__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__7__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         312);
    if ((0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) {
        VL_WRITEF_NX("  [FAIL] After overflow push: count=%0# (expected: 16)\n",0,
                     5,vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count);
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    } else {
        VL_WRITEF_NX("  [PASS] Overflow protected, count still 16\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 5U;
    VL_WRITEF_NX("\n--- Test %0d: 8N1 Frame (0x55) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__9__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__9__data = 0x55U;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__9__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__9__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__10__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__10__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__check_frame__11__data = 0x55U;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__11__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__12__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__12__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__11__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 6U;
    VL_WRITEF_NX("\n--- Test %0d: 8E1 Frame (0x55) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__14__lcr_val = 0x1bU;
    __Vtask_tb_uart_tx__DOT__push_byte__14__data = 0x55U;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__14__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__14__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val = 0x1bU;
    __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__15__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__15__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val = 0x1bU;
    __Vtask_tb_uart_tx__DOT__check_frame__16__data = 0x55U;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__16__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__17__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__17__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__16__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 7U;
    VL_WRITEF_NX("\n--- Test %0d: 8O1 Frame (0x55) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__19__lcr_val = 0x2bU;
    __Vtask_tb_uart_tx__DOT__push_byte__19__data = 0x55U;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__19__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__19__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val = 0x2bU;
    __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__20__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__20__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val = 0x2bU;
    __Vtask_tb_uart_tx__DOT__check_frame__21__data = 0x55U;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__21__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__22__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__22__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__21__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 8U;
    VL_WRITEF_NX("\n--- Test %0d: 5N1 Frame (0x1F) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__24__lcr_val = 0U;
    __Vtask_tb_uart_tx__DOT__push_byte__24__data = 0x1fU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__24__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__24__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__25__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__25__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val = 0U;
    __Vtask_tb_uart_tx__DOT__check_frame__26__data = 0x1fU;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__26__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__27__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__27__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__26__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 9U;
    VL_WRITEF_NX("\n--- Test %0d: FIFO Drain (2 bytes) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__29__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__29__data = 0xaaU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__29__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__29__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__push_byte__30__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__30__data = 0xbbU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__30__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__30__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__wait_not_busy__31__max_cycles = 0x00001770U;
    vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i, __Vtask_tb_uart_tx__DOT__wait_not_busy__31__max_cycles)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             106);
        if ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
            vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i 
                = __Vtask_tb_uart_tx__DOT__wait_not_busy__31__max_cycles;
        }
        vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i);
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         372);
    if ((0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) {
        VL_WRITEF_NX("  [PASS] FIFO empty after drain\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  [FAIL] After drain: empty=%b (expected: 1)\n",0,
                     1,(0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)));
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 0x0000000aU;
    VL_WRITEF_NX("\n--- Test %0d: Enable Pause/Resume ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__33__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__33__data = 0x55U;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__33__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__33__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             389);
    }
    tb_uart_tx__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0x00000050U;
    while (VL_LTS_III(32, 0U, tb_uart_tx__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             391);
        tb_uart_tx__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (tb_uart_tx__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__enable = 0U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000007a120ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         394);
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    __Vtask_tb_uart_tx__DOT__wait_not_busy__34__max_cycles = 0x00001770U;
    vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i, __Vtask_tb_uart_tx__DOT__wait_not_busy__34__max_cycles)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             106);
        if ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
            vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i 
                = __Vtask_tb_uart_tx__DOT__wait_not_busy__34__max_cycles;
        }
        vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i);
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         399);
    if ((0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) {
        VL_WRITEF_NX("  [PASS] Frame completed after pause/resume\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  [FAIL] After pause/resume: empty=%b\n",0,
                     1,(0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)));
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 0x0000000bU;
    VL_WRITEF_NX("\n--- Test %0d: 6N1 Frame (0x3F) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__36__lcr_val = 1U;
    __Vtask_tb_uart_tx__DOT__push_byte__36__data = 0x3fU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__36__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__36__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val = 1U;
    __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__37__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__37__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val = 1U;
    __Vtask_tb_uart_tx__DOT__check_frame__38__data = 0x3fU;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__38__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__39__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__39__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__38__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 0x0000000cU;
    VL_WRITEF_NX("\n--- Test %0d: 7N1 Frame (0x7F) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__41__lcr_val = 2U;
    __Vtask_tb_uart_tx__DOT__push_byte__41__data = 0x7fU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__41__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__41__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val = 2U;
    __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__42__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__42__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val = 2U;
    __Vtask_tb_uart_tx__DOT__check_frame__43__data = 0x7fU;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__43__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__44__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__44__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__43__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 0x0000000dU;
    VL_WRITEF_NX("\n--- Test %0d: 8N1 Frame (0x00) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__46__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__46__data = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__46__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__46__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__47__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__47__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__check_frame__48__data = 0U;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__48__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__49__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__49__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__48__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 0x0000000eU;
    VL_WRITEF_NX("\n--- Test %0d: 5E1.5 Frame (0x1F) ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__51__lcr_val = 7U;
    __Vtask_tb_uart_tx__DOT__push_byte__51__data = 0x1fU;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__51__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__51__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    __Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val = 7U;
    __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             123);
    }
    while (vlSelfRef.tb_uart_tx__DOT__TXD) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             125);
    }
    __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 = 7U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             128);
        __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__sample_frame__52__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    }
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample);
    vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample)) {
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__TXD) 
                                 << (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i))));
        __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000010U;
        while (VL_LTS_III(32, 0U, __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
            Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                              "@(posedge tb_uart_tx.PCLK)");
            vlSelfRef.__Vm_traceActivity[3U] = 1U;
            co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_uart_tx.PCLK)", 
                                                                 "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                                 144);
            __Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                = (__Vtask_tb_uart_tx__DOT__sample_frame__52__tb_uart_tx__DOT__unnamedblk1_2__DOT____Vrepeat1 
                   - (IData)(1U));
        }
        vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i);
    }
    vlSelfRef.tb_uart_tx__DOT__sampled_frame = vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    __Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val = 7U;
    __Vtask_tb_uart_tx__DOT__check_frame__53__data = 0x1fU;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val 
        = __Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val;
    __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__data 
        = __Vtask_tb_uart_tx__DOT__check_frame__53__data;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = 0U;
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
        = (0xfffeU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((1U & ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__data) 
                                        >> (7U & vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i))) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i);
    }
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
            = __Vtask_tb_uart_tx__DOT__compute_expected_frame__54__data;
        if ((5U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x1fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((6U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x3fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        } else if ((7U == vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)) {
            vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data 
                = (0x7fU & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data));
        }
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit 
            = (1U & ((0x00000020U & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val))
                      ? (~ ((IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val) 
                            >> 4U)) : ((0x00000010U 
                                        & (IData)(__Vtask_tb_uart_tx__DOT__compute_expected_frame__54__lcr_val))
                                        ? (~ VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))
                                        : VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = (((~ ((IData)(1U) << (0x0000000fU & ((IData)(1U) 
                                                   + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))) 
                & (IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame)) 
               | (0x0000ffffU & ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit) 
                                 << (0x0000000fU & 
                                     ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(2U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    } else {
        vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame 
            = ((IData)(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame) 
               | (0x0000ffffU & ((IData)(1U) << (0x0000000fU 
                                                 & ((IData)(1U) 
                                                    + vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits)))));
    }
    vlSelfRef.tb_uart_tx__DOT__expected_frame = vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits 
        = ((0U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val)))
            ? 5U : ((1U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val)))
                     ? 6U : ((2U == (3U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val)))
                              ? 7U : 8U)));
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits);
    if ((8U & (IData)(__Vtask_tb_uart_tx__DOT__check_frame__53__lcr_val))) {
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    }
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check 
        = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check);
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = 0U;
    vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i = 0U;
    while (VL_LTS_III(32, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i, vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check)) {
        if (VL_UNLIKELY((((1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                 >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))) 
                          != (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                    >> (0x0000000fU 
                                        & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))))))) {
            VL_WRITEF_NX("  [FAIL] Bit %0d: expected=%0# actual=%0#\n",0,
                         32,vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i,
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__expected_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))),
                         1,(1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__sampled_frame) 
                                  >> (0x0000000fU & vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i))));
            vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors 
                = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors);
        }
        vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i 
            = ((IData)(1U) + vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i);
    }
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors)))) {
        VL_WRITEF_NX("  [PASS] Frame matches expected\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    } else {
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    }
    vlSelfRef.tb_uart_tx__DOT__test_num = 0x0000000fU;
    VL_WRITEF_NX("\n--- Test %0d: Mid-Frame Reset ---\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__test_num);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__LCR = 3U;
    vlSelfRef.tb_uart_tx__DOT__enable = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         79);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         81);
    __Vtask_tb_uart_tx__DOT__push_byte__56__lcr_val = 3U;
    __Vtask_tb_uart_tx__DOT__push_byte__56__data = 0x55U;
    vlSelfRef.tb_uart_tx__DOT__LCR = __Vtask_tb_uart_tx__DOT__push_byte__56__lcr_val;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         91);
    vlSelfRef.tb_uart_tx__DOT__PWDATA = __Vtask_tb_uart_tx__DOT__push_byte__56__data;
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 1U;
    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                      "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_uart_tx.PCLK)", 
                                                         "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                         94);
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_push = 0U;
    vlSelfRef.tb_uart_tx__DOT__PWDATA = 0U;
    while ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             455);
    }
    tb_uart_tx__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0x00000028U;
    while (VL_LTS_III(32, 0U, tb_uart_tx__DOT__unnamedblk1_4__DOT____Vrepeat3)) {
        Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(vlSelf, 
                                                          "@(posedge tb_uart_tx.PCLK)");
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        co_await vlSelfRef.__VtrigSched_hcefd327b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_uart_tx.PCLK)", 
                                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                                             456);
        tb_uart_tx__DOT__unnamedblk1_4__DOT____Vrepeat3 
            = (tb_uart_tx__DOT__unnamedblk1_4__DOT____Vrepeat3 
               - (IData)(1U));
    }
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 0U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000c350ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         458);
    vlSelfRef.tb_uart_tx__DOT__PRESETn = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         460);
    if ((1U & ((~ (IData)(vlSelfRef.tb_uart_tx__DOT__TXD)) 
               | (IData)(vlSelfRef.tb_uart_tx__DOT__busy)))) {
        VL_WRITEF_NX("  [FAIL] After mid-frame reset: TXD=%b busy=%b\n",0,
                     1,vlSelfRef.tb_uart_tx__DOT__TXD,
                     1,(IData)(vlSelfRef.tb_uart_tx__DOT__busy));
        vlSelfRef.tb_uart_tx__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__fail_count);
    } else {
        VL_WRITEF_NX("  [PASS] Reset recovered correctly\n",0);
        vlSelfRef.tb_uart_tx__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_uart_tx__DOT__pass_count);
    }
    VL_WRITEF_NX("\n============================================\n  UART TX Testbench - Summary\n  PASS: %0d  FAIL: %0d  Total: %0d\n============================================\n",0,
                 32,vlSelfRef.tb_uart_tx__DOT__pass_count,
                 32,vlSelfRef.tb_uart_tx__DOT__fail_count,
                 32,(vlSelfRef.tb_uart_tx__DOT__pass_count 
                     + vlSelfRef.tb_uart_tx__DOT__fail_count));
    if (VL_LTS_III(32, 0U, vlSelfRef.tb_uart_tx__DOT__fail_count)) {
        VL_WRITEF_NX("  *** SOME TESTS FAILED ***\n",0);
    } else {
        VL_WRITEF_NX("  *** ALL TESTS PASSED ***\n",0);
    }
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                         nullptr, "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                         483);
    VL_FINISH_MT("/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 484, "");
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    co_return;
}

VlCoroutine Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 
                                             54);
        vlSelfRef.tb_uart_tx__DOT__PCLK = (1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__PCLK)));
    }
    co_return;
}

void Vtb_uart_tx___024root___eval_triggers_vec__act(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_triggers_vec__act\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U) 
                                                     | ((((~ (IData)(vlSelfRef.tb_uart_tx__DOT__PRESETn)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PRESETn__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_uart_tx__DOT__PCLK) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0 
        = vlSelfRef.tb_uart_tx__DOT__PCLK;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PRESETn__0 
        = vlSelfRef.tb_uart_tx__DOT__PRESETn;
}

bool Vtb_uart_tx___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___trigger_anySet__act\n"); );
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

void Vtb_uart_tx___024root___nba_sequent__TOP__0(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___nba_sequent__TOP__0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__57__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__57__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__58__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__58__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__59__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__59__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__60__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__60__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__61__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__61__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__62__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__62__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__63__Vfuncout;
    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__63__Vfuncout = 0;
    CData/*3:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state;
    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0;
    CData/*3:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter;
    __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0;
    CData/*7:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer;
    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer = 0;
    CData/*4:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count;
    __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count = 0;
    CData/*3:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
    __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count = 0;
    CData/*3:0*/ __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count;
    __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count = 0;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0;
    __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 = 0;
    CData/*3:0*/ __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0;
    __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1;
    __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 = 0;
    CData/*3:0*/ __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1;
    __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2;
    __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 = 0;
    CData/*3:0*/ __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2;
    __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3;
    __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 = 0;
    CData/*3:0*/ __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3;
    __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v4;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v4 = 0;
    // Body
    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state;
    __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
        = vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter;
    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer = vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer;
    __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count 
        = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count;
    __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
        = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count;
    __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count 
        = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 = 0U;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 = 0U;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 = 0U;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 = 0U;
    __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v4 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__PRESETn)))) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__i = 0x00000010U;
    }
    if (vlSelfRef.tb_uart_tx__DOT__PRESETn) {
        if ((1U & (~ (((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                       & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo))) 
                      & (0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))))) {
            if ((((~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push)) 
                  & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                 & (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
                __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count)));
            } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                          & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                         & (0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) 
                        & (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
                __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count)));
            } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                          & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                         & (0x10U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) 
                        & (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
                __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count)));
            }
        }
        if ((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
              & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo))) 
             & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_full)))) {
            __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)));
        } else if ((((~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push)) 
                     & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                    & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_empty)))) {
            __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
                = (0x0000001fU & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count) 
                                  - (IData)(1U)));
        } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                      & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                     & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_full))) 
                    & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_empty)))) {
            __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
                = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count;
        } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                      & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                     & (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_full)) 
                    & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_empty)))) {
            __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
                = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count;
        } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                      & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                     & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_full))) 
                    & (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_empty))) {
            __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)));
        }
        if ((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
              & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo))) 
             & (0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
            __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 
                = vlSelfRef.tb_uart_tx__DOT__PWDATA;
            __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 
                = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
            __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0 = 1U;
            __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count)));
        } else if ((1U & (~ (((~ (IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push)) 
                              & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                             & (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))))) {
            if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                   & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                  & (0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) 
                 & (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
                __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 
                    = vlSelfRef.tb_uart_tx__DOT__PWDATA;
                __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 
                    = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
                __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1 = 1U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count)));
            } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                          & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                         & (0x10U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) 
                        & (0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
                __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 
                    = vlSelfRef.tb_uart_tx__DOT__PWDATA;
                __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 
                    = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
                __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2 = 1U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count)));
            } else if (((((IData)(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push) 
                          & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo)) 
                         & (0x10U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))) 
                        & (0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)))) {
                __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 
                    = vlSelfRef.tb_uart_tx__DOT__PWDATA;
                __VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 
                    = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
                __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3 = 1U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count)));
            }
        }
    } else {
        __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count = 0U;
        __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count = 0U;
        __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count = 0U;
        __VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v4 = 1U;
    }
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count 
        = __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo = 0U;
    if (vlSelfRef.tb_uart_tx__DOT__PRESETn) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo = 0U;
        if ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
            if ((4U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                if ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0U;
                    vlSelfRef.tb_uart_tx__DOT__busy = 0U;
                    vlSelfRef.tb_uart_tx__DOT__TXD = 1U;
                } else if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0U;
                    vlSelfRef.tb_uart_tx__DOT__busy = 0U;
                    vlSelfRef.tb_uart_tx__DOT__TXD = 1U;
                } else {
                    vlSelfRef.tb_uart_tx__DOT__TXD = 1U;
                    if (vlSelfRef.tb_uart_tx__DOT__enable) {
                        if (((0U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))) 
                             & (~ (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag)))) {
                            vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag = 1U;
                            if ((7U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                                __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                                vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag = 0U;
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0U;
                            } else {
                                __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                                    = (0x0000000fU 
                                       & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                            }
                        } else if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                            vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag = 0U;
                            __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0U;
                        } else {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                    vlSelfRef.tb_uart_tx__DOT__TXD = 1U;
                    if (vlSelfRef.tb_uart_tx__DOT__enable) {
                        if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                            if ((4U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))) {
                                vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag = 0U;
                                __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0x0cU;
                            } else {
                                __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0U;
                            }
                        } else {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                        }
                    }
                } else {
                    vlSelfRef.tb_uart_tx__DOT__TXD 
                        = (1U & ((0x00000020U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                  ? (~ ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched) 
                                        >> 4U)) : (
                                                   (0x00000010U 
                                                    & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                                    ? 
                                                   (~ 
                                                    VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer))
                                                    : 
                                                   VL_REDXOR_8(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer))));
                    if (vlSelfRef.tb_uart_tx__DOT__enable) {
                        if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                            vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag = 0U;
                            __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0x0bU;
                        } else {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                        }
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                vlSelfRef.tb_uart_tx__DOT__TXD = (1U 
                                                  & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                                     >> 7U));
                if (vlSelfRef.tb_uart_tx__DOT__enable) {
                    if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                        __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__57__Vfuncout 
                            = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                ? 0x0aU : 0x0bU);
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                            = __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__57__Vfuncout;
                    } else {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                    }
                }
            } else {
                vlSelfRef.tb_uart_tx__DOT__TXD = (1U 
                                                  & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                                     >> 6U));
                if (vlSelfRef.tb_uart_tx__DOT__enable) {
                    if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                        if ((2U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched)))) {
                            __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__58__Vfuncout 
                                = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                    ? 0x0aU : 0x0bU);
                            __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer 
                                = (0x7fU & (IData)(__Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer));
                            __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                                = __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__58__Vfuncout;
                        } else {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 9U;
                        }
                    } else {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                    }
                }
            }
        } else if ((4U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
            if ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                    vlSelfRef.tb_uart_tx__DOT__TXD 
                        = (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                 >> 5U));
                    if (vlSelfRef.tb_uart_tx__DOT__enable) {
                        if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                            if ((1U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched)))) {
                                __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__59__Vfuncout 
                                    = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                        ? 0x0aU : 0x0bU);
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer 
                                    = (0x3fU & (IData)(__Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer));
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                                    = __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__59__Vfuncout;
                            } else {
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 8U;
                            }
                        } else {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                        }
                    }
                } else {
                    vlSelfRef.tb_uart_tx__DOT__TXD 
                        = (1U & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                 >> 4U));
                    if (vlSelfRef.tb_uart_tx__DOT__enable) {
                        if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                            if ((0U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched)))) {
                                __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__60__Vfuncout 
                                    = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                        ? 0x0aU : 0x0bU);
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer 
                                    = (0x1fU & (IData)(__Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer));
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                                    = __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__60__Vfuncout;
                            } else {
                                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 7U;
                            }
                        } else {
                            __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                        }
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                vlSelfRef.tb_uart_tx__DOT__TXD = (1U 
                                                  & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                                     >> 3U));
                if (vlSelfRef.tb_uart_tx__DOT__enable) {
                    if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 6U;
                    } else {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                    }
                }
            } else {
                vlSelfRef.tb_uart_tx__DOT__TXD = (1U 
                                                  & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                                     >> 2U));
                if (vlSelfRef.tb_uart_tx__DOT__enable) {
                    if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                            = ((2U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched)))
                                ? ([&]() {
                                    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__61__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                            ? 0x0aU
                                            : 0x0bU);
                                }(), (IData)(__Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__61__Vfuncout))
                                : 5U);
                    } else {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
            if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
                vlSelfRef.tb_uart_tx__DOT__TXD = (1U 
                                                  & ((IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer) 
                                                     >> 1U));
                if (vlSelfRef.tb_uart_tx__DOT__enable) {
                    if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                            = ((1U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched)))
                                ? ([&]() {
                                    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__62__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                            ? 0x0aU
                                            : 0x0bU);
                                }(), (IData)(__Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__62__Vfuncout))
                                : 4U);
                    } else {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                    }
                }
            } else {
                vlSelfRef.tb_uart_tx__DOT__TXD = (1U 
                                                  & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer));
                if (vlSelfRef.tb_uart_tx__DOT__enable) {
                    if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state 
                            = ((0U == (3U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched)))
                                ? ([&]() {
                                    __Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__63__Vfuncout 
                                        = ((8U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched))
                                            ? 0x0aU
                                            : 0x0bU);
                                }(), (IData)(__Vfunc_tb_uart_tx__DOT__dut__DOT__next_after_data__63__Vfuncout))
                                : 3U);
                    } else {
                        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state))) {
            vlSelfRef.tb_uart_tx__DOT__TXD = 0U;
            if (vlSelfRef.tb_uart_tx__DOT__enable) {
                if ((0x0fU == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter))) {
                    __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                    __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 2U;
                } else {
                    __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter)));
                }
            }
        } else {
            vlSelfRef.tb_uart_tx__DOT__busy = 0U;
            vlSelfRef.tb_uart_tx__DOT__TXD = 1U;
            if (((0U != (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count)) 
                 & (IData)(vlSelfRef.tb_uart_tx__DOT__enable))) {
                __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
                vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo = 1U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer 
                    = vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo
                    [vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count];
                vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched 
                    = vlSelfRef.tb_uart_tx__DOT__LCR;
                vlSelfRef.tb_uart_tx__DOT__busy = 1U;
                __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 1U;
            }
        }
    } else {
        __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag = 0U;
        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state = 0U;
        __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo = 0U;
        vlSelfRef.tb_uart_tx__DOT__busy = 0U;
        vlSelfRef.tb_uart_tx__DOT__TXD = 1U;
    }
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state = __Vdly__tb_uart_tx__DOT__dut__DOT__tx_state;
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter 
        = __Vdly__tb_uart_tx__DOT__dut__DOT__bit_counter;
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer 
        = __Vdly__tb_uart_tx__DOT__dut__DOT__tx_buffer;
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count 
        = __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count;
    vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count 
        = __Vdly__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count;
    if (__VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[__VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0] 
            = __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v0;
    }
    if (__VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[__VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1] 
            = __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v1;
    }
    if (__VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[__VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2] 
            = __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v2;
    }
    if (__VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[__VdlyDim0__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3] 
            = __VdlyVal__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v3;
    }
    if (__VdlySet__tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo__v4) {
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[0U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[1U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[2U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[3U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[4U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[5U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[6U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[7U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[8U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[9U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[10U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[11U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[12U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[13U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[14U] = 0U;
        vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[15U] = 0U;
    }
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_empty = (0U 
                                                == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count));
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_full = (0x10U 
                                               == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count));
}

void Vtb_uart_tx___024root___eval_nba(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_nba\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_uart_tx___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
}

void Vtb_uart_tx___024root___timing_ready(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___timing_ready\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hcefd327b__0.ready("@(posedge tb_uart_tx.PCLK)");
    }
}

void Vtb_uart_tx___024root___timing_resume(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___timing_resume\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hcefd327b__0.moveToResumeQueue(
                                                          "@(posedge tb_uart_tx.PCLK)");
    vlSelfRef.__VtrigSched_hcefd327b__0.resume("@(posedge tb_uart_tx.PCLK)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_uart_tx___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___trigger_orInto__act_vec_vec\n"); );
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
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_uart_tx___024root___eval_phase__act(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_phase__act\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_uart_tx___024root___eval_triggers_vec__act(vlSelf);
    Vtb_uart_tx___024root___timing_ready(vlSelf);
    Vtb_uart_tx___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_tx___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_uart_tx___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_uart_tx___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_uart_tx___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_uart_tx___024root___eval_phase__inact(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_phase__inact\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 11, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_uart_tx___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_uart_tx___024root___eval_phase__nba(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_phase__nba\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_uart_tx___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_uart_tx___024root___eval_nba(vlSelf);
        Vtb_uart_tx___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_uart_tx___024root___eval(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_uart_tx___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 11, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 11, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_uart_tx___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 11, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_uart_tx___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_uart_tx___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_uart_tx___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0(Vtb_uart_tx___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root____VbeforeTrig_hcefd327b__0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.tb_uart_tx__DOT__PCLK) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0 
        = vlSelfRef.tb_uart_tx__DOT__PCLK;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hcefd327b__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_uart_tx___024root___eval_debug_assertions(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_debug_assertions\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
