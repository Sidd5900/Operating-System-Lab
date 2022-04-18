#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;
int total_lines;																			//Number of lines to write in file

FILE *f1,*f2;																				//File pointers to write and read file respectively

int isprime[10001];																			//isprime[i] = 1 when i is prime
int linesWritten = 0;																		//Number of lines already written

//function to compute whether the no. is prime or not from 1 to n
void PrimeSieve(int n)																
{
	isprime[0] = isprime[1] = 0;

	for(int i=2;i<=n;i++)
		isprime[i] = 1;

	for(int j=2;j*j<=n;j++)
	{
		if(isprime[j])
		{
			for(int i=j*j;i <= n;i += j)
				isprime[i] = 0;
		}	
	}
}


void* func(void* args)															
{
	int curthread = *(int*)args;														//cuurent thread
	if(curthread == 0)																	//First thread to write on non prime lines
	{
		char str[] = "The current line number is not prime and we are inside Thread 1";
		while(linesWritten < total_lines)
		{
			if(isprime[linesWritten + 1] == 0)											//Write when the next line is not prime
			{
				fprintf(f1,"%s\n",str);										
				linesWritten++;														
			}
		}
	}
	else if(curthread == 1)																//Second thread to write on prime lines
	{
		char str[] = "The current line number is prime and we are inside Thread 1";
		while(linesWritten < total_lines)
		{
			if(isprime[linesWritten+ 1] == 1)											//Write when the next line is not prime
			{
				fprintf(f1,"%s\n",str);										
				linesWritten++;														
			}
		}
	}		
	else if(curthread == 2)																//Third thread to count the number of characters in each line written
	{
		int linesread = 0;																//To store how many lines have been read
		while(linesread < total_lines)														
		{
			if(linesread < linesWritten)													
			{
				fflush(f1);													
				int cnt = 0;															//to store the count of characters in current line
				char c = getc(f2);
				while(c != '\n')							
				{
					cnt++;
					c = getc(f2);
				}
				linesread++;														
				printf("Total number of characters in line %d is : %d\n",linesread,cnt);
			}
		}
	}
	return (void *)&SUCCESS;
}

int main(int argc,char **argv)													
{
	printf("Enter the number of lines to be written\n");
	scanf("%d",&total_lines);
	PrimeSieve(total_lines);																	//Calling PrimeSieve 

	pthread_t tid[3];
	int arg[3];

	f1 = fopen("sampleq2.txt","w");																//opening files
	f2 = fopen("sampleq2.txt","r");	

	//create threads
	for(int i=0;i<3;i++)
	{
		arg[i]=i;
		int status = pthread_create(&tid[i],NULL,&func,&arg[i]);
		if(status!=0)
			printf("Error creating Thread %d \n", i);
	}

	for(int i=0;i<3;i++)
	{
		if(pthread_join(tid[i],NULL)!=0)
			printf("Error while joining thread\n");
	}

	fclose(f1);																//Closing files
	fclose(f2);
}