/*
** EPITECH PROJECT, 2021
** src.h
** File description:
** src
*/

#ifndef SRC_H_
    #define SRC_H_
    #include "linked_list/double_linked_list.h"

void display_help(void);
int minishell1(int ac, char **av, char **env);
int start_shell(char **env);
int count_args(char **args);
int interpret_commands(char *arg, node_t **list_env, char **env);
char *my_getenv(const char *name, node_t **list_env);
int do_cd(char *pathname, node_t **list_env);
int go_to_home(node_t **list_env);
int go_to_old_path(node_t **list_env);
int go_to_a_home_directory(char *pathname, node_t **list_env);
void do_exit(char *arg);
void do_env(node_t **list_env);
int convert_env_to_envlist(char **env, node_t **list_env);
int do_setenv(node_t **list_env, char *name, char *value);
int do_unsetenv(node_t **list_env, char *name);
char *sanatize_string(char *str);
int display_actual_path(void);
int isatty_display_path(int fd);
int execute_command(char **args, node_t **list_env);
int execute_program(char **args, node_t **list_env, char **env);
int get_str_sanatized_size(char *str);
void remove_all_extra_spaces(char *buffer, char *str, int start, int end);
int get_string_start(char *str);
int get_string_end(char *str);

#endif /* !SRC_H_ */
