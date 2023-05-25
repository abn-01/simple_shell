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

#endif
