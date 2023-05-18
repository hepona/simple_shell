#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("a+b=%d\n",9+9);
    printf("%u\n", my_pid);
    return (0);
}
