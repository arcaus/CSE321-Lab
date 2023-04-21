

#include <stdio.h>
#include <stdlib.h>

// function to check email address

void check_email(char *email)
{
    int i = 0;
    while (email[i] != '\0')
    {
        if (email[i] == '@')
        {
            if (email[i + 1] != 's')
            {
                printf("Email address is outdated.\n");
                return;
            }
            else if (email[i + 1] == 's' && email[i + 2] == 'h' && email[i + 3] == 'e' && email[i + 4] == 'b' && email[i + 5] == 'a' && email[i + 6] == '.' && email[i + 7] == 'x' && email[i + 8] == 'y' && email[i + 9] == 'z')
            {
                printf("Email address is okay.\n");
                return;
            }
        }
        i++;
    }
    printf("Email address is outdated.\n");
}

// main function

int main()
{
    char email[] = {};
    printf("Enter email address: ");
    scanf("%s", email);
    check_email(email);
    return 0;
}
