#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// main function
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
    if (pid == 0)
    {
        execl("path_of_sort.c", 10, *arr); // change this line and add the absolute path of the sort.c file here
    }
    else if (pid > 0)
    {
        wait(&status);
        execl("path_of_oddeven.c", 10, *arr); // change this line and add the absolute path of the oddeven.c file here
    }
    return 0;
}
