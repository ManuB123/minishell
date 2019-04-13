/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** get and proces new line
*/

#include "my.h"

int get_spaces(char *line)
{
    int i = 0;
    int space = 0;

    for (; line[i] != '\0'; i++) {
        if (line[i] == ' ' && line[i + 1] != ' ' && line[i+1] != '\0')
            space++;
    }
    return (space);
}

char *get_bin(char *line)
{
    int i = 0;
    char *result = malloc(sizeof(char) * my_strlen(line) + 1);
    for (; line[i] != '\0'; i++) {
        if (line[i] == ' ')
            break;
        result[i] = line[i];
    }
    result[i] = '\0';
    return (result);
}

char **get_args(char *line)
{
    int spaces = get_spaces(line);
    char *binary = get_bin(line);
    char **args = NULL;
    int index[] = {0 , 0, 0};

    args = malloc_args(args, binary, line, spaces);
    for (; line[index[2]] != '\0'; index[2]++, index[1]++) {
        if (line[index[2]] == ' ') {
            args[index[0]][index[1]] = '\0';
            index[0]++;
            index[1] = -1;
        } else
            args[index[0]][index[1]] = line[index[2]];
    }
    args[index[0]][index[1]] = '\0';
    args[spaces + 1] = NULL;
    return (args);
}

char *getnewline(shell_t *shell)
{
    char *line = NULL;
    size_t len = 0;

    shell->n_read = getline(&line, &len, stdin);
    if (shell->n_read == -1) {
        my_putstr("exit\n");
        exit(shell->return_value);
    }
    line = my_strclean(line);
    line[my_strlen(line) - 1] = '\0';
    shell->base_line = line;
    return (line);
}
