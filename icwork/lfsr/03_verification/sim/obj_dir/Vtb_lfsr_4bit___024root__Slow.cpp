// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_lfsr_4bit.h for the primary calling header

#include "Vtb_lfsr_4bit__pch.h"

void Vtb_lfsr_4bit___024root___ctor_var_reset(Vtb_lfsr_4bit___024root* vlSelf);

Vtb_lfsr_4bit___024root::Vtb_lfsr_4bit___024root(Vtb_lfsr_4bit__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_lfsr_4bit___024root___ctor_var_reset(this);
}

void Vtb_lfsr_4bit___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_lfsr_4bit___024root::~Vtb_lfsr_4bit___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
