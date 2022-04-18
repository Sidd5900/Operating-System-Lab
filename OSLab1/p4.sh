#Question 4:
#Write a shell script to take a directory_path, a filename_pattern and a
#new_filename as input. Rename all files in directory which matches filename_pattern to
#{new_filename} _{count} .txt

#!/bin/bash


echo "Enter Directory Path : "											
read directory_path
echo "Enter Filename Pattern : "
read filename_pattern
echo "Enter New Filename : "
read new_filename

cd $directory_path
count=1 										        # storing count of file with new_filename

for curr_file in *										#Using for loop to iteratie over everything present in the directory_path
do
	if [ -f $curr_file ]								        #checking if its a file not a folder
		then
		file_name=$(basename "$curr_file")					        #to store name of the file with extension
		extension="${file_name##*.}"							#to store only the extension of the file
		file_name="${file_name%.*}"							#Stores only the name of file without extension
		if [[ "$file_name" =~ "$filename_pattern" ]]					#Using regex to check if filename_pattern is a substring of $file_name or not
		then
			new_name=$new_filename
			new_name+="_$count"
			new_name+=".$extension"							#Creating new_name using the new_filename,cnt and extension
			$(mv $curr_file $new_name)						#renaming the file
			((count++))								#incrementing the counter
		fi
	fi
done
