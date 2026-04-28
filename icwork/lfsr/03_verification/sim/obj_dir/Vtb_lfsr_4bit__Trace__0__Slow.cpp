// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_lfsr_4bit__Syms.h"


VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_init_sub__TOP__0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_init_sub__TOP__0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb_lfsr_4bit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+75,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"LFSR_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"TIMEOUT_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"total_tests",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"passed_tests",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"failed_tests",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("expected_d", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+40+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("expected_y", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBit(c+56+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBus(c+19,0,"test_sequence__Vstatic__cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("test_sequence__Vstatic__state_trace", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+0+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("test_sequence__Vstatic__output_trace", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBit(c+20+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBit(c+36,0,"test_periodicity__Vstatic__y_at_cycle_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"test_periodicity__Vstatic__y_at_cycle_16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"res",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("test_periodicity__Vstatic__sv2v_autoblock_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_init_top(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_init_top\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_lfsr_4bit___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_lfsr_4bit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_lfsr_4bit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_register(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_register\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_lfsr_4bit___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_lfsr_4bit___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_lfsr_4bit___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_lfsr_4bit___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_const_0_sub_0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_const_0\n"); );
    // Body
    Vtb_lfsr_4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_lfsr_4bit___024root*>(voidSelf);
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_lfsr_4bit___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_const_0_sub_0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_const_0_sub_0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+75,(0x0000000aU),32);
    bufp->fullIData(oldp+76,(0x0000000fU),32);
    bufp->fullIData(oldp+77,(0x00000064U),32);
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_full_0_sub_0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_full_0\n"); );
    // Body
    Vtb_lfsr_4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_lfsr_4bit___024root*>(voidSelf);
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_lfsr_4bit___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_lfsr_4bit___024root__trace_full_0_sub_0(Vtb_lfsr_4bit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lfsr_4bit___024root__trace_full_0_sub_0\n"); );
    Vtb_lfsr_4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[0]),4);
    bufp->fullCData(oldp+1,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[1]),4);
    bufp->fullCData(oldp+2,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[2]),4);
    bufp->fullCData(oldp+3,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[3]),4);
    bufp->fullCData(oldp+4,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[4]),4);
    bufp->fullCData(oldp+5,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[5]),4);
    bufp->fullCData(oldp+6,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[6]),4);
    bufp->fullCData(oldp+7,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[7]),4);
    bufp->fullCData(oldp+8,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[8]),4);
    bufp->fullCData(oldp+9,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[9]),4);
    bufp->fullCData(oldp+10,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[10]),4);
    bufp->fullCData(oldp+11,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[11]),4);
    bufp->fullCData(oldp+12,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[12]),4);
    bufp->fullCData(oldp+13,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[13]),4);
    bufp->fullCData(oldp+14,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[14]),4);
    bufp->fullCData(oldp+15,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace[15]),4);
    bufp->fullIData(oldp+16,(vlSelfRef.tb_lfsr_4bit__DOT__total_tests),32);
    bufp->fullIData(oldp+17,(vlSelfRef.tb_lfsr_4bit__DOT__passed_tests),32);
    bufp->fullIData(oldp+18,(vlSelfRef.tb_lfsr_4bit__DOT__failed_tests),32);
    bufp->fullIData(oldp+19,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle),32);
    bufp->fullBit(oldp+20,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[0]));
    bufp->fullBit(oldp+21,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[1]));
    bufp->fullBit(oldp+22,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[2]));
    bufp->fullBit(oldp+23,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[3]));
    bufp->fullBit(oldp+24,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[4]));
    bufp->fullBit(oldp+25,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[5]));
    bufp->fullBit(oldp+26,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[6]));
    bufp->fullBit(oldp+27,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[7]));
    bufp->fullBit(oldp+28,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[8]));
    bufp->fullBit(oldp+29,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[9]));
    bufp->fullBit(oldp+30,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[10]));
    bufp->fullBit(oldp+31,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[11]));
    bufp->fullBit(oldp+32,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[12]));
    bufp->fullBit(oldp+33,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[13]));
    bufp->fullBit(oldp+34,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[14]));
    bufp->fullBit(oldp+35,(vlSelfRef.tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace[15]));
    bufp->fullBit(oldp+36,(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_15));
    bufp->fullBit(oldp+37,(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16));
    bufp->fullIData(oldp+38,(vlSelfRef.tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle),32);
    bufp->fullBit(oldp+39,(vlSelfRef.tb_lfsr_4bit__DOT__res));
    bufp->fullCData(oldp+40,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[0]),4);
    bufp->fullCData(oldp+41,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[1]),4);
    bufp->fullCData(oldp+42,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[2]),4);
    bufp->fullCData(oldp+43,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[3]),4);
    bufp->fullCData(oldp+44,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[4]),4);
    bufp->fullCData(oldp+45,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[5]),4);
    bufp->fullCData(oldp+46,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[6]),4);
    bufp->fullCData(oldp+47,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[7]),4);
    bufp->fullCData(oldp+48,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[8]),4);
    bufp->fullCData(oldp+49,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[9]),4);
    bufp->fullCData(oldp+50,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[10]),4);
    bufp->fullCData(oldp+51,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[11]),4);
    bufp->fullCData(oldp+52,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[12]),4);
    bufp->fullCData(oldp+53,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[13]),4);
    bufp->fullCData(oldp+54,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[14]),4);
    bufp->fullCData(oldp+55,(vlSelfRef.tb_lfsr_4bit__DOT__expected_d[15]),4);
    bufp->fullBit(oldp+56,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[0]));
    bufp->fullBit(oldp+57,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[1]));
    bufp->fullBit(oldp+58,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[2]));
    bufp->fullBit(oldp+59,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[3]));
    bufp->fullBit(oldp+60,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[4]));
    bufp->fullBit(oldp+61,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[5]));
    bufp->fullBit(oldp+62,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[6]));
    bufp->fullBit(oldp+63,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[7]));
    bufp->fullBit(oldp+64,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[8]));
    bufp->fullBit(oldp+65,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[9]));
    bufp->fullBit(oldp+66,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[10]));
    bufp->fullBit(oldp+67,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[11]));
    bufp->fullBit(oldp+68,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[12]));
    bufp->fullBit(oldp+69,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[13]));
    bufp->fullBit(oldp+70,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[14]));
    bufp->fullBit(oldp+71,(vlSelfRef.tb_lfsr_4bit__DOT__expected_y[15]));
    bufp->fullBit(oldp+72,(vlSelfRef.tb_lfsr_4bit__DOT__clk));
    bufp->fullBit(oldp+73,((1U & (IData)(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d))));
    bufp->fullCData(oldp+74,(vlSelfRef.tb_lfsr_4bit__DOT__dut__DOT__d),4);
}
