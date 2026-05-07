// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_mux2to1.h for the primary calling header

#include "Vtb_mux2to1__pch.h"

void Vtb_mux2to1___024root___ctor_var_reset(Vtb_mux2to1___024root* vlSelf);

Vtb_mux2to1___024root::Vtb_mux2to1___024root(Vtb_mux2to1__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_mux2to1___024root___ctor_var_reset(this);
}

void Vtb_mux2to1___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_mux2to1___024root::~Vtb_mux2to1___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
