/*
NAME:1b.c
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
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main(int argc, char const *argv[])
{
    struct itimerval timer;
    printf("Select interval timer\n1:10s\n2:10micros");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
        break;
    case 2:
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10;
        break;
    default:
        perror("INVALID CHOICE");
        _exit(1);
        break;
    }
    int timerStatus = setitimer(ITIMER_PROF, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    while (1)
        ;
}
/*output:
Select interval timer
1:10s
2:10micros2
Profiling timer expired
kuldeep-chamoli@ubuntu:~/*/
