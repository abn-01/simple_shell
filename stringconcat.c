#include "main.h"
#include <stdlib.h>

/**
 * _strconcat - Concatenates two strings
 * @str1: Pointer to the first string
 * @str2: Pointer to the second string
 *
 * Return: Pointer to a newly allocated string
 */
char *_strconcat(char *str1, char *str2)
{
	int l1 = _strlen(str1), l2 = _strlen(str2);
	char *new = malloc(sizeof(char) * (l1 + l2 + 2));

	if (new == NULL)
		return (NULL);

	int i, j;

	for (i = 0; i < l1; i++)
		new[i] = str1[i];

	new[i++] = '/';

	for (j = 0; j < l2; j++)
		new[i + j] = str2[j];

	new[i + j] = '\0';

	return (new);
}
