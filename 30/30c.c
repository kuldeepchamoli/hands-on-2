/*
============================================================================
Name : 30c.c
Author : Kuldeep Chamoli
Description : Write a program to create a shared memory.    a. write some data to the shared memory    b. attach with O_RDONLY and check whether you are able to overwrite.    c. detach the shared memory    d. remove the shared memory
Date: 17th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    key_t key = ftok("file", 97);
    int shmid = shmget(key, 1024, 0);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Data : %s\n", str);
    shmdt(str);
    printf("Shared memory detached...\n");
}
