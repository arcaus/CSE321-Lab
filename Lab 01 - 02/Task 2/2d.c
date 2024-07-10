// written by arcaus

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// function to check email
bool checkEmail(char *email)
{
    char *suffix = "@sheba.xyz";
    int suffixLength = strlen(suffix);
    int emailLength = strlen(email);

    if (emailLength < suffixLength)
    {
        return true;
    }

    char *emailSuffix = email + emailLength - suffixLength;
    if (strcmp(emailSuffix, suffix) != 0)
    {
        return true;
    }

    return false;
}

int main()
{
    char email[100];
    printf("Enter email address: ");
    scanf("%99s", email);

    if (checkEmail(email))
    {
        printf("Email address is outdated.\n");
    }
    else
    {
        printf("Email address is okay.\n");
    }

    return 0;
}
