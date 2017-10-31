#!/bin/bash

gcc -o ord_alphlong *.c -I.
echo "./ord_alphlong | cat -e"
echo "output:"
./ord_alphlong | cat -e
echo "answer:"
echo "$"
echo "./ord_alphlong \"De son baton il frappa la pierre et l eau jaillit\" | cat -e"
echo "output:"
./ord_alphlong "De son baton il frappa la pierre et l eau jaillit" | cat -e
echo "answer:"
echo "l$
De et il la$
eau son$
baton$
frappa pierre$
jaillit$"
echo "./ord_alphlong \"A a b B cc ca cd\" | cat -e"
echo "output:"
./ord_alphlong "A a b B cc ca cd" | cat -e
echo "answer:"
echo "A a b B$
ca cc cd$"
echo "./ord_alphlong \"Pour l Imperium de l humanite\" | cat -e"
echo "output:"
./ord_alphlong "Pour l Imperium de l humanite" | cat -e
echo "answer:"
echo "l l$
de$
Pour$
humanite Imperium$"
echo "./ord_alphlong \"  C'est un exam que n'est pas comment exam2 ou exam1 mes c'est comment 123exam et 1exam\" | cat -e"
echo "output:"
./ord_alphlong "  C'est un exam que n'est pas comment exam2 ou exam1 mes c'est comment 123exam et 1exam" | cat -e
echo "answer:"
echo "et ou un$
mes pas que$
exam$
1exam C'est c'est exam1 exam2 n'est$
123exam comment comment$"
rm ord_alphlong
