// Program written by: Iftekhar Turja

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/*
Question:
Write a program in c that the parent process will create one child process and 3 grandchild
processes and print their IDs
Output: 1. Parent process ID : 0
2. Child process ID : ...
3. Grand Child process ID: ...
4. Grand Child process ID: ...
5. Grand Child process ID: ...
*/

// main function
int main()
{
    pid_t pid, pid1, pid2, status;
    pid = fork();
    if (pid == 0)
    {
        pid1 = fork();
        if (pid1 > 0)
        {
            printf("Child process ID : %d\n", getpid());
        }
        else
        {
            pid2 = fork();
            if (pid2 > 0)
            {
                fork();
                printf("Grand Child process ID: %d\n", getpid());
            }
            else
            {
                printf("Grand Child process ID: %d\n", getpid());
            }
        }
    }
    else if (pid > 0)
    {
        printf("Parent process ID : %d\n", getpid());
    }
    else
    {
        perror("Error in fork");
    }
    return 0;
}
