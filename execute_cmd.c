#include "shell.h"

/**
 * execute_cmd -> execute command from user
 * @argv: command entered by user
 * @filename: name of the executed file
 */
void execute_cmd(char **argv, char *filename)
{
	char *cmd = argv[0];
	char *cmd_vr = file_path(cmd);
	int pid = 0;

	// if (cmd_vr == NULL)
    // {
    //     printf("Command not found: %s\n", cmd);
    //     return;
    // }
	//     printf("Executing command: %s\n", cmd_vr);

	// if (cmd_vr == NULL)
	// {
	// 	printf("cmd_vr  = %s\n", cmd_vr);
	// 	return;
	// }
	
	if (access(cmd_vr, X_OK) == -1)
	{
		perror(filename);
		return;
	}
	pid = fork();

	if (pid == 0)
	{
		if (argv != NULL)
		{
			if (execve(cmd_vr, argv, NULL) == -1)
				perror(filename);
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
		// kill(pid, SIGKILL);
	}
}
