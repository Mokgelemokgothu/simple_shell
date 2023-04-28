#include "shell.h"

/**
 *_strncat - concatenate source string to destination str
 *@dest_str: pointer pointing to destination string
 *@chr: pointer to character
 *
 *Return: destination of the string
 */
char *_strncat(char *dest_str, char *chr)
{
	int index_des = 0;
	int index_sou = 0;

	while (chr[index_des] != '\0')
	{
		index_des++;
	}
	while (chr[index_sou] != '\0')
	{
		dest_str[index_des] = chr[index_sou];
		index_des++;
		index_sou++;
	}
	dest_str[index_des] = '\0';
	return (dest_str);
}

/**
 * _strncmp - compare the values of a str1 to str2
 * @str1: pointer to character of str1
 * @str2: pointer to character of str2
 *
 * Return: 0 on sucess
 */
int _strncmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - str2[i]);
	}
	return (0);
}

/**
 * _strnlen - calculate lenght of str
 * @str: pointer pointing to string
 *
 * Return: char pointer to dest
 */
int _strnlen(char *str)
{
	int len = 0;

	while (*(str + len) != '\0')
	{
		len++;
	}

	return (len);
}

/**
 *_strncmp - compares string 1 to string 2
 *@str1: first string
 *@str2: second string
 *@num: number of characters
 *
 * Return: results of comparison
 */

size_t _strcmp(char *str1, char *str2, size_t num)
{
	size_t counter;
	size_t i;

	for (i = 0; str1[i] != '\0' && i < num; i++)
	{
		counter = str1[i] - str2[i];

		if (counter != 0)
		{
			return (counter);
		}
	}
	return (0);
}

/**
 * _strncpy - copies certain number of char from src into dest
 * @dest_str: pointing to destination of the copy
 * @source_str: pointing to source of the copy
 *
 * Return: char pointer to dest
 */
char *_strncpy(char *dest_str, char *source_str)
{
	int i = 0;

	while (*(source_str + i) != '\0')
	{
		*(dest_str + i) = *(source_str + i);
		++i;
	}
	*(dest_str + i) = *(source_str + i);

	return (dest_str);
}
