#include "shell.h"
/**
 * _strlen - the function that returns the string length
 * @str: the string
 * Return: length of string, -1 on error
 */
int _strlen(char *str)
{
	int count = 0;

	if (!str)
		return (-1);

	while (str[count])
		count++;

	return (count);
}
