#include "main.h"
/**
 * getline_error_handler - handle errors from getline & handle EOF
 * @buffer: user input
 * @retval: return value from shell_clone.c
 *
 * Return: void
 */
void getline_error_handler(char *buffer, int retval)
{
	free(buffer);
	if (retval != 2 && retval != 127)
		retval = 0;
	_exit(retval);
}
