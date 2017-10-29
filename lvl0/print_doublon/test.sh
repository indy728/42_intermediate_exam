#!/bin/bash

gcc -o test print_doublon.c main.c
./test | cat -e
rm test
