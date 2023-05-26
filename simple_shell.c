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
	char *trail;
	int count = 0, f = 0, g = 0, h = 0, length = 0;

	while (env[count])
	{
		f = 0;
		while (var[f] == env[count][f])
		{
			if (f == 3)
			{
				h = count;
				break;
			}
			f++;
		}
		if (f == 3)
			break;
		count++;
	}
	length = _strlen(env[h]) - 4;
	trail = malloc(sizeof(char) * length);

	for (g = 0; env[h][f + 2] != '\0'; g++)
	{
		trail[g] = env[h][f + 2];
		f++;
	}
	trail[g] = '\0';

	return (trail);
}
