#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("Original Process - PID: %d\n", getpid());

    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            return 1;
        } else if (pid == 0) {
            // Child process
            printf("Child Process - PID: %d, Parent PID: %d\n", getpid(), getppid());
            break;
        } else {
            // Parent process continues to next iteration
            printf("Parent Process - PID: %d created Child PID: %d\n", getpid(), pid);
        }
    }

    return 0;
}
