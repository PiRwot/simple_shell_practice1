#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t pid_max;

    pid_max = getpid();
    printf("%u\n", pid_max);
    return (0);
}
