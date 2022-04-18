//Question 3:
//write a C program which creates one parent process and one child
//process. The child process will execute the task1.sh and the parent process
//will execute the task2.sh

#include <stdio.h>
//Write a C program which creates one parent process and one child
//process. The child process will execute the task1.sh and the parent process
//will execute the task2.sh

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//arguments in order ./q3 task1.sh 4 1 2 3 4 3 task2.sh 6

int main(int argc,char* argv[])
{
	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	pid_t PID = fork();

	if(PID < 0)																					
	{
		printf("Fork Failed\n");
		exit(1);
	}

	if(PID==0)																					//child process (run task1.sh)			
	{
		char *child_argv[argc-2];																														
		for(int i=0;i<argc-3;i++)																//argumemts for task1
			child_argv[i] = argv[i+1];															
		child_argv[argc-3] = NULL;																//child_argv = {task1.sh,N,n1,n2,.........,nN,S,NULL}

		printf("Inside Child Process (will execute task1.sh) with process ID : %d \n", getpid());
		execv(child_argv[0],child_argv);													    //Replacing the child process with task1.sh
		printf("Error : Unable to execute task1.sh \n");										//if we reach till this line means some error
	}
	else																						//parent process (run task2.sh)
	{
		wait(NULL);						
		char *par_argv[3];								
		par_argv[0]=argv[argc-2];
		par_argv[1]=argv[argc-1];
		par_argv[2]=NULL;																		//par_argv = {task2.sh,M,NULL}
		printf("Inside Parent Process (will execute task2.sh) with process ID : %d \n", getpid());
		execv(par_argv[0],par_argv);															//Replacing the parent process with task2.sh
		printf("Error : Unable to execute task2.sh\n");														
	}
}
