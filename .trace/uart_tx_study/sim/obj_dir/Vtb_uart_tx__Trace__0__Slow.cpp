// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_uart_tx__Syms.h"


VL_ATTR_COLD void Vtb_uart_tx___024root__trace_init_sub__TOP__0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_init_sub__TOP__0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("tb_uart_tx", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+57,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"PCLK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"PRESETn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"PWDATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+16,0,"tx_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"LCR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+18,0,"enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"tx_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"tx_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"tx_fifo_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+28,0,"busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"TXD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"test_num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+20,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+21,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+58,0,"err_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+22,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+23,0,"sampled_frame",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+24,0,"expected_frame",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+0,0,"wait_not_busy__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1,0,"sample_frame__Vstatic__num_data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+2,0,"sample_frame__Vstatic__num_bits_to_sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+3,0,"sample_frame__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+4,0,"sample_frame__Vstatic__frame",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"compute_expected_frame__Vstatic__num_data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+6,0,"compute_expected_frame__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+7,0,"compute_expected_frame__Vstatic__frame",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+8,0,"compute_expected_frame__Vstatic__parity_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"check_frame__Vstatic__num_data_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+10,0,"check_frame__Vstatic__num_bits_to_check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+11,0,"check_frame__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+12,0,"check_frame__Vstatic__bit_errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("compute_expected_frame__Vstatic__unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+13,0,"masked_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+56,0,"PCLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"PRESETn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"PWDATA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+16,0,"tx_fifo_push",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"LCR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+18,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"tx_fifo_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"tx_fifo_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"tx_fifo_count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+28,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"TXD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"S_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+60,0,"S_START",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+61,0,"S_BIT0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+62,0,"S_BIT1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+63,0,"S_BIT2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+64,0,"S_BIT3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+65,0,"S_BIT4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+66,0,"S_BIT5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+67,0,"S_BIT6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+68,0,"S_BIT7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+69,0,"S_PARITY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"S_STOP1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+71,0,"S_STOP2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+30,0,"tx_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+31,0,"bit_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+32,0,"tx_buffer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+33,0,"pop_tx_fifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"lcr_latched",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+35,0,"half_stop_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"tx_fifo_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+25,0,"tx_fifo_empty_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"tx_fifo_full_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"tx_fifo_count_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("u_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+56,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"push",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+26,0,"tx_fifo_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"pop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"rd_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+25,0,"tx_fifo_empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"count_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"FIFO_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("data_fifo", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+37+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+53,0,"ip_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+54,0,"op_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+55,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_init_top(Vtb_uart_tx___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_init_top\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_uart_tx___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_uart_tx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_uart_tx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_register(Vtb_uart_tx___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_register\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_uart_tx___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_uart_tx___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_uart_tx___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_uart_tx___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_const_0\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_uart_tx___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_const_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_const_0_sub_0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+57,(0x0000000aU),32);
    bufp->fullIData(oldp+58,(vlSelfRef.tb_uart_tx__DOT__err_flag),32);
    bufp->fullCData(oldp+59,(0U),4);
    bufp->fullCData(oldp+60,(1U),4);
    bufp->fullCData(oldp+61,(2U),4);
    bufp->fullCData(oldp+62,(3U),4);
    bufp->fullCData(oldp+63,(4U),4);
    bufp->fullCData(oldp+64,(5U),4);
    bufp->fullCData(oldp+65,(6U),4);
    bufp->fullCData(oldp+66,(7U),4);
    bufp->fullCData(oldp+67,(8U),4);
    bufp->fullCData(oldp+68,(9U),4);
    bufp->fullCData(oldp+69,(0x0aU),4);
    bufp->fullCData(oldp+70,(0x0bU),4);
    bufp->fullCData(oldp+71,(0x0cU),4);
    bufp->fullIData(oldp+72,(0x00000010U),32);
    bufp->fullIData(oldp+73,(8U),32);
    bufp->fullIData(oldp+74,(4U),32);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_full_0\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_uart_tx___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_uart_tx___024root__trace_full_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_full_0_sub_0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i),32);
    bufp->fullIData(oldp+1,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample),32);
    bufp->fullIData(oldp+3,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i),32);
    bufp->fullSData(oldp+4,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame),16);
    bufp->fullIData(oldp+5,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i),32);
    bufp->fullSData(oldp+7,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame),16);
    bufp->fullBit(oldp+8,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit));
    bufp->fullIData(oldp+9,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits),32);
    bufp->fullIData(oldp+10,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check),32);
    bufp->fullIData(oldp+11,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i),32);
    bufp->fullIData(oldp+12,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors),32);
    bufp->fullCData(oldp+13,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data),8);
    bufp->fullBit(oldp+14,(vlSelfRef.tb_uart_tx__DOT__PRESETn));
    bufp->fullCData(oldp+15,(vlSelfRef.tb_uart_tx__DOT__PWDATA),8);
    bufp->fullBit(oldp+16,(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push));
    bufp->fullCData(oldp+17,(vlSelfRef.tb_uart_tx__DOT__LCR),8);
    bufp->fullBit(oldp+18,(vlSelfRef.tb_uart_tx__DOT__enable));
    bufp->fullIData(oldp+19,(vlSelfRef.tb_uart_tx__DOT__test_num),32);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_uart_tx__DOT__pass_count),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_uart_tx__DOT__fail_count),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb_uart_tx__DOT__i),32);
    bufp->fullSData(oldp+23,(vlSelfRef.tb_uart_tx__DOT__sampled_frame),16);
    bufp->fullSData(oldp+24,(vlSelfRef.tb_uart_tx__DOT__expected_frame),16);
    bufp->fullBit(oldp+25,((0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))));
    bufp->fullBit(oldp+26,((0x10U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))));
    bufp->fullCData(oldp+27,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count),5);
    bufp->fullBit(oldp+28,(vlSelfRef.tb_uart_tx__DOT__busy));
    bufp->fullBit(oldp+29,(vlSelfRef.tb_uart_tx__DOT__TXD));
    bufp->fullCData(oldp+30,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state),4);
    bufp->fullCData(oldp+31,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter),4);
    bufp->fullCData(oldp+32,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer),8);
    bufp->fullBit(oldp+33,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo));
    bufp->fullCData(oldp+34,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched),8);
    bufp->fullBit(oldp+35,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag));
    bufp->fullCData(oldp+36,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo
                             [vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count]),8);
    bufp->fullCData(oldp+37,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[0]),8);
    bufp->fullCData(oldp+38,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[1]),8);
    bufp->fullCData(oldp+39,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[2]),8);
    bufp->fullCData(oldp+40,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[3]),8);
    bufp->fullCData(oldp+41,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[4]),8);
    bufp->fullCData(oldp+42,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[5]),8);
    bufp->fullCData(oldp+43,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[6]),8);
    bufp->fullCData(oldp+44,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[7]),8);
    bufp->fullCData(oldp+45,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[8]),8);
    bufp->fullCData(oldp+46,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[9]),8);
    bufp->fullCData(oldp+47,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[10]),8);
    bufp->fullCData(oldp+48,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[11]),8);
    bufp->fullCData(oldp+49,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[12]),8);
    bufp->fullCData(oldp+50,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[13]),8);
    bufp->fullCData(oldp+51,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[14]),8);
    bufp->fullCData(oldp+52,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[15]),8);
    bufp->fullCData(oldp+53,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count),4);
    bufp->fullCData(oldp+54,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count),4);
    bufp->fullIData(oldp+55,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__i),32);
    bufp->fullBit(oldp+56,(vlSelfRef.tb_uart_tx__DOT__PCLK));
}
