#include <stdio.h>
#include "shell.h"
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
char **s = environ;

    for (; *s; s++)
    {
        printf("%s\n", *s);
    }
    return (0);
}
