#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/* Global environemnt Variables */
extern char **environ;
/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char *argv[])
{
    char **s = environ;

    for (; *s; s++)
    {
        printf("anas=%s\n", *s);
    }
}
