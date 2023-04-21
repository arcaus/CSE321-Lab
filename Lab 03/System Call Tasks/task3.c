

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/*
Question:
Consider the following code snippet in your main function -

a = fork();
b = fork();
c = fork();

Now, write the full program, that will check the children’s PID for odd or even and if it is odd then the process
will create another child process. Lastly, print how many processes have been created
considering the first parent process.
*/

// function to check if the number is odd or even
int is_odd(int num)
{
    if (num % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// main function
int main()
{
    int a, b, c, i;
    int count = 0;
    a = fork();
    b = fork();
    c = fork();
    if (a == 0)
    {
        for (i = 0; i < 10; i++)
        {
            if (is_odd(i))
            {
                count++;
                pid_t pid = fork();
                if (pid == 0)
                {
                    printf("%d\n", i);
                    exit(0);
                }
                else if (pid > 0)
                {
                    wait(NULL);
                }
            }
        }
    }
    else if (b == 0)
    {
        for (i = 0; i < 10; i++)
        {
            if (!is_odd(i))
            {
                count++;
                pid_t pid = fork();
                if (pid == 0)
                {
                    printf("%d\n", i);
                    exit(0);
                }
                else if (pid > 0)
                {
                    wait(NULL);
                }
            }
        }
    }
    else if (c == 0)
    {
        for (i = 0; i < 10; i++)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                printf("%d\n", i);
                exit(0);
            }
            else if (pid > 0)
            {
                wait(NULL);
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
