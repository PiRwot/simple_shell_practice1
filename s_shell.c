#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_LINE 1024

int main() {
    char line[MAX_LINE];

    while (1) {
        printf("$ ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            break;
        }

        line[MAX_LINE - 1] = '\0';
        char *newline = strchr(line, '\n');  // remove newline from command
        if (newline) {
            *newline = '\0';
        }

        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed.\n");
            return 1;
        }

        if (pid == 0) {  // child process
            char *argv[] = {line, NULL};
            execv(line, argv);
            perror("execv");  // if execv returns, there was an error
            exit(1);
        } else {  // parent process
            wait(NULL);  // wait for child to finish
        }
    }

    return 0;
}
