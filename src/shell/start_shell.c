/*
** EPITECH PROJECT, 2022
** start_shell.c
** File description:
** start_shell
*/

#include "lib.h"
#include "my_printf/my_printf.h"
#include "linked_list/double_linked_list.h"
#include "src.h"
#include "exit.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int start_shell_prerequisites(char **env, node_t **list_env, int fd)
{
    if (convert_env_to_envlist(env, list_env) == EXIT_ERROR)
        return EXIT_ERROR;
    if (isatty_display_path(fd) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static void handle_getline(int nread, char **line, node_t **list_env, char **env)
{
    if (nread == -1) {
        my_putstr("NREAD -1\n");
        exit(84);
    }
    if (nread > 1) {
        (*line)[nread - 1] = '\0';
        interpret_commands(*line, list_env, env);
    }
}

int start_shell(char **env)
{
    int fd = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    node_t *list_env = NULL;

    if (start_shell_prerequisites(env, &list_env, fd) == EXIT_ERROR)
        return EXIT_ERROR;
    while ((nread = getline(&line, &len, stdin)) != -1) {
        handle_getline(nread, &line, &list_env, env);
        if (isatty_display_path(fd) == EXIT_ERROR)
        return EXIT_ERROR;
    }
    free(line);
    free_list(list_env);
    return EXIT_SUCCESS;
}
