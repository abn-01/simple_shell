#include "main.h"

/**
 * _strcpy - Entry point
 * @dest: pointer to a string, src is copied to dest
 * @src: pointer to a string, src is copied to dest
 *
 * Return: dest - pointer to a string
 */

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = src[count];

	return (dest);
}
