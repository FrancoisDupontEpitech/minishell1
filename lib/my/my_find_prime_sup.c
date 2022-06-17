/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** my_find_prime_sup
*/

int my_find_prime_sup_2(int nb, int *i, int *count)
{
    while (*i < nb) {
        if (nb % *i == 0) {
            (*count)++;
            nb++;
            *i = 2;
        }
        (*i)++;
    }
    return (nb);
}

int my_find_prime_sup(int nb)
{
    int count = 0;
    int i = 2;

    if (nb == 0 || nb == 1)
        return (2);
    while (1) {
        nb = my_find_prime_sup_2(nb, &i, &count);
        if (count == 0)
            return (nb);
        count = 0;
    }
    return (0);
}
