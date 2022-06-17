/*
** EPITECH PROJECT, 2022
** test_sanatize_string.c.c
** File description:
** test_sanatize_string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "exit.h"
#include "src.h"
#include "lib.h"
#include "unit_tests.h"

Test(sanatize_string, dont_change_the_string, .init = redirect_all_std)
{
    char *src = "Bonjour, je suis un test";
    char *output = "Bonjour, je suis un test";
    char *dest = NULL;

    dest = sanatize_string(src);
    my_putstr(dest);
    cr_assert_stdout_eq_str(output);
}

Test(sanatize_string, remove_all_inter_space, .init = redirect_all_std)
{
    char *src = "Bonjour,    je       suis un test";
    char *output = "Bonjour, je suis un test";
    char *dest = NULL;

    dest = sanatize_string(src);
    my_putstr(dest);
    cr_assert_stdout_eq_str(output);
    my_putstr(dest);
}

Test(sanatize_string, remove_all_first_space, .init = redirect_all_std)
{
    char *src = "     Bonjour, je suis un test";
    char *output = "Bonjour, je suis un test";
    char *dest = NULL;

    dest = sanatize_string(src);
    my_putstr(dest);
    cr_assert_stdout_eq_str(output);
}

// Test(sanatize_string, remove_all_last_space, .init = redirect_all_std)
// {
//     char *src = "Bonjour, je suis un test     ";
//     char *output = "Bonjour, je suis un test";
//     char *dest = NULL;

//     dest = sanatize_string(src);
//     my_putstr(dest);
//     cr_assert_stdout_eq_str(output);
// }