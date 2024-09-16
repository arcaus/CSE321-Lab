#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("I am grandchild\n");
        }
        else
        {
            wait(NULL);
            printf("I am child\n");
        }
    }
    else
    {
        wait(NULL);
        printf("I am parent\n");
    }
    return 0;
}
