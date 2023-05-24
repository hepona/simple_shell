#include "shell.h"

/**
 * _isatty -> check if shell is in interactive mode or not
 * @cmd: command
 * @filename: name of file
 * Return: 0 if success, -1 if faile
*/
int _isatty(char *cmd, char *filename)
{
	char error_msg[50];
	int len;

	if (!isatty(STDIN_FILENO))
	{
		len = snprintf(error_msg, sizeof(error_msg),
		 "/bin/%s: 1: %s: not found\n", cmd, filename);
		write(STDERR_FILENO, error_msg, len);
	}
	else
	perror(filename);
	return (0);
}
