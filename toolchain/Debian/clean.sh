#!/bin/bash
cd `dirname $0`
clear

cd ..\..

printf "***** Cleaning objects... *****\n\n"
make -f toolchain/makefile.mak clean

printf "\n***** Done *****"
