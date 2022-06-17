/*
** EPITECH PROJECT, 2022
** is_char_numeric.c
** File description:
** is_char_numeric
*/

#include "exit.h"

int is_char_numeric(char c)
{
    if (c < '0' || c > '9')
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
