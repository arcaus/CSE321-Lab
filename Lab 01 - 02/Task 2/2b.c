

#include <stdio.h>
#include <stdlib.h>

// function to remove extra whitespaces

void rmv_ew_spaces(char *str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' '))
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

// main function

int main()
{
    char str[] = {};
    printf("Enter a sentence: ");
    scanf("%[^\n]s", str);
    getchar();
    rmv_ew_spaces(str);
    printf("%s\n", str);
    return 0;
}
