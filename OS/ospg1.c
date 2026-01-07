#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process\n");
        execl("/bin/ls", "ls", "-l", NULL);
    } else {
        printf("Parent process\n");
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}