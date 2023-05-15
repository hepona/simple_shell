#ifndef SHELL_H
#define SHELL_H

#define CMD_SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putstr(char *c);
int _strlen(char *s);
void execute_cmd(char **argv);

#endif