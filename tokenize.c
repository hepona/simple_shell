#include "shell.h"

/**
 * tokenize -> tokenize a string
 * @str: string that will be tokenized
 * @delimiter: delimiter
 * Return: number of tokens
*/
int tokenize(char *str, char *delimiter)
{
int c_token = 0;
char *token;
if (str == NULL)
return (0);
token = strtok(str, delimiter);
while (token != NULL)
{
c_token++;
token = strtok(NULL, delimiter);
}
c_token++;
return (c_token);
}
