/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** is negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    if (n < 0)
        my_putchar('N');
    return (0);
}
