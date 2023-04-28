#include "shell.h"

/**
 * _get_path - determine absolute PATH variable
 * @env: pointer to environmental variables
 *
 * Return: extracted PATH string
 */
char *_get_path(char **env)
{
	size_t index = 0;
	size_t path_val = 0;
	size_t path_len = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH="); index++)
		;
	if (env[index] == NULL)
		return (NULL);

	for (path_len = 5; env[index][path_val]; path_val++, path_len++)
		;
	path = malloc(sizeof(char) * (path_len + 1));

	if (path == NULL)
		return (NULL);

	for (path_val = 5, path_len = 0; env[index][path_val]; path_val++, path_len++)
		path[path_len] = env[index][path_val];

	path[path_len] = '\0';
	return (path);
}
