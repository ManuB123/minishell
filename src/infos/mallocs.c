/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** do all the mallocs
*/

#include "my.h"

char **realloc_tab(char **tab, char *new_line)
{
    int i = 0;
    char **new_tab = malloc(sizeof(char *) * (get_indexes(tab) + 1));

    if (new_tab == NULL)
        return NULL;
    for (; tab[i] != NULL; i++)
        new_tab[i] = tab[i];
    new_tab[i] = new_line;
    new_tab[i + 1] = NULL;
    return new_tab;
}

char **malloc_array(char **dup_env, int index)
{
    dup_env[1] = malloc(sizeof(char) * 100);
    for (int i = 1; i != index + 1; i++) {
        dup_env[i] = malloc(sizeof(char) * 50);
        if (dup_env[i] == NULL)
            exit(84);
    }
    return (dup_env);
}

char *my_calloc(int size)
{
    char *res = malloc(sizeof(char) * size);

    if (res == NULL)
        exit(MALLOC_FAILED);
    for (int i = 0; i != size; i++)
        res[i] = '\0';
    return (res);
}

char **malloc_args(char **args, char *binary, char *line, int spaces)
{
    args = malloc(sizeof(char *) * (spaces + 2) * 2);
    for (int k = 0; k != spaces + 3; k++)
        args[k] = malloc(sizeof(char) * my_strlen(line) + 1);
    args[0] = binary;
    return (args);
}

char **get_replacement_env(shell_t *shell)
{
    char **env_dup = malloc(sizeof(char *) * 4);
    char *pwd = malloc(sizeof(char) * 100);

    pwd = getcwd(pwd, 100);
    if (env_dup == NULL)
        exit(MALLOC_FAILED);
    for (int i = 0; i != 3; i++) {
        env_dup[i] = malloc(sizeof(char) * 100);
        if (env_dup[i] == NULL)
            exit(MALLOC_FAILED);
    }
    env_dup[0] = my_strcat("PWD=", pwd);
    env_dup[1] = "VENDOR=unknow";
    env_dup[2] = "OSTYPE=linux";
    env_dup[3] = NULL;
    shell->skip = 1;
    return (env_dup);
}
