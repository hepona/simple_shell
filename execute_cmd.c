#include "shell.h"

/**
 * execute_cmd -> execute command from user
 * @argv: command entered by user
 * @filename: name of the executed file
 */
void execute_cmd(char **argv, char *filename)
{
	char *cmd = argv[0];
	char *cmd_vr = file_path(cmd), error_msg[50];;
	int pid, len;

	if (access(cmd_vr, X_OK) == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			len = snprintf(error_msg, sizeof(error_msg), "/bin/sh: 1: %s: not found\n", cmd);
			write(STDERR_FILENO, error_msg, len);
		}
		else
			perror(filename);
		return;
	}
	pid = fork();

	if (pid == 0)
	{
		if (cmd == NULL)
		{
			_putstr("");
			return;
		}
		if (str_comp(argv[0], "env") == 0)
		_printenv();
		else
		{
			if (argv != NULL)
			{
				if (execve(cmd_vr, argv, NULL) == -1)
				perror(filename);
			}
		}
	}
	else if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		kill(pid, SIGKILL);
	}
}
