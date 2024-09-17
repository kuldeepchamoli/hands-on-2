/*
============================================================================
Name : 6 thread.c
Author : Kuldeep Chamoli
Description :  Write a simple program to create three threads. 
Date: 11th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_number = *((int*)arg);
    printf("This is thread %d\n", thread_number);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    int thread_number[3] = {1, 2, 3};

    pthread_create(&thread1, NULL, thread_function, &thread_number[0]);
    pthread_create(&thread2, NULL, thread_function, &thread_number[1]);
    pthread_create(&thread3, NULL, thread_function, &thread_number[2]);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
