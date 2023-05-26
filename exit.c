#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Simple shell program
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int status;
	char *exit_command = "exit\n";

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			exit(EXIT_SUCCESS);
		if (strcmp(line, exit_command) == 0)
			exit(EXIT_SUCCESS);
		status = system(line);
		if (status == -1)
		{
			printf("Error executing command\n");
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	exit(EXIT_SUCCESS);
}
