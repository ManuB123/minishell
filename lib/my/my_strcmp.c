/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** compare 2 strings
*/

#include "my.h"

int my_strcmp(char *const str, char *const cmp)
{
    if (str == NULL || cmp == NULL)
        return (-1);
    if (my_strlen(str) != my_strlen(cmp))
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != cmp[i])
            return (1);
    }
    return (0);
}
