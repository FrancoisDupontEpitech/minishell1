/*
** EPITECH PROJECT, 2022
** go_to_home.c
** File description:
** go_to_home
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib.h"
#include "exit.h"
#include "src.h"
#include "linked_list/double_linked_list.h"
#include "my_printf/my_printf.h"

char const *directory_error_msg = "Invalid directory\n";

int go_to_home(node_t **list_env)
{
    char *homepath = NULL;
    int size = 0;

    homepath = my_getenv("HOME", list_env);
    if (homepath == NULL)
        return EXIT_ERROR;
    size = chdir(homepath);
    if (size == -1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
