/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** check aliases
*/

#include "my.h"

static char *get_past_bin(char *str)
{
    char *new_str = my_calloc(sizeof(char) * my_strlen(str));
    int lenght = my_strlen(get_bin(str));

    for (int i = 0; str[lenght] != '\0'; i++, lenght++)
        new_str[i] = str[lenght];
    return (new_str);
}

char *check_aliases(char *str)
{
    char *new_str = get_past_bin(str);

    if (!my_strcmp(get_bin(str), "ll"))
        return (my_strcat("ls -l --color", new_str));
    if (!my_strcmp(get_bin(str), "la"))
        return (my_strcat("ls -a --color", new_str));
    if (!my_strcmp(get_bin(str), "clean"))
        return (my_strcat("rm -f *~ ", new_str));
    else
        return (str);
}
