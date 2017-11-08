#!/bin/bash

gcc -o test clone_list.c main.c
./test
rm test
