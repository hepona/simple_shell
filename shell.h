#ifndef SHELL_H
#define SHELL_H

#define CMD_SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
/* Global Variables */
extern char **environ;
extern int stus;

/* Fixed Var */
#define PFX 4
#define FALSE 0
#define TRUE 1
#define SKP_FRK 6
#define EXT_SHLL 5

int execute_cmd(char **argv, char *filename);
char *file_path(char *cmd);
void ext_shl(char **it);
void fre_dip(char **it);
/* Helpers with anas_environ */
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);
int _printenv(void);
int check_fll_path(const char *cmd);
/* String_helpers functions */
void free_argv(char **av);
int str_comp(char *st1, char *st2);
int _putstr(char *c);
int _strlen(const char *str_l);
char *_strchr(char *st, char c);
char *str_concat(char *st1, char *st2);
int strn_comp(const char *st1, const char *st2, size_t l);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
int _putchar(char c);
int tokenize(char *str, char *delimiter);
char *_strdup(char *str);
void super_free(char **var);
/* Array_helpers functions */
int lst_idx(char **lst, char *val);
int _isatty(char *cmd, char *filename);
#endif
