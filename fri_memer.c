#include "shell.h"

/**
 * fre_dip - check code.
 * @it: Input value.
 * Return: Nothing.
 */
void fre_dip(char **it)
{
size_t s = 0;

if (it == NULL)
return;

while (it[s])
{
free(it[s]);
s++;
}

if (it[s] == NULL)
free(it[s]);
free(it);
}
