/*
** EPITECH PROJECT, 2022
** count_args.c
** File description:
** count_args
*/

#include <stddef.h>

int count_args(char **args)
{
    int count = 0;

    while (*args != NULL) {
        count++;
        args++;
    }
    if (count > 0)
        count--;
    return count;
}
