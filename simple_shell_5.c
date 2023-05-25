#include "main.h"
/**
 * our_execve - passes correct full path to execve
 * @tokens: command and args entered
 * @environ: pointer to array of strings (environment variables)
 * @fn: the full path to commands
 *
 * Description: give correct args to execve
 * Return: nothing
 */
int our_execve(char *tokens[], char *environ[], char *fn)
{
	tokens[0] = fn;
	execve(tokens[0], tokens, environ);

	return (-1);
}
