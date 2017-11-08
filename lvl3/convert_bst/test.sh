#!/bin/bash

gcc -o test convert_bst.c main.c
./test
rm test
