#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// sort in descending order
void sort(int *arr, int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    sort(arr, size);
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
