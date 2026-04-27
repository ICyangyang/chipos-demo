// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_mux2to1__Syms.h"


void Vtb_mux2to1___024root__trace_chg_0_sub_0(Vtb_mux2to1___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_mux2to1___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root__trace_chg_0\n"); );
    // Body
    Vtb_mux2to1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_mux2to1___024root*>(voidSelf);
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_mux2to1___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_mux2to1___024root__trace_chg_0_sub_0(Vtb_mux2to1___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root__trace_chg_0_sub_0\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgCData(oldp+0,(vlSelfRef.tb_mux2to1__DOT__in0),8);
        bufp->chgCData(oldp+1,(vlSelfRef.tb_mux2to1__DOT__in1),8);
        bufp->chgBit(oldp+2,(vlSelfRef.tb_mux2to1__DOT__sel));
        bufp->chgCData(oldp+3,(((IData)(vlSelfRef.tb_mux2to1__DOT__sel)
                                 ? (IData)(vlSelfRef.tb_mux2to1__DOT__in1)
                                 : (IData)(vlSelfRef.tb_mux2to1__DOT__in0))),8);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_mux2to1__DOT__test_count),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_mux2to1__DOT__pass_count),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_mux2to1__DOT__fail_count),32);
    }
    bufp->chgBit(oldp+7,(vlSelfRef.tb_mux2to1__DOT__clk));
}

void Vtb_mux2to1___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root__trace_cleanup\n"); );
    // Body
    Vtb_mux2to1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_mux2to1___024root*>(voidSelf);
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
