#!/bin/bash

cat examples.txt
gcc -o test width_tree.c main.c
./test
rm test
