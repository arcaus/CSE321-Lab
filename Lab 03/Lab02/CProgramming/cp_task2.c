// written by [24341087]

#include <stdio.h>

void print_perfect_numbers(int start, int end)
{
    int i, sum = 0;
    for (i = start; i <= end; i++)
    {
        int j;
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("\n%d \n", i); // Print perfect number keeping a line break because 'Qs e dewa'
        }
        sum = 0;
    }
}

// main function
int main()
{
    int start, end;

    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    print_perfect_numbers(start, end);

    return 0;
}
