#include "main.h"

/**
 * word_split - splits a string into tokens
 * @str: a string
 * @delim: delimeter for splitting the string
 *
 * Return: An array of pointers if successful, NULL otherwise
 */

char **word_split(char *str, char *delim)
{
	char **new = NULL;
	int args = 0, i = 0;
	char *tmp = NULL;
	int len = 0;

	args = no_of_args(str, delim);

	new = malloc(sizeof(char *) * args);
	if (!new)
		return (NULL);

	tmp = strtok(str, delim);
	while (tmp != NULL)
	{
		len = _strlen(tmp) + 1;
		new[i] = malloc(sizeof(char) * len);
		_strcpy(new[i], tmp);
		tmp = strtok(NULL, delim);
		i++;
	}
	new[i] = tmp;

	return (new);
}
