#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/* Global environemnt Variables */
extern char **environ;
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * _printenv - print environment
 * Return: 0 if success
 */
int _printenv(void)
{
int i;
int j;

i = 0;
while (environ[i])
{
j = 0;
while (environ[i][j] != 0)
{
_putchar(environ[i][j]);
j++;
}
_putchar('\n');
i++;
}
return (0);
}
/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char *argv[])
{
_printenv();
return (0);
}
