// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_uart_tx__Syms.h"


void Vtb_uart_tx___024root__trace_chg_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_uart_tx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_chg_0\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_uart_tx___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_uart_tx___024root__trace_chg_0_sub_0(Vtb_uart_tx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_chg_0_sub_0\n"); );
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_uart_tx__DOT__wait_not_busy__Vstatic__i),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__i),32);
        bufp->chgSData(oldp+4,(vlSelfRef.tb_uart_tx__DOT__sample_frame__Vstatic__frame),16);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__i),32);
        bufp->chgSData(oldp+7,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame),16);
        bufp->chgBit(oldp+8,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit));
        bufp->chgIData(oldp+9,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits),32);
        bufp->chgIData(oldp+10,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check),32);
        bufp->chgIData(oldp+11,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__i),32);
        bufp->chgIData(oldp+12,(vlSelfRef.tb_uart_tx__DOT__check_frame__Vstatic__bit_errors),32);
        bufp->chgCData(oldp+13,(vlSelfRef.tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data),8);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgBit(oldp+14,(vlSelfRef.tb_uart_tx__DOT__PRESETn));
        bufp->chgCData(oldp+15,(vlSelfRef.tb_uart_tx__DOT__PWDATA),8);
        bufp->chgBit(oldp+16,(vlSelfRef.tb_uart_tx__DOT__tx_fifo_push));
        bufp->chgCData(oldp+17,(vlSelfRef.tb_uart_tx__DOT__LCR),8);
        bufp->chgBit(oldp+18,(vlSelfRef.tb_uart_tx__DOT__enable));
        bufp->chgIData(oldp+19,(vlSelfRef.tb_uart_tx__DOT__test_num),32);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_uart_tx__DOT__pass_count),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb_uart_tx__DOT__fail_count),32);
        bufp->chgSData(oldp+22,(vlSelfRef.tb_uart_tx__DOT__sampled_frame),16);
        bufp->chgSData(oldp+23,(vlSelfRef.tb_uart_tx__DOT__expected_frame),16);
        bufp->chgIData(oldp+24,(vlSelfRef.tb_uart_tx__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+25,((0U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))));
        bufp->chgBit(oldp+26,((0x10U == (IData)(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count))));
        bufp->chgCData(oldp+27,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count),5);
        bufp->chgBit(oldp+28,(vlSelfRef.tb_uart_tx__DOT__busy));
        bufp->chgBit(oldp+29,(vlSelfRef.tb_uart_tx__DOT__TXD));
        bufp->chgCData(oldp+30,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_state),4);
        bufp->chgCData(oldp+31,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__bit_counter),4);
        bufp->chgCData(oldp+32,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__tx_buffer),8);
        bufp->chgBit(oldp+33,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__pop_tx_fifo));
        bufp->chgCData(oldp+34,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__lcr_latched),8);
        bufp->chgBit(oldp+35,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__half_stop_flag));
        bufp->chgCData(oldp+36,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo
                                [vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count]),8);
        bufp->chgCData(oldp+37,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[0]),8);
        bufp->chgCData(oldp+38,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[1]),8);
        bufp->chgCData(oldp+39,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[2]),8);
        bufp->chgCData(oldp+40,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[3]),8);
        bufp->chgCData(oldp+41,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[4]),8);
        bufp->chgCData(oldp+42,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[5]),8);
        bufp->chgCData(oldp+43,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[6]),8);
        bufp->chgCData(oldp+44,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[7]),8);
        bufp->chgCData(oldp+45,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[8]),8);
        bufp->chgCData(oldp+46,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[9]),8);
        bufp->chgCData(oldp+47,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[10]),8);
        bufp->chgCData(oldp+48,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[11]),8);
        bufp->chgCData(oldp+49,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[12]),8);
        bufp->chgCData(oldp+50,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[13]),8);
        bufp->chgCData(oldp+51,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[14]),8);
        bufp->chgCData(oldp+52,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo[15]),8);
        bufp->chgCData(oldp+53,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count),4);
        bufp->chgCData(oldp+54,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count),4);
        bufp->chgIData(oldp+55,(vlSelfRef.tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__i),32);
    }
    bufp->chgBit(oldp+56,(vlSelfRef.tb_uart_tx__DOT__PCLK));
}

void Vtb_uart_tx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_uart_tx___024root__trace_cleanup\n"); );
    // Body
    Vtb_uart_tx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_uart_tx___024root*>(voidSelf);
    Vtb_uart_tx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
