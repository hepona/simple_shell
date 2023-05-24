#include "shell.h"
/**
* _strlen - returns length of a string given
* @str_l: string
* Return:Length of the string
*/
int _strlen(const char *str_l)
{
int cn = 0;
if (str_l == NULL)
return (cn);
while (*str_l != '\0')
{
cn++;
str_l++;
}
return (cn);
}
/**
 * str_concat - concatenates two strings.
 * @st1: 1 string
 * @st2: 2 string
 *
 * Return: Pointer to new string,if Failure NULL
 */
char *str_concat(char *st1, char *st2)
{
int cn = _strlen(st1) + _strlen(st2);
char *t_o = malloc(cn + 1);
char *frm = t_o;

if (st1 != NULL)
{
while (*st1 != '\0')
{
*frm = *st1;
frm++;
st1++;
}
}

if (st2 != NULL)
{
while (*st2 != '\0')
{
*frm = *st2;
frm++;
st2++;
}
}

*frm = '\0';

return (t_o);
}
/**
 *  str_comp - Compares two strings.
 * @st1: string
 * @st2: string
 *
 * Return:Length of the string
 */
int str_comp(char *st1, char *st2)
{
while (*st1 && *st2 && *st1 == *st2)
{
st1++;
st2++;
}
if (*st1 != *st2)
return (*st1 - *st2);
return (0);
}
/**
 * _strchr - check a character in a string.
 * @st: The string to be searched.
 * @c: The character to be check.
 *
 * Return: a pointer to the first occurence
 * if c was found otherwise return Null.
 */
char *_strchr(char *st, char c)
{
int cn;

for (cn = 0; st[cn]; cn++)
{
if (st[cn] == c)
return (st + cn);
}
return (NULL);
}
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
