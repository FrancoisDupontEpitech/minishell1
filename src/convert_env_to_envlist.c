/*
** EPITECH PROJECT, 2022
** convert_env_to_envlist.c
** File description:
** convert_env_to_envlist
*/

#include "lib.h"
#include "exit.h"
#include "stdlib.h"
#include "src.h"
#include "linked_list/double_linked_list.h"
#include "my_printf/my_printf.h"

int convert_env_to_envlist(char **env, node_t **list_env)
{
    int len = get_char_array_line(env);

    *list_env = create_linked_list(len, env);
    if (*list_env == NULL)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
