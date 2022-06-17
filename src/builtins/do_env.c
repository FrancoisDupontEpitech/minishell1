/*
** EPITECH PROJECT, 2022
** do_env.c
** File description:
** do_env
*/

#include "lib.h"
#include "exit.h"
#include "src.h"
#include "my_printf/my_printf.h"
#include "linked_list/double_linked_list.h"

void do_env(node_t **list_env)
{
    display_list(*list_env);
}
