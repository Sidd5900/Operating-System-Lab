#Question 3:
#Write a shell script to simply count the number of lines in an input file by iterating
#over all lines. If the number of lines is less than a value then delete the file. The inputs are
#provided using command Line Argument only

# $1 contains filename and $2 contains the minimum number of lines required so that file is not deleted

#!/bin/bash
if [ $# -ne 2 ] 
then
    echo "Error: Invalid number of arguments."

else
    filename=$1
    min_lines=$2
    total_lines=0						#counter to store the total no. of lines in the given file

    while  read	line;						#Iterate over the lines in the file using while loop
    do
        ((total_lines = $total_lines + 1))			#increase the counter by one in each iteration
    done  < "$filename"
    
    echo "Number of lines in the file: $total_lines"		#Print the total no. of lines in the file

    if [ $total_lines -lt $min_lines ]				#delete the file if no. of lines is less than the given second argument
    then
        echo "Deleting the file $filename"
        rm -f $filename
    fi
fi
