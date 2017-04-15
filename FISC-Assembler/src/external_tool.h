/*
 * external_tool.h
 *
 *  Created on: 09/06/2016
 *      Author: Miguel
 */

#ifndef EXTERNAL_TOOL_H_
#define EXTERNAL_TOOL_H_

#include <algorithm>
#include <string>
#include <stdarg.h>
#include <fstream>
using namespace std;

enum RUN_CMD {
	UNKNOWN_CMD,
	CLEANUP_TOOL,
	/* TODO: Add External Tools */
};

extern char compiler_type(string compiler_name);
extern void external_execute(char run_cmd, ...);

#endif /* EXTERNAL_TOOL_H_ */
