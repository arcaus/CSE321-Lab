

#include <stdio.h>
#include <stdlib.h>

/*
Question:
Write a C program to print perfect numbers between given interval using function. A perfect
number is a positive integer that is equal to the sum of its positive divisors, excluding the number
itself.
*/

// Function to print perfect numbers
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
    // Declaring variables
    int start, end;

    // Taking input from the user
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Calling the function
    print_perfect_numbers(start, end);

    return 0;
}
