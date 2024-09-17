/*
============================================================================
Name : 4 timestamp.c
Author : Kuldeep Chamoli
Description :  Write a program to measure how much time is taken to execute 100 getppid ( ) 
system call. Use time stamp counter. 
Date: 11th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include<unistd.h>
#include <x86intrin.h>

unsigned long long rdtsc() {
    return __rdtsc();
}

int main() {
    unsigned long long start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    printf("Time taken to execute 100 getppid(): %llu cycles\n", end - start);

    return 0;
}
