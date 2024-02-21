#ifndef MAIN_H
#define MAIN_H
#include<signal.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "shell.h"

#define DELIM " \t\n\r;&"
#define BUFFER_SIZE 1024
#define BUF_size 60

/**
 * program list - linked list for the builtins
 * and their functions
 * @instruction: the buitins
 * @projection: the function pointer
 */
typedef program list
{
	char * instruction;
	int (*projection)(void);
} list_t;

/**
 *struct block - contains a builtin string and related function
 *@stack: the builtin command flag
 *@foll: the function
 */
typedef struct block
{
	char * stack;
	int (*foll)(info_t *);
} block_table;
/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @pro: The name of the builtin command.
 * @after: A function pointer to the builtin command's function.
 */
typedef struct function_s
{
	char *pro;
	int (*after)(char **argv, char **front);
} function_t;

/**
 * struct changer_s - A new struct defining coder.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @functions: A pointer to another struct coder_s.
 */
typedef struct changer_s
{
	char *name;
	char *value;
	struct changer_s *functions;
} changer_t;

/* coder linked list */
coder_t * coder;

extern char **environ;
int execute(char **tokens);
char *handle_path(char *line);
void execu(char **tokens);
char *handle_comment(char *input);
char *read_cmd(FILE *fp);
void print_prompt(struct stat buffer, int fd);
char *_getenv(const char *envt, char **environ);
char **parse_command(char *line);
char *read_input(char *command);
char **handle_separation(char *line);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int cmp_string(const char *env, const char *envt);
void file_read(char *file, char **args);
int hsh_env(void);
int hsh_exit(void);

/* Bold Helpers */
list_t *get_path_dir(char *path);
int execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);

/* Encode Helpers */
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);

/* Character functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Builtins */
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);

/* Builtin Helpers */
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/* Error Correction */
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* Linkedlist Helpers */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
#endif
