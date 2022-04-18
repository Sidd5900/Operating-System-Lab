#!/bin/bash

#Question 4
#Write a shell script to validate password strength. Here are a few assumptions for the
#password string.
#Length – a minimum of 7 characters.
#Contain both alphabet and number.
#Contain one special char ( /, (, ),<, >, ? )

if [ $# -ne 1 ]
then
	echo "Invalid number of arguments"
	exit 1
fi

passwd=$1																# Storing password and its length
len=${#passwd}

if [ $len -lt 7 ]
	then
	echo "Invalid Password"
	exit 1
fi

# Characters for matching
alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
nums="0123456789"
special="/()<>?"

# A function to match characters from password string and the above three strings
function MatchStrings() {
	tomatch=$1															#characters to match
	for ((i = 0; i < $len; ++i))
    do
		for ((j = 0; j < ${#tomatch}; ++j))								
        do
			if [ ${passwd:i:1} == ${tomatch:j:1} ]; 					#match found
			then
				echo 1
				return
			fi
		done
	done
	echo 0				
}

# Validating presence of characters as per problem statement
if [ $(MatchStrings "$alpha") -eq 1 ]  && [ $(MatchStrings "$nums") -eq 1 ] && [ $(MatchStrings "$special") -eq 1 ]; 
then
	echo "Password is Valid"
else
	echo "Password is invalid"
fi
