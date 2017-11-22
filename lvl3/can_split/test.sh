#!/bin/bash

cat examples.txt
gcc -o test can_split.c main.c
./test
rm test
