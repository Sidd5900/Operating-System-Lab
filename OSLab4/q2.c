#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void createProcess()
{
	pid_t PID;
	PID=fork();
	if(PID==-1)
	{
		printf("Fork Error\n");
	}
	if(PID==0)
	{
		sleep(100);					//sleep for 100 seconds so that parent process could terminate in the mean time
		printf("Child process executed\n");
		exit(0);					//exit immediately after execution
	}
	else							//parent process
	{
		return;						//simply return and get back to the next iteration of the loop
	}
}

int main(int argc,char* argv[])
{
	int n;
	printf("Enter the value of n to create n orphan process:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)						//create n child processes
	{
		createProcess();
	}
	printf("Parent process completed\n");		//Now parent process will terminate while child processes still running hence n orphan processes are created
	return 0;
}