

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/*
Question:
Write a program that will create a child and another grandchild process. Every process will print
a line.

Parent process will print, “I am parent”
Child process will print, “I am child”
Grandchild process will print, “I am grandchild”

Now, write the program in such way so that the following output will be shown -

I am grandchild
I am child
I am parent
*/

// function to create the child process

void createChild(char *argv[])

{
    // create the child process
    pid_t s;
    pid_t pid = fork();
    if (pid == 0)
    {
        // grandchild process
        printf("I am grandchild\n");
    }

    else if (pid > 0)
    {
        wait(&s);
        // child process
        printf("I am child\n");
    }

    else
    {
        // error
        printf("Error\n");
    }
}

// main function

int main(int argc, char *argv[])

{
    pid_t w;
    pid_t pid1 = fork();
    // create the parent process
    if (pid1 > 0)
    {
        wait(&w);
        printf("I am parent\n");
    }
    else if (pid1 == 0)
    {
        // create the child process
        createChild(argv);
    }
    return 0;
}
