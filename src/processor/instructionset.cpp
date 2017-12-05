#include <instructionset.hpp>
#include <instruction.hpp>

InstructionSet::InstructionSet()
{
	//TODO: we add all instructions to the map here
	//Use xmacros to generate all the instructions here
	/*
	map = {
		#define X(instruction) \
			auto instr_##instruction = new instruction();\
			{instr_##instruction->getOpCode(), &instr_##instruction},
		#undef X
	};
	*/

	#define add_instr(instruct) \
		auto instr_##instruct = new instruct();\
		map[instr_##instruct->opCode()] = instr_##instruct;

	add_instr(NOP)

	add_instr(LD_AX)
	add_instr(LD_BX)
	add_instr(LD_CX)
	add_instr(LD_DX)
	add_instr(LD_EX)
	add_instr(LD_HX)
	add_instr(LD_LX)

	add_instr(LD_AA)
	add_instr(LD_AB)
	add_instr(LD_AC)
	add_instr(LD_AD)
	add_instr(LD_AE)
	add_instr(LD_AH)
	add_instr(LD_AL)
	add_instr(LD_AHL)

	add_instr(LD_BA)
	add_instr(LD_BB)
	add_instr(LD_BC)
	add_instr(LD_BD)
	add_instr(LD_BE)
	add_instr(LD_BL)
	add_instr(LD_BHL)

	add_instr(LD_CA)
	add_instr(LD_CB)
	add_instr(LD_CC)
	add_instr(LD_CD)
	add_instr(LD_CE)
	add_instr(LD_CL)
	add_instr(LD_CHL)

	add_instr(LD_DA)
	add_instr(LD_DB)
	add_instr(LD_DC)
	add_instr(LD_DD)
	add_instr(LD_DE)
	add_instr(LD_DL)
	add_instr(LD_DHL)

	add_instr(LD_EA)
	add_instr(LD_EB)
	add_instr(LD_EC)
	add_instr(LD_ED)
	add_instr(LD_EE)
	add_instr(LD_EL)
	add_instr(LD_EHL)

	add_instr(LD_HA)
	add_instr(LD_HB)
	add_instr(LD_HC)
	add_instr(LD_HD)
	add_instr(LD_HE)
	add_instr(LD_HL)
	add_instr(LD_HHL)

	add_instr(LD_LA)
	add_instr(LD_LB)
	add_instr(LD_LC)
	add_instr(LD_LD)
	add_instr(LD_LE)
	add_instr(LD_LL)
	add_instr(LD_LHL)

	add_instr(LD_HLB)
	add_instr(LD_HLC)
	add_instr(LD_HLD)
	add_instr(LD_HLE)
	add_instr(LD_HLH)
	add_instr(LD_HLL)
	add_instr(LD_HLn)

	add_instr(LD_ABC)
	add_instr(LD_BCA)
	add_instr(LD_ADE)
	add_instr(LD_DEA)
	add_instr(LD_HLA)
	add_instr(LD_Ann)
	add_instr(LD_nnA)

	add_instr(LD_AC2)
	add_instr(LD_C2A)

	add_instr(LDD_AHL)
	add_instr(LDD_HLA)
	add_instr(LDI_AHL)
	add_instr(LDI_HLA)
	add_instr(LDH_nA)
	add_instr(LDH_An)

	add_instr(LD_BCnn)
	add_instr(LD_DEnn)
	add_instr(LD_HLnn)
	add_instr(LD_SPnn)
	add_instr(LD_nnSP)
	add_instr(LD_SPHL)
	add_instr(LD_HLSPn)

	add_instr(PUSH_BC)
	add_instr(PUSH_DE)
	add_instr(PUSH_HL)
	add_instr(POP_BC)
	add_instr(POP_DE)
	add_instr(POP_HL)


	add_instr(ADD_AA)
	add_instr(ADD_AB)
	add_instr(ADD_AC)
	add_instr(ADD_AD)
	add_instr(ADD_AE)
	add_instr(ADD_AH)
	add_instr(ADD_AL)
	add_instr(ADD_AHL)
	add_instr(ADD_AX)


	add_instr(ADC_AA)
	add_instr(ADC_AB)
	add_instr(ADC_AC)
	add_instr(ADC_AD)
	add_instr(ADC_AE)
	add_instr(ADC_AH)
	add_instr(ADC_AL)
	add_instr(ADC_AHL)
	add_instr(ADC_AX)


	add_instr(SUB_AA)
	add_instr(SUB_AB)
	add_instr(SUB_AC)
	add_instr(SUB_AD)
	add_instr(SUB_AE)
	add_instr(SUB_AH)
	add_instr(SUB_AL)
	add_instr(SUB_AHL)
	add_instr(SUB_AX) 

	add_instr(SBC_AA)
	add_instr(SBC_AB)
	add_instr(SBC_AC)
        add_instr(SBC_AD)
	add_instr(SBC_AE)
	add_instr(SBC_AH)
	add_instr(SBC_AL)
	add_instr(SBC_AHL)
	add_instr(SBC_AX) 

	add_instr(AND_AA)
	add_instr(AND_AB)
	add_instr(AND_AC)
	add_instr(AND_AD)
	add_instr(AND_AE)
	add_instr(AND_AH)
	add_instr(AND_AL)
	add_instr(AND_AHL)
	add_instr(AND_AX) 

	add_instr(OR_AA)
	add_instr(OR_AB)
	add_instr(OR_AC)
	add_instr(OR_AD)
	add_instr(OR_AE)
	add_instr(OR_AH)
	add_instr(OR_AL)
	add_instr(OR_AHL)
	add_instr(OR_AX)

	add_instr(XOR_AA)
	add_instr(XOR_AB)
	add_instr(XOR_AC)
	add_instr(XOR_AD)
	add_instr(XOR_AE)
	add_instr(XOR_AH)
	add_instr(XOR_AL)
	add_instr(XOR_AHL)
	add_instr(XOR_AX)


	add_instr(CP_AA)
	add_instr(CP_AB)
	add_instr(CP_AC)
	add_instr(CP_AD)
	add_instr(CP_AE)
	add_instr(CP_AH)
	add_instr(CP_AL)
	add_instr(CP_AHL)
	add_instr(CP_AX) 

	add_instr(INC_A)
	add_instr(INC_B)
	add_instr(INC_C)
	add_instr(INC_D)
	add_instr(INC_E)
	add_instr(INC_H)
	add_instr(INC_L)
	add_instr(INC_HLdereference)

	add_instr(INC_BC)
	add_instr(INC_DE)
	add_instr(INC_HL)
	add_instr(INC_SP)

	add_instr(DEC_A)
	add_instr(DEC_B)
	add_instr(DEC_C)
	add_instr(DEC_D)
	add_instr(DEC_E)
	add_instr(DEC_H)
	add_instr(DEC_L)
	add_instr(DEC_HL)

#warning "Add DEC on double registers HERE"

	add_instr(SWAP_AX)
	add_instr(SWAP_BX)
	add_instr(SWAP_CX)
	add_instr(SWAP_DX)
	add_instr(SWAP_EX)
	add_instr(SWAP_HX)
	add_instr(SWAP_LX)
	add_instr(SWAP_HL)

	add_instr(DAA)  
	add_instr(CPL)
	add_instr(CCF)
	add_instr(SCF)


	add_instr(BIT_0A)
	add_instr(BIT_1A)
	add_instr(BIT_2A)
	add_instr(BIT_3A)
	add_instr(BIT_4A)
	add_instr(BIT_5A)
	add_instr(BIT_6A)
	add_instr(BIT_7A)
	                            
	add_instr(BIT_0B)
	add_instr(BIT_1B)
	add_instr(BIT_2B)
	add_instr(BIT_3B)
	add_instr(BIT_4B)
	add_instr(BIT_5B)
	add_instr(BIT_6B)
	add_instr(BIT_7B)

	add_instr(BIT_0C)
	add_instr(BIT_1C)
	add_instr(BIT_2C)
	add_instr(BIT_3C)
	add_instr(BIT_4C)
	add_instr(BIT_5C)
	add_instr(BIT_6C)
	add_instr(BIT_7C)

	add_instr(BIT_0D)
	add_instr(BIT_1D)
	add_instr(BIT_2D)
	add_instr(BIT_3D)
	add_instr(BIT_4D)
	add_instr(BIT_5D)
	add_instr(BIT_6D)
	add_instr(BIT_7D)

	add_instr(BIT_0E)
	add_instr(BIT_1E)
	add_instr(BIT_2E)
	add_instr(BIT_3E)
	add_instr(BIT_4E)
	add_instr(BIT_5E)
	add_instr(BIT_6E)
	add_instr(BIT_7E)

	add_instr(BIT_0H)
	add_instr(BIT_1H)
	add_instr(BIT_2H)
	add_instr(BIT_3H)
	add_instr(BIT_4H)
	add_instr(BIT_5H)
	add_instr(BIT_6H)
	add_instr(BIT_7H)

	add_instr(BIT_0L)
	add_instr(BIT_1L)
	add_instr(BIT_2L)
	add_instr(BIT_3L)
	add_instr(BIT_4L)
	add_instr(BIT_5L)
	add_instr(BIT_6L)
	add_instr(BIT_7L)

	add_instr(BIT_0HL)
	add_instr(BIT_1HL)
	add_instr(BIT_2HL)
	add_instr(BIT_3HL)
	add_instr(BIT_4HL)
	add_instr(BIT_5HL)
	add_instr(BIT_6HL)
	add_instr(BIT_7HL)  

	add_instr(SET_0A)
	add_instr(SET_1A)
	add_instr(SET_2A)
	add_instr(SET_3A)
	add_instr(SET_4A)
	add_instr(SET_5A)
	add_instr(SET_6A)
	add_instr(SET_7A)

	add_instr(SET_0B)
	add_instr(SET_1B)
	add_instr(SET_2B)
	add_instr(SET_3B)
	add_instr(SET_4B)
	add_instr(SET_5B)
	add_instr(SET_6B)
	add_instr(SET_7B)

	add_instr(SET_0C)
	add_instr(SET_1C)
	add_instr(SET_2C)
	add_instr(SET_3C)
	add_instr(SET_4C)
	add_instr(SET_5C)
	add_instr(SET_6C)
	add_instr(SET_7C) 

	add_instr(SET_0D)
	add_instr(SET_1D)
	add_instr(SET_2D)
	add_instr(SET_3D)
	add_instr(SET_4D)
	add_instr(SET_5D)
	add_instr(SET_6D)
	add_instr(SET_7D)

	add_instr(SET_0E)
	add_instr(SET_1E)
	add_instr(SET_2E)
	add_instr(SET_3E)
	add_instr(SET_4E)
	add_instr(SET_5E)
	add_instr(SET_6E)
	add_instr(SET_7E)

	add_instr(SET_0H)
	add_instr(SET_1H)
	add_instr(SET_2H)
	add_instr(SET_3H)
	add_instr(SET_4H)
	add_instr(SET_5H)
	add_instr(SET_6H)
	add_instr(SET_7H) 

	add_instr(SET_0L)
	add_instr(SET_1L)
	add_instr(SET_2L)
	add_instr(SET_3L)
	add_instr(SET_4L)
	add_instr(SET_5L)
	add_instr(SET_6L)
	add_instr(SET_7L)

	add_instr(SET_0HL)
	add_instr(SET_1HL)
	add_instr(SET_2HL)
	add_instr(SET_3HL)
	add_instr(SET_4HL)
	add_instr(SET_5HL)
	add_instr(SET_6HL)
        add_instr(SET_7HL)        

	add_instr(RES_0A)
	add_instr(RES_1A)
	add_instr(RES_2A)
	add_instr(RES_3A)
	add_instr(RES_4A)
	add_instr(RES_5A)
	add_instr(RES_6A)
	add_instr(RES_7A)

	add_instr(RES_0B)
	add_instr(RES_1B)
	add_instr(RES_2B)
	add_instr(RES_3B)
	add_instr(RES_4B)
	add_instr(RES_5B)
	add_instr(RES_6B)
	add_instr(RES_7B)

	add_instr(RES_0C)
	add_instr(RES_1C)
	add_instr(RES_2C)
	add_instr(RES_3C)
	add_instr(RES_4C)
	add_instr(RES_5C)
	add_instr(RES_6C)
	add_instr(RES_7C)   

	add_instr(RES_0D)
	add_instr(RES_1D)
	add_instr(RES_2D)
	add_instr(RES_3D)
	add_instr(RES_4D)
	add_instr(RES_5D)
	add_instr(RES_6D)
	add_instr(RES_7D)

	add_instr(RES_0E)
	add_instr(RES_1E)
	add_instr(RES_2E)
	add_instr(RES_3E)
	add_instr(RES_4E)
	add_instr(RES_5E)
	add_instr(RES_6E)
	add_instr(RES_7E)

	add_instr(RES_0H)
	add_instr(RES_1H)
	add_instr(RES_2H)
	add_instr(RES_3H)
	add_instr(RES_4H)
	add_instr(RES_5H)
	add_instr(RES_6H)
	add_instr(RES_7H)

	add_instr(RES_0L)
	add_instr(RES_1L)
	add_instr(RES_2L)
	add_instr(RES_3L)
	add_instr(RES_4L)
	add_instr(RES_5L)
	add_instr(RES_6L)
	add_instr(RES_7L)         

	add_instr(RES_0HL)
	add_instr(RES_1HL)
	add_instr(RES_2HL)
	add_instr(RES_3HL)
	add_instr(RES_4HL)
	add_instr(RES_5HL)
	add_instr(RES_6HL)
	add_instr(RES_7HL) 
	  
	add_instr(RRC_AX)
	add_instr(RRC_BX)
	add_instr(RRC_CX)
	add_instr(RRC_DX)
	add_instr(RRC_EX)
	add_instr(RRC_HX)
	add_instr(RRC_LX)
	add_instr(RRC_HL)

	add_instr(RLC_AX)
	add_instr(RLC_BX)
	add_instr(RLC_CX)
	add_instr(RLC_DX)
	add_instr(RLC_EX)
	add_instr(RLC_HX)
	add_instr(RLC_LX)
	add_instr(RLC_HL)  
	  
	add_instr(RL_AX)
	add_instr(RL_BX)
	add_instr(RL_CX)
	add_instr(RL_DX)
	add_instr(RL_EX)
	add_instr(RL_HX)
	add_instr(RL_LX)
	add_instr(RL_HL)

	add_instr(RR_AX)
	add_instr(RR_BX)
	add_instr(RR_CX)
	add_instr(RR_DX)
	add_instr(RR_EX)
	add_instr(RR_HX)
	add_instr(RR_LX)
	add_instr(RR_HL) 

	add_instr(SLA_AX)
	add_instr(SLA_BX)
	add_instr(SLA_CX)
	add_instr(SLA_DX)
	add_instr(SLA_EX)
	add_instr(SLA_HX)
	add_instr(SLA_LX)
	add_instr(SLA_HL)  

	add_instr(SRA_AX)
	add_instr(SRA_BX)
	add_instr(SRA_CX)
	add_instr(SRA_DX)
	add_instr(SRA_EX)
	add_instr(SRA_HX)
	add_instr(SRA_LX)
	add_instr(SRA_HL) 


	add_instr(SRL_AX)
	add_instr(SRL_BX)
	add_instr(SRL_CX)
	add_instr(SRL_DX)
	add_instr(SRL_EX)
	add_instr(SRL_HX)
	add_instr(SRL_LX)
	add_instr(SRL_HL) 

        add_instr(HALT)

	add_instr(STOP)

	add_instr(EI)
	add_instr(DI)
	//add_instr(SRL_HLX) 
	

	add_instr(JP)
	add_instr(JPNZ)
	add_instr(JPZ)
	add_instr(JPNC)
	add_instr(JPC)
	add_instr(JPHL)
	add_instr(JR)
	add_instr(JRNZ)
	add_instr(JRZ)
	add_instr(JRNC)
	add_instr(JRC)

	add_instr(CALL)
	add_instr(CALLNZ)
	add_instr(CALLZ)
	add_instr(CALLNC)
	add_instr(CALLC)
	
	add_instr(RST_0x00)
	add_instr(RST_0x08)
	add_instr(RST_0x10)
	add_instr(RST_0x18)
	add_instr(RST_0x20)
	add_instr(RST_0x28)
	add_instr(RST_0x30)
	add_instr(RST_0x38)

	add_instr(RET)
	add_instr(RETNZ)
	add_instr(RETZ)
	add_instr(RETNC)
	add_instr(RETC)
	add_instr(RETI)
	
        #undef add_instr
}

int InstructionSet::isValidOpCode(OpCode opCode)
{
	auto elt = map.find(opCode);
	return (elt != map.end());
}

int InstructionSet::addInstruction(Instruction* instr)
{
	auto elt = map.find(instr->opCode());
	if (elt == map.end())
		map[instr->opCode()] = instr;
	return (elt == map.end());
}


Instruction * InstructionSet::getInstruction(OpCode opCode)
{
	return map.find(opCode)->second;
}
