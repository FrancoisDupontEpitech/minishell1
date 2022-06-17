/*
** EPITECH PROJECT, 2021
** str_to_2d_array.c
** File description:
** str_to_2d_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "exit.h"
#include "my_printf/my_printf.h"

int get_nbr_lines(char *str, char segment)
{
    int lines = 0;
    int ascii = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == segment) {
            lines++;
            ascii = 0;
        } else
            ascii++;
    }
    if (ascii > 0)
        lines++;
    return (lines);
}

int get_nbr_cols(char *buffer, int x, char segment)
{
    int cols_len = 0;

    while (buffer[x] != segment && buffer[x] != '\0') {
        cols_len++;
        x++;
    }
    return (cols_len);
}

int loop_hover_map(char *buffer, char ***buffer_2d, int lines, char segment)
{
    int x = 0;
    int cols = 0;

    for (int i = 0; i < lines; i++) {
        cols = get_nbr_cols(buffer, x, segment);
        (*buffer_2d)[i] = malloc(sizeof(char) * (cols + 1));
        if ((*buffer_2d)[i] == NULL)
            return (EXIT_MALLOC);
        for (int c = 0; buffer[x] != segment && buffer[x] != '\0'; c++, x++)
            (*buffer_2d)[i][c] = buffer[x];
        (*buffer_2d)[i][cols] = '\0';
        x++;
    }
    (*buffer_2d)[lines] = NULL;
    return (EXIT_SUCCESS);
}

int str_to_2d_array(char *buffer, char ***buffer_2d, char segment)
{
    int lines = get_nbr_lines(buffer, segment);

    *buffer_2d = malloc(sizeof(char *) * (lines + 1));
    if (*buffer_2d == NULL)
        return (EXIT_MALLOC);
    if (loop_hover_map(buffer, buffer_2d, lines, segment) == EXIT_ERROR)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}
