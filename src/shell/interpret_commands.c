/*
** EPITECH PROJECT, 2022
** interpret_commands.c
** File description:
** interpret_commands
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

int interpret_commands(char *arg, node_t **list_env, char **env)
{
    char **buffer_2d = NULL;
    char *arg_sanatized = sanatize_string(arg);
    
    if (str_to_2d_array(arg_sanatized, &buffer_2d, ' ') == EXIT_ERROR)
        return EXIT_ERROR;
    if (execute_command(buffer_2d, list_env) == EXIT_SUCCESS)
        return EXIT_SUCCESS;
    else {
        if (execute_program(buffer_2d, list_env, env) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    free(arg_sanatized);
    free_str_2d_array(buffer_2d);
    return EXIT_SUCCESS;
}
