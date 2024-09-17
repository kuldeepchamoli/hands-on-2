/*
============================================================================
Name : 31b.c
Author : Kuldeep Chanoli
Description : Write a program to create a semaphore and initialize value to the semaphore.    a. create a binary semaphore    b. create a counting semaphore
Date: 17th Oct, 2024.
============================================================================
*/
#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t counting_semaphore;

    sem_init(&counting_semaphore, 0, 5);

    printf("Counting semaphore created and initialized.\n");

    sem_destroy(&counting_semaphore);

    return 0;
}
