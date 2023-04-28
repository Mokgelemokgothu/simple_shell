#include "shell.h"
/**
 * _fork_fun - create child process using fork
 *@path: specificy search of path in the program
 *@prog: pointer to strings
 *@env: environment variable
 *@user_input: pointer to array with user input
 *@idp: interger value of id of process
 *@ch_tst: interger value of Checker add new test
 *
 *Return: 0 on success
 */
int _fork_fun(char **path, char **prog,
		char **env, char *user_input, int idp, int ch_tst)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(path[0], path, env) == -1)
		{
			fprintf(stderr, format, prog[0], idp, path[0]);
			if (!ch_tst)
				free(path[0]);
			free(path);
			free(user_input);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
