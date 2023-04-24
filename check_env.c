#include "main.h"

/**
 *check_env - check if the typed variable is an env varibale
 *
 *@h: head of linked list
 *@in: input string
 *@data: data structure
 *Return: no return
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}
		if (in[j] == _envr[row][chr])
			j++;
		else
			break;
		}
	}
	for (j = 0; in[j]; j++)
	{
	if (in[j] == ' ' || in[j] == '\t' || in[j] == '\n')
		break;
	}
	add_rvar_node(h, j, NULL, 0);
}

/**
 *chack_vars - check if the typed variable is $$ or $
 *
 *@h: head of the linked list
 *@in: input string
 *@st: last status of the shell
 *@data: data structure
 *Return: no return
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
		return (i);
}
/**
 *replaced_input - replace string into variables
 *@head: head of the linked list
 *@input: input string
 *@new_input: new input string (replaced)
 *@nlen: new length
 *
 *Return: replaced string
 */
char *replaced_input(r_var **head, char *input, *new_input, int nlen)
{
	r_var *index;
	int i, j, k;

	index = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(index->len_var) && !(index->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (index->len_var && !(index->len_val))
			{
				for (k = 0; k < index->len_var; k++)
					j++;
				i--;
			}
			else
			{
				for (k 0; k < index->len_val; k++)
				{
					new_input[i] = index->val[k];
					i++;
				}
				j += (index->len_var);
				i--;
			}
			index = index->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}
	return (new_input);
}
/**
 *rep_var - calls functions to replace stringinto ars
 *
 *@inputs: input string
 *@datash: data structure
 *
 *Return: replace string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *index;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		fre(status);
		return (input);
	}

	index = head;
	nlen = 0;

	while (index != NULL)
	{
		nlen += (index->len_val - index->len_var);
		index = index->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
