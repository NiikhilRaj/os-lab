#!/bin/bash
date_format=$(date "+%a %b %d %T %Z %Y")
day=$(date "+%d")
month=$(date "+%b")
year=$(date "+%Y")
time=$(date "+%H.%M")
echo "$day/$month/$year/$time"
