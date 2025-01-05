#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE *file = fopen("process_pids.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        fclose(file);
        return 1;
    } else if (pid == 0) {
        // Child process
        fprintf(file, "Child PID: %d\n", getpid());
        fclose(file);
        exit(0);
    } else {
        // Parent process
        wait(NULL); // Wait for child to complete
        fprintf(file, "Parent PID: %d\n", getpid());
        fclose(file);
    }

    printf("PIDs written to process_pids.txt\n");
    return 0;
}
