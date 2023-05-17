#include "shell.h"

/**
 * main -> simple shell
 * @argv: arguments
 * @ac: num of arguments
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **argv)
{
	char *cmd = NULL, *cmd_cp = NULL;
	size_t bufsize = 0;
	ssize_t cmdread;
	char *token,  **arg;
	int i, c_tok = 0;
	int extshll = 0;
	(void)argv;
	while (!extshll)
	{
		_putstr("($) > ");
		cmdread = getline(&cmd, &bufsize, stdin);
		cmd_cp = malloc(sizeof(char *)  * cmdread + 1);
		if (cmd_cp == NULL)
		{
			perror("Error: malloc");
			return (-1);
		}
		_strcpy(cmd_cp, cmd);
		token = strtok(cmd, " \n");
		while (token != NULL)
		{
			c_tok++;
			token = strtok(NULL, " \n");
		}
		c_tok++;
		arg = malloc(sizeof(char *) * c_tok);
		token = strtok(cmd_cp, " \n");
		for (i = 0; token != NULL; i++)
		{
			arg[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(arg[i], token);
			token = strtok(NULL, " \n");
		}
		arg[i] = NULL;
if (str_comp(arg[0], "exit") == 0) 
exit(EXIT_FAILURE);
if (str_comp(command, "exit") == 0)

else   
     execute_cmd(arg);
		free(cmd_cp);
		free(arg);
	}
	free(cmd);
	return (0);
}
