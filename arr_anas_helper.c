#include "shell.h"
/**
 * lst_idx - get length of a list given or an index of a val.
 * @lst: list to work on
 * @val: val to be indexed
 *
 * Return: length or index if success,or failure return -1
 */
int lst_idx(char **lst, char *val)
{
int i = 0;
if (val == NULL)
{
while (*lst != NULL)
{
i++;
lst++;
}
i++;
return (i);
}
else
{
while (*lst != NULL)
{
if (strn_comp(*lst, val, PFX) == TRUE)
return (i);

i++;
lst++;
}
}
return (-1);
}
