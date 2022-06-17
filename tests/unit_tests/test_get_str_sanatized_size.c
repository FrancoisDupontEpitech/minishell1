/*
** EPITECH PROJECT, 2022
** do_sanatize_str.c
** File description:
** do_sanatize_str
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "exit.h"
#include "src.h"
#include "lib.h"
#include "my_printf/my_printf.h"

Test(get_str_sanatized_size, same_len_as_src)
{
    char *src = "Bonjour, je suis un test";
    int output = get_str_sanatized_size(src);
        
    cr_assert_eq(my_strlen(src), output);
}

Test(get_str_sanatized_size, should_remove_space_at_start)
{
    char *src = "    Bonjour, je suis un test";
    char *sanatize = "Bonjour, je suis un test";
    int output = get_str_sanatized_size(src);
        
    cr_assert_eq(my_strlen(sanatize), output);
}

Test(get_str_sanatized_size, should_remove_space_at_middle)
{
    char *src = "Bonjour,     je       suis         un test";
    char *sanatize = "Bonjour, je suis un test";
    int output = get_str_sanatized_size(src);
        
    cr_assert_eq(my_strlen(sanatize), output);
}

Test(get_str_sanatized_size, should_remove_space_at_end)
{
    char *src = "Bonjour, je suis un test    ";
    char *sanatize = "Bonjour, je suis un test";
    int output = get_str_sanatized_size(src);
        
    cr_assert_eq(my_strlen(sanatize), output);
}

Test(get_str_sanatized_size, should_remove_both_at_start_and_at_end)
{
    char *src = "     Bonjour, je suis un test    ";
    char *sanatize = "Bonjour, je suis un test";
    int output = get_str_sanatized_size(src);   
    
    cr_assert_eq(my_strlen(sanatize), output);
}

Test(get_str_sanatized_size, should_remove_at_start_at_middle_and_at_end)
{
    char *src = "     Bonjour, je    suis un test    ";
    char *sanatize = "Bonjour, je suis un test";
    int output = get_str_sanatized_size(src);
         
    cr_assert_eq(my_strlen(sanatize), output);
}