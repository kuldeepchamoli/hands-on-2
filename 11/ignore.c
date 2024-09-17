// Name :Kuldeep Chamoli
// Roll No: MT2024081

/*
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    int status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    struct sigaction act;

    act.sa_handler = SIG_IGN; // Ignoring SIGINT
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }

    printf("reseting the default action of the SIGINT signal\n");
    struct sigaction actdefault;

    actdefault.sa_handler = SIG_DFL; // setting default SIGINT
    actdefault.sa_flags = 0;
    status = sigaction(SIGINT, &actdefault,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }
}
/*
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ mkdir 11
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ cd 11
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/11$ nano ignore.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/11$ gcc -o ignore ignore.c 
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/11$ ./ignore 
ignoring the SIGINT signal for 5 seconds
reseting the default action of the SIGINT signal
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/11$ nano ins.txt*/
