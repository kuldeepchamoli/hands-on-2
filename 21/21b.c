// Kuldeep Chamoli
// MT2024081
/*
Write two programs so that both can communicate by FIFO -Use two way communication.
*/

#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *s; 
    int fd;  
    long int size = 100;
    char *file = "./21a-fifo";
    while (1)
    {
        fd = open(file, O_RDONLY); 

        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd);
        }

        fd = open(file, O_WRONLY);
        if (fd == -1){
            perror("Error");
        }
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }


    }
}
/*
//terminal 1
uldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ cd 21
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ nano 21a.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ nano 21b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ gcc -o 21a 21a.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ gcc -o 21b 21b.c
21b.c:14:1: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘{’ token
   14 | {
      | ^
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ nano 21b.c 
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ gcc -o 21b 21b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ ./21a
enter message:
hi there
I am kuldeep

enter message:
I am ajay^C
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ 

// termianl2
kuldeep-chamoli@ubuntu:~$ cd Desktop/
kuldeep-chamoli@ubuntu:~/Desktop$ cd hands-on-2/
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2$ cd 21
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/21$ ./21b
hi there

enter message:
I am kuldeep


*/
