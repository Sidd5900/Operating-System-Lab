#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

sem_t mutex;
sem_t data;

void* A(void* arg) 
{
	sem_wait(&mutex);
	sem_wait(&data);
	printf("process A");
	sem_post(&mutex);
	sem_post(&data);
}

void* B(void* arg) 
{
	sem_wait(&mutex);
	sem_wait(&data);
	printf("process B");
	sem_post(&mutex);
	sem_post(&data);
}

int main()
{
    pthread_t tid[2];          //8 student threads
    sem_init(&mutex,0,1);
    sem_init(&data,0,1);
    int args[2];

    //create threads
    pthread_create(&tid[0],NULL, A ,NULL);
    pthread_create(&tid[1],NULL, B, NULL);

    //join threads
    for(int i=0;i<2;i++)
    {
        pthread_join(tid[i],NULL);
    }
  
    sem_destroy(&mutex);
    sem_destroy(&data);
    return 0;
}