#include "shell.h"
/**
 * is_interactive - checks if the shell is in interactive mode
 * @info: pointer to the info_t struct
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && (info->readfd >= 0 && info->readfd <= 2));
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delimiter: the delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}

	return (0);
}

/**
 * is_alpha - checks if a character is an alphabetic character
 * @c: the character to check
 *
 * Return: 1 if the character is alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * string_to_integer - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the converted number if successful, 0 otherwise
 */
int _atoi(char *s)
{
	int sign = 1, result = 0;
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
		}
		else if (result > 0)
		{
			break;
		}

		s++;
	}

	return (sign * result);
}
