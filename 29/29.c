/*
============================================================================
Name : 29.c
Author : Kuldeep Chamoli
Description : Write a program to remove the message queue
Date: 17th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
   
    int key = ftok(".", 1);
    if(key == -1) {
    	perror("Error occured while running ftok");
    	return 0;
    }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1) {
    	perror("Error occured while running msgget");
    	return 0;
    }
    
    printf("Message queue id = %d\n", msgid);


    int ctr = msgctl(msgid, IPC_RMID, NULL);
    if(ctr == -1) {
        perror("Error while calling msgctl");
        return 0;
    }

    printf("Message queue removed.\n");
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/29$ nano 29.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/29$ gcc -o 29 29.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/29$ ./29
Message queue id = 3
Message queue removed.
*/
