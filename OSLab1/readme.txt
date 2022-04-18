#Question 1:

[01/11/22]seed@VM:~/.../OS_Lab$ bash p1.sh 4567
The reverse of 4567 is 7654

[01/11/22]seed@VM:~/.../OS_Lab$ bash p1.sh
Error: No argument provided



#Question 2:

[01/11/22]seed@VM:~/.../OS_Lab$ bash p2.sh 2 8
2 3 4 5 6 7 8 

[01/11/22]seed@VM:~/.../OS_Lab$ bash p2.sh 8 2
Error: First argument is greater than second argument



#Question 3:

[01/11/22]seed@VM:~/.../OS_Lab$ ls
f1.txt  p1.sh  p2.sh  p3.sh  p4.sh  readme.txt  sample.txt

[01/11/22]seed@VM:~/.../OS_Lab$ bash p3.sh sample.txt 7
Number of lines in the file: 9

[01/11/22]seed@VM:~/.../OS_Lab$ bash p3.sh sample.txt 10
Number of lines in the file: 9
Deleting the file sample.txt

[01/11/22]seed@VM:~/.../OS_Lab$ ls
f1.txt  p1.sh  p2.sh  p3.sh  p4.sh  readme.txt
[01/11/22]seed@VM:~/.../OS_Lab$ 



#Question 4:

root@VM:/home/seed/test# ls
f1.txt  f2.txt  f3.txt  OS_Lab  p4.sh  testing_1.txt  testing_2.txt

root@VM:/home/seed/test/OS_Lab# bash p4.sh 

Enter Directory Path : 
/home/seed/test
Enter Filename Pattern : 
est
Enter New Filename : 
hey

root@VM:/home/seed/test/OS_Lab# cd ..

root@VM:/home/seed/test# ls
f1.txt  f2.txt  f3.txt  hey_1.txt  hey_2.txt  OS_Lab  p4.sh










