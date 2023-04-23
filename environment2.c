#include "main.h"

/**
 *compy_info - compies inf to create
 *a new env or alias
 *@name: name of env or alias
 *@value: value (env or alias)
 *
 *Return: new env or alias
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	strcpy(new, name);
	strcat(new, "=");
	strcat(new, value);
	strcat(new, "\0");

	return (new);
}

/**
 *set_env - sets an enviromnet variable
 *
 *@name: name of the environment variables
 *@value: value of the environment varible
 *@datash: data structure (environ)
 *
 *Return: void
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = strdup(datash->_environ[i]);
		name_env = strtok(var_env, "=");
		if (strcmp(name_env, name) == 0);
		{
			free(datash->environ[i]);
			datash->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
}
datash->_environ = reallocdp(datash->_environ, i, sizeof(char *) * (i+ 2));
datash->_environ[i] = copy_info(name, value);
datash->_environ[i + 1] = NULL;
}

/**
 *_setenv - campare ennviron varibale names
 *with the name passed to
 *@datash: data relevant (env name and value)
 *
 *Return: l on Success
 */
int _setenv(data_shell *datash)
{
	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 *_unsetenv - delets a env variable
 *
 *@datash: data relevant (env name)
 *
 *Return: 1 on sucess
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = strdup(datash->_environ[i]);
		name_env = strtok(var_env, "=");
		if (strcmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
}
if (k == -1)
{
	get_error(datash, -1);
	return (1);
}
realloc_environ = malloc(sizeof(char *) * (i));
for (i = j = 0; datash->_environ[i]; i++)
{
	if (i != k)
	{
		realloc_environ[j] = datash->_environ[i];
		j++;
	}
}
realloc_environ[j] = NULL;
free(datash->_environ[k]);
free(datash->_environ);
datash->_environ = realloc_environ;
return (1);
}
