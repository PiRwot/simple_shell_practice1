#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    /* Fork a child process */
    pid = fork();

    if (pid < 0) { /* Error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) { /* Child process */
        printf("I am the child, PID = %d\n", getpid());
    } else { /* Parent process */
        printf("I am the parent, PID = %d\n", getpid());
    }

    return 0;
}

