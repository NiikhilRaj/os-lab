#!/bin/bash
Hello (){
    echo "Hello for $1 to $2"
    return 10
}
Hello "Krish" "Shyam"
ret=$?
echo $ret