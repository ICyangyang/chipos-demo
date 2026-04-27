// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_mux2to1.h for the primary calling header

#include "Vtb_mux2to1__pch.h"

VL_ATTR_COLD void Vtb_mux2to1___024root___eval_initial__TOP(Vtb_mux2to1___024root* vlSelf);
VlCoroutine Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__0(Vtb_mux2to1___024root* vlSelf);
VlCoroutine Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__1(Vtb_mux2to1___024root* vlSelf);
VlCoroutine Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__2(Vtb_mux2to1___024root* vlSelf);

void Vtb_mux2to1___024root___eval_initial(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_initial\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_mux2to1___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__0(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_mux2to1__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                             22);
        vlSelfRef.tb_mux2to1__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_mux2to1__DOT__clk)));
    }
    co_return;
}

extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_he4dc0fd2_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h8201d201_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h44935d8e_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_he4dc5e61_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h8201c290_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h9d536ddd_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h0a3d75fa_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h1de09444_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_hcbd6f443_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h94fb0d63_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h3cbf1f04_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h71904359_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_hacd27b04_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h95199759_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h1183dce3_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_h3f333acb_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_hd1cee0bb_0;
extern const VlWide<8>/*255:0*/ Vtb_mux2to1__ConstPool__CONST_hf45cbd50_0;

VlCoroutine Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__1(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_mux2to1__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_mux2to1__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ tb_mux2to1__DOT__unnamedblk1_2__DOT____Vrepeat1;
    tb_mux2to1__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__0__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__0__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__0__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__0__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__0__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__0__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__0__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__0__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__0__expected;
    __Vtask_tb_mux2to1__DOT__run_test__0__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__1__expected;
    __Vtask_tb_mux2to1__DOT__check_output__1__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__1__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__1__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__2__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__2__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__2__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__2__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__2__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__2__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__2__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__2__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__2__expected;
    __Vtask_tb_mux2to1__DOT__run_test__2__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__3__expected;
    __Vtask_tb_mux2to1__DOT__check_output__3__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__3__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__3__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__4__expected;
    __Vtask_tb_mux2to1__DOT__check_output__4__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__4__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__4__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__5__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__5__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__5__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__5__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__5__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__5__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__5__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__5__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__5__expected;
    __Vtask_tb_mux2to1__DOT__run_test__5__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__6__expected;
    __Vtask_tb_mux2to1__DOT__check_output__6__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__6__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__6__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__7__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__7__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__7__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__7__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__7__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__7__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__7__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__7__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__7__expected;
    __Vtask_tb_mux2to1__DOT__run_test__7__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__8__expected;
    __Vtask_tb_mux2to1__DOT__check_output__8__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__8__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__8__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__9__expected;
    __Vtask_tb_mux2to1__DOT__check_output__9__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__9__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__9__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__10__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__10__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__10__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__10__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__10__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__10__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__10__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__10__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__10__expected;
    __Vtask_tb_mux2to1__DOT__run_test__10__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__11__expected;
    __Vtask_tb_mux2to1__DOT__check_output__11__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__11__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__11__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__12__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__12__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__12__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__12__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__12__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__12__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__12__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__12__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__12__expected;
    __Vtask_tb_mux2to1__DOT__run_test__12__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__13__expected;
    __Vtask_tb_mux2to1__DOT__check_output__13__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__13__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__13__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__14__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__14__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__14__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__14__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__14__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__14__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__14__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__14__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__14__expected;
    __Vtask_tb_mux2to1__DOT__run_test__14__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__15__expected;
    __Vtask_tb_mux2to1__DOT__check_output__15__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__15__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__15__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__16__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__16__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__16__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__16__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__16__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__16__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__16__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__16__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__16__expected;
    __Vtask_tb_mux2to1__DOT__run_test__16__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__17__expected;
    __Vtask_tb_mux2to1__DOT__check_output__17__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__17__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__17__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__18__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__18__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__18__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__18__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__18__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__18__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__18__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__18__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__18__expected;
    __Vtask_tb_mux2to1__DOT__run_test__18__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__19__expected;
    __Vtask_tb_mux2to1__DOT__check_output__19__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__19__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__19__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__20__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__20__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__20__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__20__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__20__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__20__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__20__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__20__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__20__expected;
    __Vtask_tb_mux2to1__DOT__run_test__20__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__21__expected;
    __Vtask_tb_mux2to1__DOT__check_output__21__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__21__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__21__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__22__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__22__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__22__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__22__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__22__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__22__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__22__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__22__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__22__expected;
    __Vtask_tb_mux2to1__DOT__run_test__22__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__23__expected;
    __Vtask_tb_mux2to1__DOT__check_output__23__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__23__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__23__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__24__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__24__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__24__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__24__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__24__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__24__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__24__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__24__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__24__expected;
    __Vtask_tb_mux2to1__DOT__run_test__24__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__25__expected;
    __Vtask_tb_mux2to1__DOT__check_output__25__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__25__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__25__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__26__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__26__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__26__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__26__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__26__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__26__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__26__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__26__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__26__expected;
    __Vtask_tb_mux2to1__DOT__run_test__26__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__27__expected;
    __Vtask_tb_mux2to1__DOT__check_output__27__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__27__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__27__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__28__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__28__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__28__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__28__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__28__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__28__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__28__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__28__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__28__expected;
    __Vtask_tb_mux2to1__DOT__run_test__28__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__29__expected;
    __Vtask_tb_mux2to1__DOT__check_output__29__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__29__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__29__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__30__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__30__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__30__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__30__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__30__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__30__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__30__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__30__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__30__expected;
    __Vtask_tb_mux2to1__DOT__run_test__30__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__31__expected;
    __Vtask_tb_mux2to1__DOT__check_output__31__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__31__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__31__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__32__t_in0;
    __Vtask_tb_mux2to1__DOT__run_test__32__t_in0 = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__32__t_in1;
    __Vtask_tb_mux2to1__DOT__run_test__32__t_in1 = 0;
    CData/*0:0*/ __Vtask_tb_mux2to1__DOT__run_test__32__t_sel;
    __Vtask_tb_mux2to1__DOT__run_test__32__t_sel = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__run_test__32__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__run_test__32__tname);
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__run_test__32__expected;
    __Vtask_tb_mux2to1__DOT__run_test__32__expected = 0;
    CData/*7:0*/ __Vtask_tb_mux2to1__DOT__check_output__33__expected;
    __Vtask_tb_mux2to1__DOT__check_output__33__expected = 0;
    VlWide<8>/*255:0*/ __Vtask_tb_mux2to1__DOT__check_output__33__tname;
    VL_ZERO_W(256, __Vtask_tb_mux2to1__DOT__check_output__33__tname);
    // Body
    VL_WRITEF_NX("============================================================\n  Testbench for mux2to1 (DATA_WIDTH = 8)\n============================================================\n",0);
    vlSelfRef.tb_mux2to1__DOT__in0 = 0U;
    vlSelfRef.tb_mux2to1__DOT__in1 = 0U;
    vlSelfRef.tb_mux2to1__DOT__sel = 0U;
    vlSelfRef.tb_mux2to1__DOT__test_count = 0U;
    vlSelfRef.tb_mux2to1__DOT__pass_count = 0U;
    vlSelfRef.tb_mux2to1__DOT__fail_count = 0U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         69);
    VL_WRITEF_NX("\n--- Test Group 1: sel=0 (out = in0) ---\n",0);
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__0__tname, Vtb_mux2to1__ConstPool__CONST_he4dc0fd2_0);
    __Vtask_tb_mux2to1__DOT__run_test__0__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__0__t_in1 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__0__t_in0 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__0__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__0__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__0__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__0__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__0__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__0__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__0__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__0__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__1__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__0__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__1__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__0__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__1__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__1__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__1__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__1__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__2__tname, Vtb_mux2to1__ConstPool__CONST_h8201d201_0);
    __Vtask_tb_mux2to1__DOT__run_test__2__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__2__t_in1 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__2__t_in0 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__2__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__2__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__2__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__2__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__2__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__2__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__2__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__2__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__3__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__2__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__3__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__2__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__3__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__3__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__3__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__3__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    tb_mux2to1__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0x00000014U;
    while (VL_LTS_III(32, 0U, tb_mux2to1__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        vlSelfRef.tb_mux2to1__DOT__in0 = (0x000000ffU 
                                          & VL_RANDOM_I());
        vlSelfRef.tb_mux2to1__DOT__in1 = (0x000000ffU 
                                          & VL_RANDOM_I());
        vlSelfRef.tb_mux2to1__DOT__sel = 0U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                             78);
        VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__check_output__4__tname, Vtb_mux2to1__ConstPool__CONST_h44935d8e_0);
        __Vtask_tb_mux2to1__DOT__check_output__4__expected 
            = vlSelfRef.tb_mux2to1__DOT__in0;
        vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__test_count);
        if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) 
             == (IData)(__Vtask_tb_mux2to1__DOT__check_output__4__expected))) {
            vlSelfRef.tb_mux2to1__DOT__pass_count = 
                ((IData)(1U) + vlSelfRef.tb_mux2to1__DOT__pass_count);
            VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,
                         32,vlSelfRef.tb_mux2to1__DOT__test_count,
                         256,__Vtask_tb_mux2to1__DOT__check_output__4__tname.data());
        } else {
            vlSelfRef.tb_mux2to1__DOT__fail_count = 
                ((IData)(1U) + vlSelfRef.tb_mux2to1__DOT__fail_count);
            VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                         32,vlSelfRef.tb_mux2to1__DOT__test_count,
                         256,__Vtask_tb_mux2to1__DOT__check_output__4__tname.data(),
                         8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__4__expected),
                         8,vlSelfRef.tb_mux2to1__DOT__out);
        }
        tb_mux2to1__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_mux2to1__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\n--- Test Group 2: sel=1 (out = in1) ---\n",0);
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__5__tname, Vtb_mux2to1__ConstPool__CONST_he4dc5e61_0);
    __Vtask_tb_mux2to1__DOT__run_test__5__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__5__t_in1 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__5__t_in0 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__5__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__5__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__5__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__5__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__5__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__5__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__5__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__5__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__6__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__5__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__6__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__5__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__6__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__6__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__6__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__6__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__7__tname, Vtb_mux2to1__ConstPool__CONST_h8201c290_0);
    __Vtask_tb_mux2to1__DOT__run_test__7__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__7__t_in1 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__7__t_in0 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__7__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__7__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__7__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__7__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__7__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__7__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__7__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__7__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__8__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__7__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__8__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__7__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__8__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__8__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__8__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__8__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    tb_mux2to1__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0x00000014U;
    while (VL_LTS_III(32, 0U, tb_mux2to1__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        vlSelfRef.tb_mux2to1__DOT__in0 = (0x000000ffU 
                                          & VL_RANDOM_I());
        vlSelfRef.tb_mux2to1__DOT__in1 = (0x000000ffU 
                                          & VL_RANDOM_I());
        vlSelfRef.tb_mux2to1__DOT__sel = 1U;
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                             89);
        VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__check_output__9__tname, Vtb_mux2to1__ConstPool__CONST_h9d536ddd_0);
        __Vtask_tb_mux2to1__DOT__check_output__9__expected 
            = vlSelfRef.tb_mux2to1__DOT__in1;
        vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__test_count);
        if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) 
             == (IData)(__Vtask_tb_mux2to1__DOT__check_output__9__expected))) {
            vlSelfRef.tb_mux2to1__DOT__pass_count = 
                ((IData)(1U) + vlSelfRef.tb_mux2to1__DOT__pass_count);
            VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,
                         32,vlSelfRef.tb_mux2to1__DOT__test_count,
                         256,__Vtask_tb_mux2to1__DOT__check_output__9__tname.data());
        } else {
            vlSelfRef.tb_mux2to1__DOT__fail_count = 
                ((IData)(1U) + vlSelfRef.tb_mux2to1__DOT__fail_count);
            VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                         32,vlSelfRef.tb_mux2to1__DOT__test_count,
                         256,__Vtask_tb_mux2to1__DOT__check_output__9__tname.data(),
                         8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__9__expected),
                         8,vlSelfRef.tb_mux2to1__DOT__out);
        }
        tb_mux2to1__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (tb_mux2to1__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    VL_WRITEF_NX("\n--- Test Group 3: Boundary Conditions ---\n",0);
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__10__tname, Vtb_mux2to1__ConstPool__CONST_h0a3d75fa_0);
    __Vtask_tb_mux2to1__DOT__run_test__10__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__10__t_in1 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__10__t_in0 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__10__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__10__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__10__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__10__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__10__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__10__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__10__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__10__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__11__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__10__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__11__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__10__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__11__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__11__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__11__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__11__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__12__tname, Vtb_mux2to1__ConstPool__CONST_h1de09444_0);
    __Vtask_tb_mux2to1__DOT__run_test__12__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__12__t_in1 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__12__t_in0 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__12__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__12__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__12__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__12__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__12__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__12__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__12__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__12__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__13__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__12__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__13__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__12__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__13__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__13__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__13__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__13__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__14__tname, Vtb_mux2to1__ConstPool__CONST_hcbd6f443_0);
    __Vtask_tb_mux2to1__DOT__run_test__14__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__14__t_in1 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__14__t_in0 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__14__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__14__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__14__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__14__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__14__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__14__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__14__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__14__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__15__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__14__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__15__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__14__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__15__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__15__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__15__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__15__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__16__tname, Vtb_mux2to1__ConstPool__CONST_h94fb0d63_0);
    __Vtask_tb_mux2to1__DOT__run_test__16__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__16__t_in1 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__16__t_in0 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__16__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__16__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__16__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__16__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__16__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__16__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__16__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__16__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__17__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__16__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__17__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__16__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__17__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__17__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__17__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__17__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__18__tname, Vtb_mux2to1__ConstPool__CONST_h3cbf1f04_0);
    __Vtask_tb_mux2to1__DOT__run_test__18__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__18__t_in1 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__18__t_in0 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__18__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__18__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__18__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__18__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__18__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__18__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__18__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__18__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__19__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__18__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__19__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__18__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__19__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__19__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__19__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__19__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__20__tname, Vtb_mux2to1__ConstPool__CONST_h71904359_0);
    __Vtask_tb_mux2to1__DOT__run_test__20__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__20__t_in1 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__20__t_in0 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__20__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__20__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__20__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__20__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__20__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__20__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__20__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__20__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__21__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__20__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__21__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__20__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__21__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__21__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__21__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__21__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__22__tname, Vtb_mux2to1__ConstPool__CONST_hacd27b04_0);
    __Vtask_tb_mux2to1__DOT__run_test__22__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__22__t_in1 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__22__t_in0 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__22__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__22__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__22__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__22__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__22__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__22__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__22__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__22__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__23__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__22__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__23__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__22__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__23__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__23__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__23__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__23__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__24__tname, Vtb_mux2to1__ConstPool__CONST_h95199759_0);
    __Vtask_tb_mux2to1__DOT__run_test__24__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__24__t_in1 = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__24__t_in0 = 0xffU;
    __Vtask_tb_mux2to1__DOT__run_test__24__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__24__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__24__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__24__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__24__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__24__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__24__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__24__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__25__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__24__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__25__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__24__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__25__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__25__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__25__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__25__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_WRITEF_NX("\n--- Test Group 4: Toggle Patterns ---\n",0);
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__26__tname, Vtb_mux2to1__ConstPool__CONST_h1183dce3_0);
    __Vtask_tb_mux2to1__DOT__run_test__26__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__26__t_in1 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__26__t_in0 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__26__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__26__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__26__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__26__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__26__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__26__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__26__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__26__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__27__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__26__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__27__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__26__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__27__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__27__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__27__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__27__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__28__tname, Vtb_mux2to1__ConstPool__CONST_h3f333acb_0);
    __Vtask_tb_mux2to1__DOT__run_test__28__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__28__t_in1 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__28__t_in0 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__28__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__28__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__28__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__28__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__28__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__28__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__28__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__28__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__29__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__28__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__29__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__28__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__29__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__29__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__29__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__29__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__30__tname, Vtb_mux2to1__ConstPool__CONST_hd1cee0bb_0);
    __Vtask_tb_mux2to1__DOT__run_test__30__t_sel = 0U;
    __Vtask_tb_mux2to1__DOT__run_test__30__t_in1 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__30__t_in0 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__30__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__30__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__30__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__30__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__30__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__30__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__30__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__30__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__31__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__30__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__31__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__30__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__31__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__31__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__31__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__31__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    VL_ASSIGN_W(256, __Vtask_tb_mux2to1__DOT__run_test__32__tname, Vtb_mux2to1__ConstPool__CONST_hf45cbd50_0);
    __Vtask_tb_mux2to1__DOT__run_test__32__t_sel = 1U;
    __Vtask_tb_mux2to1__DOT__run_test__32__t_in1 = 0x55U;
    __Vtask_tb_mux2to1__DOT__run_test__32__t_in0 = 0xaaU;
    __Vtask_tb_mux2to1__DOT__run_test__32__expected = 0;
    vlSelfRef.tb_mux2to1__DOT__in0 = __Vtask_tb_mux2to1__DOT__run_test__32__t_in0;
    vlSelfRef.tb_mux2to1__DOT__in1 = __Vtask_tb_mux2to1__DOT__run_test__32__t_in1;
    vlSelfRef.tb_mux2to1__DOT__sel = __Vtask_tb_mux2to1__DOT__run_test__32__t_sel;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         53);
    __Vtask_tb_mux2to1__DOT__run_test__32__expected 
        = ((IData)(__Vtask_tb_mux2to1__DOT__run_test__32__t_sel)
            ? (IData)(__Vtask_tb_mux2to1__DOT__run_test__32__t_in1)
            : (IData)(__Vtask_tb_mux2to1__DOT__run_test__32__t_in0));
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[0U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[0U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[1U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[1U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[2U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[2U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[3U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[3U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[4U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[4U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[5U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[5U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[6U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[6U];
    __Vtask_tb_mux2to1__DOT__check_output__33__tname[7U] 
        = __Vtask_tb_mux2to1__DOT__run_test__32__tname[7U];
    __Vtask_tb_mux2to1__DOT__check_output__33__expected 
        = __Vtask_tb_mux2to1__DOT__run_test__32__expected;
    vlSelfRef.tb_mux2to1__DOT__test_count = ((IData)(1U) 
                                             + vlSelfRef.tb_mux2to1__DOT__test_count);
    if (((IData)(vlSelfRef.tb_mux2to1__DOT__out) == (IData)(__Vtask_tb_mux2to1__DOT__check_output__33__expected))) {
        vlSelfRef.tb_mux2to1__DOT__pass_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__pass_count);
        VL_WRITEF_NX("[PASS] Test %0d: %s\n",0,32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__33__tname.data());
    } else {
        vlSelfRef.tb_mux2to1__DOT__fail_count = ((IData)(1U) 
                                                 + vlSelfRef.tb_mux2to1__DOT__fail_count);
        VL_WRITEF_NX("[FAIL] Test %0d: %s - Expected: 0x%x, Got: 0x%x\n",0,
                     32,vlSelfRef.tb_mux2to1__DOT__test_count,
                     256,__Vtask_tb_mux2to1__DOT__check_output__33__tname.data(),
                     8,(IData)(__Vtask_tb_mux2to1__DOT__check_output__33__expected),
                     8,vlSelfRef.tb_mux2to1__DOT__out);
    }
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                         nullptr, "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         107);
    VL_WRITEF_NX("\n============================================================\n  Test Summary: DATA_WIDTH = 8\n  Total Tests:  %0d\n  Passed:       %0d\n  Failed:       %0d\n============================================================\n",0,
                 32,vlSelfRef.tb_mux2to1__DOT__test_count,
                 32,vlSelfRef.tb_mux2to1__DOT__pass_count,
                 32,vlSelfRef.tb_mux2to1__DOT__fail_count);
    if ((0U == vlSelfRef.tb_mux2to1__DOT__fail_count)) {
        VL_WRITEF_NX("\n>>> ALL TESTS PASSED <<<\n\n",0);
    } else {
        VL_WRITEF_NX("\n>>> SOME TESTS FAILED <<<\n\n",0);
    }
    VL_FINISH_MT("/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 119, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;
}

VlCoroutine Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__2(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x00000000000186a0ULL, 
                                         nullptr, "/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 
                                         122);
    VL_WRITEF_NX("\n[ERROR] Simulation timeout - possible infinite loop\n",0);
    VL_FINISH_MT("/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 125, "");
    co_return;
}

void Vtb_mux2to1___024root___eval_triggers_vec__act(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_triggers_vec__act\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
}

bool Vtb_mux2to1___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_mux2to1___024root___act_sequent__TOP__0(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___act_sequent__TOP__0\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_mux2to1__DOT__out = ((IData)(vlSelfRef.tb_mux2to1__DOT__sel)
                                       ? (IData)(vlSelfRef.tb_mux2to1__DOT__in1)
                                       : (IData)(vlSelfRef.tb_mux2to1__DOT__in0));
}

void Vtb_mux2to1___024root___eval_act(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_act\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_mux2to1___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_mux2to1___024root___eval_nba(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_nba\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_mux2to1___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_mux2to1___024root___timing_resume(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___timing_resume\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_mux2to1___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_mux2to1___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_mux2to1___024root___eval_phase__act(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_phase__act\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_mux2to1___024root___eval_triggers_vec__act(vlSelf);
    Vtb_mux2to1___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_mux2to1___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_mux2to1___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_mux2to1___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_mux2to1___024root___timing_resume(vlSelf);
        Vtb_mux2to1___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_mux2to1___024root___eval_phase__inact(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_phase__inact\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 1, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_mux2to1___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_mux2to1___024root___eval_phase__nba(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_phase__nba\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_mux2to1___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_mux2to1___024root___eval_nba(vlSelf);
        Vtb_mux2to1___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_mux2to1___024root___eval(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_mux2to1___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 1, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_mux2to1___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/chipos_verilator_6cfi2dmr/temp_tb_mux2to1.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_mux2to1___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_mux2to1___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_mux2to1___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_mux2to1___024root___eval_debug_assertions(Vtb_mux2to1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_mux2to1___024root___eval_debug_assertions\n"); );
    Vtb_mux2to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
