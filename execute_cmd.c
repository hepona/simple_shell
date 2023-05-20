#include "shell.h"

/**
 * execute_cmd -> execute command from user
 * @argv: command entered by user
 * @filename: name of the executed file
 */
void execute_cmd(char **argv, char *filename)
{
	char *cmd = str_concat("/bin/", argv[0]);
	int pid = 0;
	char *path = _getenv("PATH");

	if (access(cmd, X_OK))
	{
		perror(filename);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(filename);
			exit(EXIT_FAILURE);
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
