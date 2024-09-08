// written by [24341087]

#include "oddeven.h"
#include <stdio.h>

void oddeven(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d is even\n", arr[i]);
        }
        else
        {
            printf("%d is odd\n", arr[i]);
        }
    }
}
