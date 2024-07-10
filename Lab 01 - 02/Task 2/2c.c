// written by arcaus

#include <stdio.h>
#include <stdbool.h>

// function to check password
void check_password(const char *str)
{
    bool lowercase = false, uppercase = false, digit = false, special = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            lowercase = true;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            uppercase = true;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digit = true;
        }
        else if (str[i] == '_' || str[i] == '$' || str[i] == '#' || str[i] == '@')
        {
            special = true;
        }
    }

    if (!lowercase)
    {
        printf("Lowercase character missing\n");
    }
    if (!uppercase)
    {
        printf("Uppercase character missing\n");
    }
    if (!digit)
    {
        printf("Digit Missing\n");
    }
    if (!special)
    {
        printf("Special character missing\n");
    }

    if (lowercase && uppercase && digit && special)
    {
        printf("OK\n");
    }
}

int main()
{
    char str[100];

    printf("Enter a password: ");
    scanf("%[^\n]s", str);
    getchar();

    check_password(str);

    return 0;
}
