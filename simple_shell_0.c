#include "shell.h"

/**
 * _strcpy - The entry point
 * @dest: pointer to a string
 * @src: pointer to a string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];

	return (dest);
}
