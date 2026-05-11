// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_uart_tx.h for the primary calling header

#include "Vtb_uart_tx__pch.h"

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static__TOP(Vtb_uart_tx___024root* vlSelf);
void Vtb_uart_tx___024root___timing_ready(Vtb_uart_tx___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_static\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_uart_tx___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0 
        = vlSelfRef.tb_uart_tx__DOT__PCLK;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PRESETn__0 
        = vlSelfRef.tb_uart_tx__DOT__PRESETn;
    Vtb_uart_tx___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_static__TOP(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_static__TOP\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_uart_tx__DOT__wait_not_busy__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14926047651143079530ull);
    vlSelf->tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9628756617587407929ull);
    vlSelf->tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5271230790078318201ull);
    vlSelf->tb_uart_tx__DOT__sample_frame__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16655604512663255804ull);
    vlSelf->tb_uart_tx__DOT__sample_frame__Vstatic__frame = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5059742771893951498ull);
    vlSelf->tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8489676500599105402ull);
    vlSelf->tb_uart_tx__DOT__compute_expected_frame__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15025047401326051809ull);
    vlSelf->tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6053807628342671725ull);
    vlSelf->tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9414254075685997350ull);
    vlSelf->tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11986212709882970274ull);
    vlSelf->tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17197783729318016274ull);
    vlSelf->tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12872071286031782378ull);
    vlSelf->tb_uart_tx__DOT__check_frame__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5603018253584351167ull);
    vlSelf->tb_uart_tx__DOT__check_frame__Vstatic__bit_errors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1397338662026856452ull);
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_initial__TOP(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_initial__TOP\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_uart_tx__DOT__PCLK = 0U;
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_final(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_final\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_uart_tx___024root___eval_phase__stl(Vtb_uart_tx___024root* vlSelf);

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_settle(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_settle\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_uart_tx___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/workspace/work/uart_tx/02_verification/tb_uart_tx.v", 11, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_uart_tx___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_triggers_vec__stl(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_triggers_vec__stl\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_uart_tx___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_uart_tx___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_uart_tx___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb_uart_tx___024root___stl_sequent__TOP__0(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___stl_sequent__TOP__0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_empty = (0U 
                                                == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count));
    vlSelfRef.tb_uart_tx__DOT__tx_fifo_full = (0x10U 
                                               == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count));
}

VL_ATTR_COLD void Vtb_uart_tx___024root___eval_stl(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_stl\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_uart_tx___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_uart_tx___024root___eval_phase__stl(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___eval_phase__stl\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_uart_tx___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_uart_tx___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_uart_tx___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_uart_tx___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_uart_tx___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_uart_tx___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_uart_tx___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_uart_tx.PCLK)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_uart_tx.PRESETn)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_uart_tx___024root___ctor_var_reset(Vtb_uart_tx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root___ctor_var_reset\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_uart_tx__DOT__PCLK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5552168456565929305ull);
    vlSelf->tb_uart_tx__DOT__PRESETn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10344268851853470295ull);
    vlSelf->tb_uart_tx__DOT__PWDATA = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10707999788617888785ull);
    vlSelf->tb_uart_tx__DOT__tx_fifo_push = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1303326848124944078ull);
    vlSelf->tb_uart_tx__DOT__LCR = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14841798944430097900ull);
    vlSelf->tb_uart_tx__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17637808367737260156ull);
    vlSelf->tb_uart_tx__DOT__tx_fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4548574978529361921ull);
    vlSelf->tb_uart_tx__DOT__tx_fifo_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8618818924205824538ull);
    vlSelf->tb_uart_tx__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8936002566485585760ull);
    vlSelf->tb_uart_tx__DOT__TXD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5062169120011034067ull);
    vlSelf->tb_uart_tx__DOT__test_num = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3507893366135458705ull);
    vlSelf->tb_uart_tx__DOT__pass_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14902954497807090923ull);
    vlSelf->tb_uart_tx__DOT__fail_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17646208559517190139ull);
    vlSelf->tb_uart_tx__DOT__err_flag = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7457415045050604572ull);
    vlSelf->tb_uart_tx__DOT__sampled_frame = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8970568403212762676ull);
    vlSelf->tb_uart_tx__DOT__expected_frame = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16764879648806569168ull);
    vlSelf->tb_uart_tx__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14472007418990304912ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__tx_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5858316892304534390ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__bit_counter = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15064144557781806413ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__tx_buffer = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4024394092212009706ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__pop_tx_fifo = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15098104400419972187ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__lcr_latched = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15939570837052861259ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__half_stop_flag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5809132557561695911ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5278862395562453777ull);
    }
    vlSelf->tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13553582836185314837ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7987622986259591607ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6583670895393631735ull);
    vlSelf->tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16388105485940696001ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_uart_tx__DOT__PRESETn__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
