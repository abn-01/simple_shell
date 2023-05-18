#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

void handle_sigint(int signum);
void parse_input(char *input, char **args);
void execute_command(char **args);
void handle_builtin_commands(char **args);
/**
 * main - calls all the functions to perform
 * the shell's functionality
 * Return: 0
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];
	struct sigaction sigint_action;
	ssize_t bytes_read = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);

	sigint_action.sa_handler = handle_sigint;
	sigemptyset(&sigint_action.sa_mask);
	sigint_action.sa_flags = 0;
	sigaction(SIGINT, &sigint_action, NULL);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (bytes_read == -1)
			break;
		input[bytes_read - 1] = '\0';
		parse_input(input, args);

		if (args[0] != NULL)
		{
			handle_builtin_commands(args);
			execute_command(args);
		}
	}
	return (0);
}
/**
 * handle_sigint - handles the SIGINT signal
 * @signum: signal number that is passed as an argument
 */
void handle_sigint(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
/**
 * parse_input - parses the input into arguments
 * @input: the data stored
 * @args: arguments
 */
void parse_input(char *input, char **args)
{
	int arg_count = 0;
	int input_len = strlen(input);
	int arg_start = 0;
	int i;

	for (i = 0; i < input_len; i++)
	{
		if (input[i] == ' ' || input[i] == '\t')
		{
			if (i > arg_start)
			{
				input[i] = '\0';
				args[arg_count++] = &input[arg_start];
			}
			arg_start = i + 1;
		}
	}
	if (i > arg_start)
	{
		input[i] = '\0';
		args[arg_count++] = &input[arg_start];
	}
	args[arg_count] = NULL;
}
/**
 * execute_command - forks and executes the command
 * @args: arguments
 */
void execute_command(char **args)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) < 0)
		{
			perror("execve");
			_exit(1);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
		exit(1);
	}
}
/**
 * handle_builtin_commands - handles the built-in commands
 * @args: arguments
 */
void handle_builtin_commands(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			write(STDERR_FILENO, "cd: expected 1 argument\n", 23);
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("chdir");
			}
		}
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
}
