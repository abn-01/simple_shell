#include "shell.h"
/**
 * cmd_not_found_error - prints error message
 * @argv: first element of arguments
 * @token: the command
 * Return: void
 */
void cmd_not_found_error(char *argv, char *token)
{
	int length;
	char count;

	count = arg_count(0);
	length = _strlen(argv);
	write(1, argv, length);
	length = _strlen(token);
	write(1, ": ", 2);
	write(1, &count, 1);
	write(1, ": ", 2);
	write(1, token, length);
	write(1, ": not found\n", 12);
}
