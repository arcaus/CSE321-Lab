// written by arcaus

#include <stdio.h>
#include <stdlib.h>

float add(float x, float y)
{
    return x + y;
}

float sub(float x, float y)
{
    return x - y;
}

float mul(float x, float y)
{
    return x * y;
}

int main()
{
    float a, b;
    char c;

    do
    {
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

        printf("\nDo you want to run the program again? (y/n): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');

    printf("\nThank you for using the program!\n");
    return 0;
}
