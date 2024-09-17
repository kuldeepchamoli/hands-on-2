// Kuldeep Chamoli
// MT2024081
/*
    Create a FIFO file by
    a.mknod command
    b.mkfifo command
    c.use strace command to find out,which command(mknod or mkfifo) is better.
    c.mknod system call
    d.mkfifo library function
*/

#include <stdio.h>
#include <sys/stat.h>
int main()
{
    int op = mkfifo("./mkfifo_syscall", S_IRWXU);
    if (op == 0)
    {
        printf("fifo special file is created\n");
    }

    int f = mknod("./fifo_using_mknode_sys_call", S_IRWXU | S_IFIFO, 0);
    if (f == 0)
    {
        printf("fifo special file is created\n");
    }
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/19$ nano fifo.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/19$ gcc -o fifo fifo.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/19$ ./fifo 
fifo special file is created
fifo special file is created
*/
