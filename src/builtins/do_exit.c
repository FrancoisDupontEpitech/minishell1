/*
** EPITECH PROJECT, 2022
** do_exit.c
** File description:
** do_exit
*/

#include "lib.h"
#include "exit.h"
#include "my_printf/my_printf.h"
#include <stdlib.h>
#include <stdio.h>

static const char *display_exit = "exit\n";

void do_exit(char *arg)
{
    int nb = 0;
    char *nb_str = NULL;
    
    if (arg == NULL) {
        my_putstr(display_exit);
        exit(0);
    }
    nb = my_getnbr(arg);
    nb_str = my_getstr(nb);
    if (my_strcmp(nb_str, arg) == 0) {
        free(nb_str);
        my_putstr(display_exit);
        exit(nb);
    }
    free(nb_str);
    my_putstr_error("exit: Expression Syntax.\n");
}
