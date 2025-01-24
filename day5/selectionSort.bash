#!/bin/bash

selection_sort() {
    arr=("$@")
    n=${#arr[@]}
    
    for ((i = 0; i < n-1; i++)); do
        min_idx=$i
        for ((j = i+1; j < n; j++)); do
            if (( arr[j] < arr[min_idx] )); then
                min_idx=$j
            fi
        done
        temp=${arr[i]}
        arr[i]=${arr[min_idx]}
        arr[min_idx]=$temp
    done

    echo "${arr[@]}"
}

read -p "Enter the elements of the array:" -a array

sorted_array=($(selection_sort "${array[@]}"))

# Print the sorted array
echo "Sorted array: ${sorted_array[@]}"