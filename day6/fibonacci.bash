#!/bin/bash

fibonacci() {
    a=0
    b=1
    echo "Fibonacci series:"
    for (( i=0; i<$1; i++ ))
    do
        echo -n "$a "
        fn=$((a + b))
        a=$b
        b=$fn
    done
    echo
}

echo "Enter the number of terms:"
read n
fibonacci $n
