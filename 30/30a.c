/*
============================================================================
Name : 30a.c
Author : Kuldeep Chamoli
Description : Write a program to create a shared memory.    a. write some data to the shared memory    b. attach with O_RDONLY and check whether you are able to overwrite.    c. detach the shared memory    d. remove the shared memory
Date: 17th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
    int key, shmid;
    char *data;
    key=ftok("file", 97);
    shmid=shmget(key, 1024, IPC_CREAT | 0744);
    data=(char *)shmat(shmid, NULL, 0);
    printf("Enter input : ");
    scanf("%s", data);
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ ./30a
Enter input : hi
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ ./30b
Shared memory input : hi
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ ./30c
Data : hi
Shared memory detached...
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ ./30d
Data : hi
Destroyed shared memory... 
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/30$ 
*/
