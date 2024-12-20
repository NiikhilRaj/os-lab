#!/bin/bash
echo "Enter three numbers:"
read a b c
max=$a
min=$a
if (( b > max )); then max=$b; fi
if (( c > max )); then max=$c; fi
if (( b < min )); then min=$b; fi
if (( c < min )); then min=$c; fi
echo "Largest number: $max"
echo "Smallest number: $min"
