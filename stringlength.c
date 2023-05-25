#include "main.h"

/**
 * _strlen - Calculate the length of a string
 * @str: The string to calculate the length of
 *
 * This function determines the length of the provided string.
 *
 * Return: The length of the string on success, -1 on error.
 */
int _strlen(char *str)
{
	int length = 0;

	if (!str)
		return (-1);

	while (str[length])
		length++;

	return (length);
}
