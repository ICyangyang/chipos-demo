// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_lfsr_4bit.h for the primary calling header

#ifndef VERILATED_VTB_LFSR_4BIT___024ROOT_H_
#define VERILATED_VTB_LFSR_4BIT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_lfsr_4bit__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_lfsr_4bit___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_lfsr_4bit__DOT__clk;
    CData/*0:0*/ tb_lfsr_4bit__DOT__res;
    CData/*0:0*/ tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_15;
    CData/*0:0*/ tb_lfsr_4bit__DOT__test_periodicity__Vstatic__y_at_cycle_16;
    CData/*3:0*/ tb_lfsr_4bit__DOT__dut__DOT__d;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_lfsr_4bit__DOT__res__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_lfsr_4bit__DOT__total_tests;
    IData/*31:0*/ tb_lfsr_4bit__DOT__passed_tests;
    IData/*31:0*/ tb_lfsr_4bit__DOT__failed_tests;
    IData/*31:0*/ tb_lfsr_4bit__DOT__test_sequence__Vstatic__cycle;
    IData/*31:0*/ tb_lfsr_4bit__DOT__test_periodicity__Vstatic__sv2v_autoblock_1__DOT__cycle;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*3:0*/, 16> tb_lfsr_4bit__DOT__expected_d;
    VlUnpacked<CData/*0:0*/, 16> tb_lfsr_4bit__DOT__expected_y;
    VlUnpacked<CData/*3:0*/, 16> tb_lfsr_4bit__DOT__test_sequence__Vstatic__state_trace;
    VlUnpacked<CData/*0:0*/, 16> tb_lfsr_4bit__DOT__test_sequence__Vstatic__output_trace;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_ha65afd0f__0;
    VlTriggerScheduler __VtrigSched_ha65afde3__0;

    // INTERNAL VARIABLES
    Vtb_lfsr_4bit__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_lfsr_4bit___024root(Vtb_lfsr_4bit__Syms* symsp, const char* namep);
    ~Vtb_lfsr_4bit___024root();
    VL_UNCOPYABLE(Vtb_lfsr_4bit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
