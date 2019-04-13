/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** sample text
*/

#include "my.h"

char *get_pwd(void)
{
    int index = 0;
    char *pwd = my_calloc(100);
    pwd = getcwd(pwd, 100);

    return pwd;
}

void update_path(char *name, char *value, shell_t *shell)
{
    (void) value;

    if (!my_strcmp(name, "PATH"))
        fill_path(shell, shell->env_dup);
}

int update_env_by_str(shell_t *shell, char *name, char *value)
{
    char *args[] = {"setenv", name, value, NULL};

    for (int index = 0; shell->env_dup[index] != NULL; index++) {
        if (!my_strcmp(get_name(shell->env_dup[index]), name)) {
            shell->env_dup[index] = my_strcat_env(name, value);
            return 0;
        }
    }
    my_setenv(shell, args);
    return 1;
}
