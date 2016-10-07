/*
 * external_tool.cpp
 *
 *  Created on: 09/06/2016
 *      Author: Miguel
 */
#include <headers.h>
#include <external_tool.h>

#define TMP_FILE string("a")

char compiler_type(string compiler_name) {
	transform(compiler_name.begin(), compiler_name.end(), compiler_name.begin(), (int (*)(int))tolower);
	/* TODO: Add External Tools */
	return UNKNOWN_CMD;
}

string strip_extension(string filename) {
	string name = filename;
	size_t pos = name.rfind(".");
	if(pos == -1) {
		/* No extension found */
		return name;
	} else if (pos == 0) {
		/* Found . at the front. Therefore not an extension */
		return name;
	} else {
		/* File extension found */
		return name.substr(0, pos);
	}
}

void exec_cmd(char * cmd) {
	/* Execute command */
#if DEBUG == 1
			printf("Executing external command: '%s'\n", cmd);
#endif
		system(cmd);
}

static std::vector<string> temp_objfiles;

void external_execute(char run_cmd, ...) {
	char cmd[128];
	va_list args;
	va_start(args, run_cmd);

	switch(run_cmd){
	case CLEANUP_TOOL:
		for(auto file : temp_objfiles)
			remove(file.c_str());
		break;
	}
	va_end(args);
}

