// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsaturn_dsp.h for the primary calling header

#include "Vsaturn_dsp.h"       // For This
#include "Vsaturn_dsp__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsaturn_dsp) {
    Vsaturn_dsp__Syms* __restrict vlSymsp = __VlSymsp = new Vsaturn_dsp__Syms(this, name());
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsaturn_dsp::__Vconfigure(Vsaturn_dsp__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsaturn_dsp::~Vsaturn_dsp() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsaturn_dsp::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsaturn_dsp::eval\n"); );
    Vsaturn_dsp__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vsaturn_dsp::_eval_initial_loop(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vsaturn_dsp::_settle__TOP__1(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_settle__TOP__1\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_TOP = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->PC_TO_TOP = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->P_TO_PL = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->IMM_TO_LOP = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_LOP = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->PC_TO_D0 = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RA = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->RA_TO_RAMS = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->SHIFT_L16_TO_D1 = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_PROG_RAM = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->CLR_A = 0U;
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RY = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		vlTOPp->LOAD_RY = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->LOAD_RX = 1U;
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->X_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->X_TO_RX = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->ACL_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->ACL_TO_D1 = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->ACH_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U != (0xfU & vlTOPp->FETCH))) {
				if ((0xaU == (0xfU 
					      & vlTOPp->FETCH))) {
				    vlTOPp->ACH_TO_D1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((0x10000U & vlTOPp->FETCH)) {
					vlTOPp->INC_CT1 = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT1 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->INC_CT1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			} else {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((0x10000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->INC_CT0 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((0x10000U 
					     & vlTOPp->FETCH)) {
					    vlTOPp->INC_CT2 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT2 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT2 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    if ((0x10000U 
						 & vlTOPp->FETCH)) {
						vlTOPp->INC_CT3 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT3 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT3 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD0_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD0_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD0_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD1_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD1_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD2_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD2_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD2_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD3_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD3_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD0_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD0_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->MD0_TO_Y = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD1_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->MD1_TO_Y = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD2_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD2_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->MD2_TO_Y = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD3_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->MD3_TO_Y = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->X_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->X_TO_PL = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->LOAD_PL = 1U;
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->ALU_TO_A = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->ALU_TO_A = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->Y_TO_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->Y_TO_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->Y_TO_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->Y_TO_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->Y_TO_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_ACH = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACH = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACL = 1U;
		    } else {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->LOAD_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->LOAD_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->LOAD_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->LOAD_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_WA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_WA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_WA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_LOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_LOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_LOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_TOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_TOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_TOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:395
    if ((0x20000000U & vlTOPp->FETCH)) {
	if ((0x10000000U & vlTOPp->FETCH)) {
	    if ((0x8000000U & vlTOPp->FETCH)) {
		if ((0x4000000U & vlTOPp->FETCH)) {
		    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
			= ((QData)((IData)(vlTOPp->A_REG)) 
			   << 8U);
		}
	    }
	} else {
	    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
		= ((0x8000000U & vlTOPp->FETCH) ? (
						   (0x4000000U 
						    & vlTOPp->FETCH)
						    ? (QData)((IData)(
								      ((0xfffffffeU 
									& ((IData)(vlTOPp->A_REG) 
									   << 1U)) 
								       | (1U 
									  & (IData)(
										(vlTOPp->A_REG 
										>> 0x1fU))))))
						    : (QData)((IData)(
								      (0xfffffffeU 
								       & ((IData)(vlTOPp->A_REG) 
									  << 1U)))))
		    : ((0x4000000U & vlTOPp->FETCH)
		        ? (QData)((IData)(((0x80000000U 
					    & ((IData)(vlTOPp->A_REG) 
					       << 0x1fU)) 
					   | (0x7fffffffU 
					      & (IData)(
							(vlTOPp->A_REG 
							 >> 1U))))))
		        : (QData)((IData)(((0x80000000U 
					    & ((IData)(
						       (vlTOPp->A_REG 
							>> 0x1fU)) 
					       << 0x1fU)) 
					   | (0x7fffffffU 
					      & (IData)(
							(vlTOPp->A_REG 
							 >> 1U))))))));
	}
    } else {
	if ((0x10000000U & vlTOPp->FETCH)) {
	    if ((0x8000000U & vlTOPp->FETCH)) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x1aU)))) {
		    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
			= (VL_ULL(0x3ffffffffffff) 
			   & (vlTOPp->A_REG + vlTOPp->P_REG));
		}
	    } else {
		vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
		    = (VL_ULL(0x3ffffffffffff) & ((0x4000000U 
						   & vlTOPp->FETCH)
						   ? 
						  ((QData)((IData)(vlTOPp->A_REG)) 
						   - (QData)((IData)(vlTOPp->P_REG)))
						   : 
						  ((QData)((IData)(vlTOPp->A_REG)) 
						   + (QData)((IData)(vlTOPp->P_REG)))));
	    }
	} else {
	    if ((0x8000000U & vlTOPp->FETCH)) {
		vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
		    = ((0x4000000U & vlTOPp->FETCH)
		        ? ((QData)((IData)(vlTOPp->A_REG)) 
			   ^ (QData)((IData)(vlTOPp->P_REG)))
		        : ((QData)((IData)(vlTOPp->A_REG)) 
			   | (QData)((IData)(vlTOPp->P_REG))));
	    } else {
		if ((0x4000000U & vlTOPp->FETCH)) {
		    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
			= ((QData)((IData)(vlTOPp->A_REG)) 
			   & (QData)((IData)(vlTOPp->P_REG)));
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD3_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U == (0xfU 
						& vlTOPp->FETCH))) {
					vlTOPp->MD3_TO_D1 = 1U;
				    } else {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD3_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD2_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U == (0xfU & vlTOPp->FETCH))) {
				    vlTOPp->MD2_TO_D1 = 1U;
				} else {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD2_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD1_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->MD1_TO_D1 = 1U;
			    } else {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->MD1_TO_D1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD0_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U == (0xfU & vlTOPp->FETCH))) {
			    vlTOPp->MD0_TO_D1 = 1U;
			} else {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->MD0_TO_D1 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->IMM_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			vlTOPp->IMM_TO_D1 = 1U;
		    } else {
			if ((0x200U & vlTOPp->FETCH)) {
			    vlTOPp->IMM_TO_D1 = 1U;
			}
		    }
		} else {
		    vlTOPp->IMM_TO_D1 = 1U;
		}
	    }
	}
    }
    vlTOPp->D1_BUS = ((IData)(vlTOPp->MD0_TO_D1) ? 
		      vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM
		      [vlTOPp->CT0] : ((IData)(vlTOPp->MD1_TO_D1)
				        ? vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM
				       [vlTOPp->CT1]
				        : ((IData)(vlTOPp->MD2_TO_D1)
					    ? vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM
					   [vlTOPp->CT2]
					    : ((IData)(vlTOPp->MD3_TO_D1)
					        ? vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM
					       [vlTOPp->CT3]
					        : ((IData)(vlTOPp->IMM_TO_D1)
						    ? 
						   (0xffU 
						    & vlTOPp->FETCH)
						    : 0U)))));
}

VL_INLINE_OPT void Vsaturn_dsp::_sequent__TOP__2(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_sequent__TOP__2\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__CT0,5,0);
    VL_SIG8(__Vdly__CT1,5,0);
    VL_SIG8(__Vdly__CT2,5,0);
    VL_SIG8(__Vdly__CT3,5,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0,7,0);
    VL_SIG8(__Vdlyvset__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0,0,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0,7,0);
    VL_SIG8(__Vdlyvset__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0,0,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0,7,0);
    VL_SIG8(__Vdlyvset__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0,0,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0,7,0);
    VL_SIG8(__Vdlyvset__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0,0,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2,7,0);
    VL_SIG8(__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3,5,0);
    VL_SIG8(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3,4,0);
    VL_SIG8(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3,7,0);
    // Body
    __Vdly__CT3 = vlTOPp->CT3;
    __Vdly__CT2 = vlTOPp->CT2;
    __Vdly__CT1 = vlTOPp->CT1;
    __Vdly__CT0 = vlTOPp->CT0;
    __Vdlyvset__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0 = 0U;
    __Vdlyvset__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0 = 0U;
    __Vdlyvset__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0 = 0U;
    __Vdlyvset__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0 = 0U;
    // ALWAYS at saturn_dsp.sv:197
    vlTOPp->INST_ADDR = (0xffU & ((IData)(1U) + (IData)(vlTOPp->INST_ADDR)));
    // ALWAYS at saturn_dsp.sv:197
    if (vlTOPp->MUL_TO_P) {
	vlTOPp->P_REG = (VL_ULL(0xffffffffffff) & ((QData)((IData)(vlTOPp->saturn_dsp__DOT__RX)) 
						   * (QData)((IData)(vlTOPp->saturn_dsp__DOT__RY))));
    }
    // ALWAYS at saturn_dsp.sv:197
    if (vlTOPp->CLR_A) {
	vlTOPp->A_REG = VL_ULL(0);
    }
    if (vlTOPp->ALU_TO_A) {
	vlTOPp->A_REG = (VL_ULL(0xffffffffffff) & vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES);
    }
    // ALWAYS at saturn_dsp.sv:197
    if (vlTOPp->LOAD_CT3) {
	__Vdly__CT3 = (0x3fU & vlTOPp->D1_BUS);
    }
    if (vlTOPp->INC_CT3) {
	__Vdly__CT3 = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->CT3)));
    }
    // ALWAYS at saturn_dsp.sv:197
    if (vlTOPp->LOAD_CT2) {
	__Vdly__CT2 = (0x3fU & vlTOPp->D1_BUS);
    }
    if (vlTOPp->INC_CT2) {
	__Vdly__CT2 = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->CT2)));
    }
    // ALWAYS at saturn_dsp.sv:197
    if (vlTOPp->LOAD_CT1) {
	__Vdly__CT1 = (0x3fU & vlTOPp->D1_BUS);
    }
    if (vlTOPp->INC_CT1) {
	__Vdly__CT1 = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->CT1)));
    }
    // ALWAYS at saturn_dsp.sv:197
    if (vlTOPp->LOAD_CT0) {
	__Vdly__CT0 = (0x3fU & vlTOPp->D1_BUS);
    }
    if (vlTOPp->INC_CT0) {
	__Vdly__CT0 = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->CT0)));
    }
    // ALWAYS at saturn_dsp.sv:1001
    if (vlTOPp->LOAD_MD3) {
	__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD3_DI);
	__Vdlyvset__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0 = 1U;
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0 = 0x18U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0 
	    = vlTOPp->CT3;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD3_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1 = 0x10U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1 
	    = vlTOPp->CT3;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD3_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2 = 8U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2 
	    = vlTOPp->CT3;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD3_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3 = 0U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3 
	    = vlTOPp->CT3;
    }
    // ALWAYS at saturn_dsp.sv:1001
    if (vlTOPp->LOAD_MD2) {
	__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD2_DI);
	__Vdlyvset__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0 = 1U;
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0 = 0x18U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0 
	    = vlTOPp->CT2;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD2_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1 = 0x10U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1 
	    = vlTOPp->CT2;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD2_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2 = 8U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2 
	    = vlTOPp->CT2;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD2_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3 = 0U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3 
	    = vlTOPp->CT2;
    }
    // ALWAYS at saturn_dsp.sv:1001
    if (vlTOPp->LOAD_MD1) {
	__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD1_DI);
	__Vdlyvset__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0 = 1U;
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0 = 0x18U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0 
	    = vlTOPp->CT1;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD1_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1 = 0x10U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1 
	    = vlTOPp->CT1;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD1_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2 = 8U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2 
	    = vlTOPp->CT1;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD1_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3 = 0U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3 
	    = vlTOPp->CT1;
    }
    // ALWAYS at saturn_dsp.sv:1001
    if (vlTOPp->LOAD_MD0) {
	__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD0_DI);
	__Vdlyvset__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0 = 1U;
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0 = 0x18U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0 
	    = vlTOPp->CT0;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD0_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1 = 0x10U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1 
	    = vlTOPp->CT0;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD0_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2 = 8U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2 
	    = vlTOPp->CT0;
	__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3 
	    = (0xffU & vlTOPp->saturn_dsp__DOT__MD0_DI);
	__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3 = 0U;
	__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3 
	    = vlTOPp->CT0;
    }
    // ALWAYS at saturn_dsp.sv:197
    vlTOPp->FETCH = vlTOPp->INST_IN;
    vlTOPp->CT3 = __Vdly__CT3;
    // ALWAYSPOST at saturn_dsp.sv:1003
    if (__Vdlyvset__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0) {
	vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v0)));
	vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v1)));
	vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v2)));
	vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md3__DOT__RAM__v3)));
    }
    vlTOPp->CT2 = __Vdly__CT2;
    // ALWAYSPOST at saturn_dsp.sv:1003
    if (__Vdlyvset__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0) {
	vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v0)));
	vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v1)));
	vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v2)));
	vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md2__DOT__RAM__v3)));
    }
    vlTOPp->CT1 = __Vdly__CT1;
    // ALWAYSPOST at saturn_dsp.sv:1003
    if (__Vdlyvset__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0) {
	vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v0)));
	vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v1)));
	vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v2)));
	vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md1__DOT__RAM__v3)));
    }
    vlTOPp->CT0 = __Vdly__CT0;
    // ALWAYSPOST at saturn_dsp.sv:1003
    if (__Vdlyvset__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0) {
	vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v0)));
	vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v1)));
	vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v2)));
	vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3] 
	    = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3))) 
		& vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM
		[__Vdlyvdim0__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3]) 
	       | ((IData)(__Vdlyvval__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3) 
		  << (IData)(__Vdlyvlsb__saturn_dsp__DOT__data_ram_md0__DOT__RAM__v3)));
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RY = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		vlTOPp->LOAD_RY = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->LOAD_RX = 1U;
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->X_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->X_TO_RX = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->ACL_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->ACL_TO_D1 = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->ACH_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U != (0xfU & vlTOPp->FETCH))) {
				if ((0xaU == (0xfU 
					      & vlTOPp->FETCH))) {
				    vlTOPp->ACH_TO_D1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((0x10000U & vlTOPp->FETCH)) {
					vlTOPp->INC_CT1 = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT1 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->INC_CT1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			} else {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((0x10000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->INC_CT0 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((0x10000U 
					     & vlTOPp->FETCH)) {
					    vlTOPp->INC_CT2 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT2 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT2 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->INC_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    if ((0x10000U 
						 & vlTOPp->FETCH)) {
						vlTOPp->INC_CT3 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT3 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT3 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD0_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD0_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD0_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD1_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD1_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD2_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD2_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD2_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD3_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD3_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD0_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD0_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->MD0_TO_Y = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD1_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->MD1_TO_Y = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD2_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD2_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->MD2_TO_Y = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD3_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->MD3_TO_Y = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->X_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->X_TO_PL = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->LOAD_PL = 1U;
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->ALU_TO_A = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->ALU_TO_A = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->Y_TO_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->Y_TO_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->Y_TO_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->Y_TO_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->Y_TO_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_ACH = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACH = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACL = 1U;
		    } else {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->LOAD_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->LOAD_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->LOAD_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->LOAD_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_RA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_WA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_WA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_WA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_LOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_LOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_LOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->LOAD_TOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_TOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_TOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:395
    if ((0x20000000U & vlTOPp->FETCH)) {
	if ((0x10000000U & vlTOPp->FETCH)) {
	    if ((0x8000000U & vlTOPp->FETCH)) {
		if ((0x4000000U & vlTOPp->FETCH)) {
		    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
			= ((QData)((IData)(vlTOPp->A_REG)) 
			   << 8U);
		}
	    }
	} else {
	    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
		= ((0x8000000U & vlTOPp->FETCH) ? (
						   (0x4000000U 
						    & vlTOPp->FETCH)
						    ? (QData)((IData)(
								      ((0xfffffffeU 
									& ((IData)(vlTOPp->A_REG) 
									   << 1U)) 
								       | (1U 
									  & (IData)(
										(vlTOPp->A_REG 
										>> 0x1fU))))))
						    : (QData)((IData)(
								      (0xfffffffeU 
								       & ((IData)(vlTOPp->A_REG) 
									  << 1U)))))
		    : ((0x4000000U & vlTOPp->FETCH)
		        ? (QData)((IData)(((0x80000000U 
					    & ((IData)(vlTOPp->A_REG) 
					       << 0x1fU)) 
					   | (0x7fffffffU 
					      & (IData)(
							(vlTOPp->A_REG 
							 >> 1U))))))
		        : (QData)((IData)(((0x80000000U 
					    & ((IData)(
						       (vlTOPp->A_REG 
							>> 0x1fU)) 
					       << 0x1fU)) 
					   | (0x7fffffffU 
					      & (IData)(
							(vlTOPp->A_REG 
							 >> 1U))))))));
	}
    } else {
	if ((0x10000000U & vlTOPp->FETCH)) {
	    if ((0x8000000U & vlTOPp->FETCH)) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x1aU)))) {
		    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
			= (VL_ULL(0x3ffffffffffff) 
			   & (vlTOPp->A_REG + vlTOPp->P_REG));
		}
	    } else {
		vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
		    = (VL_ULL(0x3ffffffffffff) & ((0x4000000U 
						   & vlTOPp->FETCH)
						   ? 
						  ((QData)((IData)(vlTOPp->A_REG)) 
						   - (QData)((IData)(vlTOPp->P_REG)))
						   : 
						  ((QData)((IData)(vlTOPp->A_REG)) 
						   + (QData)((IData)(vlTOPp->P_REG)))));
	    }
	} else {
	    if ((0x8000000U & vlTOPp->FETCH)) {
		vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
		    = ((0x4000000U & vlTOPp->FETCH)
		        ? ((QData)((IData)(vlTOPp->A_REG)) 
			   ^ (QData)((IData)(vlTOPp->P_REG)))
		        : ((QData)((IData)(vlTOPp->A_REG)) 
			   | (QData)((IData)(vlTOPp->P_REG))));
	    } else {
		if ((0x4000000U & vlTOPp->FETCH)) {
		    vlTOPp->saturn_dsp__DOT__alu_inst__DOT__INT_RES 
			= ((QData)((IData)(vlTOPp->A_REG)) 
			   & (QData)((IData)(vlTOPp->P_REG)));
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->D1_TO_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD3_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U == (0xfU 
						& vlTOPp->FETCH))) {
					vlTOPp->MD3_TO_D1 = 1U;
				    } else {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD3_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD2_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U == (0xfU & vlTOPp->FETCH))) {
				    vlTOPp->MD2_TO_D1 = 1U;
				} else {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD2_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD1_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->MD1_TO_D1 = 1U;
			    } else {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->MD1_TO_D1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->MD0_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U == (0xfU & vlTOPp->FETCH))) {
			    vlTOPp->MD0_TO_D1 = 1U;
			} else {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->MD0_TO_D1 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:570
    vlTOPp->IMM_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			vlTOPp->IMM_TO_D1 = 1U;
		    } else {
			if ((0x200U & vlTOPp->FETCH)) {
			    vlTOPp->IMM_TO_D1 = 1U;
			}
		    }
		} else {
		    vlTOPp->IMM_TO_D1 = 1U;
		}
	    }
	}
    }
    vlTOPp->D1_BUS = ((IData)(vlTOPp->MD0_TO_D1) ? 
		      vlTOPp->saturn_dsp__DOT__data_ram_md0__DOT__RAM
		      [vlTOPp->CT0] : ((IData)(vlTOPp->MD1_TO_D1)
				        ? vlTOPp->saturn_dsp__DOT__data_ram_md1__DOT__RAM
				       [vlTOPp->CT1]
				        : ((IData)(vlTOPp->MD2_TO_D1)
					    ? vlTOPp->saturn_dsp__DOT__data_ram_md2__DOT__RAM
					   [vlTOPp->CT2]
					    : ((IData)(vlTOPp->MD3_TO_D1)
					        ? vlTOPp->saturn_dsp__DOT__data_ram_md3__DOT__RAM
					       [vlTOPp->CT3]
					        : ((IData)(vlTOPp->IMM_TO_D1)
						    ? 
						   (0xffU 
						    & vlTOPp->FETCH)
						    : 0U)))));
}

void Vsaturn_dsp::_initial__TOP__3(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_initial__TOP__3\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at saturn_dsp.sv:245
    vlTOPp->saturn_dsp__DOT__MD0_DI = ((IData)(vlTOPp->D1_TO_MD0)
				        ? vlTOPp->D1_BUS
				        : vlTOPp->D0_BUS_IN);
    // INITIAL at saturn_dsp.sv:260
    vlTOPp->saturn_dsp__DOT__MD1_DI = ((IData)(vlTOPp->D1_TO_MD1)
				        ? vlTOPp->D1_BUS
				        : vlTOPp->D0_BUS_IN);
    // INITIAL at saturn_dsp.sv:275
    vlTOPp->saturn_dsp__DOT__MD2_DI = ((IData)(vlTOPp->D1_TO_MD2)
				        ? vlTOPp->D1_BUS
				        : vlTOPp->D0_BUS_IN);
    // INITIAL at saturn_dsp.sv:290
    vlTOPp->saturn_dsp__DOT__MD3_DI = ((IData)(vlTOPp->D1_TO_MD3)
				        ? vlTOPp->D1_BUS
				        : vlTOPp->D0_BUS_IN);
}

void Vsaturn_dsp::_eval(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLOCK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLOCK)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLOCK = vlTOPp->CLOCK;
}

void Vsaturn_dsp::_eval_initial(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval_initial\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLOCK = vlTOPp->CLOCK;
    vlTOPp->_initial__TOP__3(vlSymsp);
}

void Vsaturn_dsp::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::final\n"); );
    // Variables
    Vsaturn_dsp__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsaturn_dsp::_eval_settle(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval_settle\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vsaturn_dsp::_change_request(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_change_request\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsaturn_dsp::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLOCK & 0xfeU))) {
	Verilated::overWidthError("CLOCK");}
}
#endif // VL_DEBUG

void Vsaturn_dsp::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_ctor_var_reset\n"); );
    // Body
    CLOCK = VL_RAND_RESET_I(1);
    D0_BUS_IN = VL_RAND_RESET_I(32);
    D0_BUS_OUT = VL_RAND_RESET_I(32);
    FETCH = VL_RAND_RESET_I(32);
    LOAD_CT0 = VL_RAND_RESET_I(1);
    LOAD_CT1 = VL_RAND_RESET_I(1);
    LOAD_CT2 = VL_RAND_RESET_I(1);
    LOAD_CT3 = VL_RAND_RESET_I(1);
    INC_CT0 = VL_RAND_RESET_I(1);
    INC_CT1 = VL_RAND_RESET_I(1);
    INC_CT2 = VL_RAND_RESET_I(1);
    INC_CT3 = VL_RAND_RESET_I(1);
    MD0_TO_X = VL_RAND_RESET_I(1);
    MD1_TO_X = VL_RAND_RESET_I(1);
    MD2_TO_X = VL_RAND_RESET_I(1);
    MD3_TO_X = VL_RAND_RESET_I(1);
    MD0_TO_Y = VL_RAND_RESET_I(1);
    MD1_TO_Y = VL_RAND_RESET_I(1);
    MD2_TO_Y = VL_RAND_RESET_I(1);
    MD3_TO_Y = VL_RAND_RESET_I(1);
    MD0_TO_D1 = VL_RAND_RESET_I(1);
    MD1_TO_D1 = VL_RAND_RESET_I(1);
    MD2_TO_D1 = VL_RAND_RESET_I(1);
    MD3_TO_D1 = VL_RAND_RESET_I(1);
    D1_TO_MD0 = VL_RAND_RESET_I(1);
    D1_TO_MD1 = VL_RAND_RESET_I(1);
    D1_TO_MD2 = VL_RAND_RESET_I(1);
    D1_TO_MD3 = VL_RAND_RESET_I(1);
    ACH_TO_D1 = VL_RAND_RESET_I(1);
    ACL_TO_D1 = VL_RAND_RESET_I(1);
    LOAD_MD0 = VL_RAND_RESET_I(1);
    LOAD_MD1 = VL_RAND_RESET_I(1);
    LOAD_MD2 = VL_RAND_RESET_I(1);
    LOAD_MD3 = VL_RAND_RESET_I(1);
    X_TO_RX = VL_RAND_RESET_I(1);
    D1_TO_RX = VL_RAND_RESET_I(1);
    LOAD_RX = VL_RAND_RESET_I(1);
    LOAD_RY = VL_RAND_RESET_I(1);
    PC_TO_TOP = VL_RAND_RESET_I(1);
    D1_TO_TOP = VL_RAND_RESET_I(1);
    MUL_TO_P = VL_RAND_RESET_I(1);
    P_TO_PL = VL_RAND_RESET_I(1);
    X_TO_PL = VL_RAND_RESET_I(1);
    D1_TO_PL = VL_RAND_RESET_I(1);
    LOAD_PL = VL_RAND_RESET_I(1);
    ALU_TO_A = VL_RAND_RESET_I(1);
    Y_TO_ACL = VL_RAND_RESET_I(1);
    LOAD_ACH = VL_RAND_RESET_I(1);
    LOAD_ACL = VL_RAND_RESET_I(1);
    IMM_TO_D1 = VL_RAND_RESET_I(1);
    IMM_TO_LOP = VL_RAND_RESET_I(1);
    D1_TO_LOP = VL_RAND_RESET_I(1);
    PC_TO_D0 = VL_RAND_RESET_I(1);
    LOAD_RA = VL_RAND_RESET_I(1);
    RA_TO_RAMS = VL_RAND_RESET_I(1);
    SHIFT_L16_TO_D1 = VL_RAND_RESET_I(1);
    CLR_A = VL_RAND_RESET_I(1);
    LOAD_RA0 = VL_RAND_RESET_I(1);
    LOAD_WA0 = VL_RAND_RESET_I(1);
    LOAD_LOP = VL_RAND_RESET_I(1);
    LOAD_TOP = VL_RAND_RESET_I(1);
    LOAD_PROG_RAM = VL_RAND_RESET_I(1);
    P_REG = VL_RAND_RESET_Q(48);
    A_REG = VL_RAND_RESET_Q(48);
    CT0 = VL_RAND_RESET_I(6);
    CT1 = VL_RAND_RESET_I(6);
    CT2 = VL_RAND_RESET_I(6);
    CT3 = VL_RAND_RESET_I(6);
    D1_BUS = VL_RAND_RESET_I(32);
    INST_ADDR = VL_RAND_RESET_I(8);
    INST_IN = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__RX = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__RY = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__MD0_DI = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__MD1_DI = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__MD2_DI = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__MD3_DI = VL_RAND_RESET_I(32);
    saturn_dsp__DOT__alu_inst__DOT__INT_RES = VL_RAND_RESET_Q(50);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    saturn_dsp__DOT__data_ram_md0__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    saturn_dsp__DOT__data_ram_md1__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    saturn_dsp__DOT__data_ram_md2__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    saturn_dsp__DOT__data_ram_md3__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
