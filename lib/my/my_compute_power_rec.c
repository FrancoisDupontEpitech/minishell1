/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (nb == 0)
        return (0);
    if (nb == 1)
        return (1);
    if (p > 1)
        return (nb * my_compute_power_rec(nb, p - 1));
    return (nb);
}
