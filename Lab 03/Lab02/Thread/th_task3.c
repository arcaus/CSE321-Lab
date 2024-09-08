// written by [24341087]

#include <stdio.h>
#include <pthread.h>
#include <string.h>

int sum = 0;
void *thread(void *arg)
{
    char *name = (char *)arg;
    for (int i = 0; i < strlen(name); i++)
    {
        sum += name[i];
    }
    return NULL;
}

int main()
{
    pthread_t tid[4];
    char name[3][100];
    printf("Enter three user names: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Enter user name %d: ", i + 1);
        scanf("%s", name[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tid[i], NULL, thread, (void *)name[i]);
        pthread_join(tid[i], NULL);
    }
    pthread_create(&tid[3], NULL, thread, (void *)name[0]);
    pthread_join(tid[3], NULL);
    if (sum == (name[0][0] + name[1][0] + name[2][0]))
    {
        printf("Youreka\n");
    }
    else if (sum == (name[0][0] + name[1][0]) || sum == (name[0][0] + name[2][0]) || sum == (name[1][0] + name[2][0]))
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta la vista\n");
    }
    return 0;
}
