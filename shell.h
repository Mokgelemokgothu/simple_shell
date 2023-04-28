#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strncmp(char *str1, char *str2);
size_t _strcmp(char *str1, char *str2, size_t num);
int _strnlen(char *str);
char *_strncpy(char *dest_str, char *source_str);
char *_strncat(char *dest_str, char *chr);
int _putchar(char c);
int main(int count, char **arg, char **env);
char *_get_path(char **env);
int _values_path(char **user_coms, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *user_input);
void _exit_command(char **user_coms, char *user_input, int _exit);
int _fork_fun(char **path, char **prog, char **env,
		char *user_input, int idp, int ch_tst);
char *_strntok(char *strn, const char *delim);

#endif /* SHELL_H */
