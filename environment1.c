#include "main.h"

/**
 *cmp_env_name - compare env variable names
 *with the name passed
 *@nenv: name of the environment variable
 *@name: name passed
 *
 *Return: 0 if are not equal else other value
 */
int cmp_env_name(const char *nenv, const *name)
{
	int i;
	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}
	return (i + 1);
}

/**
 *_getenv - get an environment variable
 *@name: name of the environment varible
 *@_environ: enviroment variable
 *
 *Return: value of the environment variable if foud
 *else, return NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* initialize the ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* compare all enviroment variables */
	/* envoron is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* if name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}
	return (ptr_env + mov);
}

/**
 *_env - print the envoronment variables
 *
 *@datash: data relevant
 *
 *Return: 1 on Success
 */
int _env(data_shell *datash)
{
	int i, j;
	for (i = 0; datash->_environ[i]; i++)
	{
		for (j = 0; datash->_environ[i][j]; j++)
			;
		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
