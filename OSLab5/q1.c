#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

void* func(address_t args)
{
	int curthread= *(int*)args;										//current thread
	printf("Thread %d: Hello World!\n",curthread);
	char * str=(char *)malloc(30*sizeof(char));						//dynamically allocate space for writing the return status
	sprintf(str,"Thread %d",curthread);								//write where str is pointing
	sleep(5);														//wait so that threads do not terminate instantly
	return (void *)str;												//returnn the status
}

int main(int argc, char* argv[])
{
	pthread_t tid[10];												//for creating ten threads
	int arg[10];
	for(int i=0;i<10;i++)
	{
		arg[i]=i;
		int status = pthread_create(&tid[i], NULL, func, (address_t)&arg[i]);	//create thread
		
		if(status!=0)
			printf("Error creating Thread %d \n", i);
		
	}

	address_t statusp;												//to store the status returned
	pthread_cancel(tid[9]);											//cancel the last thread

	for(int i=0;i<10;i++)
	{

		if(pthread_join( tid[i], &statusp )==0)
		{
			//printing return status
			if(statusp== (int*)(-1) )
			printf("Thread %d, status = CANCELLED\n",i);
			else
			printf("i = %d, status = %s \n", i, (char*)statusp );
		}
		else
			printf("Error while joining thread %d\n",i );
	}
	
	pthread_exit( NULL );
	return 0;
}