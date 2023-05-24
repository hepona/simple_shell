#include "shell.h"

/**
 * execute_cmd -> execute command from user
 * @argv: command entered by user
 * @filename: name of the executed file
 * Return: 0 or 1
 */
int execute_cmd(char **argv, char *filename)
{
	char *cmd = argv[0];
	char *cmd_vr = file_path(cmd);
	int pid;

	if (access(cmd_vr, X_OK) == -1)
	{
		_isatty(cmd, filename);
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		if (cmd == NULL)
		{
			_putstr("");
			return (0);
		}
		if (str_comp(argv[0], "env") == 0)
		_printenv();
		else
		{
				if (execve(cmd_vr, argv, NULL) == -1)
				perror(filename);
				exit(EXIT_FAILURE);
		}
	}
	else if (pid == -1)
	{
		perror("pid");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		kill(pid, SIGKILL);
	}
	return (1);
}
