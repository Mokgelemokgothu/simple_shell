#nclude "shell.h"
/**
 * fork_fun - function that create a fork
 *@path: command and values path
 * parent process waits for the child process to complete and returns the exit
 *status of the child process.
 *@prog: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@q: id of process
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **path, char **prog,
		char **env, char *lineptr, int q, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0) /* create a child process.*/
	{
		if (execve(path[0], path, env) == -1)
		{
			/* print error message to standard error stream and exit with errno. */
			fprintf(stderr, format, prog[0], q, path[0]);
			if (!c)
				free(path[0]);
			free(path);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		/* wait for the child process to complete */
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
