/*
** EPITECH PROJECT, 2022
** minishell1.c
** File description:
** minishell1
*/

#include "lib.h"
#include "my_printf/my_printf.h"
#include "exit.h"
#include "src.h"

int minishell1(int ac, char **av, char **env)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == EXIT_SUCCESS) {
        display_help();
        return EXIT_SUCCESS;
    }
    start_shell(env);
    return EXIT_SUCCESS;
}
