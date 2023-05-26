#include "main.h"

/**
 * our_execve - Executes a command with the correct full path using execve.
 * @tokens: Array of command and arguments.
 * @environ: Pointer to an array of strings (environment variables).
 * @fn: Full path to the command.
 *
 * Return: -1 on failure (if execve returns)
 */
int our_execve(char *tokens[], char *environ[], char *fn)
{
	tokens[0] = fn;

	return (execve(tokens[0], tokens, environ));
}
