#include <stdlib.h> 
#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>

int main(int argc, char* argv[]){
    fflush(stdout);  
    pid_t PID1;
    PID1=fork();
    if(PID1==-1)
    {
        printf("Fork error\n");
    }
    else if(PID1 > 0)                                           //parent process
    {
        while(wait(NULL) > 0);
        fflush(stdout);
        if(fork() > 0)
        {
            while (wait(NULL) > 0);   
            fflush(stdout);
            pid_t PID2;
            PID2=fork();
            if (PID2 == 0)                                      // Third child
            {  
                printf("\n\n\n");    
                printf("\nThe PID of third child is: %d \n", getpid());
                if( access( "f2.c", F_OK ) == 0 )               //check for existence of file
                {
                    remove("f2.c");
                    printf("f2.c is deleted now\n");
                } 
                else 
                {
                    printf("file does not exist\n");
                }
            }
            else                                                //parent process
            { 
                while (wait(NULL) > 0);
                printf("\n\n\n");
                printf("\nThe parent PID is: %d\n\n", getpid());
                printf("Parent process now executed");
            }
        }
        else                                                    //second child
        {  
            printf("\n\n\n");
            printf("\n THe PID of second child is: %d\n", getpid());
            printf("Now printing the contents of f2.c\n");
            FILE *file;              
            file = fopen("f2.c", "r");
            char ch = fgetc(file);
            while(ch != EOF) 
            {
                fputc(ch, stdout);                          // Print the contents
                ch = fgetc(file);
            }
            fclose(file);                                   
        }
    }
    else                                                    //First child
    { 
        printf("\n\n\n");
        printf("\n The PID of first child is: %d\n", getpid());
        FILE *file1;
        FILE *file2;
        file1 = fopen("q4.c", "r");
        file2 = fopen("f2.c", "w");
        char c = fgetc(file1); 
        while (c != EOF) 
        { 
            fputc(c, file2); 
            c = fgetc(file1); 
        }
        printf("Now the source program is copied to f2.c\n");
        fclose(file1);
        fclose(file2);
    }
}




