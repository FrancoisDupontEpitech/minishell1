/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb == 1)
        return (1);
    while (i < nb) {
        if (i * i == nb)
            return (i);
        i++;
    }
    return (0);
}
