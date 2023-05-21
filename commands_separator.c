#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100
/**
 * print_exit_status - convert the exit status to a string
 * @exit_status: integer
 */
void print_exit_status(int exit_status)
{
	char exit_status_str[10];
	int i = 0;
	int num = exit_status;
	int digit = num % 10;

	if (num == 0)
	{
		exit_status_str[i++] = '0';
	}
	else
	{
		while (num != 0)
		{
			exit_status_str[i++] = '0' + digit;
			num /= 10;
		}
	}

	write(STDOUT_FILENO, "exit status: ", 13);

	while (i > 0)
	{
		write(STDOUT_FILENO, &exit_status_str[--i], 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * execute_command - executing a single command within the shell program
 * @command: string command
 * Return: status
 */
int execute_command(char *command)
{
	char *trimmed_command = strtok(command, " \t\r\n");
	char *arguments[MAX_ARGUMENTS];
	int argument_count = 0;
	int status;
	pid_t pid = fork();

	arguments[argument_count] = NULL;

	if (trimmed_command == NULL)
	{
		return (0);
	}

	while (trimmed_command != NULL && argument_count < MAX_ARGUMENTS - 1)
	{
		arguments[argument_count++] = trimmed_command;
		trimmed_command = strtok(NULL, " \t\r\n");
	}

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(arguments[0], arguments, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}
/**
 * main - Handle the commands separator
 * Return: 0
 */
int main(void)
{
	char commands[MAX_COMMAND_LENGTH];
	ssize_t num_read = read(STDIN_FILENO, commands, sizeof(commands));
	char *command = strtok(commands, ";");
	int exit_status = execute_command(command);

	write(STDOUT_FILENO, "enter commands: ", 16);

	if (num_read <= 0)
	{
		exit(EXIT_FAILURE);
	}
	commands[num_read] = '\0';

	while (command != NULL)
	{
		print_exit_status(exit_status);
		command = strtok(NULL, ";");
	}
	return (0);
}
