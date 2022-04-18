#Problem 2:
#Write a simple shell script that takes two numbers as parameters and uses a while
#loop to print all the numbers from the first to the second inclusive, each number separated
#only by a space from the previous number

# $1 and $2 contains the input numbers

#!/bin/bash
if [ $# -ne 2 ]										
then
    echo "Error: Number of arguments not equal to 2"

elif [ $1 -gt $2 ]
then
    echo "Error: First argument is greater than second argument"

else
    num=$1								#initialize num with the first argument

    while [ $num -le $2 ]						#go till second argument 
    do
        echo -n "$num "							#Print the number
        ((num = $num + 1))						#Increment the number by 1
    done

echo ""
fi	
