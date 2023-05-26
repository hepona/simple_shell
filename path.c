#include "shell.h"

/**
 * file_path -> localisation of the path
 * @cmd: command
 * Return: the whole command
*/

char *file_path(char *cmd)
{
	char *path = _getenv("PATH"), *dir_cmd, *full_path;
	char *path_cp = _strdup(path);
	char *dir = strtok(path_cp, ":");
	struct stat buf;

	if (path == NULL || str_comp(path, "\0") == 0)
		return (_strdup(cmd));
	while (dir != NULL)
	{
		dir_cmd = str_concat(dir, "/");
		full_path = str_concat(dir_cmd, cmd);
		free(dir_cmd);

		if (stat(full_path, &buf) == 0)
		{
			free(path_cp);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_cp);

	if (check_fll_path(cmd))
		return (_strdup(cmd));

	return (NULL);
}

/**
 * check_fll_path -> chck path
 * @cmd: command entered by user
 * Return: O or 1
 */
int check_fll_path(const char *cmd)
{
if (access(cmd, X_OK) == 0)
return (1);
return (0);
}
