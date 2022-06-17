/*
** EPITECH PROJECT, 2021
** free_all_allocation.c
** File description:
** free_all_allocation
*/

#include <stdlib.h>

void free_str_2d_array(char **arr)
{
    for (int i = 0; arr[i] != 0; i++)
        free(arr[i]);
    free(arr);
}

void free_int_2d_array(int **arr)
{
    for (int i = 0; arr[i] != 0; i++)
        free(arr[i]);
    free(arr);
}

void free_allocation(char **buffer_char_2d, int **buffer_int_2d, char *buffer)
{
    free_str_2d_array(buffer_char_2d);
    free_int_2d_array(buffer_int_2d);
    free(buffer);
}
