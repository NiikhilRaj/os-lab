#!/bin/bash
echo "Enter distance in meters:"
read distance
km=$(echo "scale=2; $distance / 1000" | bc)
cm=$(echo "scale=2; $distance * 100" | bc)
echo "Distance in kilometers: $km km"
echo "Distance in centimeters: $cm cm"
