/*
** EPITECH PROJECT, 2022
** bs my hunter
** File description:
** my_put
*/

#include <unistd.h>

void my_putchar(int c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    if (!(*str))
        return;
    my_putchar(*str++);
    my_putstr(str);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar('0' + nb);
        return;
    }
    my_put_nbr(nb / 10);
    my_putchar('0' + nb % 10);
}
