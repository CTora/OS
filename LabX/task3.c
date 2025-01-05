#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void signal_handler(int signum) {
    printf("Child process received signal %d\n", signum);
    exit(0);
}

int main() {
    pid_t pid;

    // Fork the process to create a child
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {  // Parent process
        printf("Parent process sending signal to child\n");
        sleep(1);  // Give child time to set up signal handler
        kill(pid, SIGUSR1);  // Send signal to child
        wait(NULL);  // Wait for child to complete

    } else {  // Child process
        signal(SIGUSR1, signal_handler);  // Set up signal handler
        printf("Child process waiting for signal\n");
        pause();  // Wait for signal
    }

    return 0;
}
