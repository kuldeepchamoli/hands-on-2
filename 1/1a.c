/*
NAME:1a.c
AUTHOR: Kuldeep Chamoli
ROLLNO: MT2024081
PROGRAM:
1.This program sets an interval timer for two different time domains:
    a. 10 seconds (choice 1)
    b. 10 microseconds (choice 2)

    The program uses:
    - ITIMER_REAL: Real-time timer (sends SIGALRM when the time expires).
    - ITIMER_VIRTUAL and ITIMER_PROF can also be configured similarly for other cases.

    User selects between the two intervals.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*
    This program sets an interval timer for two different time domains:
    a. 10 seconds (choice 1)
    b. 10 microseconds (choice 2)

    The program uses:
    - ITIMER_REAL: Real-time timer (sends SIGALRM when the time expires).
    - ITIMER_VIRTUAL and ITIMER_PROF can also be configured similarly for other cases.

    User selects between the two intervals.
*/

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct itimerval timer;
    int choice;

    // Prompt user to select the interval timer duration
    printf("Select interval timer duration:\n1. 10 seconds\n2. 10 microseconds\n");
    scanf("%d", &choice);

    // Configure the timer based on user input
    switch (choice) {
        case 1:
            // Set the timer for 10 seconds
            timer.it_interval.tv_sec = 0;  // No repeated interval
            timer.it_interval.tv_usec = 0; // No repeated interval
            timer.it_value.tv_sec = 10;    // 10 seconds for the initial expiration
            timer.it_value.tv_usec = 0;
            break;
        case 2:
            // Set the timer for 10 microseconds
            timer.it_interval.tv_sec = 0;  // No repeated interval
            timer.it_interval.tv_usec = 0; // No repeated interval
            timer.it_value.tv_sec = 0;     // 0 seconds for the initial expiration
            timer.it_value.tv_usec = 10;   // 10 microseconds
            break;
        default:
            // Invalid choice
            fprintf(stderr, "Invalid choice. Exiting.\n");
            exit(EXIT_FAILURE);
    }

    // Set the interval timer (ITIMER_REAL)
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting interval timer");
        exit(EXIT_FAILURE);
    }

    // Loop indefinitely, waiting for the timer to expire and signal to be delivered
    while (1) {
        // The program will be interrupted by the SIGALRM signal when the timer expires
        pause(); // Wait for signals
    }

    return 0;
}
/*output
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/1$ ./1a
Select interval timer duration:
1. 10 seconds
2. 10 microseconds
2
Alarm clock
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/1$ ./1a
Select interval timer duration:
1. 10 seconds
2. 10 microseconds
1
Alarm clock
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/1$ 
*/
