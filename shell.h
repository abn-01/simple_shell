#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGUMENTS 100

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
