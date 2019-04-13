/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** abc
*/

#include "my.h"

int is_present(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++) {
        if (!my_strcmp(get_name(tab[i]), "OLDPWD"))
            return (1);
    }
    return (0);
}

static char **get_new_tab(char **tab)
{
    int index = get_indexes(tab);
    int count = 0;
    char **new_tab = malloc(sizeof(char *) * (index * 2));

    for (int i = 0; i != index; i++, count++) {
        if (!my_strcmp(get_name(tab[i]), "OLDPWD"))
            count--;
        else
            new_tab[count] = tab[i];
    }
    new_tab[count] = NULL;
    new_tab[count + 1] = NULL;
    return (new_tab);
}

void remove_oldpwd(shell_t *shell)
{
    char *args[] = {"unsetenv", "OLDPWD", NULL};

    if (is_present(shell->env_dup))
        shell->env_dup = get_new_tab(shell->env_dup);
}
