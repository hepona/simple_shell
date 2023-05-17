/*
 * File: anas_environ.c
 * Auth: Jelloul Anas
 *       Rahif Hiba
 */
#include "shell.h"
/**
 * _getenv - Gets an envirment variable.
 * @name: The name of the envirment variable to get.
 *
 * Return: If the envirment variable does not exist - NULL.
 *         Otherwise - a pointer to the envirment variable.
 */
char *_getenv(const char *name)
{
unsigned int idx, cn;
idx = 0;
cn = _strlen(name);
while (environ[idx] != NULL)
{
if (strn_comp(name, environ[idx], cn) == 0)
return (environ[idx]);
idx++;
}
return (NULL);
}
/**
 * _setenv - changes or adds an environment variable
 * @name: The name of the environmental variable to add or change.
 * @value: The value of the env variable
 * @overwrite: value
 *
 * Return: returns zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
unsigned int i, cn;
char *el;
char *bffr;
char *bffrtp;
cn = _strlen(name);
bffr = str_concat((char *)name, "=");
bffrtp = str_concat(bffr, (char *)value);
free(bffr);
bffr = bffrtp;
el = _getenv(name);
if (!el)
{
if (!overwrite)
return (0);
}
cn = lst_idx(environ, (char *)name);
// free(environ[cn]);
printf("env %s\n", el);
environ[cn] = bffr;
return (SKP_FRK);
}
