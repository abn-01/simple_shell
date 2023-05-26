#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/**
 * _getline - reads a line from input
 *
 * Return: The line read from input
 */
char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static char *pos;
	static ssize_t remaining = -1;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		if (remaining <= 0)
		{
			read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (read == 0)
				return (line);
			if (read == -1)
				return (NULL);
			pos = buffer;
			remaining = read;
		}
		if (*pos == '\n' || *pos == '\0')
		{
			line = realloc(line, len + remaining + 1);
			if (line == NULL)
				return (NULL);
			strncat(line, buffer, pos - buffer + 1);
			remaining -= pos - buffer + 1;
			memmove(buffer, pos + 1, remaining);
			return (line);
		}
		pos++;
		remaining--;
		len++;
	}
}

/**
 * main - Simple shell program
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while (1)
	{
		printf("$ ");
		line = _getline();
		if (line == NULL)
			exit(EXIT_FAILURE);
		printf("%s", line);
		free(line);
	}

	return (0);
}
