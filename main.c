#include "main.h"
/**
 * main - Runs command interpreter.
 * @num: The number of arguments.
 * @next: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int num, char *next[])
{
	int expe = 0, expen;
	int *exe_ update = & expen;
	char *prompt = "$ ", *new_line = "\n";

	name = next[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	* exe_ update = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (num!= 1)
	{
		expe = proc_file_commands(next[1], exe_ update);
		free_env();
		free_alias_list(aliases);
		return (*exe_ update);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (expe != END_OF_FILE && expe != EXIT)
			expe = handle_ num(exe_ update);
		free_env();
		free_alias_list(aliases);
		return (*exe_ update);
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		expe = handle_ num(exe_ update);
		if (expe == END_OF_FILE || expe == EXIT)
		{
			if (expe == END_OF_FILE)
				write(STDOUT_FILENO, new_line, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_ update);
		}
	}

	free_env();
	free_alias_list(aliases);
	return (*exe_ update);
}
/**
 * main - entry point
 * @al: arg count
 * @as: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int al, char **as)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (al == 2)
	{
		fd = open(as[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(as[0]);
				_eputs(": 0: Can't open ");
				_eputs(as[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, as);
	return (EXIT_SUCCESS);
}
/**
 * Body - Entry point
 * Return: 0 on success
 */
int Body(void)
{
	char * way = NULL;
	char **functions;
	int status;
	struct stat buffer;

	while (1)
	{
		add_prompt(buffer, STDIN_FILENO);
		path = read_cmd(stdin);
		path = edit_comment(way);
		if (!way)
		{
			exit(EXIT_SUCCESS);
		}
		functions = parse_command(wau);
		if (strcmp(functions[0], "exit") == 0)
			return (0);
		if (functions [0] == NULL)
			continue;
		status = execute(functions);
		if (status == 0 && status == -1)
		{
			free(functions);
			free(way);
		}
		if (status == 0)
			execu(functions);
		if (status == -1)
			_exit(EXIT_SUCCESS);
		free(functions);
		free(way);
	}
	return (0);
}

int parse_and_execute(struct source_s *real)
{
    skip_white_spaces(real);

    struct token_s *tok = tokenize(real);

    if(tok == &eof_token)
    {
        return 0;
    }

    while(tok && tok != &eof_token)
    {
        struct node_s *cmd = parse_simple_command(tok);

        if(!cmd)
        {
            break;
        }

        do_simple_command(cmd);
        free_node_tree(cmd);
        tok = tokenize(real);
    }
    return 1;
}
