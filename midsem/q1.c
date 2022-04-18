#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//create files 1.txt, 2.txt, ...
void createFile(int num,char *cur_line)
{
    char file_name[25];  
    sprintf(file_name,"%d.txt",num);
    printf("%s is being created\n",file_name);

    FILE *fptr2;
    fptr2=fopen(file_name,"w");
    fputs(cur_line,fptr2);
    fclose(fptr2);

    exit(0);
}

int main()
{
    FILE *fptr1;
    char* file_name = "test1.c";
    fptr1 = fopen(file_name, "r");

    //calculate total no. of lines
    int linecount=0;
    char *cur_line = (char*)malloc(80 * sizeof(char));
    while(fgets(cur_line, 80,fptr1))
    {
        linecount++;
    }
    fclose(fptr1);

    //read line one by one and create file
    fptr1 = fopen(file_name, "r");
    int cur_linenum=0;
    while(fgets(cur_line, 80,fptr1)) 
    {
        cur_linenum++; 
        pid_t PID = fork();
        if(PID < 0)
        {
            printf("fork failed\n");
            exit(1);
        }
        else if(PID == 0)
        {
            createFile(cur_linenum, cur_line);
        }
        else
            wait(NULL);

        //all lines read
        if(cur_linenum == linecount)
        {
            break;
        } 
    }

    fclose(fptr1);
    return 0;
}