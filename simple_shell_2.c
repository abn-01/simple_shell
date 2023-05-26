#include "shell.h"

/**
 * cmd_not_found_error - prints error message on stdout
 * @argv: the first element of argv
 * @token: the command entered on the cmdline
 *
 * Return: Void
 */

void cmd_not_found_error(char *argv, char *token)
{
	int len;
	char i;

	i = arg_count(0);
	len = _strlen(argv);
	write(1, argv, len);
	len = _strlen(token);
	write(1, ": ", 2);
	write(1, &i, 1);
	write(1, ": ", 2);
	write(1, token, len);
	write(1, ": not found\n", 12);
}
