#include <stdio.h>

/**
 * execute_command - Execute a single command
 * @command: The command to be executed
 *
 * This function executes a single command by using the system() function.
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
 *
 * This function handles the shell logic for executing commands with logical
 * operators && and ||. It prompts for commands and executes them accordingly.
 *
 * Return: Always 0
 */
int main(void)
{
	char command[100];

	while (1)
	{
		printf("alex@~$ ");
		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		char *and_operator = strstr(command, "&&");
		char *or_operator = strstr(command, "||");

		if (and_operator)
		{
			*and_operator = '\0';
			int status = execute_command(command);

			if (status == 0)
				execute_command(and_operator + 2);
		}
		else if (or_operator)
		{
			*or_operator = '\0';
			int status = execute_command(command);

			if (status != 0)
				execute_command(or_operator + 2);
		}
		else
		{
			execute_command(command);
		}
	}

	return (0);
}
