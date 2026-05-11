// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_uart_tx.h for the primary calling header

#ifndef VERILATED_VTB_UART_TX___024ROOT_H_
#define VERILATED_VTB_UART_TX___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_uart_tx__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_uart_tx___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_uart_tx__DOT__PCLK;
    CData/*0:0*/ tb_uart_tx__DOT__PRESETn;
    CData/*7:0*/ tb_uart_tx__DOT__PWDATA;
    CData/*0:0*/ tb_uart_tx__DOT__tx_fifo_push;
    CData/*7:0*/ tb_uart_tx__DOT__LCR;
    CData/*0:0*/ tb_uart_tx__DOT__enable;
    CData/*0:0*/ tb_uart_tx__DOT__tx_fifo_empty;
    CData/*0:0*/ tb_uart_tx__DOT__tx_fifo_full;
    CData/*0:0*/ tb_uart_tx__DOT__busy;
    CData/*0:0*/ tb_uart_tx__DOT__TXD;
    CData/*0:0*/ tb_uart_tx__DOT__compute_expected_frame__Vstatic__parity_bit;
    CData/*7:0*/ tb_uart_tx__DOT__compute_expected_frame__Vstatic__unnamedblk1__DOT__masked_data;
    CData/*3:0*/ tb_uart_tx__DOT__dut__DOT__tx_state;
    CData/*3:0*/ tb_uart_tx__DOT__dut__DOT__bit_counter;
    CData/*7:0*/ tb_uart_tx__DOT__dut__DOT__tx_buffer;
    CData/*0:0*/ tb_uart_tx__DOT__dut__DOT__pop_tx_fifo;
    CData/*7:0*/ tb_uart_tx__DOT__dut__DOT__lcr_latched;
    CData/*0:0*/ tb_uart_tx__DOT__dut__DOT__half_stop_flag;
    CData/*3:0*/ tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__ip_count;
    CData/*3:0*/ tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__op_count;
    CData/*4:0*/ tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__count;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_tx__DOT__PCLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_tx__DOT__PRESETn__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*15:0*/ tb_uart_tx__DOT__sampled_frame;
    SData/*15:0*/ tb_uart_tx__DOT__expected_frame;
    SData/*15:0*/ tb_uart_tx__DOT__sample_frame__Vstatic__frame;
    SData/*15:0*/ tb_uart_tx__DOT__compute_expected_frame__Vstatic__frame;
    IData/*31:0*/ tb_uart_tx__DOT__test_num;
    IData/*31:0*/ tb_uart_tx__DOT__pass_count;
    IData/*31:0*/ tb_uart_tx__DOT__fail_count;
    IData/*31:0*/ tb_uart_tx__DOT__err_flag;
    IData/*31:0*/ tb_uart_tx__DOT__wait_not_busy__Vstatic__i;
    IData/*31:0*/ tb_uart_tx__DOT__sample_frame__Vstatic__num_data_bits;
    IData/*31:0*/ tb_uart_tx__DOT__sample_frame__Vstatic__num_bits_to_sample;
    IData/*31:0*/ tb_uart_tx__DOT__sample_frame__Vstatic__i;
    IData/*31:0*/ tb_uart_tx__DOT__compute_expected_frame__Vstatic__num_data_bits;
    IData/*31:0*/ tb_uart_tx__DOT__compute_expected_frame__Vstatic__i;
    IData/*31:0*/ tb_uart_tx__DOT__check_frame__Vstatic__num_data_bits;
    IData/*31:0*/ tb_uart_tx__DOT__check_frame__Vstatic__num_bits_to_check;
    IData/*31:0*/ tb_uart_tx__DOT__check_frame__Vstatic__i;
    IData/*31:0*/ tb_uart_tx__DOT__check_frame__Vstatic__bit_errors;
    IData/*31:0*/ tb_uart_tx__DOT__i;
    IData/*31:0*/ tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__i;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*7:0*/, 16> tb_uart_tx__DOT__dut__DOT__u_fifo__DOT__data_fifo;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hcefd327b__0;

    // INTERNAL VARIABLES
    Vtb_uart_tx__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_uart_tx___024root(Vtb_uart_tx__Syms* symsp, const char* namep);
    ~Vtb_uart_tx___024root();
    VL_UNCOPYABLE(Vtb_uart_tx___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
