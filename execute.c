#include "main.h"

/**
 * exe- function to begin the process
 * @tokeners: parsed input
 * Return: Nothing
 */
void exe(char **tokeners)
{
	pid_t pid;
	char *cmd_add = NULL;
	char *cpy_comm = NULL;
	int val = 0, status;
	char **envp = environ;

	pid = fork();
	if (pid == -1)
		perror("hvd: Error");
	if (pid == 0)
	{
		if (tokeners)
		{
			cmd_add = tokeners[0];
			cpy_comm = handle_way (cmd_add);
			val = exe(cpy_comm, tokeners, envp);
			if (val == -1)
				perror("hvd");
		}
	}
	else
	{
		wait(&status);
	}
}
