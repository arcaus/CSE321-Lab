// written by arcaus

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

int main(int argc, char *argv[])
{
    FILE *inputFile, *outputFile;
    char outputFileName[] = "output.txt";
    char str[100];

    if (argc < 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("Unable to open input file.\n");
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        printf("Unable to open output file.\n");
        fclose(inputFile);
        return 1;
    }

    fgets(str, sizeof(str), inputFile);
    rmv_ew_spaces(str);
    fprintf(outputFile, "%s", str);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
