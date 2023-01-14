// written by Turja

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// function to check password

void check_password(char *str)
{
    int lowercase = 0, uppercase = 0, digit = 0, special = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            lowercase = 1;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            uppercase = 1;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit = 1;
        }
        else if (str[i] == '_' || str[i] == '$' || str[i] == '#' || str[i] == '@')
        {
            special = 1;
        }
    }
    if (lowercase == 0)
    {
        printf("Lowercase Missing\n");
    }
    if (uppercase == 0)
    {
        printf("Uppercase Missing\n");
    }
    if (digit == 0)
    {
        printf("Digit Missing\n");
    }
    if (special == 0)
    {
        printf("Special Missing\n");
    }
    if (lowercase == 1 && uppercase == 1 && digit == 1 && special == 1)
    {
        printf("OK\n");
    }
}

// main function

int main()
{
    char str[] = {};
    printf("Enter a password: ");
    scanf("%[^\n]s", str);
    getchar();
    check_password(str);
    return 0;
}
