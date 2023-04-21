

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/*
Question:
Write a program that will create a child process and the child process will first
sort the array that you have declared in this program. And then, the parent process will print the
odd/even status for each number in the array.
*/

// main function
int main()
{
    pid_t pid, status;
    pid = fork();
    // array declaration
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (pid == 0)
    {
        execl("/home/kali/Desktop/CSE321_LAB3/sort.c", 10, *arr);
    }
    else if (pid > 0)
    {
        wait(&status);
        execl("/home/kali/Desktop/CSE321_LAB3/oddeven.c", 10, *arr);
    }
    return 0;
}
