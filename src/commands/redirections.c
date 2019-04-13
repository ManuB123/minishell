/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** handle redirections / pipes
*/

#include "my.h"

static int is_a_pipe(char *string)
{
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '|')
            return (1);
        if (string[i] == '>'&& string[i + 1] != '>')
            return (2);
        else if (string[i] == '>'&& string[i + 1] == '>')
            return (3);
        if (string[i] == '<' && string[i + 1] != '<')
            return (4);
        else if (string[i] == '<' && string[i + 1] == '<')
            return (5);
    }
    return (0);
}

static int get_pipes(char *string)
{
    int pipes = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        string[i] == '|' ? pipes++ : pipes;
        string[i] == '>' && string[i + 1] != '>' ? pipes++ : pipes;
        string[i] == '<' && string[i + 1] != '<' ? pipes++ : pipes;
    }
    return (pipes);
}

static char **malloc_arr(char *string)
{
    int pipes = get_pipes(string) + 1;
    char **res = malloc(sizeof(char *) * pipes + 10);

    if (res == NULL)
        exit(MALLOC_FAILED);
    for (int i = 0; i != pipes; i++) {
        res[i] = malloc(sizeof(char) * my_strlen(string) + 1);
        if (res[i] == NULL)
            exit(MALLOC_FAILED);
    }
    res[pipes] = NULL;
    return (res);
}

static char **divide_string(char *string, char cara)
{
    char **res = malloc_arr(string);
    int index1 = 0;
    int index2 = 0;
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++, index2++, count++) {
        if (string[i] == cara) {
            res[index1][index2] = '\0';
            index1++;
            index2 = -1;
        } else
            res[index1][index2] = string[count];
    }
    res[index1][index2] = '\0';
    for (int i = 0; i <= index1; i++)
        res[i] = my_strclean(res[i]);
    return (res);
}

int check_redirections(char **args, shell_t *shell, char *base_line)
{
    int pipe = is_a_pipe(base_line);
    char **strings = {NULL};
    (void) args;

    if (pipe == 1) {
        strings = divide_string(base_line, '|');
        handle_pipe(strings, shell);
        return (1);
    } else if (pipe == 2) {
        strings = divide_string(base_line, '>');
        handle_redirections(strings, shell);
        return (1);
    } if (pipe == 4) {
        strings = divide_string(base_line, '<');
        handle_input(strings, shell);
        return (1);
    }
    return (0);
}
