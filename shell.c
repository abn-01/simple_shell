#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork error");
			exit(1);
		}
		else if (pid == 0)
		{
			execlp(command, command, NULL);

			perror("Execution error");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}
