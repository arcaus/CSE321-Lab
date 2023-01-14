// Program writte by: Iftekhar Turja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/*
write a program that will create a child process. Inside the child process it will create a .txt file named Labmid.txt for writing and will write the Name: ABCD\nID: 15101256\nCourse: CSE321. Inside the parent process it will open the file Labmid.txt for reading.
*/

// Function to create child process
void createChildProcess(char *filename)
{
    // Create child process
    pid_t pid = fork();
    FILE *fp;

    // Check if fork() failed
    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }

    // If child process
    if (pid == 0)
    {
        // Create file
        fp = fopen(filename, "w");

        // Check if file creation failed
        if (fp == NULL)
        {
            printf("File creation failed\n");
            exit(1);
        }

        // Write to file
        fprintf(fp, "Name: ABCD\nID: 15101256\nCourse: CSE321\n");

        // Close file
        fclose(fp);
    }
    // If parent process
    else
    {
        // Open file
        fp = fopen(filename, "r");

        // Read every line from file
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            // Print line
            printf("%s", line);
        }

        // Close file
        fclose(fp);
    }
}

// main function
int main()
{
    // Create child process
    createChildProcess("Labmid.txt");

    return 0;
}
