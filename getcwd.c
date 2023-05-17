#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

/**
 * cd_builtin - change the current working directory
 * @args: array of arguments, where args[1] is the directory to change to
 * @envp: environment variables
 *
 * Return: On success, 0. On error, -1.
 */
int cd_builtin(char **args, char **envp)
{
	char *home = getenv("HOME");
	char *oldpwd = getenv("OLDPWD");
	char *dir, *pwd;
	char buf[BUFSIZE];

	if (!args[1] || strcmp(args[1], "~") == 0)
		dir = home;
	else if (strcmp(args[1], "-") == 0)
		dir = oldpwd;
	else
		dir = args[1];

	if (chdir(dir) != 0)
	{
		perror("cd");
		return (-1);
	}

	pwd = getcwd(buf, BUFSIZE);
	if (pwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	if (setenv("OLDPWD", getenv("PWD"), 1) < 0)
	{
		perror("setenv");
		return (-1);
	}

	if (setenv("PWD", pwd, 1) < 0)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}
