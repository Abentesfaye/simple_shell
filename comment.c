#include"main.h"

/**
 * edit_comment - handles comment
 * @enter: input string or command
 * Return: a comment handled input
 */

char * edit_comment(char * enter)
{
	int i = 0, n = 0;

	for (; enter[i]; i++)
	{
		if (enter[i] == '#')
		{
			if (i == 0)
			{
				free(enter);
				return (NULL);
			}
			if (enter[i - 1] == ' ' || enter[i - 1] == '\t' || enter[i - 1] == ';')
				n = i;
		}
	}
	if (n != 0)
	{
		enter = realloc(enter, n + 1);
		enter[n] = '\0';
	}
	return (enter);
}
