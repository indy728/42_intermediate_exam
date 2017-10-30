#!/bin/bash

gcc -o test print_doublon.c main.c
./test
rm test
