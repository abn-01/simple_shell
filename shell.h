#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int get_prompt(void);
void getline_error_handler(char *, int);
char **word_split(char *str, char *delim);
int no_of_args(char *str, char *delim);
void free_grid(char **grid, int height);
char *_strdup(char *str);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_getenv(char *var, char **env);
char *_strconcat(char *str1, char *str2);
char **waymaker(int *i, char **env);
char **abs_path(char *token[], char **env);
int file_check(char *tokens[], char **env);
int exec_builtin(char **, char **, char *, char **);
int our_exit(char **tok, char **env, char **);
int print_env(char **, char **env, char **);
int stringcomp(char *, char *);
int our_execve(char *tokens[], char *environ[], char *fn);
/**
 * struct get_inbuilt - holds a string and a function pointer
 * @cmd: command
 * @func: pointer to function corresponding to command
 */
typedef struct get_inbuilt
{
	char *cmd;
	int (*func)(char **tokens, char **env, char **);
} get_func;
void cmd_not_found_error(char *argv, char *token);
int _fork(char **tokens, char **env, char **argv, char *filename);
char arg_count(int);
void illegal_num_error(char **tok, char **argv);

#define MAX_INPUT_LENGTH 1024
#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100
#define BUFFER_SIZE 1024
#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 1000
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 100
#define DELIMITERS " \t\r\n\a"

int execute_command(char **args)
char *replace_variables(char *command)
int execute_command(char *command)
char *_getline(void)
int cd_builtin(char **args, char **envp)
int execute_command(char *command)
int main(int argc, char *argv[])
void print_exit_status(int exit_status)
int execute_command(char *command)
void handle_sigint(int signum);
void parse_input(char *input, char **args);
void execute_command(char **args);
void handle_builtin_commands(char **args);
int check_command_exists(const char *command, char *path);
void print_error_message(const char *command);
void setenv_command(char *variable, char *value);
void unsetenv_command(char *variable);
void print_exit_status(int exit_status);
void print_all_aliases(void);
void print_alias_value(char *alias_name);
void define_alias(char *alias_name, char *alias_value);


#endif
