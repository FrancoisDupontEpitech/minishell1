/*
** EPITECH PROJECT, 2022
** display_path.c
** File description:
** display_path
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf/my_printf.h"
#include "exit.h"

int display_actual_path(void)
{
    char *path = getcwd(NULL, 0);

    if (path == NULL) {
        free(path);
        return EXIT_ERROR;
    }
    my_printf("[%s]$ ", path);
    free(path);
    return EXIT_SUCCESS;
}

int isatty_display_path(int fd)
{
    if (isatty(fd) == 1) {
        if (display_actual_path() == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
