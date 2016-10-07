%{
	#include <headers.h>
%}

%union {
	int ival;
	float fval;
	char *sval;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%start source
%%
source:
	INT source      { cout << "bison found an int: " << $1 << endl; }
	| FLOAT source  { cout << "bison found a float: " << $1 << endl; }
	| STRING source { cout << "bison found a string: " << $1 << endl; }
	| INT            { cout << "bison found an int: " << $1 << endl; }
	| FLOAT          { cout << "bison found a float: " << $1 << endl; }
	| STRING         { cout << "bison found a string: " << $1 << endl; }
%%
