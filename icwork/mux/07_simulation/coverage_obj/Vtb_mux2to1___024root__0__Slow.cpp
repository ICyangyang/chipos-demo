// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_mux2to1.h for the primary calling header

#include "Vtb_mux2to1__pch.h"

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_static(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_static\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_initial__TOP(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_initial__TOP\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("mux2to1.vcd"s);
    vlSymsp->_traceDumpOpen();
    ++(vlSymsp->__Vcoverage[568]);
}

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_final(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_final\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_mux2to1___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_mux2to1___024root___eval_phase__stl(Vtb_mux2to1___024root* vlSelf);

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_settle(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_settle\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_mux2to1___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb_mux2to1.sv", 17, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_mux2to1___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_triggers_vec__stl(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_triggers_vec__stl\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_mux2to1___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_mux2to1___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_mux2to1___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_mux2to1___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtb_mux2to1___024root___stl_sequent__TOP__0(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___stl_sequent__TOP__0\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __Vtemp_1;
    // Body
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__in0) ^ (IData)(vlSelfRef.tb_mux2to1__DOT____Vtogcov__in0))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 0, vlSelfRef.tb_mux2to1__DOT__in0, vlSelfRef.tb_mux2to1__DOT____Vtogcov__in0);
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__in0 = vlSelfRef.tb_mux2to1__DOT__in0;
    }
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__in1) ^ (IData)(vlSelfRef.tb_mux2to1__DOT____Vtogcov__in1))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 16, vlSelfRef.tb_mux2to1__DOT__in1, vlSelfRef.tb_mux2to1__DOT____Vtogcov__in1);
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__in1 = vlSelfRef.tb_mux2to1__DOT__in1;
    }
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__sel) ^ (IData)(vlSelfRef.tb_mux2to1__DOT____Vtogcov__sel))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 32, vlSelfRef.tb_mux2to1__DOT__sel, vlSelfRef.tb_mux2to1__DOT____Vtogcov__sel);
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__sel = vlSelfRef.tb_mux2to1__DOT__sel;
    }
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__clk) ^ (IData)(vlSelfRef.tb_mux2to1__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 50, vlSelfRef.tb_mux2to1__DOT__clk, vlSelfRef.tb_mux2to1__DOT____Vtogcov__clk);
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__clk = vlSelfRef.tb_mux2to1__DOT__clk;
    }
    __Vtemp_1[0U] = (vlSelfRef.tb_mux2to1__DOT__test_name[0U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[0U]);
    __Vtemp_1[1U] = (vlSelfRef.tb_mux2to1__DOT__test_name[1U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[1U]);
    __Vtemp_1[2U] = (vlSelfRef.tb_mux2to1__DOT__test_name[2U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[2U]);
    __Vtemp_1[3U] = (vlSelfRef.tb_mux2to1__DOT__test_name[3U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[3U]);
    __Vtemp_1[4U] = (vlSelfRef.tb_mux2to1__DOT__test_name[4U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[4U]);
    __Vtemp_1[5U] = (vlSelfRef.tb_mux2to1__DOT__test_name[5U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[5U]);
    __Vtemp_1[6U] = (vlSelfRef.tb_mux2to1__DOT__test_name[6U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[6U]);
    __Vtemp_1[7U] = (vlSelfRef.tb_mux2to1__DOT__test_name[7U] 
                     ^ vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[7U]);
    if (__Vtemp_1) {
        VL_COV_TOGGLE_CHG_ST_W(256, vlSymsp->__Vcoverage + 52, vlSelfRef.tb_mux2to1__DOT__test_name, vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name);
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[0U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[0U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[1U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[1U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[2U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[2U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[3U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[3U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[4U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[4U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[5U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[5U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[6U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[6U];
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__test_name[7U] 
            = vlSelfRef.tb_mux2to1__DOT__test_name[7U];
    }
    vlSelfRef.tb_mux2to1__DOT__out = ((IData)(vlSelfRef.tb_mux2to1__DOT__sel)
                                       ? ([&]() {
                ++(vlSymsp->__Vcoverage[583]);
            }(), (IData)(vlSelfRef.tb_mux2to1__DOT__in1))
                                       : ([&]() {
                ++(vlSymsp->__Vcoverage[584]);
            }(), (IData)(vlSelfRef.tb_mux2to1__DOT__in0)));
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) ^ (IData)(vlSelfRef.tb_mux2to1__DOT____Vtogcov__out))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSymsp->__Vcoverage + 34, vlSelfRef.tb_mux2to1__DOT__out, vlSelfRef.tb_mux2to1__DOT____Vtogcov__out);
        vlSelfRef.tb_mux2to1__DOT____Vtogcov__out = vlSelfRef.tb_mux2to1__DOT__out;
    }
}

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_stl(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_stl\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_mux2to1___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_mux2to1___024root___eval_phase__stl(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_phase__stl\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_mux2to1___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_mux2to1___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_mux2to1___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_mux2to1___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_mux2to1___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_mux2to1___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_mux2to1___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_mux2to1___024root___ctor_var_reset(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___ctor_var_reset\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_mux2to1__DOT__in0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17950926309627239869ull);
    vlSelf->tb_mux2to1__DOT__in1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15362641811623258626ull);
    vlSelf->tb_mux2to1__DOT__sel = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7827724351176912394ull);
    vlSelf->tb_mux2to1__DOT__out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17032799185236233841ull);
    vlSelf->tb_mux2to1__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15342171790387957222ull);
    vlSelf->tb_mux2to1__DOT__test_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7526663401875674221ull);
    vlSelf->tb_mux2to1__DOT__pass_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15167114599254992382ull);
    vlSelf->tb_mux2to1__DOT__fail_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7104022360146208563ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tb_mux2to1__DOT__test_name, __VscopeHash, 10992846176521262018ull);
    vlSelf->tb_mux2to1__DOT____Vtogcov__in0 = 0;
    vlSelf->tb_mux2to1__DOT____Vtogcov__in1 = 0;
    vlSelf->tb_mux2to1__DOT____Vtogcov__sel = 0;
    vlSelf->tb_mux2to1__DOT____Vtogcov__out = 0;
    vlSelf->tb_mux2to1__DOT____Vtogcov__clk = 0;
    VL_ZERO_RESET_W(256, vlSelf->tb_mux2to1__DOT____Vtogcov__test_name);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

VL_ATTR_COLD void Vtb_mux2to1___024root___configure_coverage(Vtb_mux2to1___024root* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___configure_coverage\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[0]), first, "tb_mux2to1.sv", 25, 27, ".tb_mux2to1", "v_toggle/tb_mux2to1", "in0");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[16]), first, "tb_mux2to1.sv", 26, 27, ".tb_mux2to1", "v_toggle/tb_mux2to1", "in1");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[32]), first, "tb_mux2to1.sv", 27, 27, ".tb_mux2to1", "v_toggle/tb_mux2to1", "sel");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[34]), first, "tb_mux2to1.sv", 28, 27, ".tb_mux2to1", "v_toggle/tb_mux2to1", "out");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[50]), first, "tb_mux2to1.sv", 31, 17, ".tb_mux2to1", "v_toggle/tb_mux2to1", "clk");
    vlSelf->__vlCoverToggleInsert(0, 255, 1, &(vlSymsp->__Vcoverage[52]), first, "tb_mux2to1.sv", 35, 17, ".tb_mux2to1", "v_toggle/tb_mux2to1", "test_name");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[564]), first, "tb_mux2to1.sv", 50, 39, ".tb_mux2to1", "v_expr/tb_mux2to1", "(clk==0) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[565]), first, "tb_mux2to1.sv", 50, 39, ".tb_mux2to1", "v_expr/tb_mux2to1", "(clk==1) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[566]), first, "tb_mux2to1.sv", 50, 9, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[567]), first, "tb_mux2to1.sv", 48, 5, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "48-49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[568]), first, "tb_mux2to1.sv", 54, 5, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "54-56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[569]), first, "tb_mux2to1.sv", 65, 13, ".tb_mux2to1", "v_branch/tb_mux2to1", "if", "65-67");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[570]), first, "tb_mux2to1.sv", 65, 14, ".tb_mux2to1", "v_branch/tb_mux2to1", "else", "68-71");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[571]), first, "tb_mux2to1.sv", 60, 20, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "60,63-64");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[572]), first, "tb_mux2to1.sv", 88, 24, ".tb_mux2to1", "v_expr/tb_mux2to1", "(t_sel==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[573]), first, "tb_mux2to1.sv", 88, 24, ".tb_mux2to1", "v_expr/tb_mux2to1", "(t_sel==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[574]), first, "tb_mux2to1.sv", 88, 32, ".tb_mux2to1", "v_branch/tb_mux2to1", "cond_then", "88");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[575]), first, "tb_mux2to1.sv", 88, 33, ".tb_mux2to1", "v_branch/tb_mux2to1", "cond_else", "88");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[576]), first, "tb_mux2to1.sv", 77, 20, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "77,82-89");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[577]), first, "tb_mux2to1.sv", 120, 9, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "120-125");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[578]), first, "tb_mux2to1.sv", 138, 9, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "138-143");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[579]), first, "tb_mux2to1.sv", 187, 9, ".tb_mux2to1", "v_branch/tb_mux2to1", "if", "187-188");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[580]), first, "tb_mux2to1.sv", 187, 10, ".tb_mux2to1", "v_branch/tb_mux2to1", "else", "189-190");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[581]), first, "tb_mux2to1.sv", 94, 5, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "94,96-98,100-105,108,113,116-117,120,131,134-135,138,149,152-153,156-157,160-163,168,171-174,179-185,193");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[582]), first, "tb_mux2to1.sv", 197, 5, ".tb_mux2to1", "v_line/tb_mux2to1", "block", "197-200");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[0]), first, "mux2to1.v", 11, 34, ".tb_mux2to1.dut", "v_toggle/mux2to1", "in0");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[16]), first, "mux2to1.v", 12, 34, ".tb_mux2to1.dut", "v_toggle/mux2to1", "in1");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[32]), first, "mux2to1.v", 13, 35, ".tb_mux2to1.dut", "v_toggle/mux2to1", "sel");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, &(vlSymsp->__Vcoverage[34]), first, "mux2to1.v", 14, 34, ".tb_mux2to1.dut", "v_toggle/mux2to1", "out");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[583]), first, "mux2to1.v", 18, 24, ".tb_mux2to1.dut", "v_branch/mux2to1", "cond_then", "18");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[584]), first, "mux2to1.v", 18, 25, ".tb_mux2to1.dut", "v_branch/mux2to1", "cond_else", "18");
}
