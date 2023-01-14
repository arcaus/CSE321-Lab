#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// function to check if given number is odd or even
void checkNumber(int *number)
{
    if (*number % 2 == 0)
    {
        printf("%d is even\n", *number);
    }
    else
    {
        printf("%d is odd\n", *number);
    }
}

// main function
int main(int argc, char *argv[])
{
    int i, size;
    int *arr;
    size = atoi(argv[1]);
    arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
    for (i = 0; i < size - 1; i++)
    {
        checkNumber(&arr[i]);
    }
    return 0;
}
