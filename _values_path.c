#include "shell.h"

/**
 * _values_path - process file paths and env variables
 * @user_coms: user commands input
 * @env: enviromental variable
 *
 * Return:  a pointer
 */
int _values_path(char **user_coms, char **env)
{
	char *token = NULL;
	char *path_val = NULL;
	char *path_absol = NULL;
	size_t value_path;
	size_t command;
	struct stat stat_lineptr;

	if (stat(*user_coms, &stat_lineptr) == 0)
		return (-1);
	path_val = _get_path(env);
	if (!path_val)
		return (-1);
	token = _strntok(path_val, ":");
	command = _strnlen(*user_coms);
	while (token)
	{
		value_path = _strnlen(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_val);
			return (-1);
		}
		path_absol = _strncpy(path_absol, token);
		_strncat(path_absol, "/");
		_strncat(path_absol, *user_coms);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*user_coms = path_absol;
			free(path_val);
			return (0);
		}
		free(path_absol);
		token = _strntok(NULL, ":");
	}
	free(path_val);
	return (-1);
}
