#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/**
 * Assignment 6
 * due 11/18/2024
 */
int data = 0;
pthread_mutex_t mutex;

void* thread1(void* arg){
    for (int i = 1; i <= 5; i++){
        pthread_mutex_lock(&mutex); //Acquire lock 
        data = i; //update shared variable 
        printf("Thread_1 with value %d in critical section\n",data);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* thread2(void * arg){
    for (int i = 1; i <= 5; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("Thread_2 with value %d in critical section\n",data);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main(){
    pthread_t t1,t2;
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    //create threads
    pthread_create(&t1, NULL, thread1,NULL);
    pthread_create(&t2, NULL, thread2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}

