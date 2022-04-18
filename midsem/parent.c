#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//arguments in order ./parent Boy Raj Girl Priyanka Boy Harsh Boy Siddharth

int main(int argc,char* argv[])
{
	//arguments must be in pair
	if(argc % 2 == 0)
	{
		printf("Invalid number of arguments\n");
		exit(1);
	}

	int pairs = (argc-1)/2;
	printf("I have %d children\n", pairs);

	pid_t PID;
	for(int i=0;i<pairs;i++)
	{
		//create process
		PID = fork();
		if(PID < 0)
		{
			printf("fork failed\n");
			exit(1);
		}
		if(PID == 0)									//child process
		{
			char *newargv[5];
			newargv[0] = "child";
			char * str=(char *)malloc(2*sizeof(char));						
			sprintf(str,"%d", i+1);	
			//arguments to execute child program
			newargv[1] = str;
			newargv[2] = argv[ 2*i +1 ];
			newargv[3] = argv[ 2*i + 2];
			newargv[4] = NULL; 
			execv(newargv[0], newargv);
			printf("Error running execv()\n");
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}

	printf("All child processes terminated. Parent exits.\n");
    
}
