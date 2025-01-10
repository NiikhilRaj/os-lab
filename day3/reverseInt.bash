#!/bin/bash

# Script to reverse a given integer
echo "Enter an integer: "
read num
reverse=0

while [ $num -ne 0 ]; do
  digit=$((num % 10))
  reverse=$((reverse * 10 + digit))
  num=$((num / 10))
done

echo "Reversed integer: $reverse"