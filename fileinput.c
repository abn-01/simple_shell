#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * execute_command - Execute a single command
 * @command: The command to be executed
 *
 * This function executes a single command by using the system() function.
 * It replaces the supported variables before executing the command.
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{

	int status = system(command);

	return (status);
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * This function handles the shell logic,
 * for executing commands with variable replacement.
 * It prompts for commands, executes them,
 * and replaces supported variables in the command.
 * If a filename is provided as a command line argument,
 * the shell reads commands from the file instead.
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char command[100];
	FILE *file = NULL;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fprintf(stderr, "Error: Failed to open file '%s'\n", argv[1]);
			return (1);
		}
	}

	if (file == NULL)
	{
		while (1)
		{
			printf("$ ");
			fgets(command, sizeof(command), stdin);

			command[strcspn(command, "\n")] = '\0';

			execute_command(command);
		}
	}
	else
	{
		while (fgets(command, sizeof(command), file) != NULL)
		{
			command[strcspn(command, "\n")] = '\0';

			execute_command(command);
		}

		fclose(file);
	}

	return (0);
}
