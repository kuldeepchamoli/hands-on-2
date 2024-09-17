// Kuldeep Chamoli
// MT2022081


/*
    Write a program to execute ls -l | wc.
    a. use dup
    b. use dup2
    c. use fcntl
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>

void main(){
    int pipefd[2];
    pid_t cid;

    if(pipe(pipefd)==-1){
        printf("ERROR");
    }else{
        cid=fork();
        if(cid==0){
            //closing standard output
            close(0);
            // reassigning stdin to pipe reading end;
            // dup will reassign pipefd[0] to 0 as it is lowest avalible fd.so now pipefd[0] will act as STDIN
            dup(pipefd[0]);
            close(pipefd[1]);//closing unused pipe writing end
            execl("/usr/bin/wc", "wc", NULL);
        }else{
            close(1);//closing stdout 
            dup(pipefd[1]);//reassigning stdout to pipe writing end
            // dup will reassign pipefd[1] to 1(STDOUT) as it is lowes avalible fd. so now pipefd[1] will act as STDOUT
            close(pipefd[0]);//closing unused reading end

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ cd 17
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/17$ ./dup
      7      56     423
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/17$ 
*/
