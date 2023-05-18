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



/**
 * _atoi - Check the code
 * @s: Input
 * Return: int value.
 */
int _atoi(char *s)
{
int anas = 1;
unsigned int smu = 0;
char n_vr = 0;
if (s == NULL)
return (0);
while (*s)
{
if (*s == '-')
anas *= -1;
if (*s >= '0' && *s <= '9')
{
n_vr = 1;
smu = smu * 10 + (*s - '0');
}
else if (*s < '0' || *s > '9')
{
if (n_vr == 1)
break;
}
s++;
}
if (anas < 0)
smu = (-1 * (smu));
return (smu);
}
