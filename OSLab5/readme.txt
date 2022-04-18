Q1)

[02/09/22]seed@VM:~/.../OSLab5$ gcc q1.c -o q1 -lpthread
[02/09/22]seed@VM:~/.../OSLab5$ ./q1
Thread 1: Hello World!
Thread 0: Hello World!
Thread 4: Hello World!
Thread 3: Hello World!
Thread 2: Hello World!
Thread 6: Hello World!
Thread 5: Hello World!
Thread 7: Hello World!
Thread 8: Hello World!
Thread 9: Hello World!
i = 0, status = Thread 0 
i = 1, status = Thread 1 
i = 2, status = Thread 2 
i = 3, status = Thread 3 
i = 4, status = Thread 4 
i = 5, status = Thread 5 
i = 6, status = Thread 6 
i = 7, status = Thread 7 
i = 8, status = Thread 8 
Thread 9, status = CANCELLED




Q2)

[02/09/22]seed@VM:~/.../OSLab5$ gcc q2.c -o q2 -lpthread
[02/09/22]seed@VM:~/.../OSLab5$ ./q2
Enter the number of lines to be written
10
Total number of characters in line 1 is : 63
Total number of characters in line 2 is : 59
Total number of characters in line 3 is : 59
Total number of characters in line 4 is : 63
Total number of characters in line 5 is : 59
Total number of characters in line 6 is : 63
Total number of characters in line 7 is : 59
Total number of characters in line 8 is : 63
Total number of characters in line 9 is : 63
Total number of characters in line 10 is : 63


//Contents of the file sampleq2.txt after execution

The current line number is not prime and we are inside Thread 1
The current line number is prime and we are inside Thread 1
The current line number is prime and we are inside Thread 1
The current line number is not prime and we are inside Thread 1
The current line number is prime and we are inside Thread 1
The current line number is not prime and we are inside Thread 1
The current line number is prime and we are inside Thread 1
The current line number is not prime and we are inside Thread 1
The current line number is not prime and we are inside Thread 1
The current line number is not prime and we are inside Thread 1




Q3)

[02/09/22]seed@VM:~/.../OSLab5$ gcc q3.c -o q3 -lpthread
[02/09/22]seed@VM:~/.../OSLab5$ ./q3
Enter the capacity of petrol tanker:
10
Enter the petrol taken in litres per customer at a time
1
Enter the no. of vending machines (m):
4
Enter m values, the no. of customers in each of the m queues:
2 3 4 3
Petrol taken by a customer on vending machine 3
Petrol left in tank = 9
Petrol taken by a customer on vending machine 3
Petrol left in tank = 8
Petrol taken by a customer on vending machine 0
Petrol left in tank = 7
Petrol taken by a customer on vending machine 2
Petrol left in tank = 6
Petrol taken by a customer on vending machine 3
Petrol left in tank = 5
Petrol taken by a customer on vending machine 0
Petrol left in tank = 4
Petrol taken by a customer on vending machine 2
Petrol left in tank = 3
Petrol taken by a customer on vending machine 1
Petrol left in tank = 2
Petrol taken by a customer on vending machine 2
Petrol left in tank = 1
Petrol taken by a customer on vending machine 1
Petrol left in tank = 0


[02/09/22]seed@VM:~/.../OSLab5$ gcc q3.c -o q3 -lpthread
[02/09/22]seed@VM:~/.../OSLab5$ ./q3
Enter the capacity of petrol tanker:
100
Enter the petrol taken in litres per customer at a time
15
Enter the no. of vending machines (m):
7
Enter m values, the no. of customers in each of the m queues:
3 5 4 2 1 6 3
Petrol taken by a customer on vending machine 0
Petrol left in tank = 85
Petrol taken by a customer on vending machine 1
Petrol left in tank = 70
Petrol taken by a customer on vending machine 2
Petrol left in tank = 55
Petrol taken by a customer on vending machine 0
Petrol left in tank = 40
Petrol taken by a customer on vending machine 1
Petrol left in tank = 25
Petrol taken by a customer on vending machine 3
Petrol left in tank = 10
[02/09/22]seed@VM:~/.../OSLab5$ 
