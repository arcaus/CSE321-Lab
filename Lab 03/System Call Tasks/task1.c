#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char str[100];
    char fname[100];

    if (argc != 2)
    {
        printf("Error: No filename given.\nUsage: %s <filename>\n", argv[0]);
        printf("Enter the file name here: ");
        fgets(fname, sizeof(fname), stdin);
        fname[strcspn(fname, "\n")] = 0;
        fd = open(fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
    }
    else
    {
        fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    }

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    printf("Enter a string (Enter -1 to end): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    while (strcmp(str, "-1") != 0)
    {
        write(fd, str, strlen(str));
        write(fd, "\n", 1);
        printf("Enter a string (Enter -1 to end): ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;
    }
    close(fd);
    return 0;
}
