/*
 * fisc_opcodes.h
 *
 *  Created on: 08/10/2016
 *      Author: Miguel
 */

#ifndef SRC_FISC_OPCODES_H_
#define SRC_FISC_OPCODES_H_

enum OPCODES {
	/* ARITHMETIC AND LOGIC */
	ADD, ADDI, ADDIS, ADDS,
	SUB, SUBI, SUBIS, SUBS,
	MUL, SMULH, UMULH,
	SDIV, UDIV,
	AND, ANDI, ANDIS, ANDS,
	ORR, ORRI,
	EOR, EORI,
	LSL, LSR,
	MOVK, MOVZ,
	/* BRANCHING */
	B, BCOND, BL, BR, CBNZ, CBZ,
	/* LOAD AND STORE */
	LDUR, LDURB, LDURH, LDURSW, LDXR,
	STUR, STURB, STURH, STURW, STXR,
	/* PSEUDO INSTRUCTIONS */
	CMP, CMPI,
	LDA,
	MOV
};

enum INSTRUCTION_FMT {
	IFMT_R,  /* Register-Register Format     */
	IFMT_I,  /* Register-Immediate Format    */
	IFMT_D,  /* Register-Memory Format       */
	IFMT_B,  /* PC-Immediate-Register Format */
	IFMT_CB, /* PC-Immediate-Register Format */
	IFMT_IW  /* Register-Immediate Format    */
};

enum ARG_TYPES {
	ARG_REGISTER, ARG_IMMEDIATE
};

#endif /* SRC_FISC_OPCODES_H_ */
