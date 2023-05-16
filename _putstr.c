#include "shell.h"

/**
 * _putstr - writes strings
 * @s: the string to print
 * Return: 1
 */
int _putstr(char *s)
{
	int i;

	for (i = 0; s[i] != '\0' ; i++)
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
	}
	return (1);
}
