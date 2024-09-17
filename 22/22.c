/*
============================================================================
Name : 22.c
Author : Kuldeep Chamoli
Description :  Write a program to wait for data to be written into FIFO within 10 seconds, use select 
system call with FIFO.
Date: 13th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"
#define TIMEOUT 10  // Timeout in seconds

int main() {
    int fifo_fd;
    fd_set read_fds;
    struct timeval timeout;
    int ret;
    char buffer[1024];

    // Create a FIFO (named pipe) with read/write permissions for everyone
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    printf("Waiting for someone to write data into the FIFO...\n");

    // Open the FIFO for reading (blocking mode)
    fifo_fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);  // Non-blocking mode
    if (fifo_fd == -1) {
        perror("open failed");
        return 1;
    }

    // Initialize the file descriptor set
    FD_ZERO(&read_fds);         // Clear the set
    FD_SET(fifo_fd, &read_fds); // Add FIFO file descriptor to the set

    // Set the timeout to 10 seconds
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    // Wait for data to be available on the FIFO using select()
    ret = select(fifo_fd + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        // Error occurred
        perror("select failed");
    } else if (ret == 0) {
        // Timeout occurred
        printf("No data was written into the FIFO within %d seconds.\n", TIMEOUT);
    } else {
        // Data is available for reading
        if (FD_ISSET(fifo_fd, &read_fds)) {
            ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';  // Null-terminate the string
                printf("Data received: %s\n", buffer);
            } else {
                perror("read failed");
            }
        }
    }

    // Close the FIFO and remove it
    close(fifo_fd);
    unlink(FIFO_NAME);

    return 0;
}

