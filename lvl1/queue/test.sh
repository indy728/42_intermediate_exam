#!/bin/bash

gcc -o test queue.c main.c
./test
rm test
