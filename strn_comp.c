#include "shell.h"

/**
 * strn_comp - Compares two strings.
 * @st1: string
 * @st2: string
 * @l: first n bytes of the strings to compare.
 * Return:Length of the string
 */
int strn_comp(const char *st1, const char *st2, size_t l)
{
size_t i;
for (i = 0; st1[i] && st2[i] && i < l; i++)
{
if (st1[i] > st2[i])
return (st1[i] - st2[i]);
else if (st1[i] < st2[i])
return (st1[i] - st2[i]);
}
if (i == l)
return (0);
else
return (-15);
}
