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
/* Fixed Var */
#define PFX 4
#define FALSE 0
#define TRUE 1
#define SKP_FRK 6


void execute_cmd(char **argv);

/* Helpers with anas_environ */
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);

/* String_helpers functions */
int str_comp(char *st1, char *st2);
int _putstr(char *c);
int _strlen(const char *str_l);
char *_strchr(char *st, char c);
char *str_concat(char *st1, char *st2);
int strn_comp(const char *st1, const char *st2, size_t l);
char *_strcpy(char *dest, char *src);

/* Array_helpers functions */
int lst_idx(char **lst, char *val);
#endif
