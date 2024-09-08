// written by [24341087]

#include <stdio.h>
#include <pthread.h>

void *thread(void *arg)
{
    printf("%s running\n", (char *)arg);
    printf("%s closed\n", (char *)arg);
    return NULL;
}

int main()
{
    pthread_t tid[5];
    char *thread_name[5] = {"thread-1", "thread-2", "thread-3", "thread-4", "thread-5"};
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tid[i], NULL, thread, (void *)thread_name[i]);
        pthread_join(tid[i], NULL);
    }
    return 0;
}
