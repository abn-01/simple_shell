#include "main.h"

/**
 * _fork - Handles the fork and executes a command.
 * @tokens: An array of pointers to strings representing command tokens.
 * @env: An array of pointers to strings representing environment variables.
 * @argv: The argv[0] string.
 * @filename: A string containing the absolute path of a file.
 *
 * Return: The exit status of the child process.
 */
int _fork(char **tokens, char **env, char **argv, char *filename)
{
	int retval = 0, pid = 0, status, exit_status = 0;

	retval = file_check(tokens, env);

	if (retval != 0)
	{
		cmd_not_found_error(argv[0], filename);
		return (127);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		exit(98);
	}
	else if (pid == 0)
	{
		if (retval == 0)
			our_execve(tokens, env, tokens[0]);
	}
	else
		wait(&status);

	return (exit_status);
}
