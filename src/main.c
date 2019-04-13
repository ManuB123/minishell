/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main loop
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
    shell_t *shell = get_struct(env);
    (void) argv;

    if (argc != 1)
        return (84);
    signal(SIGINT, SIG_IGN);
    remove_oldpwd(shell);
    while (1)
        exec_functions(shell);
    signal(SIGINT, SIG_DFL);
    return (0);
}
