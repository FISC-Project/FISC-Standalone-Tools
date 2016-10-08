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
	/* PSEUDO INSTRUCTIONS */
	CMP = 0x758, CMPI = 0x788,
	LDA = 0x488,
	MOV = 0x489
};

std::map<unsigned int, std::pair<std::string, std::vector<afmt> > > opcode_strings = {
	/* ARITHMETIC AND LOGIC */
	{ADD,   {"ADD",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {ADDI,   {"ADDI",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{ADDIS, {"ADDIS", {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {ADDS,   {"ADDS",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{SUB,   {"SUB",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {SUBI,   {"SUBI",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{SUBIS, {"SUBIS", {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {SUBS,   {"SUBS",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{MUL,   {"MUL",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {SMULH,  {"SMULH",  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{UMULH, {"UMULH", {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{SDIV,  {"SDIV",  {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {UDIV,   {"UDIV",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{AND,   {"AND",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {ANDI,   {"ANDI",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{ANDIS, {"ANDIS", {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {ANDS,   {"ANDS",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}},
	{ORR,   {"ORR",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {ORRI,   {"ORRI",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{EOR,   {"EOR",   {afmt{REG,0}, afmt{REG,0}, afmt{REG,0}}}}, {EORI,   {"EORI",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{LSL,   {"LSL",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}}, {LSR,    {"LSR",    {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{MOVK,  {"MOVK",  {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}}, {MOVZ,   {"MOVZ",   {afmt{REG,0}, afmt{IMM,0}, afmt{IMM,0}}}},
	/* BRANCHING */
	{B,     {"B",     {afmt{IMM,0}}}},                           {BL,     {"BL",     {afmt{IMM,0}}}},
	{BR,    {"BR",    {afmt{REG,0}}}},                           {CBNZ,   {"CBNZ",   {afmt{REG,0}, afmt{IMM,0}}}},
	{CBZ,   {"CBZ",   {afmt{REG,0}, afmt{IMM,0}}}},              {BEQ,    {"BEQ",    {afmt{IMM,0}}}},
	{BNE,   {"BNE",   {afmt{IMM,0}}}},                           {BLT,    {"BLT",    {afmt{IMM,0}}}},
	{BGT,   {"BGT",   {afmt{IMM,0}}}},                           {BGE,    {"BGE",    {afmt{IMM,0}}}},
	{BLO,   {"BLO",   {afmt{IMM,0}}}},                           {BLS,    {"BLS",    {afmt{IMM,0}}}},
	{BHI,   {"BHI",   {afmt{IMM,0}}}},                           {BHS,    {"BHS",    {afmt{IMM,0}}}},
	{BMI,   {"BMI",   {afmt{IMM,0}}}},                           {BPL,    {"BPL",    {afmt{IMM,0}}}},
	{BVS,   {"BVS",   {afmt{IMM,0}}}},                           {BVC,    {"BVC",    {afmt{IMM,0}}}},
	/* LOAD AND STORE */
	{LDUR,  {"LDUR",  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDURB,  {"LDURB",  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDURH, {"LDURH", {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {LDURSW, {"LDURSW", {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{LDXR,  {"LDXR",  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STUR,  {"STUR",  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STURB,  {"STURB",  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STURH, {"STURH", {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}}, {STURW,  {"STURW",  {afmt{REG,0}, afmt{REG,1}, afmt{IMM,1}}}},
	{STXR,  {"STXR",  {afmt{REG,0}, afmt{REG,0}, afmt{REG,1}}}},
	/* PSEUDO INSTRUCTIONS */
	{CMP,   {"CMP",   {afmt{REG,0}, afmt{REG,0}}}},              {CMPI,   {"CMPI",   {afmt{REG,0}, afmt{IMM,0}}}},
	{LDA,   {"LDA",   {afmt{REG,0}, afmt{REG,0}, afmt{IMM,0}}}},
	{MOV,   {"MOV",   {afmt{REG,0}, afmt{REG,0}}}}
};

#endif /* SRC_FISC_OPCODES_H_ */
