/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** seek commands
*/

#include "my.h"

int seek_command(char *string, char **args, shell_t *shell)
{
    char *bin = get_bin(string);

    if (!functions(bin, shell, args)) {
        if (!is_a_binary(bin, args, shell) ||
            !is_valid_input(bin, shell, args, string));
        else if (my_strlen(string) > 0)
            print_error(bin, shell);
    }
}
