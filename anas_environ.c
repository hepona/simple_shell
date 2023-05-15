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
char **s = environ;
for (; *s; s++)
printf("%s\n", s[1]);
 return (NULL);
}
