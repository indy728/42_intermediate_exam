#!/bin/bash

gcc -o count_alpha count_alpha.c
echo "./count_alpha abbcc"
./count_alpha abbcc
echo "./count_alpha \"abbcc\""
./count_alpha "abbcc"
echo "./count_alpha abbcc dddeef | cat -e"
./count_alpha abbcc dddeef | cat -e
echo "./count_alpha \"My Hyze 47y 7.\" | cat -e"
./count_alpha "My Hyze 47y 7." | cat -e
echo "./count_alpha \"\" | cat -e"
./count_alpha "" | cat -e
rm count_alpha
