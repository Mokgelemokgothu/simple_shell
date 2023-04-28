#include "shell.h"

/**
 * _getline_command - prompt user for input
 *
 * Return: pointer pointing to string input for user
 */
char *_getline_command(void)
{
	char *user_input = NULL;
	size_t buf;

	buf = 0;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&user_input, &buf, stdin) == -1)
	{
		free(user_input);
		return (NULL);
	}

	return (user_input);
}
