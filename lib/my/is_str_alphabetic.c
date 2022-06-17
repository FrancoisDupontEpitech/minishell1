/*
** EPITECH PROJECT, 2022
** is_str_alphabetic.c
** File description:
** is_str_alphabetic
*/

#include "lib.h"
#include "exit.h"

int is_str_alphabetic(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_char_alphabetic(str[i]) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
