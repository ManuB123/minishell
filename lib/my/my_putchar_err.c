/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** put a char in err output
*/

#include "my.h"

void my_putchar_err(char c)
{
    write(2, &c, 1);
}
