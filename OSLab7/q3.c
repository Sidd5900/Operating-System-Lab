#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

const int SUCCESS = 0;
const int FAIL = -1;

typedef void* address_t;

//mutex variable to access shared variables
pthread_mutex_t mutex;

int sliceCount=5;
int pizzaNotPresent=0;

//semaphore to run delivery thread
sem_t deliverySemaphore;


//eat slice if available else order pizza
void * eatSlice(void *arg)
{
    int studnum= *(int *)arg;

    while(1)
    {
        //aquire lock
        pthread_mutex_lock(&mutex);

        //eat slice if available and study
        if(sliceCount > 0)
        {
            sliceCount--;
            printf("Student %d picked up a slice and started studying. Slices left = %d\n", studnum, sliceCount);
        }
        //initiate delivery when no slice left and then go to sleep
        else{
            if(pizzaNotPresent)
            {
                printf("Student %d went to sleep as no slices left.\n",studnum);  
            }
            else
            {
                pizzaNotPresent=1;
                //signal delivery semaphore
                sem_post(&deliverySemaphore);
                printf("Student %d ordered pizza as no slices left and went to sleep\n",studnum);
            }  
        }
        
        //release lock
        pthread_mutex_unlock(&mutex); 
        sleep(1);    
    }
}

void * deliverPizza()
{
    while(1)
    {  
        //wait call for delivery semaphore
        sem_wait(&deliverySemaphore);

        //acquire lock when there is a delivery request (no pizza left)
        pthread_mutex_lock(&mutex);
        if(pizzaNotPresent)
        {
            sliceCount=5;
            pizzaNotPresent=0;
            printf("Pizza delivered...Slice Count =  %d\n",sliceCount);
        }
        //release the lock
        pthread_mutex_unlock(&mutex);     
    }
    
}

int main()
{
    pthread_t students[8];          //8 student threads
    pthread_t delivery;             //1 delivery thread

    pthread_mutex_init(&mutex,NULL);
    sem_init(&deliverySemaphore,0,1);
    int args[8];

    //create threads
    for(int i=0;i<8;i++)
    {
        args[i]=i+1;
        int status = pthread_create(&students[i],NULL, eatSlice, (void *) &args[i]);
        if(status!=0)
            printf("Error creating Student Thread %d \n", args[i]);
    }
    pthread_create(&delivery,NULL, deliverPizza ,NULL);

    //join threads
    for(int i=0;i<8;i++)
    {
        pthread_join(students[i],NULL);
    }
    pthread_join(delivery,NULL);
   
    //destroy mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&deliverySemaphore);
    return 0;
}