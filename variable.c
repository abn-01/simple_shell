#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define DELIMITERS " \t\r\n\a"

/**
 * main- program ues execvp
 * Execute a command by forking a child process and using execvp.
 *
 * @param args The array of command arguments.
 * @return The exit status of the command.
 */
int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (WEXITSTATUS(status));
}

/**
 * Replace variables in a command string with their corresponding values.
 *
 * @param command The command string to process.
 * @return The processed command string with variables replaced.
 */
char *replace_variables(char *command)
{
	char *result = malloc(MAX_INPUT_SIZE * sizeof(char));
	char *token = strtok(command, DELIMITERS);
	char *var_value;

	while (token != NULL)
	{
		if (strcmp(token, "$?") == 0)
		{
			sprintf(result + strlen(result), "%d", WEXITSTATUS(status));
		}
		else if (strcmp(token, "$$") == 0)
		{
			sprintf(result + strlen(result), "%d", getpid());
		}
		else if (token[0] == '$')
		{
			var_value = getenv(token + 1);
			if (var_value != NULL)
			{
				sprintf(result + strlen(result), "%s", var_value);
			}
		}
		else
		{
			sprintf(result + strlen(result), "%s", token);
		}

		token = strtok(NULL, DELIMITERS);
		if (token != NULL)
		{
			strcat(result, " ");
		}
	}

	return (result);
}

/**
 * Main function for the simple shell.
 *
 * @return The exit status of the shell.
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *tokens[MAX_TOKENS];
	int status;

	while (1)
	{
		printf("$ ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		char *replaced_input = replace_variables(input);

		char *token = strtok(replaced_input, DELIMITERS);
		int token_count = 0;

		while (token != NULL)
		{
			tokens[token_count++] = token;
			token = strtok(NULL, DELIMITERS);
		}
		tokens[token_count] = NULL;

		status = execute_command(tokens);

		free(replaced_input);

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
	}

	return (0);
}

