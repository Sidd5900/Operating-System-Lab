
//Question1:
//Create 2 child processes using fork() system call, Child 1 for adding two integers
//and Child 2 for multiplying two integers. The parent process should divide the results
//of Child 2 by the result of Child 1. All the results must be printed along with the
//respective process ids.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Invalid number of arguments");
        exit(1);
    }

    int num1,num2;

    //storing the arguments in num1 and num2

    sscanf(argv[1],"%d",&num1);
    sscanf(argv[2],"%d",&num2);

    //fd[0] will be the fd(file descriptor) for the read end of pipe.
    //fd[1] will be the fd for the write end of pipe.

    int fdchild1[2], fdchild2[2];

    if(pipe(fdchild1)==-1 || pipe(fdchild2)==-1)
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

    if(PID==0)                                                                      //child process 1 for adding two numbers
    {
        int sum = num1 + num2;
        printf("Sum of two numbers (inside child 1 with process id : %d) = %d\n\n",getpid(),sum);
        write(fdchild1[1],&sum,sizeof(sum));
        close(fdchild1[1]);
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

        if(PID==0)                                                                  //child process 2 for multiplying 
        {
            int product = num1 * num2;
            printf("Multiplication of two numbers (inside child 2 with process id : %d) = %d\n\n",getpid(),product);
            write(fdchild2[1],&product,sizeof(product));
            close(fdchild2[1]);
        }
        else                                                                        //parent process
        {
            wait(NULL);
            int sum,product;

            read(fdchild1[0],&sum,sizeof(sum));
            close(fdchild1[0]);
            read(fdchild2[0],&product,sizeof(product));
            close(fdchild2[0]);

            int ans = product/sum;
            printf("Inside parent process with process id : %d\n", getpid());
            printf("Division of product (computed inside child2) by sum (computed inside child1) = %d\n",ans);
        }
    }
    return 0;
}

