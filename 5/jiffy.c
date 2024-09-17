/*
============================================================================
Name : 5 jiffy.c
Author : Kuldeep Chamoli
Description :  Write a program to print the system limitation of         a. maximum length of the arguments to the exec family of functions.         b. maximum number of simultaneous process per user id.         c. number of clock ticks (jiffy) per second.         d. maximum number of open files        e. size of a page        f. total number of pages in the physical memory        g. number of currently available pages in the physical memory. 
Date: 11th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec functions: %ld\n", arg_max);

    // b. Maximum number of simultaneous processes per user ID
    long max_pro = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user ID: %ld\n", max_pro);

    // c. Number of clock ticks (jiffy) per second
    long ticks_per_second = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second: %ld\n", ticks_per_second);

    // d. Maximum number of open files
    struct rlimit rlim;
    getrlimit(RLIMIT_NOFILE, &rlim);
    printf("Maximum number of open files: %ld\n", rlim.rlim_max);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory
    long available_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in the physical memory: %ld\n", available_pages);

    return 0;
}
/*Output
uldeep-chamoli@ubuntu:~/Desktop/hands-on-2/5$ nano jiffy.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/5$ ls
jiffy.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/5$ gcc -o jiffy jiffy.c 
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/5$ ./jiffy
Maximum length of arguments to exec functions: 2097152
Maximum number of simultaneous processes per user ID: 47076
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 1048576
Size of a page: 4096 bytes
Total number of pages in the physical memory: 3031649
Number of currently available pages in the physical memory: 888741
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/5$ */
