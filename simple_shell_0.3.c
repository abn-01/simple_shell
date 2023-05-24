#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * check_command_exists - checks the command if it exixts
 * @command: the shell command
 * @path: the path environment
 * Return: 0
 */
int check_command_exists(const char *command, char *path)
{
	char *directory = strtok(path, ":");
	DIR *dir = opendir(directory);
	struct dirent *entry;

	while (directory != NULL)
	{
		if (dir != NULL)
		{
			while ((entry = readdir(dir)) != NULL)
			{
				if (strcmp(entry->d_name, command) == 0)
				{
					closedir(dir);
					return (1);
				}
			}
			closedir(dir);
		}
		directory = strtok(NULL, ":");
	}
	return (0);
}
/**
 * execute_command - this fuction executes the command
 * @command: the shell command
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork();
	int status;
	char *const argv[] = {NULL};

	if (child_pid == 0)
	{
		execve(command, argv, NULL);
		perror("execve");
		_exit(1);
	}
	else if (child_pid > 0)
	{
		waitpid(child_pid, &status, 0);
		exit(WEXITSTATUS(status));
	}
	else
	{
		perror("fork");
		exit(1);
	}
}
/**
 * print_error_message - this fuction prints the error message
 * @command: the shell command
 */
void print_error_message(const char *command)
{
	char error_msg[256] = "Command not found: ";
	size_t msg_len = strlen(error_msg);

	strncpy(error_msg + msg_len, command, sizeof(error_msg) - msg_len - 1);
	error_msg[sizeof(error_msg) - 1] = '\n';
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	exit(1);
}
/**
 * main - handles the PATH environment variable and checks if a command exists
 * Return: 0
 */
int main(void)
{
	char *path = getenv("PATH");
	char command[256];
	ssize_t num_bytes = read(STDIN_FILENO, command, sizeof(command));

	write(STDOUT_FILENO, "Enter a command: ", 17);
	if (num_bytes > 0 && command[num_bytes - 1] == '\n')
	{
		command[num_bytes - 1] = '\0';
	}
	if (check_command_exists(command, path))
	{
		execute_command(command);
	}
	else
	{
		print_error_message(command);
	}
	return (0);
}
