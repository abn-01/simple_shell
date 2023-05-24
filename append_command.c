#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * append_command - Concatenates a directory path with a command
 * @dir_path: Directory string to be appended with the command
 * @command: Command to be concatenated with the directory
 * Return: Buffer containing the concatenated path
 */
char *append_command(const char *dir_path, const char *command)
{
	size_t dir_len = strlen(dir_path);
	size_t cmd_len = strlen(command);

	char *command_path = malloc(dir_len + 1 + cmd_len + 1);

	if (command_path == NULL)
		return (NULL);

	strcpy(command_path, dir_path);

	if (dir_len > 0 && dir_path[dir_len - 1] != '/')
	{
		command_path[dir_len] = '/';
		command_path[dir_len + 1] = '\0';
	}

	strcat(command_path, command);

	return (command_path);
}
