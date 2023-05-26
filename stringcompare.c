#include "main.h"
/**
 * stringcomp - This function compares the similarity of two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if strings are equal, -1 otherwise
 */
int stringcomp(char *str1, char *str2)
{
	int i = 0;

	if (!str1 || !str2)
		return (-1);

	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}

	if (str1[i] != str2[i])
		return (-1);

	return (0);
}
