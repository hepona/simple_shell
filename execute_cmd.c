#include "shell.h"

/**
 * execute_cmd -> execute command from user
 * @argv: command entered by user
 */
void execute_cmd(char **argv)
{
	char *cmd = NULL;
	int pid = fork();

	if (pid == 0)
	{
		if (argv != NULL)
		{
			cmd = argv[0];
			if (execve(cmd, argv, NULL) == -1)
				perror("Error");
			
		}
	}
 else if (pid == -1)
    {
        perror("Error");
        exit (1);
    }
	else
		wait(NULL);
}
