Q1)
[03/01/22]seed@VM:~/.../midsem$ gcc q1.c -o q1
[03/01/22]seed@VM:~/.../midsem$ ./q1
1.txt is being created
2.txt is being created
3.txt is being created
4.txt is being created

//test1.c
#include <stdio.h>
int main(){
	return 0;
}

1.txt:
#include <stdio.h>

2.txt:
int main(){

3.txt:
	return 0;

4.txt:
}

Q2)
[03/01/22]seed@VM:~/.../midsem$ ./parent Boy Raj Girl Priyanka Boy Harsh Boy Siddharth
I have 4 children
Child # 1: I am a Boy, and my name is Raj.
Child # 2: I am a Girl, and my name is Priyanka.
Child # 3: I am a Boy, and my name is Harsh.
Child # 4: I am a Boy, and my name is Siddharth.
All child processes terminated. Parent exits.


Q3)
5 2
0 10 2
3 7 1
4 6 2
12 5 1
18 8 1
Avg_WT = 10.40 Avg_TAT = 17.60
P2 P4 P5 P3 P1

Q4)

.\...
5 Treasure deposited by depositor thread
Treasure left = 80
5 Treasure borrowed by borrower thread
Treasure left = 75
5 Treasure deposited by depositor thread
Treasure left = 80
5 Treasure borrowed by borrower thread
Treasure left = 75
Hacker thread takes all the treasure left which is equal to 75

