#!/bin/bash

#Question 3
#Implement an XOR function using a shell script that will take two numbers as CLA and
#output its XOR. Note: You need to convert the inputs in binary form. Also, implement the
#same using python/C and observe the time taken by both the programs for the same
#input(> 100)

#function to find the XOR value of two numbers passed as parameters
XOR () {
    a=$1
    b=$2
    answer=0
    multiplier=1
   
    while [ 1 ]                                                             #extracting one bit at a time from the lsb, xor them and add the contribution into the answer
    do
        if [ $a == 0 ] && [ $b == 0 ]                                       #if both numbers become zero then break 
        then
            break
        fi        
        lsba=$(($a % 2))                                                    #extract the least significant bits
        lsbb=$(($b % 2))
        lsbxor=$(($lsba * !$lsbb + !$lsba * $lsbb))                         #a xor b = a*b'+a'*b
        answer=$(($answer + $lsbxor * $multiplier))                         #adding the contribution by multiplying with multiplier
        a=$(($a / 2))                                                       #right shift a and b and increase the multiplier
        b=$(($b / 2))
        multiplier=$(($multiplier * 2))
    done

    echo "XOR of $1 and $2 = $answer"                                       #Print the answer
}

num1=$1
num2=$2

if [[ $# -ne 2 ]]
then
    echo "Error: Invalid number of arguments(2 required)"
else
    XOR $num1 $num2                                                         #call XOR function with the given parameters num1 and num2
fi