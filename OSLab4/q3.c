
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
	int n;
	printf("Enter the value of n to generate first n lucas sequence:\n");
	scanf("%d",&n);

	//fdchild1[0] will be the fd(file descriptor) for the read end of pipe.
    //fdchild1[1] will be the fd for the write end of pipe.

	int fdchild1[2];

    if(pipe(fdchild1)==-1)
    {   
        printf("Error while opening the file");
        exit(1);
    }

    pid_t PID = fork();                                                             //create new process
    if(PID < 0)
    {
        printf("Fork Failed");
        exit(1);
    }

    if(PID==0)                                                                      //child process 1 for generating the lucas sequence
    {
    	int lucas[n];
		lucas[0]=2;
		lucas[1]=1;
		for(int i=2;i<n;i++)														//generate lucas sequence by adding the previous two terms
		{
			lucas[i]= lucas[i-1] + lucas[i-2];
		}

        write(fdchild1[1],lucas,sizeof(lucas));										//write the lucas sequence array								
        close(fdchild1[1]);
        printf("\nChild process 1 executed (lucas sequence generated)\n");
    }
    else                                                                            //parent process
    {
        wait(NULL);
        PID = fork();                                                               //create new process
        if(PID < 0)
        {
            printf("Fork Failed");
            exit(1);
        }

        if(PID==0)                                                                  //child process 2 for displaying the lucas sequence
        {
        	int lucas[n];
            read(fdchild1[0],lucas,sizeof(lucas));									//read the lucas sequence array
            close(fdchild1[0]);
            printf("\nIn child process 2 and printing the lucas sequence:\n");
            for(int i=0;i<n;i++)													//print the lucas sequence
            	printf("%d ", lucas[i]);
            printf("\nChild Process 2 executed\n");
        }
        else                                                                        //parent process
        {
            wait(NULL);
            printf("\nParent process terminated\n");
        }
    }
	return 0;
}