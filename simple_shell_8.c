#include "shell.h"
/**
 * word_split - the function splits a string into tokens
 * @str: the string
 * @delim: delimeter
 * Return: array of pointers, NULL otherwise
 */
char **word_split(char *str, char *delim)
{
	char **up_to_date = NULL;
	int args = 0, count = 0;
	char *tmp = NULL;
	int length = 0;

	args = no_of_args(str, delim);

	up_to_date = malloc(sizeof(char *) * args);
	if (!up_to_date)
		return (NULL);

	tmp = strtok(str, delim);
	while (tmp != NULL)
	{
		length = _strlen(tmp) + 1;
		up_to_date[count] = malloc(sizeof(char) * length);
		_strcpy(up_to_date[count], tmp);
		tmp = strtok(NULL, delim);
		count++;
	}
	up_to_date[count] = tmp;

	return (up_to_date);
}
