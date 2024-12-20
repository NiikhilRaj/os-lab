#!/bin/bash
echo "Enter three numbers:"
read a b c
if (( a >= b && a >= c )); then
    echo "The greatest number is $a."
elif (( b >= a && b >= c )); then
    echo "The greatest number is $b."
else
    echo "The greatest number is $c."
fi
