#include "shell.h"
/**
 * _getenv - get value of environment variable
 * @var: Some environment variable
 * @env: the environment
 *
 * Return: the value of var
 */
char *_getenv(char *var, char **env)
{
	char *path;
	int i = 0, j = 0, k = 0, loc = 0, len = 0;

	while (env[i])
	{
		j = 0;
		while (var[j] == env[i][j])
		{
			if (j == 3)
			{
				loc = i;
				break;
			}
			j++;
		}
		if (j == 3)
			break;
		i++;
	}
	len = _strlen(env[loc]) - 4;
	path = malloc(sizeof(char) * len);

	for (k = 0; env[loc][j + 2] != '\0'; k++)
	{
		path[k] = env[loc][j + 2];
		j++;
	}
	path[k] = '\0';

	return (path);
}
