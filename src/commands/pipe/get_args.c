/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** abc
*/

#include "my.h"

char ***get_arguments(char **strings)
{
    int index = get_indexes(strings);
    char ***args = malloc(sizeof(char **) * (index * 2));
    int indexes[] = {0, 0};

    if (args == NULL)
        exit(84);
    for (; indexes[0] != index; indexes[0]++, indexes[1]++)
        args[indexes[0]] = get_args(strings[indexes[0]]);
    return (args);
}
