// written by Turja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find palindrome

void palindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            printf("Not Palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}

// main function

int main()
{
    char str[] = {};
    printf("Enter a sentence: ");
    scanf("%[^\n]s", str);
    getchar();
    palindrome(str);
    return 0;
}