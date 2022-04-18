#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

pthread_mutex_t mutex;															//create mutex variable

int no_of_cust[1001];															//stores number of customers in each queue
int capacity;																	//total capacity of petrol tanker in litres
int petrol_taken;																//the petrol taken in litres per customer at a time

void* func(address_t args)
{
	int vid= *(int*)args;
	int customers_left = no_of_cust[vid];										//process the current queue

	while(customers_left > 0 && capacity - petrol_taken >= 0)					//give petrol until no customer left in current queue or insufficient petrol left
	{
		pthread_mutex_lock(&mutex);
		printf("Petrol taken by a customer on vending machine %d\n", vid);
		capacity = capacity - petrol_taken;										//give petrol and update capacity
		customers_left--;														//decrement customers left
		printf("Petrol left in tank = %d\n", capacity);
		pthread_mutex_unlock(&mutex);
		sleep(0.01);															//to prevent the same vending machine to get the chance everytime
	}
 	
	return (void *)&SUCCESS;
}

int main(int argc, char* argv[])
{
	pthread_mutex_init(&mutex,NULL);											//initialize mutex
	printf("Enter the capacity of petrol tanker:\n");
	scanf("%d",&capacity);

	printf("Enter the petrol taken in litres per customer at a time\n");
	scanf("%d",&petrol_taken);

	printf("Enter the no. of vending machines (m):\n");
	int m;
	scanf("%d",&m);


	printf("Enter m values, the no. of customers in each of the m queues:\n");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&no_of_cust[i]);
	}
	
	pthread_t tid[1001];
	int arg[1001];

	//create threads for each vending machine
	for(int i=0;i<m;i++)
	{
		arg[i]=i;
		int status = pthread_create(&tid[i], NULL, func, (address_t)&arg[i]);
		if(status!=0)
			printf("Error creating Thread %d \n", i);
	}

	for(int i=0;i<m;i++)
	{
		if(pthread_join(tid[i],NULL)!=0)
			printf("Error while joining thread\n");
	}

	//destroy mutex
	pthread_mutex_destroy(&mutex);
	pthread_exit( NULL );
	return 0;
}

