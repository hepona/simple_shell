#include "shell.h"

/**
 * execute_cmd -> execute command from user
 * @argv: command entered by user
 * @filename: name of the executable file
 */
void execute_cmd(char **argv, char *filename)
{
	char *cmd = NULL;
	int pid = fork();
	if (pid == 0)
	{
	  if(check_fll_path(argv[0]))
	  cmd=argv[0];
	  else
	   cmd =str_concat("/bin/", argv[0]);
	  if (execve(cmd, argv, NULL) == -1)
	   perror(filename);
	  exit(EXIT_FAILURE);
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
