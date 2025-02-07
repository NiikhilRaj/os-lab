#!/bin/bash

fibonacci_recursive() {
    if [ $1 -le 0 ]; then
        echo 0
    elif [ $1 -eq 1 ]; then
        echo 1
    else
        echo $(( $(fibonacci_recursive $(( $1 - 1 ))) + $(fibonacci_recursive $(( $1 - 2 ))) ))
    fi
}

fib_series() {
    echo "Fibonacci series:"
    for (( i=0; i<$1; i++ ))
    do
        echo -n "$(fibonacci_recursive $i) "
    done
    echo
}

echo "Enter the number of terms:"
read n
fib_series $n
