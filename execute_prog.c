#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
    char *newargv[] = { NULL, "hello", "world", NULL };

    newargv[0] = argv[1];  // The new program to execute

    if (newargv[0] != NULL) {
        execve(newargv[0], newargv, envp);
        perror("execve");  // execve returns only on error
        return 1;
    } else {
        printf("Please provide a program to execute as an argument.\n");
        return 0;
    }
}

