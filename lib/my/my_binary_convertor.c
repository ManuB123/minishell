/*
** EPITECH PROJECT, 2018
** my_binary_convertor
** File description:
** binary convertor
*/

#include "my.h"

char *my_binary_convertor(unsigned int nb)
{
    char *res = malloc(sizeof(char) * 100);
    res = my_memset(res, '\0', 100);

    for (int i = 0; nb > 0 ; i = i + 1) {
        res[i] = (nb % 2) + '0';
        nb = nb / 2;
    }
    my_revstr(res);
    return (res);
}
