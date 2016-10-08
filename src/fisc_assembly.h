/*
 * fisc_assembly.h
 *
 *  Created on: 08/10/2016
 *      Author: Miguel
 */

#ifndef SRC_FISC_ASSEMBLY_H_
#define SRC_FISC_ASSEMBLY_H_

#include <utility>
#include <vector>
#include <string>
#include <map>

typedef struct argument {
	char arg_type;      /* Is it a register or immediate? */
	char is_offset;     /* Is this argument inside an offset? example: [X0, #0], X0 and #0 are both inside an offset */
	long long value;    /* The meaning of the value depends on the arg_type */
	char * label;       /* This is only used by labels, and its purpose is for the program to find AFTER parsing what the label value is */
} argument_t;

typedef struct argfmt {
	char arg_type;
	char is_offset;
} afmt;

typedef struct instruction_fmt {
	std::string mnemonic;
	char fmt;
} ifmt;

typedef struct arglist {
	argument_t ** arguments;
	unsigned int argcount;
} arglist_t;

typedef struct instruction {
	char       * mnemonic;
	unsigned int opcode;
	arglist_t  * args;
} instruction_t;

extern std::vector<instruction_t> program;
extern std::map<unsigned int, std::pair<ifmt, std::vector<afmt> > > instruction_lookup;
extern std::map<std::string, unsigned int> label_lst;

extern char make_instruction(char * mnemonic, arglist_t * args);
extern arglist_t * make_argument_list(unsigned int argcount, ...);
extern argument_t * make_argument(char arg_type, char is_offset, long long value);
extern argument_t * make_argument(char arg_type, char is_offset, char * label);
extern void free_argument_list(arglist_t * args);
extern void add_label(std::string label_name, unsigned int line_number);
extern void resolve_labels();

#endif /* SRC_FISC_ASSEMBLY_H_ */
