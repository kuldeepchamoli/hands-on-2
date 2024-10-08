/*
============================================================================
Name : 27b.c
Author : Kuldeep Chamoli
Description : Write a program to receive messages from the message queue.
a. with IPC_NOWAIT as a flag
Date: 17th,Sep 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buf {
	long msg_type;
	char msg_text[100];
}msg; 

int main(void) {	
	int key = ftok(".", 1);
	if(key == -1) {
		perror("Error ouccred while calling ftok");
		return 0;
	}
	
	int msg_que = msgget(key, 0666 | IPC_CREAT);
	if(msg_que == -1) {
		perror("Error while running msgget");
		return 0;
	}
	
	msg.msg_type = 1;
	fgets(msg.msg_text, 10, stdin);
	
	//Sending the message
	msgsnd(msg_que, &msg, sizeof(msg), 0); 
	
	//Receiving the msg with IPC_NOWAIT as a flag
	int rec = msgrcv(msg_que, &msg, sizeof(msg), 1, IPC_NOWAIT);
	if(rec == -1) {
		perror("Message not received");
		return 0;
	}
	
	printf("Message Received is %s\n", msg.msg_text);
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/27$ nano 27b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/27$ gcc -o 27b 27b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/27$ ./27b
hi there
Message Received is hi there
*/	
	
