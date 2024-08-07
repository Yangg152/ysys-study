// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+44,"out", false,-1, 31,0);
    tracep->declBus(c+45,"pc", false,-1, 31,0);
    tracep->declBit(c+46,"break_out", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+44,"out", false,-1, 31,0);
    tracep->declBus(c+45,"pc", false,-1, 31,0);
    tracep->declBit(c+46,"break_out", false,-1);
    tracep->declBus(c+47,"pc_n", false,-1, 31,0);
    tracep->declBus(c+2,"imm", false,-1, 31,0);
    tracep->declBus(c+3,"rd", false,-1, 4,0);
    tracep->declBus(c+4,"rs1", false,-1, 4,0);
    tracep->declBus(c+5,"rs2", false,-1, 4,0);
    tracep->declBus(c+6,"opcode7", false,-1, 6,0);
    tracep->declBus(c+7,"opcode3", false,-1, 2,0);
    tracep->declBus(c+50,"wdata", false,-1, 31,0);
    tracep->declBit(c+8,"wen", false,-1);
    tracep->declBus(c+51,"rs1_value", false,-1, 31,0);
    tracep->declBus(c+52,"rs2_value", false,-1, 31,0);
    tracep->declBus(c+53,"rd_value", false,-1, 31,0);
    tracep->declBus(c+48,"result", false,-1, 31,0);
    tracep->declBus(c+49,"regfile_out", false,-1, 31,0);
    tracep->pushNamePrefix("exu ");
    tracep->declBus(c+54,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+2,"immI", false,-1, 31,0);
    tracep->declBus(c+49,"rs1_value", false,-1, 31,0);
    tracep->declBus(c+52,"rs2_value", false,-1, 31,0);
    tracep->declBus(c+53,"rd_value", false,-1, 31,0);
    tracep->declBus(c+6,"opcode7", false,-1, 6,0);
    tracep->declBus(c+7,"opcode3", false,-1, 2,0);
    tracep->declBus(c+48,"result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+54,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+43,"inst", false,-1, 31,0);
    tracep->declBus(c+2,"imm", false,-1, 31,0);
    tracep->declBus(c+3,"rd", false,-1, 4,0);
    tracep->declBus(c+4,"rs1", false,-1, 4,0);
    tracep->declBus(c+5,"rs2", false,-1, 4,0);
    tracep->declBus(c+6,"opcode7", false,-1, 6,0);
    tracep->declBus(c+7,"opcode3", false,-1, 2,0);
    tracep->declBit(c+8,"wen", false,-1);
    tracep->declBit(c+46,"ebreak", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBus(c+54,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+45,"pc", false,-1, 31,0);
    tracep->declBus(c+55,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBus(c+54,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+56,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+42,"rst", false,-1);
    tracep->declBus(c+47,"din", false,-1, 31,0);
    tracep->declBus(c+45,"dout", false,-1, 31,0);
    tracep->declBit(c+57,"wen", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBus(c+58,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+54,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+41,"clk", false,-1);
    tracep->declBit(c+8,"wen", false,-1);
    tracep->declBus(c+48,"wdata", false,-1, 31,0);
    tracep->declBus(c+3,"waddr", false,-1, 4,0);
    tracep->declBus(c+4,"raddr", false,-1, 4,0);
    tracep->declBus(c+49,"rdata", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+9+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__regfile__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__imm),32);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__rd),5);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__rs1),5);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__rs2),5);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__opcode7),7);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__opcode3),3);
    bufp->fullBit(oldp+8,(vlSelf->top__DOT__wen));
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+41,(vlSelf->clk));
    bufp->fullBit(oldp+42,(vlSelf->rst));
    bufp->fullIData(oldp+43,(vlSelf->inst),32);
    bufp->fullIData(oldp+44,(vlSelf->out),32);
    bufp->fullIData(oldp+45,(vlSelf->pc),32);
    bufp->fullBit(oldp+46,(vlSelf->break_out));
    bufp->fullIData(oldp+47,(((0U == vlSelf->pc) ? 0x80000000U
                               : ((IData)(4U) + vlSelf->pc))),32);
    bufp->fullIData(oldp+48,((vlSelf->top__DOT__imm 
                              + ((0U == (IData)(vlSelf->top__DOT__rs1))
                                  ? 0U : vlSelf->top__DOT__regfile__DOT__rf
                                 [vlSelf->top__DOT__rs1]))),32);
    bufp->fullIData(oldp+49,(((0U == (IData)(vlSelf->top__DOT__rs1))
                               ? 0U : vlSelf->top__DOT__regfile__DOT__rf
                              [vlSelf->top__DOT__rs1])),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__wdata),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__rs1_value),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__rs2_value),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__rd_value),32);
    bufp->fullIData(oldp+54,(0x20U),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__ifu__DOT__inst),32);
    bufp->fullIData(oldp+56,(0x80000000U),32);
    bufp->fullBit(oldp+57,(1U));
    bufp->fullIData(oldp+58,(5U),32);
}
