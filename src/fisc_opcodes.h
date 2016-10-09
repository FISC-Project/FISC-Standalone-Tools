/*
 * fisc_opcodes.h
 *
 *  Created on: 08/10/2016
 *      Author: Miguel
 */

#ifndef SRC_FISC_OPCODES_H_
#define SRC_FISC_OPCODES_H_

#include <fisc_assembly.h>

enum INSTRUCTION_FMT {
	IFMT_R,  /* Register-Register Format     */
	IFMT_I,  /* Register-Immediate Format    */
	IFMT_D,  /* Register-Memory Format       */
	IFMT_B,  /* PC-Immediate-Register Format */
	IFMT_CB, /* PC-Immediate-Register Format */
	IFMT_IW  /* Register-Immediate Format    */
};

enum ARG_TYPES {
	REG, IMM
};

enum OPCODES {
	/* ARITHMETIC AND LOGIC */
	ADD = 0x458, ADDI = 0x488, ADDIS = 0x588, ADDS = 0x558,
	SUB = 0x658, SUBI = 0x688, SUBIS = 0x788, SUBS = 0x758,
	MUL = 0x4D8, SMULH = 0x4DA, UMULH = 0x4DE,
	SDIV = 0x4D6, UDIV = 0x4D7,
	AND = 0x450, ANDI = 0x490, ANDIS = 0x790, ANDS = 0x750,
	ORR = 0x550, ORRI = 0x590,
	EOR = 0x650, EORI = 0x690,
	LSL = 0x69B, LSR = 0x69A,
	MOVK = 0x794, MOVZ = 0x694,
	/* BRANCHING */
	B   = 0x0A0, BL  = 0x4A0, BR  = 0x6B0, CBNZ = 0x5A8,
	CBZ = 0x2A0, BEQ = 0x2A1, BNE = 0x2A2, BLT  = 0x2A3,
	BGT = 0x2A4, BGE = 0x2A5, BLO = 0x2A6, BLS  = 0x2A7,
	BHI = 0x2A8, BHS = 0x2A9, BMI = 0x2A9, BPL  = 0x2AA,
	BVS = 0x2AB, BVC = 0x2AC,
	/* LOAD AND STORE */
	LDUR = 0x7C2, LDURB = 0x1C2, LDURH = 0x3C2, LDURSW = 0x5C4, LDXR = 0x642,
	STUR = 0x7C0, STURB = 0x1C0, STURH = 0x3C0, STURW = 0x5C0,  STXR = 0x640,
	/* PSEUDO INSTRUCTIONS (these opcodes can't be used because the map won't allow duplicate keys) */
	CMP = 0, CMPI = 1,
	LDA = 2,
	MOV = 3
};

std::map<unsigned int, std::pair<ifmt, std::vector<afmt> > > instruction_lookup = {
	/* ARITHMETIC AND LOGIC */
	{ADD,   {ifmt{"ADD",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {ADDI,   {ifmt{"ADDI",  IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{ADDIS, {ifmt{"ADDIS", IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {ADDS,   {ifmt{"ADDS",  IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{SUB,   {ifmt{"SUB",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {SUBI,   {ifmt{"SUBI",  IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{SUBIS, {ifmt{"SUBIS", IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {SUBS,   {ifmt{"SUBS",  IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{MUL,   {ifmt{"MUL",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {SMULH,  {ifmt{"SMULH", IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{UMULH, {ifmt{"UMULH", IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{SDIV,  {ifmt{"SDIV",  IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {UDIV,   {ifmt{"UDIV",  IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{AND,   {ifmt{"AND",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {ANDI,   {ifmt{"ANDI",  IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{ANDIS, {ifmt{"ANDIS", IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {ANDS,   {ifmt{"ANDS",  IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{ORR,   {ifmt{"ORR",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {ORRI,   {ifmt{"ORRI",  IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{EOR,   {ifmt{"EOR",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {EORI,   {ifmt{"EORI",  IFMT_I},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{LSL,   {ifmt{"LSL",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {LSR,    {ifmt{"LSR",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{MOVK,  {ifmt{"MOVK", IFMT_IW},  {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}}, {MOVZ,   {ifmt{"MOVZ", IFMT_IW},  {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}},
	/* BRANCHING */
	{B,     {ifmt{"B",     IFMT_B},  {afmt{IMM,0}}}},                           {BL,     {ifmt{"BL",    IFMT_R},  {afmt{IMM,0}}}},
	{BR,    {ifmt{"BR",    IFMT_R},  {afmt{REG,0}}}},                           {CBNZ,   {ifmt{"CBNZ", IFMT_CB},  {afmt{REG,0}, afmt{IMM,0}}}},
	{CBZ,   {ifmt{"CBZ",  IFMT_CB},  {afmt{REG,0}, afmt{IMM,0}}}},              {BEQ,    {ifmt{"BEQ",  IFMT_CB},  {afmt{IMM,0}}}},
	{BNE,   {ifmt{"BNE",  IFMT_CB},  {afmt{IMM,0}}}},                           {BLT,    {ifmt{"BLT",  IFMT_CB},  {afmt{IMM,0}}}},
	{BGT,   {ifmt{"BGT",  IFMT_CB},  {afmt{IMM,0}}}},                           {BGE,    {ifmt{"BGE",  IFMT_CB},  {afmt{IMM,0}}}},
	{BLO,   {ifmt{"BLO",  IFMT_CB},  {afmt{IMM,0}}}},                           {BLS,    {ifmt{"BLS",  IFMT_CB},  {afmt{IMM,0}}}},
	{BHI,   {ifmt{"BHI",  IFMT_CB},  {afmt{IMM,0}}}},                           {BHS,    {ifmt{"BHS",  IFMT_CB},  {afmt{IMM,0}}}},
	{BMI,   {ifmt{"BMI",  IFMT_CB},  {afmt{IMM,0}}}},                           {BPL,    {ifmt{"BPL",  IFMT_CB},  {afmt{IMM,0}}}},
	{BVS,   {ifmt{"BVS",  IFMT_CB},  {afmt{IMM,0}}}},                           {BVC,    {ifmt{"BVC",  IFMT_CB},  {afmt{IMM,0}}}},
	/* LOAD AND STORE */
	{LDUR,  {ifmt{"LDUR",  IFMT_D},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDURB,  {ifmt{"LDURB",  IFMT_D}, {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDURH, {ifmt{"LDURH", IFMT_D},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDURSW, {ifmt{"LDURSW", IFMT_D}, {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDXR,  {ifmt{"LDXR",  IFMT_D},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STUR,  {ifmt{"STUR",  IFMT_D},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STURB,  {ifmt{"STURB",  IFMT_D}, {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STURH, {ifmt{"STURH", IFMT_D},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STURW,  {ifmt{"STURW",  IFMT_D}, {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STXR,  {ifmt{"STXR",  IFMT_D},  {afmt{REG,0}, afmt{REG,0}, afmt{REG,1}}}},
	/* PSEUDO INSTRUCTIONS */
	{CMP,   {ifmt{"CMP",   IFMT_R, SUBS},  {afmt{REG,0}, afmt{REG,0}}}},        {CMPI,   {ifmt{"CMPI",  IFMT_I, SUBI},  {afmt{REG,0}, afmt{IMM,0}}}},
	{LDA,   {ifmt{"LDA",   IFMT_I, ADDI},  {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{MOV,   {ifmt{"MOV",   IFMT_I, ADDI},  {afmt{REG,0}, afmt{REG,0}}}}
};

#endif /* SRC_FISC_OPCODES_H_ */
