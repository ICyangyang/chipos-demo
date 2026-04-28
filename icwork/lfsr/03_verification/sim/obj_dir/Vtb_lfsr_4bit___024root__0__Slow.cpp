// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_lfsr_4bit.h for the primary calling header

#include "Vtb_lfsr_4bit__pch.h"

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_static__TOP(Vtb_lfsr_4bit___024root* vlSelf);
void Vtb_lfsr_4bit___024root___timing_ready(Vtb_lfsr_4bit___024root* vlSelf);

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_static(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_static\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_lfsr_4bit___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0 
        = vlSelfRef.tb_lfsr_4bit__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__res__0 
        = vlSelfRef.tb_lfsr_4bit__DOT__res;
    Vtb_lfsr_4bit___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_static__TOP(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_static__TOP\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lfsr_4bit__DOT__total_tests = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__passed_tests = 0U;
    vlSelfRef.tb_lfsr_4bit__DOT__failed_tests = 0U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13867843833251967736ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10391961196148251598ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4677564835522027824ull);
    }
    vlSelf->tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8537214215992065300ull);
    vlSelf->tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2015948346664288037ull);
    vlSelf->tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13225481801384468340ull);
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_initial__TOP(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_initial__TOP\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("tb_lfsr_4bit.vcd"s);
    vlSymsp->_traceDumpOpen();
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_final(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_final\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___eval_settle(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___eval_settle\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_lfsr_4bit___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lfsr_4bit___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_lfsr_4bit___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_lfsr_4bit.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_lfsr_4bit.res)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge tb_lfsr_4bit.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_lfsr_4bit___024root___ctor_var_reset(Vtb_lfsr_4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root___ctor_var_reset\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_lfsr_4bit__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9633799635192052335ull);
    vlSelf->tb_lfsr_4bit__DOT__res = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17886571097406682647ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_lfsr_4bit__DOT__expected_d[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16667979752195107331ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_lfsr_4bit__DOT__expected_y[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1868520671702020212ull);
    }
    vlSelf->tb_lfsr_4bit__DOT__dut__DOT__d = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13624089067004942636ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__res__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
