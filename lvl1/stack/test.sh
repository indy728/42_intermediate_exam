#!/bin/bash

gcc -o test stack.c main.c
./test
rm test
