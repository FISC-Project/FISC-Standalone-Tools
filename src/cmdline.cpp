/*
 * cmdline.cpp
 *
 *  Created on: 09/06/2016
 *      Author: Miguel
 */

#include <string>
#include <utility>
#include <vector>
using namespace std;

#define NULLSTR "(null)"

vector<std::pair<char, string>> opts_single_list;
vector<std::pair<string, string>> opts_list;

char is_opt(string opt) {
	return !opt.find("--") ? 2 : !opt.find("-") ? 1 : 0;
}

char get_single_opt(string opt) {
	for(int i = 0; i < opt.size(); i++)
		if(opt[i] != '-')
			return opt[i];
	return -1;
}

string get_string_opt(string opt) {
	for(int i = 0; i < opt.size(); i++)
		if(opt[i] != '-')
			return opt.substr(i, opt.size());
	return NULLSTR;
}

/* Pushes options such as -o, -c, -e, etc */
void cmd_push_single(string opt, string arg) {
	opts_single_list.push_back(make_pair(get_single_opt(opt), arg));
}

/* Pushes options such as --opt=, --compile, --enable="feature", etc */
void cmd_push(string opt, string arg) {
	opts_list.push_back(make_pair(get_string_opt(opt), arg));
}

std::pair<char,string> cmd_query(char opt_query) {
	for(auto pair : opts_single_list)
		if(pair.first == opt_query) return pair;
	return make_pair(0, NULLSTR);
}

std::pair<string,string> cmd_query(string opt_query) {
	for(auto pair : opts_list)
		if(pair.first == opt_query) return pair;
	return make_pair(NULLSTR, NULLSTR);
}

char cmd_has_opt(char opt) {
	for(auto pair : opts_single_list)
		if(pair.first == opt) return 1;
	return 0;
}

char cmd_has_opt(string opt) {
	for(auto pair : opts_list)
		if(pair.first == opt) return 1;
	return 0;
}

void cmdline_parse(int argc, char ** argv) {
	/* Iterate through the cmdline: */
	int ctr = 2;
	while(ctr < argc) {
		string opt = string(argv[ctr++]);
		char opt_type;
		if((opt_type = is_opt(opt)))
			if(opt_type == 1)
				cmd_push_single(opt, ctr < argc ? string(argv[ctr]) : NULLSTR);
			else if(opt_type == 2)
				cmd_push(opt, ctr < argc ? string(argv[ctr]) : NULLSTR);
	}
}
