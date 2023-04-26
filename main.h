#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/*points to an array of pointer to string called the "environment" .*/
 extern char **environ;


 /**
  * struct data strut that contains all relevant data on runtime
  * @av: argument vector
  * @input: command line written by user
  * @status: last status of the shell
  * @counter: lines counter
  * @_enviro: environmental variable
  * @pid: process ID of the shell
  * 
  */
 typedef struct data
 {
    char **av;
    char *input;
    char **args;
    int status;
    char **_environ;
    char *pid;
 } data_shell;

 /**
  * struct line_list_s - single linked list
  * @line: command line
  * Description: single linked list tp store command lines
  * 
  */
 typedef struct line_list_s
 {
    char *line;
    struct line_list_s *next;
 } line_list;

 /**
  * struct r_var_list - single linked list 
  * @len_var: length of the variable
  * @val: value of the variable
  * @len_val: length of the value
  * @next: next node
  * Description: single linked list to stor variable
  * 
  */

 typedef struct r_var_list
 {
    int len_var;
    char *val;
    int len_val;
    struct r_var_list *next;
 } r_var;
 /**
  * struct builtin_s - builtin struct for command args.
  * @name: the name of the command builtin 
  * @f: data type pointer function
  * 
  */

 typedef struct builtin_s
 {
    char *name;
    int (*f)(datashell *datash)
 } builtin_t;
 
 int cmp_env_name(const char *nenv, const *name);
 char *_getenv(const char *name, char **_environ);
 int _env(data_shell *datash);
 int exec_line(data_shell *datash);
 char *read_line(int *i_eof);
 void free_rvar_list(r_var **head);
 r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);
 void rev_string(char *s);
 char *error_path_126(data_shell *datash);
 char *error_env(data_shell *datash);
 void aux_help_cd(void);
 void aux_help_alias(void);
 void aux_help(void);
 void free_line_list(line_list **head);
 line_list *add_line_node_end(line_list **head, char *line);
 void free_sep_list(sep_list **head);
 sep_list *add_sep_node_end(sep_list **head, char sep);
 char *without_comment(char *in);
 void shell_loop(data_shell *datash);
 char *error_exit_shell(data_shell *datash);
 char *error_not_found(data_shell datash);
 char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str);
 int get_len(int n);
 char *aux_itoa(int n);
 int _atoi(char *s);
 void cd_dot(data_shell *datash);
 void cd_to(data_shell *datash);
 void cd_previous(data_shell *datash);
 void cd_to_home(data_shell *datash);
 int repeated_char(char *input, int i);
 int error_sep_op(char *input, int i, char last);
 int first_char(char *input, int *i);
 void print_syntax_error(data_shell *datash, char *input, int i, int bool);
 int check_syntax_error(data_shell *datash, char *input);
 void check_env(r_var **h, char *in, data_shell *data);
 int check_vars(r_var **h, char *in, char *st, data_shell *data);
 char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
 char *rep_var(char *input, data_shell *datash);
 void rev_string(char *s);
 void aux_help_env(void);
 void aux_help_setenv(void);
 void aux_help_unsetenv(void);
 void aux_help_general(void);
 void aux_help_exit(void);
 int get_help(data_shell *datash);
 int exit_shell(data_shell *datash);
 int get_error(data_shell *datash, int eval);
 char *copy_info(char *name, char *value);
 void set_env(char *name, char *value, data_shell *datash);
 int _setenv(data_shell *datash);
 int _unsetenv(data_shell *datash);
 int cmp_env_name(const char *nenv, const char *name);
 char *_getenv(const char *name, char **_environ);
 int _env(data_shell *datash);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input)l;
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

#endif

