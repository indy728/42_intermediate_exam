#!/bin/bash

cat examples.txt
gcc -o test longest_sequence.c main.c
./test
rm test
