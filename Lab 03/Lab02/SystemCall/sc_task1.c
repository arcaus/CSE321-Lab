// written by [24341087]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[100];
    char fname[100];

    if (argc != 2)
    {
        printf("Error: No filename given.\nUsage: %s <filename>\n", argv[0]);
        printf("Enter the file name here: ");
        gets(fname);
        fp = fopen(fname, "a");
    }

    else
    {
        fp = fopen(argv[1], "a");
    }

    printf("Enter a string: ");
    gets(str);
    while (strcmp(str, "-1") != 0)
    {
        fprintf(fp, "%s\n", str);
        printf("Enter a string: ");
        gets(str);
    }
    fclose(fp);
    return 0;
}