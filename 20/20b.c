// Kuldeep Chamoli
// MT2024081
/*
Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include <sys/types.h> // 
#include <sys/stat.h>  
#include <fcntl.h>     // 
#include <unistd.h>    // Import for `read`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    char *file = "./20-fifo";
    int fd = open(file, O_RDONLY); // File descriptor of the FIFO file

    while (1)
    {
        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
        }
        close(fd);
    }
}
/*kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ gcc -o 20b 20b.c
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ ./20b
^C
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ ./20b
^C
kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ ./20b
hi there
hpw are you
I am fine thank u

another terminal

kuldeep-chamoli@ubuntu:~/Desktop/hands-on-2/20$ ./20a
enter message:
hi there
enter message:
hpw are you
enter message:
I am fine thank u
enter message:

}
Now open two terminals and execute both programs and you can see the blocking calls in
action and how FIFO communication happens.

*/
