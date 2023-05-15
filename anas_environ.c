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

