#!/usr/bin/bash

echo "Prime nos between 1 and 20 are: "
new_array=()

for((i=2;i <= 20;i++)); do
    for((j=2;j<i;j++)); do
        if((i%j==0)); then
            continue 2
        fi
    done
    if [[ ! "${new_array[*]}" =~ "$i" ]]; then
        new_array+=($i)
    fi
done
echo "${new_array[@]}"
