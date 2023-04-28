#include "shell.h"

/**
 * _get_token - split strings into token
 * @user_input: string of arguments
 *
 * Return: a pointer pointing to array with extracted tokens
 */
char **_get_token(char *user_input)
{
	char **user_coms = NULL;
	char *token = NULL;
	size_t pos = 0;
	int num = 0;

	if (user_input == NULL)
		return (NULL);

	for (pos = 0; user_input[pos]; pos++)
	{
		if (user_input[pos] == ' ')
			num++;
	}
	if ((num + 1) == _strnlen(user_input))
		return (NULL);
	user_coms = malloc(sizeof(char *) * (num + 2));
	if (user_coms == NULL)
		return (NULL);

	token = _strntok(user_input, " \n\t\r");
	for (pos = 0; token != NULL; pos++)
	{
		user_coms[pos] = token;
		token = _strntok(NULL, " \n\t\r");
	}
	user_coms[pos] = NULL;
	return (user_coms);
}
