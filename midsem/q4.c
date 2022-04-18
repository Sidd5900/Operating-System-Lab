#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

pthread_mutex_t mutex;															//create mutex variable

pthread_t tid[3];
int treasure_left;																//amount of treasure left
int treasure_bd;																//amount of treasure deposited / borrowed in one go

void* func(address_t args)
{
	int id= *(int*)args;

	if(id == 0)				//borrower thread
	{
		while(1)
		{
			//wait so that depositor deposits some treasure if sufficient treasure not available
			while(treasure_left < treasure_bd)
			{
				sleep(0.01);
			}
			pthread_mutex_lock(&mutex);
			treasure_left = treasure_left - treasure_bd;
			printf("%d Treasure borrowed by borrower thread\nTreasure left = %d\n", treasure_bd, treasure_left);
			pthread_mutex_unlock(&mutex);
			sleep(0.01);	
		}
	}
	else if(id == 1)		//depositor thread
	{

		while(1)
		{
			pthread_mutex_lock(&mutex);
			treasure_left = treasure_left + treasure_bd;
			printf("%d Treasure deposited by depositor thread\nTreasure left = %d\n", treasure_bd, treasure_left);
			pthread_mutex_unlock(&mutex);
			sleep(0.01);	
		}
	}
    else if(id == 2)		//hacker thread
    {
    	sleep(1);
    	pthread_mutex_lock(&mutex);
    	printf("Hacker thread takes all the treasure left which is equal to %d\n", treasure_left);

    	//immediately cancel other threads
    	pthread_cancel(tid[0]);
    	pthread_cancel(tid[1]);
    	pthread_mutex_unlock(&mutex);
    }
 	
	return (void *)&SUCCESS;
}

int main(int argc, char* argv[])
{
	pthread_mutex_init(&mutex,NULL);											//initialize mutex
	printf("Enter the initial treasure amount:\n");
	scanf("%d",&treasure_left);

	printf("Enter the treasure amount borrowed / deposited in one go\n");
	scanf("%d",&treasure_bd);
	
	
	int arg[3];

	//create threads for each vending machine
	for(int i=0;i<3;i++)
	{
		arg[i]=i;
		int status = pthread_create(&tid[i], NULL, func, (address_t)&arg[i]);
		if(status!=0)
			printf("Error creating Thread %d \n", i);
	}

	for(int i=0;i<3;i++)
	{
		if(pthread_join(tid[i],NULL)!=0)
			printf("Error while joining thread\n");
	}

	//destroy mutex
	pthread_mutex_destroy(&mutex);
	pthread_exit( NULL );
	return 0;
}

