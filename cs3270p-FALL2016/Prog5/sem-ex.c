
// to compile: gcc -o sem-ex sem-ex.c -Wall -Werror -lrt -lpthread
// to run: ./sem-ex number_of_threads (e.g., ./sem-ex 3)


/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

/* prototype for thread routine */
void handler ( void *ptr );

/* global vars */
/* semaphores are declared global so they can be accessed 
   in main() and in thread routine,
   here, the semaphore is used as a mutex */
sem_t mutex; /* semaphore object */
int counter; /* shared variable */

int main(int argc, char **argv)
{
    int num_threads = atoi(argv[1]);
    int i[num_threads], j;
    pthread_t thread[num_threads];
   
    for(j=0; j<num_threads; j++)
       i[j] = j;      /* argument to threads */
    
    sem_init(&mutex, 0, 1);      /* initialize mutex to 1 - binary semaphore */
                                 /* second param = 0 - semaphore is local */

    /* creating pthreads */                             
    for(j=0; j<num_threads; j++)
        pthread_create (&thread[j], NULL, (void *) &handler, (void *) &i[j]);

    /* joining threads- waiting threads to be terminated */   
    for(j=0; j<num_threads; j++)
        pthread_join(thread[j], NULL);

    sem_destroy(&mutex); /* destroy semaphore */
                  
    /* exit */  
    exit(0);
} /* main() */

void handler ( void *ptr )
{
    int x; 
    x = *((int *) ptr);
 
    printf("Thread %d: Waiting to enter critical region...\n", x);
    sem_wait (&mutex);	/* down semaphore */
    /* START CRITICAL REGION */
    printf("Thread %d: Now in critical region...\n", x);
    printf("Thread %d: Counter Value: %d\n", x, counter);
    printf("Thread %d: Incrementing Counter...\n", x);
    counter++;
    printf("Thread %d: New Counter Value: %d\n", x, counter);
    printf("Thread %d: Exiting critical region...\n", x);
    /* END CRITICAL REGION */    
    sem_post (&mutex);	/* up semaphore */
    pthread_exit(0); /* exit thread */
}
