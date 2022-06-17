/*
** EPITECH PROJECT, 2022
** do_unsetenv.c
** File description:
** do_unsetenv
*/

#include "lib.h"
#include "exit.h"
#include "stdlib.h"
#include "linked_list/double_linked_list.h"
#include "my_printf/my_printf.h"
#include <stdlib.h>

void prev_to_next(node_t **tmp, char *name)
{
    if (my_strcmp((*tmp)->name, name) == 0) {
        (*tmp)->prev->next = (*tmp)->next;
        if ((*tmp)->next != NULL)
            (*tmp)->next->prev = (*tmp)->prev;
        free(*tmp);
    }
    (*tmp) = (*tmp)->next;
}

int do_unsetenv(node_t **list_env, char *name)
{
    node_t *tmp = *list_env;

    if (tmp != NULL && my_strcmp(tmp->name, name) == 0) {
        *list_env = tmp->next;
        (*list_env)->prev = NULL;
        free(tmp);
    }
    while (tmp != NULL)
        prev_to_next(&tmp, name);
    return EXIT_SUCCESS;
}
