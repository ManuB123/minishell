/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** display a string in the error output
*/

#include "my.h"

int my_putstr_err(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}
