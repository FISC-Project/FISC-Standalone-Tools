@cd "%~dp0"
@echo off
cls

cd ..\..

printf "***** Cleaning objects... *****\n\n"
make -f toolchain/makefile.mak clean

printf "\n***** Done *****"
