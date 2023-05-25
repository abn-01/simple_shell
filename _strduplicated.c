#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Creates a duplicate of a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to a newly allocated memory,
 * location containing the duplicate string.
 */
char *_strdup(char *str)
{
	int len = _strlen(str) + 1;
	char *new = malloc(sizeof(char) * len);

	if (new)
	{
		int i;

		for (i = 0; str[i]; i++)
			new[i] = str[i];

		new[i] = '\0';
	}

	return (new);
}
