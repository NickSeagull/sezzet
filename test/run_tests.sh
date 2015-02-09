#!/bin/bash

cd $1
make -f "Makefile"&&
clear &&
echo '##########################'&&
echo '#       TEST RESULTS     #'&&
echo '##########################'&&
./run_tests.o
