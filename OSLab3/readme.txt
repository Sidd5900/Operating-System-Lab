Question 1:

[01/25/22]seed@VM:~/.../OSLab3$ gcc q1.c -o q1

[01/25/22]seed@VM:~/.../OSLab3$ ./q1 8 8
Sum of two numbers (inside child 1 with process id : 4197) = 16

Multiplication of two numbers (inside child 2 with process id : 4198) = 64

Inside parent process with process id : 4196
Division of product (computed inside child2) by sum (computed inside child1) = 4


[01/25/22]seed@VM:~/.../OSLab3$ ./q1 12 6
Sum of two numbers (inside child 1 with process id : 4204) = 18

Multiplication of two numbers (inside child 2 with process id : 4205) = 72

Inside parent process with process id : 4203
Division of product (computed inside child2) by sum (computed inside child1) = 4




Question 2:

[01/25/22]seed@VM:~/.../OSLab3$ gcc q2.c -o q2

[01/25/22]seed@VM:~/.../OSLab3$ ./q2
Hello	Hello	Hello	Hello	Hello	Hello	Hello	Hello	

[01/25/22]seed@VM:~/.../OSLab3$ ./q2
Hello	Hello	Hello	Hello	Hello	Hello	Hello	Hello	



Question 3:

[01/25/22]seed@VM:~/.../OSLab3$ gcc q3.c -o q3

[01/25/22]seed@VM:~/.../OSLab3$ ./q3 task1.sh 4 10 9 8 7 9 task2.sh 4
Inside Child Process (will execute task1.sh) with process ID : 4746 
Element 9 found at indices 1

Inside Parent Process (will execute task2.sh) with process ID : 4745 
fact(4) * PrimeNoLessThan(4) = 120


[01/25/22]seed@VM:~/.../OSLab3$ ./q3 task1.sh 4 10 9 8 7 11 task2.sh 6
Inside Child Process (will execute task1.sh) with process ID : 4757 
Element not found.

Inside Parent Process (will execute task2.sh) with process ID : 4756 
fact(6) * PrimeNoLessThan(6) = 7200




