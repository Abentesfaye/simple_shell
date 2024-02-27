#include"main.h"

/**
 * hvd_env - a command which prints the enviroment variable
 * Return: 0 if success
 */

int hvd_env(void)
{
	unsigned int i = 0, lene = 0;

	lene = strlen(environ[i]);
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], lene);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
		return (0);
}
