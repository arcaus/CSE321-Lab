// written by [24341087]

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "sort.h"
#include "oddeven.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <numbers>\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i + 1]);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process (PID: %d) - Sorting array\n", getpid());
        sort(arr, n);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        exit(0);
    }
    else
    {
        // Parent process
        wait(NULL);

        printf("Parent process (PID: %d) - Checking odd/even\n", getpid());
        oddeven(arr, n);
    }

    return 0;
}
