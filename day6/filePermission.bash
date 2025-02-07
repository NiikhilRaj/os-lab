#!/bin/bash

list_rw_files() {
    echo "Files and directories with both read and write permissions:"
    for item in *  
    do
        if [ -e "$item" ] && [ -r "$item" ] && [ -w "$item" ]; then
            echo "$item"
        fi
    done
}

# Call the function
list_rw_files
