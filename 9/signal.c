/*
============================================================================
Name : 9 signal.c
Author : Kuldeep Chamoli
Description :  Write a C program to ignore a SIGINT signal then reset the default action of the SIGINT
               signal - Use signal system call.
Date: 11th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Received SIGINT (Interrupt)\n");
    exit(0);
}

int main() {
    // Ignore SIGINT using the signal system call
    signal(SIGINT, SIG_IGN);

    printf("SIGINT is now ignored. Press Ctrl+C to send SIGINT.\n");

    // Sleep to allow time for user input (Ctrl+C)
    sleep(10);

    // Reset SIGINT to its default action using the signal system call
    signal(SIGINT, SIG_DFL);

    printf("SIGINT is now reset to its default action.\n");

    while (1) {
        // Program continues running until Ctrl+C is pressed
    }

    return 0;
}
