/*
NAME:12 orphan.c
AUTHOR: Kuldeep Chamoli
ROLLNO: MT2024081
PROGRAM:
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
DATE: 11 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid()); // as parent terminated we can't get parent id in child process so we will get different value;
        int status=kill(getppid(),SIGKILL);
        if(status==0){
            printf("Parent is killed Child is now orphan\n");   
            sleep(10);
        }else{
            perror("Error while killing parent process!");
        }
    }
    else
    {
        // inside parent
        while(1);
    }
    return 0;
}
/*
output:
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/12$ nano orphan.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/12$ gcc -o orphan orphan.c 
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/12$ ./orphan 
inside child pid= 30320
parent id= 30319
Parent is killed Child is now orphan
Killed
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/12$ nano ins.txt
*/
