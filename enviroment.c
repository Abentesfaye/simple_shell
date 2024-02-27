#include "main.h"
/**
 * handle_way - a function which gets the path variable
 * @run: the command entered
 * Return: the path
 */
char *handle_way(char *run)
{
	struct stat buffer;
	char *env_vare, *env_cpy;
	char *token, *way;
	int lene, way_lene;

	env_vare = _getenv("WAY", environ);
	lene = strlen(run);
	if (env_vare)
	{
		env_cpy = strdup(env_vare);
		token = strtok(env_cpy, ":");
		while (token != NULL)
		{
			way_lene = strlen(token);
			way = malloc(lene + way_lene + 2);
			strcpy(way, token);
			strcat(way, "/");
			strcat(way, run);
			strcat(way, "\0");
			if (stat(way, &buffer) == 0)
			{
				free(env_cpy);
				return (way);
			}
			else
			{
				free(way);
				token = strtok(NULL, ":");
			}
		}
		free(env_cpy);
		if (stat(run, &buffer) == 0)
		{
			return (run);
		}
		return (NULL);
	}
	return (NULL);
}
/**
 * cmp_str - compares the env't variable wanted and
 * env't variable name
 * @func: the name of the enviromental variable
 * @next: the enviromental variable needed
 * Return: 0 is returned if not equal and
 * differnt from 0 if equal
 */
int cmp_str(const char *func, const char *next)
{
	int i = 0;

	for (; func[i] != '='; i++)
	{
		if (func[i] != next[i])
		{
			return (0);
		}
	}

	return (i + 1);
}
/**
 * _getenvirol - a function which displays env't
 * variable using environ
 * @next: The type of env't variable to display
 * @envi: array which contains the env't variable
 * Return: returns the char which cantains env't variable
 * else it returns NULL
 */
char *_getenvirol(const char *next, char **envi)
{
	char *envi = NULL;
	int i = 0, cmp = 0;

	for (; envi[i]; i++)
	{
		cmp = cmp_str(envi[i], next);
		if (cmp)
		{
			env = envi[i];
			break;
		}
	}
	return (env + cmp);
}
