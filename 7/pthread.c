/*
============================================================================
Name : 7 pthread.c
Author : Kuldeep Chamoli
Description :  Write a simple program to print the created thread ids. 
Date: 11th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t tid = pthread_self(); // Get the thread ID
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_create(&thread3, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
