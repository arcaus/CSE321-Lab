

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

/*
Question:
Write a c program that will open a file given from the command line argument and then it will
ask the user to input strings which will be written to that file. It will continue to ask the user to
enter a string as long as the user enters “-1”. If the given file does not exist in the directory, then
your program will automatically create the file.
All code should be Unix compatible.
*/

// function complete the task
void task1(int argc, char *argv[])
{
    // check if the file exists
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        // if not, create the file
        fp = fopen(argv[1], "w");
    }
    // close the file
    fclose(fp);

    // open the file again
    fp = fopen(argv[1], "a");

    // ask the user to enter strings
    char str[100];
    while (1)
    {
        printf("Enter a string: ");
        scanf("%s", str);
        if (strcmp(str, "-1") == 0)
        {
            break;
        }
        // write the string to the file
        fprintf(fp, "%s\n", str);
    }
    // close the file
    fclose(fp);
}

// main function
int main(int argc, char *argv[])
{
    // check if the user has entered the correct number of arguments
    if (argc != 2)
    {
        printf("Invalid number of arguments.\n");
        return 0;
    }
    // call the function
    task1(argc, argv);
    return 0;
}
