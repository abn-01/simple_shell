#include "shell.h"
/**
 * _fork - handle the fork
 * @tokens: array of pointers to strings
 * @env: array of pointers to strings(env)
 * @argv: the argument string
 * @filename: a string containing the path of a file
 * Return: void
 */
int _fork(char **tokens, char **env, char **argv, char *filename)
{
	int regain = 0, pid = 0, position, exit_position = 0;

	regain = file_check(tokens, env);

	if (regain != 0)
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
		if (regain == 0)
			our_execve(tokens, env, tokens[0]);
	}
	else
		wait(&position);
	return (exit_position);
}
