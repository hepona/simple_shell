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
