#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

sem_t wrt;
pthread_mutex_t mutex;
int sharedVariable = 1;
int readerCount = 0;			//count of processes currently reading 

void *writer(address_t writerNumber)
{   
    sem_wait(&wrt);
    int wnum = *(int *)writerNumber;
    sharedVariable = sharedVariable + 1;
    printf("Writing....Writer %d updates sharedVariable to %d\n", wnum, sharedVariable);
    sem_post(&wrt);
    return (void *)&SUCCESS;

}
void *reader(address_t readerNumber)
{   
	int rnum = *(int *)readerNumber;

    // Reader acquire the lock before modifying readerCount
    pthread_mutex_lock(&mutex);
    readerCount++;
    if(readerCount == 1) 
    {
        sem_wait(&wrt); // block the writer when first reader comes
    }
    pthread_mutex_unlock(&mutex);

    // Reading Section
    printf("Reading...Reader %d reads sharedVariable which equals %d\n", rnum, sharedVariable);

    //acquire lock before modifying readerCount
    pthread_mutex_lock(&mutex);
    readerCount--;
    if(readerCount == 0) 
    {
        sem_post(&wrt); // wake up the writer when no more reader
    }
    pthread_mutex_unlock(&mutex);
    return (void *)&SUCCESS;
}

int main()
{   

    pthread_t read[5],write[2];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);

    int readnum[5];
    int writenum[2];

    for(int i = 0; i < 5; i++) 
    {
    	readnum[i] = i+1;
        int status = pthread_create(&read[i], NULL, reader, (void *)&readnum[i]);
        if(status!=0)
			printf("Error creating Reader Thread %d \n", readnum[i]);

    }

    for(int i = 0; i < 2; i++) 
    {
    	writenum[i] = i+1;
        int status = pthread_create(&write[i], NULL, writer, (void *)&writenum[i]);
        if(status!=0)
			printf("Error creating Writer Thread %d \n", writenum[i]);    
    }

    for(int i = 0; i < 5; i++) 
    {
        pthread_join(read[i], NULL);
    }

    for(int i = 0; i < 2; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
    
}

