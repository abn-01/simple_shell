#include "main.h"

/**
 * no_of_args - Counts the number of arguments in a string.
 * @str: User input.
 * @delim: Space delimiting arguments.
 *
 * Return: The number of arguments in the string.
 */
int no_of_args(char *str, char *delim)
{
	char *tmp = _strdup(str);
	char *token = strtok(tmp, delim);
	int args = (token != NULL) ? 1 : 0;

	while (token != NULL)
	{
		token = strtok(NULL, delim);
		if (token != NULL)
			args++;
	}

	free(tmp);

	return (args);
}
