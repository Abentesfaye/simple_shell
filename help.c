#include "main.h"

/**
 *aux_help_env - built in env information help
 *
 *Return: void
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, strlen(help));
	help = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help, strlen(help));
}
/**
 *aux_help_setenv - built in setenv information help
 *
 *Return: void
 */
void aux_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, strlen(help));
	help = "Add a new defination to the environment\n";
	write(STDOUT_FILENO, help, strlen(help));
}
/**
 *aux_help_unsetenv(void)
 *
 *Return: no return
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name) \n\t";

	write(STDOUT_FILENO, help, strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, strlen(help));
}

/**
 *aux_help_general - entry point for help in builtin env
 *Return: no return
 */
void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, strlen(help));
	help = "These commands are defined internally. Type 'help' to see the list";
	write(STDOUT_FILENO, help, strlen(help));
	help = "Type 'help name' to find out more about the function 'name'. \n\n ";
	write(STDOUT_FILENO, help, strlen(help));
	help = "alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]]";
	write(STDOUT_FILENO. help, strlen(help));
	help = "[dir]\nexit: exit [n]\n env: env [option] [name-value] [command";
	write(STDOUT_FILENO, help, strlen(help));
	help = "[args]]\n setenv: setenv [variable] [value]\n ubsetenv: ";
	write(STDOUT_FILENO, help, strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, strlen(help));
}
/**
 *aux_help_exit - help information for the builtin exit
 *
 *Return: no return
 */
void aux_hep_exit(void)
{
	char help = "exit: exit [n]\n Exit shell. \n";
	write(STDOUT_FILENO, help, strlen(help));
	help = "Exits the shell with a status of N. if N is ommited, the exit";
	write(STDOUT_FILENO, help, strlen(help));
	help = "status is that of the last command excuted\n";
	write(STDOUT_FILENO, help, strlen(help));
}
