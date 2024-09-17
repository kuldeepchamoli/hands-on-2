/*
============================================================================
Name : 26 msgq.c
Author :Kuldeep Chamoli
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 17th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct buffer{
	long mtype;
	char mtext[100];
}msg;

int main(void) {
	int key = ftok(".", 1);
	if(key == -1) {
		perror("Error while running ftok");
		return 0;
	}
	
	int msg_que = msgget(key, 0666 | IPC_CREAT);
	if(msg_que == -1) {
		perror("Error while running msgget");
		return 0;
	}
	
	msg.mtype = 1;
	fgets(msg.mtext, 10, stdin);
	int ms = msgsnd(msg_que, &msg, sizeof(msg), 0);
	if(ms == -1) {
		perror("Error while running msgsnd");
		return 0;
	}
	
	printf("Data sent to the message queue\n");
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/26$ nano msgq.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/26$ gcc -o msgq msgq.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/26$ ./msgq 
Hello there
Data sent to the message queue
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x011601e3 0          kuldeep-ch 666        224          2           

kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/26$ */
