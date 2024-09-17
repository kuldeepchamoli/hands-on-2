/*
============================================================================
Name : 31a.c
Author : Kuldeep Chamoli
Description : Write a program to create a semaphore and initialize value to the semaphore.    a. create a binary semaphore    b. create a counting semaphore
Date: 17th Oct, 2024.
============================================================================
*/
#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t binary_semaphore;

    sem_init(&binary_semaphore, 0, 1);

    printf("Binary semaphore created and initialized.\n");

    sem_destroy(&binary_semaphore);

    return 0;
}
/*
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ ./31a
Binary semaphore created and initialized.
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ nano 31b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ gcc -o 31b 31b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ ./31b
Counting semaphore created and initialized.
*/
