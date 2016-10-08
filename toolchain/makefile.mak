SRC = src
OBJ = obj
GEN = $(SRC)/gen
BIN = bin
EXEC = flasm
RM = rm
CXX = g++
CPPFLAGS = -Isrc -Isrc/gen -lfl
ENV =
ifeq ($(OS),Windows_NT)
	ENV += toolchain/Windows/Tools/GnuWin32/bin/
	CPPFLAGS += -Ltoolchain/Windows/Tools/GnuWin32/lib
endif
LEX = $(ENV)flex
BISON = $(ENV)bison
YFLAGS = -d
LFLAGS = 

makefile_dir:=$(shell dirname \"$("realpath $(lastword $(MAKEFILE_LIST)))\")

####### Source filenames:
LEXER = lex
PARSER = parser

####### Objects/Outputs:
OBJS = $(GEN)/$(PARSER).tab.c $(GEN)/$(LEXER).yy.c $(OBJ)/main.o \
	$(OBJ)/cmdline.o $(OBJ)/external_tool.o $(OBJ)/fisc_assembly.o

####### Lexer:
$(GEN)/$(LEXER).yy.c: $(SRC)/$(LEXER).l
	$(LEX) $(LFLAGS) "$^"
	mv $(LEXER).yy.c "$@"

####### Parser:
$(GEN)/$(PARSER).tab.c: $(SRC)/$(PARSER).y
	$(BISON) $(YFLAGS) "$^"
	mv $(PARSER).tab.c "$@"
	mv $(PARSER).tab.h $(patsubst %.c, %.h, $@)

####### C++ code:
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CXX) -o $@ -c $^ $(CPPFLAGS)
	
$(OBJ)/cmdline.o: $(SRC)/cmdline.cpp
	$(CXX) -o $@ -c $^ -std=gnu++11 $(CPPFLAGS)

$(OBJ)/external_tool.o: $(SRC)/external_tool.cpp
	$(CXX) -o $@ -c $^ -std=gnu++11 $(CPPFLAGS)

$(OBJ)/fisc_assembly.o: $(SRC)/fisc_assembly.cpp
	$(CXX) -o $@ -c $^ -std=gnu++11 $(CPPFLAGS)	

all: $(OBJS)
	$(CXX) -o $(BIN)/$(EXEC) $^ $(CPPFLAGS)
	@printf "Finished!\n"

clean:
	$(RM) $(GEN)/*.*
	$(RM) $(BIN)/*
	$(RM) $(OBJ)/*.o

run:
	@$(BIN)/$(EXEC) ${ARGS}

test%:
	@cd $(makefile_dir)/..
	@$(BIN)/flasm testbench/$@ -c icarus -s -r -g
