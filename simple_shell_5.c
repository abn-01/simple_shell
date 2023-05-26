#include "shell.h"

/**
 * our_execve - passes correct full path to execve
 * @tokens: the command
 * @environ: pointer to array of strings
 * @fn: the full path
 * Description: give correct args
 * Return: nothing
 */
int our_execve(char *index[], char *environ[], char *function)
{
	index[0] = function;
	execve(index[0], index, environ);

	return (-1);
}
