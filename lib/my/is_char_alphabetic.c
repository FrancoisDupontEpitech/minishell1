/*
** EPITECH PROJECT, 2022
** is_char_alphabetic.c
** File description:
** is_char_alphabetic
*/

#include "exit.h"

int is_char_alphabetic(char c)
{
    if ((c < 'a' || c > 'z') &&
        (c < 'A' || c > 'Z'))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
