#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/**
 * setenv_command - Initialize a new environment variable
 * or modify an existing one
 * @variable: name of the environment
 * @value: the value you want to assign
 */
void setenv_command(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		perror("failed to set environment variable");
	}
}
/**
 * unsetenv_command - Remove an environment variable
 * @variable: name of the environment
 */
void unsetenv_command(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		perror("failed to unset environment variable");
	}
}
/**
 * main - Implement the setenv and unsetenv builtin commands
 * Return: 0
 */
int main(void)
{
	char *my_var_value_set = getenv("MY_VAR");
	char *my_var_value_unset = getenv("MY_VAR");

	setenv_command("MY_VAR", "Hello");
	unsetenv_command("MY_VAR");

	if (my_var_value_set != NULL)
	{
		write(STDOUT_FILENO, "MY_VAR: ", 8);
		write(STDOUT_FILENO, my_var_value_set, strlen(my_var_value_set));
		write(STDOUT_FILENO, "\n", 1);
	}

	if (my_var_value_unset != NULL)
	{
		write(STDOUT_FILENO, "MY_VAR: ", 8);
		write(STDOUT_FILENO, my_var_value_unset, strlen(my_var_value_unset));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
