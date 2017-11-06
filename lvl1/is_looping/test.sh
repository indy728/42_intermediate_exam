#!/bin/bash

gcc -o test is_looping.c main.c
./test
rm test
