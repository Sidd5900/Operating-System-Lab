#!/bin/bash

#Question 2
#Write a recursive shell program that should output the product of factorial of a number
#with the sum of all the prime no. less than equal to that number. Take N from CLA. E.g :
#N = n , Output = fact(n) * PrimeNoLessThan(n) = n * fact(n-1) * (if(n⋿ Prime number) +
#PrimeNoLessThan(n-1) )


# Function to find sum of prime numbers less than or equal to a number(passed as parameter to the function)

function PrimeNoLessThan() {
	curnum=$1
	if [ $curnum -le 1 ]															#base case
	then
		echo 0
	else
		for((i=2;i*i<=$curnum;i++))													#check every number from 2 to sqrt(curnum) for divisibility
		do
			if [ $(($curnum % $i)) -eq 0 ]											#if factor found then not a prime
			then
				echo $(PrimeNoLessThan $(( $curnum - 1)) )							#recur for curnum-1
				return
			fi
		done
		echo $(( $curnum + $( PrimeNoLessThan $(( $curnum - 1)) ) ))				#no factor found (curnum is prime) so add curnum and recur for curnum-1
	fi
}

# Recursive function to calculate factorial of a number(passed as parameter to the function)

function fact() { 
	num=$1
    if [ $num -le 1 ]																	#base case
    then
        echo 1
    else	
        echo $(( $num * $( fact $(( $num - 1 )) ) ))									#recur for num-1 and multiply the result with num 
    fi
}


if [ $# -ne 1 ]
then
	echo "Error: Invalid input format"
else
	echo "fact($1) * PrimeNoLessThan($1) = $(( $(PrimeNoLessThan $1) * $(fact $1) ))"
fi	



