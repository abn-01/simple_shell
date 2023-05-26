#include "main.h"

/**
 * get_prompt - Prints the prompt symbol "$" to the standard output.
 *
 * Return: The number of characters written.
 */
int get_prompt(void)
{
	return (write(STDOUT_FILENO, "$ ", 2));
}
