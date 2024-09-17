/*
============================================================================
Name : 2.c
Author : Kuldeep Chamoli
Description :  Write a program to print the system resource limits. Use getrlimit system call. 
Date: 11 september,2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

void print_limit(int resource, const char *name) {
    struct rlimit rlim;

    if (getrlimit(resource, &rlim) == 0) {
        printf("%s soft limit = %lld, hard limit = %lld\n",
               name, (long long)rlim.rlim_cur, (long long)rlim.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "RLIMIT_CPU");
    print_limit(RLIMIT_FSIZE, "RLIMIT_FSIZE");
    print_limit(RLIMIT_STACK, "RLIMIT_STACK");
    print_limit(RLIMIT_DATA, "RLIMIT_DATA");
    print_limit(RLIMIT_NOFILE, "RLIMIT_NOFILE");

    return 0;
}
/*
output
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ mkdir 2
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ cd 2
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/2$ nano get.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/2$ gcc -o get get.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/2$ ./get
RLIMIT_CPU soft limit = -1, hard limit = -1
RLIMIT_FSIZE soft limit = -1, hard limit = -1
RLIMIT_STACK soft limit = 8388608, hard limit = -1
RLIMIT_DATA soft limit = -1, hard limit = -1
RLIMIT_NOFILE soft limit = 1024, hard limit = 1048576
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/2$ */
