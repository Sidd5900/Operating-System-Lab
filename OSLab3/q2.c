//Question 2:
//using fork() system calls over a parent process to print
//the following output.
//Output:
//Hello Hello Hello Hello Hello Hello Hello Hello

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

//two forks hence total processes=4 => 4 Hello printed inside func for each of the process
int func()
{
	pid_t PID;
	PID = fork();
	if(PID<0)
	{
		printf("fork failed\n");
		exit(1);
	}

	PID = fork();
	if(PID<0)
	{
		printf("fork failed\n");
		exit(1);
	}													
	printf("Hello\t");													
}

int main() 
{
	func();															
	printf("Hello\t");												//For each process one more Hello printed => 4 more Hello printed hence total hello = 4 + 4 = 8
	exit(0);
}
