#!/bin/bash

gcc -o test equation.c main.c
./test
rm test
