#!/bin/bash

gcc -o test reverse_tree.c main.c
./test
rm test
