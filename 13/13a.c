/*
NAME:13.c
AUTHOR: Kuldeep Chamoli
ROLLNO: MT2024081
PROGRAM:
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
DATE: 17 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>

int main(){

	printf("My PID is %d",getpid());
	while(1){};

}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/13$ ./13a &
[1] 23458
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/13$ ./13b
Enter PID to be killed
23458
SIGSTOP Signal sent
*/
