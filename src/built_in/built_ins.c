/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** contain other built ins
*/

#include "my.h"

int check_other_functions(char *string, shell_t *shell, char **args)
{
    if (my_strcmp(string, "echo") == 0) {
        my_echo(shell, args);
        return (1);
    }
    return (0);
}

char *get_name(char *env_str)
{
    char *res = malloc(sizeof(char) * my_strlen(env_str));
    int i = 0;

    if (res == NULL)
        exit(84);
    for (; env_str[i] != '\0'; i++) {
        if (env_str[i] == '=') {
            res[i] = '\0';
            break;
        }
        res[i] = env_str[i];
    }
    return (res);
}
