#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
/**
 * main - prints the current environment
 * Return: 0
 */
int main(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
	return (0);
}
