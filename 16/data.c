/*
NAME:16 data.c
AUTHOR: Kuldeep Chamoli
ROLLNO: MT2024081
PROGRAM:16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
DATE: SEP 8 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2], a[2], l;
    pid_t cpid;
    char buf;
    char *s;
    long int size = 50;
    s = (char *)malloc(size);
    if (pipe(pipefd) == -1)
    {
        perror("pipe pipefd");
        exit(EXIT_FAILURE);
    }

    if (pipe(a) == -1)
    {
        perror("pipe a");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0)
    { // child  write in pipe
        sleep(5);
        printf("writing in pipe from child process\n");
        l = getline(&s, &size, stdin);
        close(a[0]); /* Close unused read end */
        write(a[1], s, l);
        close(a[1]); /* closing writing end so Reader will see EOF */

        /* Child reads from pipe */
        sleep(5);
        close(pipefd[1]); /* Close unused write end */
        // display from kernal using pipes reading end in child
        printf("display in child \n");
        while (read(pipefd[0], &buf, 1) > 0)
            write(1, &buf, 1);

        write(1, "\n", 1);
        close(pipefd[0]); /* Close unused read end */
    }
    else
    { /* Parent writes argv[1](message) to pipe */

        printf("writing in pipe from parent process\n");
        l = getline(&s, &size, stdin);
        close(pipefd[0]); /* Close unused read end */
        write(pipefd[1], s, l);
        close(pipefd[1]); /*closing writing end so  Reader will see EOF */

        /* Child reads from pipe */
        sleep(5);
        close(a[1]); /* Close unused write end */
        // display from kernal using pipes reading end in child
        printf("display in parent \n");
        while (read(a[0], &buf, 1) > 0)
            write(1, &buf, 1);
        write(1, "\n", 1);
        close(a[0]); /* Close unused read end */

        wait(0); /* Wait for child */
    }
}
/*
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ mkdir 16
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ cd 16
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/16$ nano data.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/16$ gcc -o data data.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/16$ ./data 
writing in pipe from parent process
hi therewriting in pipe from child process
^C
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/16$ nano ins.txt*/
