// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VExercise1.h for the primary calling header

#include "VExercise1__pch.h"
#include "VExercise1___024root.h"

VL_INLINE_OPT void VExercise1___024root___ico_sequent__TOP__0(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((0U == (IData)(vlSelf->op))) {
        vlSelf->out = ((IData)(vlSelf->a) ^ (IData)(vlSelf->b));
    } else if ((1U == (IData)(vlSelf->op))) {
        vlSelf->out = (0xffU & VL_SHIFTL_III(8,8,8, (IData)(vlSelf->a), (IData)(vlSelf->b)));
    } else if ((2U == (IData)(vlSelf->op))) {
        vlSelf->out = (0xffU & VL_MODDIV_III(8, (IData)(vlSelf->a), (IData)(vlSelf->b)));
    } else if ((3U == (IData)(vlSelf->op))) {
        vlSelf->out = (0xffU & (~ ((IData)(vlSelf->a) 
                                   & (IData)(vlSelf->b))));
    }
}

void VExercise1___024root___eval_ico(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VExercise1___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VExercise1___024root___eval_triggers__ico(VExercise1___024root* vlSelf);

bool VExercise1___024root___eval_phase__ico(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VExercise1___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VExercise1___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VExercise1___024root___eval_act(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_act\n"); );
}

void VExercise1___024root___eval_nba(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_nba\n"); );
}

void VExercise1___024root___eval_triggers__act(VExercise1___024root* vlSelf);

bool VExercise1___024root___eval_phase__act(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VExercise1___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VExercise1___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VExercise1___024root___eval_phase__nba(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VExercise1___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise1___024root___dump_triggers__ico(VExercise1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise1___024root___dump_triggers__nba(VExercise1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise1___024root___dump_triggers__act(VExercise1___024root* vlSelf);
#endif  // VL_DEBUG

void VExercise1___024root___eval(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VExercise1___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/Exercise1.sv", 9, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VExercise1___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VExercise1___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/Exercise1.sv", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VExercise1___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/Exercise1.sv", 9, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VExercise1___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VExercise1___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VExercise1___024root___eval_debug_assertions(VExercise1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise1___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->op & 0xfcU))) {
        Verilated::overWidthError("op");}
}
#endif  // VL_DEBUG
