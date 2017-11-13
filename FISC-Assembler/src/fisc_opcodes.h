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
	ADD   = 0,  ADDI   = 1,  ADDIS = 2,  ADDS = 3,
	SUB   = 4,  SUBI   = 5,  SUBIS = 6,  SUBS = 7,
	MUL   = 8,  SMULH  = 9,  UMULH = 10,
	SDIV  = 11, UDIV   = 12,
	AND   = 13, ANDI   = 14, ANDIS = 15, ANDS = 16,
	ORR   = 17, ORRI   = 18,
	EOR   = 19, EORI   = 20,
	NEG   = 21, NEGI   = 22,
	NOT   = 23, NOTI   = 24,
	LSL   = 25, LSR    = 26,
	MOVK  = 27, MOVZ   = 28,
	MOVRK = 29, MOVRZ  = 30,
	LDPC  = 31,
	/* BRANCHING */
	B     = 0x0A0, BL     = 0x4A0, BR    = 0x6B0, CBNZ   = 0x5A8,
	CBZ   = 0x5A0, BEQ    = 0x2A0, BNE   = 0x2A1, BLT    = 0x2A2,
	BLE   = 0x2A3, BGT    = 0x2A4, BGE   = 0x2A5, BLO    = 0x2A6,
	BLS   = 0x2A7, BHI    = 0x2A8, BHS   = 0x2A9, BMI    = 0x2AA, BPL   = 0x2AB,
	BVS   = 0x2AC, BVC    = 0x2AD,
	/* LOAD AND STORE */
	LDR   = 0x7C2, LDRB   = 0x1C2, LDRH  = 0x3C2, LDRSW  = 0x5C4, LDXR  = 0x642,
	LDRR  = 0x7D2, LDRBR  = 0x1D2, LDRHR = 0x3D2, LDRSWR = 0x4C4, LDXRR = 0x652,
	STR   = 0x7C0, STRB   = 0x1C0, STRH  = 0x3C0, STRW   = 0x5C0, STXR  = 0x640,
	STRR  = 0x7D0, STRBR  = 0x1D0, STRHR = 0x3D0, STRWR  = 0x5D0, STXRR = 0x5D1,
	/* CPU STATUS CONTROL */
	HALT  = 32,
	MSR   = 0x614, MRS    = 0x5F4,
	/* INTERRUPTS */
	LIVP  = 0x5D4, SIVP   = 0x5B4,
	LEVP  = 0x594, SEVP   = 0x574, SESR  = 0x554,
	SINT  = 0x520, RETI   = 0x500,
	/* VIRTUAL MEMORY */
	LPDP  = 0x4F4, SPDP   = 0x4D4, LPFLA = 0x4B4
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
	{MOVK,  {ifmt{"MOVK",  IFMT_IW}, {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}}, {MOVZ,   {ifmt{"MOVZ",  IFMT_IW}, {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}},
	{MOVRK, {ifmt{"MOVRK", IFMT_IW}, {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}}, {MOVRZ,  {ifmt{"MOVRZ", IFMT_IW}, {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}},
	{NEG,   {ifmt{"NEG",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}}}},              {NEGI,   {ifmt{"NEGI",  IFMT_I},  {afmt{REG,0}, afmt{IMM,0}}}},
	{NOT,   {ifmt{"NOT",   IFMT_R},  {afmt{REG,0}, afmt{REG,0}}}},              {NOTI,   {ifmt{"NOTI",  IFMT_I},  {afmt{REG,0}, afmt{IMM,0}}}},
	{LDPC,  {ifmt{"LDPC",  IFMT_R, 0, 0, 1},      {afmt{0,0}}}},
	/* BRANCHING */
	{B,     {ifmt{"B",     IFMT_B},  {afmt{IMM,0}}}},                           {BL,     {ifmt{"BL",    IFMT_B},  {afmt{IMM,0}}}},
	{BR,    {ifmt{"BR",    IFMT_R},  {afmt{REG,0}}}},                           {CBNZ,   {ifmt{"CBNZ",  IFMT_CB}, {afmt{REG,0}, afmt{IMM,0}}}},
	{CBZ,   {ifmt{"CBZ",   IFMT_CB}, {afmt{REG,0}, afmt{IMM,0}}}},              {BEQ,    {ifmt{"BEQ",   IFMT_CB}, {afmt{IMM,0}}}},
	{BNE,   {ifmt{"BNE",   IFMT_CB}, {afmt{IMM,0}}}},                           {BLT,    {ifmt{"BLT",   IFMT_CB}, {afmt{IMM,0}}}},
	{BLE,   {ifmt{"BLE",   IFMT_CB}, {afmt{IMM,0}}}},                           {BGT,    {ifmt{"BGT",   IFMT_CB}, {afmt{IMM,0}}}},
	{BGE,   {ifmt{"BGE",   IFMT_CB}, {afmt{IMM,0}}}},                           {BLO,    {ifmt{"BLO",   IFMT_CB}, {afmt{IMM,0}}}},
	{BLS,   {ifmt{"BLS",   IFMT_CB}, {afmt{IMM,0}}}},                           {BHI,    {ifmt{"BHI",   IFMT_CB}, {afmt{IMM,0}}}},
	{BHS,   {ifmt{"BHS",   IFMT_CB}, {afmt{IMM,0}}}},                           {BMI,    {ifmt{"BMI",   IFMT_CB}, {afmt{IMM,0}}}},
	{BPL,   {ifmt{"BPL",   IFMT_CB}, {afmt{IMM,0}}}},                           {BVS,    {ifmt{"BVS",   IFMT_CB}, {afmt{IMM,0}}}},
	{BVC,   {ifmt{"BVC",   IFMT_CB}, {afmt{IMM,0}}}},
	/* LOAD AND STORE */
	{LDR,   {ifmt{"LDR",   IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDRB,  {ifmt{"LDRB",  IFMT_D, 0, 8},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDRH,  {ifmt{"LDRH",  IFMT_D, 0, 16},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDRSW, {ifmt{"LDRSW", IFMT_D, 0, 32},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDXR,  {ifmt{"LDXR",  IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STR,   {ifmt{"STR",   IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STRB,  {ifmt{"STRB",  IFMT_D, 0, 8},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STRH,  {ifmt{"STRH",  IFMT_D, 0, 16},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STRW,  {ifmt{"STRW",  IFMT_D, 0, 32},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STXR,  {ifmt{"STXR",  IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,0}, afmt{REG,1}}}},
	{LDRR,  {ifmt{"LDRR",  IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDRBR, {ifmt{"LDRBR",  IFMT_D, 0, 8},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDRHR, {ifmt{"LDRHR", IFMT_D, 0, 16},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDRSWR,{ifmt{"LDRSWR", IFMT_D, 0, 32}, {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDXRR, {ifmt{"LDXRR", IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STRR,  {ifmt{"STRR",  IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STRBR, {ifmt{"STRBR",  IFMT_D, 0, 8},  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STRHR, {ifmt{"STRHR", IFMT_D, 0, 16},   {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STRWR, {ifmt{"STRWR",  IFMT_D, 0, 32}, {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STXRR, {ifmt{"STXRR", IFMT_D, 0, 64},   {afmt{REG,0}, afmt{REG,0}, afmt{REG,1}}}},
	/* CPU STATUS CONTROL */
	{HALT,  {ifmt{"HALT",  IFMT_R, 0, 0, 1}, {afmt{0,0}}}},
	{MSR,   {ifmt{"MSR",   IFMT_R},          {afmt{REG,0}, afmt{REG,0}}}},              {MRS,   {ifmt{"MRS",   IFMT_R},          {afmt{REG,0}, afmt{REG,0}}}},
	/* INTERRUPTS */
	{LIVP,  {ifmt{"LIVP",  IFMT_R},          {afmt{REG,0}}}},                           {SIVP,  {ifmt{"SIVP",  IFMT_R},          {afmt{REG,0}}}},
	{LEVP,  {ifmt{"LEVP",  IFMT_R},          {afmt{REG,0}}}},                           {SEVP,  {ifmt{"SEVP",  IFMT_R},          {afmt{REG,0}}}},
	{SESR,  {ifmt{"SESR",  IFMT_R},          {afmt{REG,0}}}},                           {RETI,  {ifmt{"RETI",  IFMT_B, 0, 0, 1}, {afmt{0,0}}}},
	{SINT,  {ifmt{"SINT",  IFMT_B},          {afmt{IMM,0}}}},
	/* VIRTUAL MEMORY */
	{LPDP,  {ifmt{"LPDP",  IFMT_R},          {afmt{REG,0}}}},                           {SPDP,  {ifmt{"SPDP",  IFMT_R},          {afmt{REG,0}}}},
	{LPFLA, {ifmt{"LPFLA", IFMT_R},          {afmt{REG,0}}}}
};

#endif /* SRC_FISC_OPCODES_H_ */
