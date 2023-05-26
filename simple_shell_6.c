#include "shell.h"

void free_str(char *buffer, char *getline_cp);
/**
 * main - the entry point
 * @argc: argument
 * @argv: array of argument
 * @env: environment
 * Return: 0
 */
int main(__attribute__((unused))int argc, char *argv[], char *env[])
{
	size_t byt;
	int regain = 0, regainb = 0;

	while (1)
	{
		char *buffer = NULL, *delim = " ", *getline_cp, **tokens = NULL, *filename;
		int plan = 0, args = 0, j = 0, reg = 0;

		plan = isatty(STDIN_FILENO);
		if (plan)
		{
			reg = get_prompt();
			j = 1;
		}
		reg = getline(&buffer, &byt, stdin);
		if (reg == -1)
		{
			write(1, "\n", j);
			getline_error_handler(buffer, regainb);
		}
		arg_count(1);
		buffer[_strlen(buffer) - 1] = '\0';
		getline_cp = _strdup(buffer);
		args = no_of_args(buffer, delim);
		if (args > 1)
		{
			tokens = word_split(getline_cp, delim);
			free_str(buffer, getline_cp);
			filename = _strdup(tokens[0]);
			regainb = exec_builtin(tokens, env, filename, argv);
			if (regainb == -1)
			{
				regain = _fork(tokens, env, argv, filename);
				free(filename);
				free_grid(tokens, args);
				if (regain == 127)
					regainb = regain;
			}
		}
		else
			free_str(buffer, getline_cp);
	}
	return (regain);
}
/**
 * free_str - frees all dynamically allocated memory
 * @buffer: the string to free
 * @getline_cp: the string to free
 * Return: void
 */
void free_str(char *buffer, char *getline_cp)
{

	free(buffer);
	free(getline_cp);

}
