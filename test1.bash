#!/usr/bin/bash

read -p "Enter elements of string" -a string
n=${#string[@]}

for((i=$((n-1)); i >= 0; i--)); do
echo ${string[i]}
done