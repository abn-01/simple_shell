#include "main.h"

/**
 * _strlen - returns the string length
 * @str: string
 *
 * Return: length of string on success, -1 on error
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (-1);

	while (str[i])
		i++;

	return (i);
}
