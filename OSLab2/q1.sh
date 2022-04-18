#!/bin/bash
# Problem 1
# As per the problem, first argument N will be number of elements in array
# Next N arguments will be the elements of array.
# Last element will be the number to be searched.

N=$1
if [ $# -ne $(($N + 2)) ]											#Number of arguments must be N + 2
	then
	echo "Invalid number of arguments"			
	exit 1
fi

arr=(${@:2:$N})												# Storing arguments (contents of array) into array arr

flag=0																#to check if element found
indices=()															#will store the indices (0 based) of the element found
tosearch=${!#}														#element to be searched

for ((i=0;i<$N;i++))												#Iterating the array to check for element tosearch
do
    if [ ${arr[$i]} -eq $tosearch ]
		then
		indices+=($i)
		flag=1
	fi
done

if [ $flag -eq 1 ]													#if element found print the indices
then
    echo Element $tosearch found at indices ${indices[@]}
else
    echo "Element not found."
fi
