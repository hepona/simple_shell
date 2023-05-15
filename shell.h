#ifndef SHELL_H
#define SHELL_H

#define CMD_SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/* Global environemnt Variables */
extern char **environ;
int _putstr(char *c);
int _strlen(char *s);
void execute_cmd(char **argv);

/* Helpers with anas_environ */
char *_getenv(const char *name);

#endif
