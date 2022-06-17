/*
** EPITECH PROJECT, 2022
** go_to_old_path.c
** File description:
** go_to_old_path
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"
#include "exit.h"
#include "src.h"
#include "linked_list/double_linked_list.h"

int go_to_old_path(node_t **list_env)
{
    char *old_path = my_strdup(my_getenv("OLDPWD", list_env));
    char *cur_path = my_strdup(my_getenv("PWD", list_env));
    int size = 0;

    if (old_path == NULL || cur_path == NULL)
        return EXIT_MALLOC;
    size = chdir(old_path);
    if (size == -1)
        return EXIT_ERROR;
    do_setenv(list_env, "OLDPWD", cur_path);
    do_setenv(list_env, "PWD", old_path);
    free(old_path);
    free(cur_path);
    return EXIT_SUCCESS;
}
