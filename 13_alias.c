#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * print_all_aliases - print all the defined aliases
 */
void print_all_aliases(void)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (child_pid == 0)
	{
		char *args[] = {"alias", NULL};
		execve("/bin/alias", args, NULL);
		perror("execve");
		_exit(1);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}
/**
 * print_alias_value - prints the defined alias value
 * @alias_name: the alias name
 */
void print_alias_value(char *alias_name)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (child_pid == 0)
	{
		char *args[] = {"alias", alias_name, NULL};
		execve("/bin/alias", args, NULL);
		perror("execve");
		_exit(1);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
}
/**
 * define_alias - the function of defining the alias
 * @alias_name: alias name
 * @alias_value: alias value
 */
void define_alias(char *alias_name, char *alias_value)
{
	char *command = malloc(strlen(alias_name) + strlen(alias_value) + 20);
	char **args = malloc(4 * sizeof(char*));
	pid_t child_pid = fork();

	if (command == NULL)
	{
		perror("malloc");
		exit(1);
	}

	strcpy(command, "alias ");
	strcat(command, alias_name);
	strcat(command, "='");
	strcat(command, alias_value);
	strcat(command, "'");

	if (child_pid == -1)
	{
		perror("fork");
		free(command);
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (args == NULL)
		{
		perror("malloc");
		free(command);
		exit(1);
	}
	args[0] = "sh";
	args[1] = "-c";
	args[2] = command;
	args[3] = NULL;

	execve("/bin/sh", args, NULL);
	perror("execve");
	free(args);
	free(command);
	_exit(1);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
		free(command);
	}
}
/**
 * main - Implement the alias builtin command
 * @argc: arguments
 * @argv: array of arguments
 * Retrun:  If name is already an alias
 * replaces its value with value
 */
int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		print_all_aliases();
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		char *arg = argv[i];
		char *equals = strchr(arg, '=');
		char *alias_name;
		char *alias_value;

		if (equals != NULL)
		{
			*equals = '\0';
			alias_name = arg;
			alias_value = equals + 1;
			define_alias(alias_name, alias_value);
		}
		else
		{
			alias_name = arg;
			print_alias_value(alias_name);
		}
	}
	return (0);
}
