/*
NAME:20a.c
AUTHOR: Kuldeep Chamoli
ROLLNO: MT2024081
PROGRAM:
20. Write two programs so that both can communicate by FIFO -Use one way communication.
DATE: SEP 8 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <sys/types.h> // Import for `mkfifo` & `open`
#include <sys/stat.h>  // Import for `mkfifo` & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`

void main()
{
    char *s; // Data to be sent through the buffer
    int fd;  // File descriptor of the FIFO file
    long int size = 100;
    char *file = "./20-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }
    }
}
/*
terminal 1
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ ./20b
hi 
hello
terminal 2
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ ./20a
hi 
enter message:
enter message:
hello
enter message:

*/
