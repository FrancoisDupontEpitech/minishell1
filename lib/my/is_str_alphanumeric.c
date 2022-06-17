/*
** EPITECH PROJECT, 2022
** is_str_alphanumeric.c
** File description:
** is_str_alphanumeric
*/

#include "exit.h"
#include "lib.h"

int is_str_alphanumeric(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((is_char_alphabetic(str[i]) == EXIT_ERROR) && 
        (is_char_numeric(str[i]) == EXIT_ERROR))
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
