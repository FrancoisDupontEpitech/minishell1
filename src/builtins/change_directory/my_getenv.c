/*
** EPITECH PROJECT, 2022
** my_getenv.c
** File description:
** my_getenv
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"
#include "exit.h"
#include "src.h"
#include "linked_list/double_linked_list.h"

char *my_getenv(const char *name, node_t **list_env)
{
    node_t *tmp = *list_env;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            return tmp->value;
        tmp = tmp->next;
    }
    return NULL;
}
