#Question 1:
#Write a shell script to print a given Number in reverse order such that the input is
#provided using command Line Argument only. If the input data is not provided as a
#Command Line Argument, it should throw an error. 

# $1 contains the input number

#!/bin/bash
if [ $# -eq 0 ]
then
    echo "Error: No argument provided"

elif [ $# -gt 1 ]
then
    echo "Error: More than one arguments provided"

else
    num=$1							#initialize num with the input integer
    ans=0							#to store the final answer

    while [ $num -ne 0 ]					#loop till num not equal to zero
    do
        ((rem = $num % 10))					#extract the unit digit
        ((ans = $ans * 10 + $rem))				#add the unit digit's contribution to answer
        ((num = $num / 10))					#divide by 10 to remove the unit digit
    done

    echo "The reverse of $1 is $ans"				#Print the answer
fi	
