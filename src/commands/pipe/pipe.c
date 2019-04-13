/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** pipes
*/

#include "my.h"

int handle_exec(char ***args, char **strings, shell_t *shell, int pipefd[])
{
    pid_t child = fork();
    int status = 0;

    if (!child) {
        dup2(pipefd[0], 0);
        close(pipefd[1]);
        seek_command(strings[1], args[1], shell);
    }
    else {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        seek_command(strings[0], args[0], shell);
    }
    return (0);
}

int handle_pipe(char **strings, shell_t *shell)
{
    char ***args = get_arguments(strings);
    pid_t all;
    pid_t child;
    int pipefd[2];
    int status = 0;

    pipe(pipefd);
    all = fork();
    if (!all) {
        handle_exec(args, strings, shell, pipefd);
        exit(0);
    } else {
        close(pipefd[1]);
        close(pipefd[0]);
        waitpid(all, &status, WUNTRACED);
    }
    return (0);
}

int pipe_loop(char ***args, shell_t *shell)
{
    return (0);
}
