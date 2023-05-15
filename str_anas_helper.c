/**
 *  _strlen - returns length of a string given
 * @str_l: string 
 *
 * Return:Length of the string
 */
int _strlen(char *str_l)
{
int cn = 0;
if (str_l == NULL)
return (0);
while (*str_l != '\0')
{
cn++;
str_l++;
}
return (cn);
}
