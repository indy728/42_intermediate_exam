#!/bin/bash

gcc -o test gold_gain.c main.c
./test
rm test
