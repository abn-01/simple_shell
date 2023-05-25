#include "main.h"
/**
 * abs_path - creates absolute path if user only give cmd name
 * @token: tokenised user input
 * @env: the environment
 *
 * Return: Pointer to pointer
 */
char **abs_path(char *token[], char **env)
{
	int i = 0, len = 0, j = 0, k = 0, l = 0;
	char **absolute_path = NULL, **path = NULL;

	path = waymaker(&i, env);
	absolute_path = malloc(sizeof(char *) * (i + 1));
	if (!absolute_path)
		return (NULL);

	while (j < i)
	{
		k = 0;
		l = 0;
		len = _strlen(path[j]) + _strlen(token[0]) + 2;
		absolute_path[j] = malloc(sizeof(char) * len);
		if (!(absolute_path[j]))
			return (NULL);

		while (path[j][k])
		{
			absolute_path[j][k] = path[j][k];
			k++;
		}
		absolute_path[j][k] = '/';
		k++;
		while (token[0][l])
		{
			absolute_path[j][k] = token[0][l];
			k++;
			l++;
		}
		absolute_path[j][k] = '\0';
		j++;
	}
	absolute_path[j] = NULL;
	free_grid(path, i);
	return (absolute_path);
}
