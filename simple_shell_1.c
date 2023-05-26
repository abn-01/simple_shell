#include "shell.h"

/**
 * abs_path - creates absolute path
 * @token: token user input
 * @env:environment
 * Return: Pointer to pointer
 */
char **abs_path(char *token[], char **env)
{
	int count = 0, length = 0, f = 0, g = 0, h = 0;
	char **absolute_path = NULL, **path = NULL;

	path = waymaker(&count, env);
	absolute_path = malloc(sizeof(char *) * (count + 1));
	if (!absolute_path)
		return (NULL);

	while (f < count)
	{
		g = 0;
		h = 0;
		length = _strlen(path[f]) + _strlen(token[0]) + 2;
		absolute_path[f] = malloc(sizeof(char) * length);
		if (!(absolute_path[f]))
			return (NULL);

		while (path[f][g])
		{
			absolute_path[f][g] = path[f][g];
			g++;
		}
		absolute_path[f][g] = '/';
		g++;
		while (token[0][h])
		{
			absolute_path[f][g] = token[0][h];
			g++;
			h++;
		}
		absolute_path[f][g] = '\0';
		f++;
	}
	absolute_path[f] = NULL;
	free_grid(path, count);
	return (absolute_path);
}
