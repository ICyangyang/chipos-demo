// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_mux2to1.h for the primary calling header

#ifndef VERILATED_VTB_MUX2TO1___024ROOT_H_
#define VERILATED_VTB_MUX2TO1___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_mux2to1__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_mux2to1___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ tb_mux2to1__DOT__in0;
    CData/*7:0*/ tb_mux2to1__DOT__in1;
    CData/*0:0*/ tb_mux2to1__DOT__sel;
    CData/*7:0*/ tb_mux2to1__DOT__out;
    CData/*0:0*/ tb_mux2to1__DOT__clk;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_mux2to1__DOT__test_count;
    IData/*31:0*/ tb_mux2to1__DOT__pass_count;
    IData/*31:0*/ tb_mux2to1__DOT__fail_count;
    VlWide<8>/*255:0*/ tb_mux2to1__DOT__test_name;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_mux2to1__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_mux2to1___024root(Vtb_mux2to1__Syms* symsp, const char* namep);
    ~Vtb_mux2to1___024root();
    VL_UNCOPYABLE(Vtb_mux2to1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
