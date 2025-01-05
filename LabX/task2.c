#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2]; // Array to hold the file descriptors for the pipe
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[BUFFER_SIZE];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {  // Parent process
        close(pipefd[0]);  // Close unused read end
        printf("Parent: Sending message to child process...\n");
        write(pipefd[1], write_msg, strlen(write_msg) + 1);  // Write message to pipe
        close(pipefd[1]);  // Close write end after sending
        wait(NULL);  // Wait for child process to finish
    } else {  // Child process
        close(pipefd[1]);  // Close unused write end
        read(pipefd[0], read_msg, BUFFER_SIZE);  // Read message from pipe
        printf("Child: Received message: '%s'\n", read_msg);
        close(pipefd[0]);  // Close read end
    }

    return 0;
}
