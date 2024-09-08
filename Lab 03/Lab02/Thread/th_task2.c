// written by [24341087]

#include <stdio.h>
#include <pthread.h>

void *thread(void *arg)
{
    int *thread_num = (int *)arg;
    for (int i = 1; i <= 5; i++)
    {
        printf("Thread %d prints %d\n", *thread_num, (*thread_num * 5) + i);
    }
    return NULL;
}

int main()
{
    pthread_t tid[5];
    int thread_num[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], NULL, thread, (void *)&thread_num[i]);
        pthread_join(tid[i], NULL);
    }
    return 0;
}