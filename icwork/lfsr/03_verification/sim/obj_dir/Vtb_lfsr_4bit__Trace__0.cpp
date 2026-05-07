// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_lfsr_4bit__Syms.h"


void Vtb_lfsr_4bit___024root__trace_chg_0_sub_0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_lfsr_4bit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_chg_0\n"); );
    // Body
    Vtb_lfsr_4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_lfsr_4bit___024root*>(voidSelf);
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_lfsr_4bit___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_lfsr_4bit___024root__trace_chg_0_sub_0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_chg_0_sub_0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[0]),4);
        bufp->chgCData(oldp+1,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[1]),4);
        bufp->chgCData(oldp+2,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[2]),4);
        bufp->chgCData(oldp+3,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[3]),4);
        bufp->chgCData(oldp+4,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[4]),4);
        bufp->chgCData(oldp+5,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[5]),4);
        bufp->chgCData(oldp+6,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[6]),4);
        bufp->chgCData(oldp+7,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[7]),4);
        bufp->chgCData(oldp+8,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[8]),4);
        bufp->chgCData(oldp+9,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[9]),4);
        bufp->chgCData(oldp+10,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[10]),4);
        bufp->chgCData(oldp+11,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[11]),4);
        bufp->chgCData(oldp+12,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[12]),4);
        bufp->chgCData(oldp+13,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[13]),4);
        bufp->chgCData(oldp+14,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[14]),4);
        bufp->chgCData(oldp+15,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[15]),4);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+16,(vlSelfRef.tb_lfsr_4bit__DOT__total_tests),32);
        bufp->chgIData(oldp+17,(vlSelfRef.tb_lfsr_4bit__DOT__passed_tests),32);
        bufp->chgIData(oldp+18,(vlSelfRef.tb_lfsr_4bit__DOT__failed_tests),32);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle),32);
        bufp->chgBit(oldp+20,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[0]));
        bufp->chgBit(oldp+21,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[1]));
        bufp->chgBit(oldp+22,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[2]));
        bufp->chgBit(oldp+23,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[3]));
        bufp->chgBit(oldp+24,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[4]));
        bufp->chgBit(oldp+25,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[5]));
        bufp->chgBit(oldp+26,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[6]));
        bufp->chgBit(oldp+27,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[7]));
        bufp->chgBit(oldp+28,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[8]));
        bufp->chgBit(oldp+29,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[9]));
        bufp->chgBit(oldp+30,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[10]));
        bufp->chgBit(oldp+31,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[11]));
        bufp->chgBit(oldp+32,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[12]));
        bufp->chgBit(oldp+33,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[13]));
        bufp->chgBit(oldp+34,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[14]));
        bufp->chgBit(oldp+35,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[15]));
        bufp->chgBit(oldp+36,(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_15));
        bufp->chgBit(oldp+37,(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16));
        bufp->chgIData(oldp+38,(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgBit(oldp+39,(vlSelfRef.tb_lfsr_4bit__DOT__res));
        bufp->chgCData(oldp+40,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[0]),4);
        bufp->chgCData(oldp+41,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[1]),4);
        bufp->chgCData(oldp+42,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[2]),4);
        bufp->chgCData(oldp+43,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[3]),4);
        bufp->chgCData(oldp+44,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[4]),4);
        bufp->chgCData(oldp+45,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[5]),4);
        bufp->chgCData(oldp+46,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[6]),4);
        bufp->chgCData(oldp+47,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[7]),4);
        bufp->chgCData(oldp+48,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[8]),4);
        bufp->chgCData(oldp+49,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[9]),4);
        bufp->chgCData(oldp+50,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[10]),4);
        bufp->chgCData(oldp+51,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[11]),4);
        bufp->chgCData(oldp+52,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[12]),4);
        bufp->chgCData(oldp+53,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[13]),4);
        bufp->chgCData(oldp+54,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[14]),4);
        bufp->chgCData(oldp+55,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[15]),4);
        bufp->chgBit(oldp+56,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0]));
        bufp->chgBit(oldp+57,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[1]));
        bufp->chgBit(oldp+58,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[2]));
        bufp->chgBit(oldp+59,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[3]));
        bufp->chgBit(oldp+60,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[4]));
        bufp->chgBit(oldp+61,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[5]));
        bufp->chgBit(oldp+62,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[6]));
        bufp->chgBit(oldp+63,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[7]));
        bufp->chgBit(oldp+64,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[8]));
        bufp->chgBit(oldp+65,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[9]));
        bufp->chgBit(oldp+66,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[10]));
        bufp->chgBit(oldp+67,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[11]));
        bufp->chgBit(oldp+68,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[12]));
        bufp->chgBit(oldp+69,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[13]));
        bufp->chgBit(oldp+70,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[14]));
        bufp->chgBit(oldp+71,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[15]));
    }
    bufp->chgBit(oldp+72,(vlSelfRef.tb_lfsr_4bit__DOT__clk));
    bufp->chgBit(oldp+73,((1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d))));
    bufp->chgCData(oldp+74,(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d),4);
}

void Vtb_lfsr_4bit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_cleanup\n"); );
    // Body
    Vtb_lfsr_4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_lfsr_4bit___024root*>(voidSelf);
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
