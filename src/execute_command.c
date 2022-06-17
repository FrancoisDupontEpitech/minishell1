/*
** EPITECH PROJECT, 2022
** execute_command.c
** File description:
** execute_command
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"
#include "exit.h"
#include "src.h"
#include "my_printf/my_printf.h"

static int parse_condition_setenv(char **args, node_t **list_env)
{
    if (get_char_array_line(args) == 3)
        do_setenv(list_env, args[1], args[2]);
    else if (get_char_array_line(args) == 2)
        do_setenv(list_env, args[1], NULL);
    else
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int parse_condition_unsetenv(char **args, node_t **list_env)
{
    if (get_char_array_line(args) != 2)
        return EXIT_ERROR;
    do_unsetenv(list_env, args[1]);
    return EXIT_SUCCESS;
}

static int loop_hover_commands(int i, char **args, node_t **list_env)
{
    switch (i) {
        case 0:
        return do_cd(args[1], list_env);
        case 1:
        do_exit(args[1]);
        return EXIT_SUCCESS;
        case 2:
        do_env(list_env);
        return EXIT_SUCCESS;
        case 3:
        return parse_condition_setenv(args, list_env);
        case 4:
        return parse_condition_unsetenv(args, list_env);
    }
    return EXIT_ERROR;
}

int execute_command(char **args, node_t **list_env)
{
    char const *commands[] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
    int i = 0;

    while (commands[i] != NULL) {
        if (my_strcmp(args[0], commands[i]) == 0)
            break;
        i++;
    }
    return loop_hover_commands(i, args, list_env);   
}
