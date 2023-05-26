#include "shell.h"
/**
 * getline_error_handler - handle errors
 * @buffer: input
 * @regain: return value
 * Return: void
 */
void getline_error_handler(char *buffer, int regain)
{
	free(buffer);
	if (regain != 2 && regain != 127)
		regain = 0;
	_exit(regain);
}
