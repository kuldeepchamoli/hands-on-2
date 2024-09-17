/*
============================================================================
Name : 3 set.c
Author : Kuldeep Chamoli
Description :  Write a program to set (any one) system resource limit. Use setrlimit system call. 
Date: 11,September 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;

    // Define the new limit
    rlim.rlim_cur = 2;  // Soft limit of 2 seconds
    rlim.rlim_max = 2;  // Hard limit of 2 seconds

    // Set the CPU time limit
    if (setrlimit(RLIMIT_CPU, &rlim) == 0) {
        printf("CPU time limit set to 2 seconds.\n");
    } else {
        perror("setrlimit");
    }

    return 0;
}
/*output
uldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ mkdir 3
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ nano set.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ gcc -o set set.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ ./set
CPU time limit set to 2 seconds.
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ nano ins.txt
*/
