/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** setenv
*/

#include "lib.h"
#include "exit.h"
#include "stdlib.h"
#include "linked_list/double_linked_list.h"
#include "my_printf/my_printf.h"
#include <stdlib.h>

static char *concatenate_strings(char *name, char *value, char separator)
{
    int len = my_strlen(name) + my_strlen(value) + 1;
    char *envstr = NULL;
    int c = 0;

    envstr = malloc(sizeof(char) * (len + 1));
    if (envstr == NULL)
        return NULL;
    for (int i = 0; name[i] != '\0'; i++, c++)
        envstr[c] = name[i];
    envstr[c] = separator;
    c++;
    if (value != NULL)
        for (int i = 0; value[i] != '\0'; i++, c++)
            envstr[c] = value[i];
    envstr[c] = '\0';
    return envstr;
}

static int replace_name_value(node_t **tmp, char *value)
{
    int value_len = my_strlen(value);

    free((*tmp)->value);
    (*tmp)->value = malloc(sizeof(char) * (value_len + 1));
    if ((*tmp)->value == NULL)
        return EXIT_ERROR;
    my_strcpy((*tmp)->value, value);
    return EXIT_SUCCESS;
}

static int handle_setenv_error(char *name)
{
    char tmp[my_strlen(name)];

    my_strcpy(tmp, name);
    if (is_char_alphabetic(tmp[0]) == EXIT_ERROR) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return EXIT_ERROR;
    }
    if (is_str_alphanumeric(tmp + 1) == EXIT_ERROR) {
        my_putstr_error("setenv: Variable name must contain alphanumeric characters.\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

static int insert_env(node_t *tmp, char *envstr, char *name, char *value)
{
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0) {
            replace_name_value(&tmp, value);
            free(envstr);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int do_setenv(node_t **list_env, char *name, char *value)
{
    char *envstr = NULL;
    node_t *new_node = NULL;
    node_t *tmp = *list_env;

    if (handle_setenv_error(name) == EXIT_ERROR)
        return EXIT_ERROR;
    envstr = concatenate_strings(name, value, '=');
    if (envstr == NULL)
        return EXIT_MALLOC;
    if (insert_env(tmp, envstr, name, value))
        return EXIT_SUCCESS;
    new_node = create_new_node(envstr);
    insert_at_end(list_env, new_node);
    free(envstr);
    return EXIT_SUCCESS;
}
