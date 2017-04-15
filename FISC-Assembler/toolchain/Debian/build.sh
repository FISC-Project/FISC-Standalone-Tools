#!/bin/bash
cd `dirname $0`
clear

cd ../.. # Go to the root of the project

printf "***** Building Makefile... *****\n\n"
make -f toolchain/makefile.mak all

printf "\n***** Done *****\n\n"

printf "\nPress enter to exit"
read
