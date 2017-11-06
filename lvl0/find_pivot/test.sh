#!/bin/bash

gcc -o test find_pivot.c main.c
./test
rm test
