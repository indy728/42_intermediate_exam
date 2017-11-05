#!/bin/bash

gcc -o test is_anagram.c main.c
./test
rm test
