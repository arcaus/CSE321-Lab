// written by arcaus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find palindrome
void palindrome(char *str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end)
    {
        if (*start != *end)
        {
            printf("Not Palindrome\n");
            return;
        }

        start++;
        end--;
    }

    printf("Palindrome\n");
}

int main()
{
    char str[100];
    printf("Enter a sentence: ");
    scanf("%[^\n]s", str);
    getchar();
    palindrome(str);
    return 0;
}
