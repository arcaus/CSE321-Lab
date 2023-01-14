// Program written by: Iftekhar Turja

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#define MAX 10 // producers and consumers can produce and consume upto MAX

#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */

void *consumer(int *id);
void *producer(int *id);

char buffer[BUFLEN];
char source[BUFLEN]; // from this array producer will store it's production into buffer

int pCount = 0;
int cCount = 0;
int buflen;

// initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0, 1};
int i = 0;
int j = 0;

void *producer(int *id)
{
    /*
    1. Producer stores the values in the buffer (Here copies values from source[] to buffer[]).
    2. Use mutex and thread communication (wait(), sleep() etc.) for critical section.
    3. Print which producer is storing which values using which thread inside the critical
    section.
    4. Producer can produce upto MAX
    */
    // Write code here
    int i;
    for (i = 0; i < MAX; i++)
    {
        pthread_mutex_lock(&count_mutex);
        int item = rand();
        while (pCount == item && pCount <= BUFLEN && pCount > 0)
        {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }

        buffer[pCount] = source[pCount % buflen];
        printf("%d produced %c by Thread %d\n", i, buffer[pCount], *id);
        pCount = (pCount + 1) % buflen;
        cCount++;

        pthread_mutex_unlock(&count_mutex);
        pthread_cond_signal(&full);
    }
    pthread_exit(NULL);
}

void *consumer(int *id)
{
    /*
    1. Consumer takes out the value from the buffer and makes it empty.
    2. Use mutex and thread communication (wait(), sleep() etc.) for critical section
    3. Print which consumer is taking which values using which thread inside the critical
    section.
    4. Consumer can consume upto MAX
    */
    // Write code here
    pthread_mutex_lock(&count_mutex);
    while (j < cCount)
    {
        int item = rand();
        if (item <= BUFLEN)
        {
            if (j == item || j < pCount || j == 0)
            // if(cCount == 0)
            {
                pthread_cond_wait(&full, &count_mutex);
            }
        }

        printf("%d consumed %c by Thread %d\n", j, buffer[j], *id);
        j++;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    int i;
    /* define the type to be pthread */
    pthread_t thread[NUMTHREAD];
    strcpy(source, "abcdef");
    buflen = strlen(source);
    /* create 2 threads, one producer thread and one consumer thread and define the multi-thread properties for both of them */
    pthread_create(&thread[0], NULL, (void *)producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, (void *)consumer, &thread_id[1]);
    /* wait for the threads to complete */
    for (i = 0; i < NUMTHREAD; i++)
    {
        pthread_join(thread[i], NULL);
    }
    return 0;
}