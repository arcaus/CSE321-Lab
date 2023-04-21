

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

/*
Question:
Write a c program that creates 5 threads and prints which thread is running and after the thread is
closed, a new thread starts its execution. Each thread should run sequentially one by one.
*/

// Thread function
void *thread_function(void *arg)
{
    int *id = (int *)arg;
    printf("thread-%d running\n", *id);
    sleep(1);
    printf("thread-%d closed\n", *id);
    pthread_exit(NULL);
}

// Main function
int main()
{
    pthread_t thread_id[5];
    int i;
    int *id;
    for (i = 0; i < 5; i++)
    {
        id = (int *)malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&thread_id[i], NULL, thread_function, id);
        pthread_join(thread_id[i], NULL);
    }
    return 0;
}
