#include "main.h"

/**
 * exec_builtin - Executes a built-in command using a system call.
 * @tok: User input tokens.
 * @env: Environment variables.
 * @filename: Full pathname of the file/command.
 * @argv: Array of pointers to strings.
 *
 * Description: Executes the function associated with the user command.
 * Return: void
 */
int exec_builtin(char **tok, char **env, char *filename, char *argv[])
{
	int i, retval;
	BuiltInCommand inbuilt[] = {
		{"exit", our_exit},
		{"env", print_env},
		{NULL, NULL}
	};

	for (i = 0; inbuilt[i].cmd != NULL; i++)
	{
		if (stringcomp(inbuilt[i].cmd, tok[0]) == 0)
		{
			free(filename);

			retval = (*inbuilt[i].func)(tok, env, argv);

			return (retval);
		}
	}

	return (-1);
}

/**
 * our_exit - Wrapper for the exit syscall.
 * @tok: Unused user command for typedef compliance.
 * @env: Environment variables.
 * @argv: Array of pointers to strings.
 *
 * Description: Terminates the current process.
 * Return: void
 */
int our_exit(char **tok, __attribute__((unused)) char **env, char *argv[])
{
	int len = 0, i = 0, sig_fig = 1, num = 0, j = 0, err = 0;

	while (tok[j])
		j++;

	err = errno;

	if (!tok[j] && j == 0)
	{
		errno = 0;
		free_grid(tok, j);
		exit(err);
	}

	if (tok[1])
	{
		while (tok[1][i])
		{
			if ((tok[1][i] < '0') || (tok[1][i] > '9'))
			{
				illegal_num_error(tok, argv);
				free_grid(tok, j);
				return (2);
			}

			i++;
			len++;
			sig_fig *= 10;
		}

		sig_fig /= 10;

		for (i = 0; tok[1][i]; i++)
		{
			num += (tok[1][i] - 48) * sig_fig;
			sig_fig /= 10;
		}
	}

	free_grid(tok, j);

	exit(num);
}

/**
 * print_env - Prints the environment variables.
 * @tok: Unused variable holding user input.
 * @env: Environment variables.
 * @argv: An array of pointers to strings.
 *
 * Description: This function prints the environment variables.
 * Return: void
 */
int print_env(__attribute__((unused)) char **tok, char **env,
		__attribute__((unused)) char *argv[])
{
	int i = 0, len;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(1, env[i], len);
		write(1, "\n", 1);
		i++;
	}

	return (0);
}

/**
 * illegal_num_error - Prints an error message for,
 * the failure of the exit builtin command.
 * @tok: An array of pointers to strings.
 * @argv: An array of pointers to strings.
 *
 * Return: void
 */
void illegal_num_error(char **tok, char *argv[])
{
	int len = 0;
	char i;

	i = arg_count(0);
	len = _strlen(argv[0]);
	write(1, argv[0], len);
	write(1, ": ", 2);
	write(1, &i, 1);
	write(1, ": ", 2);
	len = _strlen(tok[0]);
	write(1, tok[0], len);
	write(1, ": Illegal number: ", 18);
	len = _strlen(tok[1]);
	write(1, tok[1], len);
	write(1, "\n", 1);
}
