// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*4:0*/ top__DOT__rd;
    CData/*4:0*/ top__DOT__rs1;
    CData/*6:0*/ top__DOT__opcode7;
    CData/*2:0*/ top__DOT__opcode3;
    CData/*0:0*/ top__DOT__wen;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    VL_OUT(out,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ top__DOT__pc_internal;
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__wdata;
    IData/*31:0*/ top__DOT__exu__DOT__rs1_value;
    IData/*31:0*/ top__DOT__exu__DOT__regfile__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__exu__DOT__regfile__DOT__rf;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
