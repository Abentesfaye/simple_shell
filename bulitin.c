#include"main.h"

/**
 * finder - builtin execution
 * @tok: tokinized command
 * Return: the respectve function for the command name
 */

int finder(char ** tok)
{
	int update = 0;
	unsigned int lene = 0, no = 0, i = 0;

	list list[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{NULL, NULL}
	};

	if (tok[0] == NULL)
		return (1);
	lene = strlen(tok[0]);
	while ((list[no].command) != NULL)
		no++;
	for (; i < no; i++)
	{
		if (strncmp(tok[0], list[i].command, lene) == 0)
		{
			update = (list[i].fun)();
			return (update);
		}
	}

	return (0);
}
