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
int _putstr(char *s);
void execute_cmd(char **argv);

/* Helpers with anas_environ */
char *_getenv(const char *name);

/* String_helpers functions */
int str_comp(char *st1, char *st2);
int _strlen(const char *str_l);
int strn_comp(const char *st1, const char *st2, size_t l);
#endif
