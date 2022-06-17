/*
** EPITECH PROJECT, 2022
** go_to_a_home_directory.c
** File description:
** go_to_a_home_directory
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

int go_in_folder_from_home(char *pathname, node_t **list_env)
{
    char *homepath = NULL;
    int size = 0;

    homepath = my_getenv("HOME", list_env);
    if (homepath != NULL) {
        size = chdir(homepath);
        if (size == -1)
            return EXIT_ERROR;
        pathname = pathname + 2;
        if (pathname != NULL)
            size = chdir(pathname);
    }
    return EXIT_SUCCESS;
}

int go_to_a_home_directory(char *pathname, node_t **list_env)
{
    int size = 0;

    if (pathname[0] == '~')
        go_in_folder_from_home(pathname, list_env);
    else {
        size = chdir(pathname);
        if (size == -1)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
