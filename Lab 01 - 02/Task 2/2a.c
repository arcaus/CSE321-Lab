// written by Turja

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// addition

float add(float x, float y)
{
    return x + y;
}

// subtraction

float sub(float x, float y)
{
    return x - y;
}

// multiplication

float mul(float x, float y)
{
    return x * y;
}

// main function

int main()
{
    float a, b;
    printf("Enter the first number: ");
    scanf("%f", &a);
    printf("Enter the second number: ");
    scanf("%f", &b);
    if (a > b)
    {
        printf("Subtraction: %.3f\n", sub(a, b));
    }
    else if (a < b)
    {
        printf("Addition: %.3f\n", add(a, b));
    }
    else if (a == b)
    {
        printf("Multiplication: %.3f\n", mul(a, b));
    }

    // loop the program to run again

    printf("\nDo you want to run the program again? (y/n): ");
    char c;
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y')
    {
        main();
    }
    else
    {
        printf("\nThank you for using the program!\n");
    }
    return 0;
}
