/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** execute functions
*/

#include "my.h"

int get_semis(char *line)
{
    int semis = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ';')
            semis++;
    }
    return (semis);
}

char **get_commands_from_input(char *line, shell_t *shell)
{
    int semis = get_semis(line);
    char **tab = malloc(sizeof(char *) * (semis + 1));
    int index = 0;
    int count = 0;
    shell->command_lenght = semis + 1;

    for (int i = 0; i != semis + 1; i++)
        tab[i] = malloc(sizeof(char) * my_strlen(line) + 1);
    for (int i = 0; line[i] != '\0'; i++, count++) {
        if (line[i] == ';') {
            tab[index][count] = '\0';
            index++;
            count = -1;
        } else
            tab[index][count] = line[i];
    }
    tab[index][count] = '\0';
    for (int i = 0; i <= semis; i++)
        tab[i] = my_strclean(tab[i]);
    return (tab);
}

int execute_command(char *string, char **args, shell_t *shell, char *base_line)
{
    pid_t child;
    int status = 0;

    if (check_redirections(args, shell, base_line))
        return (0);
    child = fork();
    if (!child) {
        signal(SIGINT, SIG_DFL);
        execve(string, args, shell->env_dup);
    }
    else {
        waitpid(child, &status, WUNTRACED);
        check_status(status, shell);
    }
    return (0);
}
