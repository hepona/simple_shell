#include "shell.h"

/**
 * file_path -> localisation of the path
 * @cmd: command
 * Return: the whole command
*/

char *file_path(char *cmd)
{
    char *path, *path_cp, *path_tok, *dir;
    struct stat buf;

    path = _getenv("PATH");
    if (path == NULL)
        return (NULL);

    path_cp = strdup(path);
    path_tok = strtok(path_cp, ":");
    while(path_tok != NULL)
    {
        dir = malloc(_strlen(cmd) + _strlen(path_tok) + 2);
        _strcpy(dir, path_tok);
        dir = str_concat(dir, "/");
        dir = str_concat(dir, cmd);
        dir = str_concat(dir, "\0");
            if (stat(dir, &buf) == 0)
            {
                free(path_cp);
                return (dir);
            }
            else
            {
                free(dir);
                path_tok = strtok(NULL, ":");
            }
        }
        if (stat(cmd, &buf) == 0)
            return (cmd);
        free(path_cp);
    return (cmd);
}
/**
 * check_fll_path -> chck path
 * @cmd: command entered by user
 * Return O or 1
 */
int check_fll_path(const char *cmd) {
    if (access(cmd, X_OK) == 0) 
        return 1; 
    return 0;
}
