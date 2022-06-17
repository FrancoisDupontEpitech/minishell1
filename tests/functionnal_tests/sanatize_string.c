/*
** EPITECH PROJECT, 2022
** sanatize_string.c
** File description:
** sanatize_string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "exit.h"
#include "src.h"
#include "unit_tests.h"

Test(sanatize_string, remove_all_extra_space, .init = redirect_all_std)
{
    char *src = "Bonjour, je suis un test";
    char *output = "Bonjour, je suis un test";
    char *dest = NULL;
        
    dest = sanatize_string(src);
    my_putstr(output);
    cr_assert_stdout_eq_str(output);
}
