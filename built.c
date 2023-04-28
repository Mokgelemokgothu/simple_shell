#include "shell.h"
/**
 * _exit_command - used to exit the currently running shell
 * @user_coms: pointer to array of commands
 * @user_input: pointer to arrat of string with input
 * @_exit: integer exit value
 *
 * Return: Nothing
 */
void _exit_command(char **user_coms, char *user_input, int _exit)
{
	int exit_status;

	exit_status = 0;
	if (!user_coms[1])
	{
		free(user_input);
		free(user_coms);
		exit(_exit);
	}
	exit_status = atoi(user_coms[1]);

	free(user_input);
	free(user_coms);
	exit(exit_status);
}

/**
 *_getenv - function to get all env
 *@env: enviroment
 *
 *Return: 0
 */
void _getenv(char **env)
{
	size_t num = 0;

	while (env[num])
	{
		write(STDOUT_FILENO, env[num], _strnlen(env[num]));
		write(STDOUT_FILENO, "\n", 1);
		rtn++;
	}
}
