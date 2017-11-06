#!/bin/bash

gcc -o test is_looping.c main.c
cat subject.is_looping.txt
./test
rm test
