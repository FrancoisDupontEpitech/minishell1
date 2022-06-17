/*
** EPITECH PROJECT, 2022
** do_cd.c
** File description:
** do_cd
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
#include "linked_list/double_linked_list.h"
#include "my_printf/my_printf.h"

int set_path(char *variable_env, node_t **list_env)
{
    char *path = NULL;

    path = getcwd(NULL, 0);
    if (path != NULL) {
        if (do_setenv(list_env, variable_env, path) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int do_cd(char *pathname, node_t **list_env)
{
    if (pathname != NULL && my_strcmp(pathname, "-") == 0)
        return go_to_old_path(list_env);
    if (set_path("OLDPWD", list_env) == EXIT_ERROR)
        return EXIT_ERROR;
    if (pathname == NULL) {
        if (go_to_home(list_env) == EXIT_ERROR)
            return EXIT_ERROR;
    } else {
        if (go_to_a_home_directory(pathname, list_env) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    if (set_path("PWD", list_env) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
