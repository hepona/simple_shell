#include "shell.h"

/**
 * main -> simple shell
 * @argv: arguments
 * @ac: num of arguments
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *cmd = NULL, *cmd_cp = NULL;
	size_t bufsize = 0;
	ssize_t cmdread;
	char *token, *exe_name = argv[0], *sep = " \n";
	int c_tok = 0, extshll = 0;

	while (!extshll)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) > ", 6);
		cmdread = getline(&cmd, &bufsize, stdin);
		if (cmdread == -1)
			break;
		cmd_cp = malloc(sizeof(char)  * cmdread);
		if (cmd_cp == NULL)
		{
			perror("malloc");
			return (-1);
		}
		_strcpy(cmd_cp, cmd);
		c_tok = tokenize(cmd, sep);
		argv = malloc(sizeof(char *) * c_tok);
		token = strtok(cmd_cp, sep);
		for (ac = 0; token != NULL; ac++)
		{
			argv[ac] = malloc(sizeof(char) * (_strlen(token) + 1));
			_strcpy(argv[ac], token);
			token = strtok(NULL, sep);
		}
		argv[ac] = NULL;
		execute_cmd(argv, exe_name);
	}
	free(cmd_cp);
	free(cmd);
	return (0);
}

/**
 * ext_shl - Chck
 * @it: input
 * Return: Nothing.
 */
void ext_shl(char **it)
{
	int sts = 0;

	if (it[1] == NULL)
	{
		fre_dip(it);
		exit(EXIT_SUCCESS);
	}
	sts = _atoi(it[1]);
	fre_dip(it);
	exit(sts);
}
