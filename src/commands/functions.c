/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** abcd
*/

#include "my.h"

int list_functions(char **commands, char **args, shell_t *shell)
{
    char *bin = NULL;

    for (int i = 0; i != shell->command_lenght; i++) {
        commands[i] = check_aliases(commands[i]);
        bin = get_bin(commands[i]);
        args = get_args(commands[i]);
        if (!functions(bin, shell, args)) {
            if (!is_a_binary(bin, args, shell) ||
                !is_valid_input(bin, shell, args, commands[i]));
            else if (my_strlen(commands[i]) > 0)
                print_error(bin, shell);
        }
    }
}
