#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * execute_command - Execute a command.
 * @command: The command to be executed.
 */
void execute_command(char **args)
{
	printf("Executing command: %s\n", command);
}
/**
 * main - Entry point of the shell program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	char input[100];

	while (1)
	{
		printf("Enter a command: ");
		fgets(input, sizeof(input), stdin);

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		execute_command(input);
	}

	return (0);
}
