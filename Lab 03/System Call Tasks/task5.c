#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("Child process ID: %d\n", getpid());
        for (int i = 0; i < 3; i++)
        {
            pid = fork();
            if (pid == 0)
            {
                printf("Grand Child process ID: %d\n", getpid());
                break;
            }
        }
    }
    else if (pid > 0)
    {
        printf("Parent process ID: %d\n", getpid());
    }

    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
