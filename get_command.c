#include "shell.h"

/**
 * _getline_command - print "#cisfun$ " and wait for the user type something
 *
 * Return: line of string input for user
 */
char *_getline_command(void)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  printf("#cisfun$ ");
  read = getline(&line, &len, stdin);

  if (read == -1)
  {
    perror("getline");
    exit(EXIT_FAILURE);
  }

  return (line);
}
