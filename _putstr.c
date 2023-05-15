#include <unistd.h>

/**
 * _putstr - writes the characters c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstr(char *c)
{   int i;

    for (i = 0; c[i] != '\0'; i++)
    {
        if (write(1, &c[i], 1) == -1)
            return -1;
       
    }    
    
	return (1);
}