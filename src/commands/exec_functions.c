/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** exec functions
*/

#include "my.h"

static void print_log_name(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (!my_strcmpn(env[i], "LOGNAME", 7)) {
            for (int j = 8; env[i][j] != '\0'; j++)
                my_putchar(env[i][j]);
            return;
        }
    }
    my_putstr("Unknown");
}

static void print_pwd(void)
{
    int slash = 0;
    int slash_cpy = 0;
    char *pwd = malloc(100);
    pwd = getcwd(pwd, 100);
    for (int j = 0; pwd[j] != '\0'; j++) {
        if (pwd[j] == '/')
            slash++;
    }
    for (int i = 0; pwd[i] != '\0'; i++) {
        if (pwd[i] == '/')
            slash_cpy++;
        else if (slash_cpy >= slash)
            my_putchar(pwd[i]);
    }
}

static void print_display(char **env)
{
    my_putchar('/');
    print_log_name(env);
    my_putstr(" | ");
    print_pwd();
    my_putchar('\\');
    my_putstr(" $> ");
}

void exec_functions(shell_t *shell)
{
    char *line = NULL;
    char **args = {NULL};
    char **commands = {NULL};

    print_display(shell->env_dup);
    line = getnewline(shell);
    commands = get_commands_from_input(line, shell);
    list_functions(commands, args, shell);
    free_utility(line, args);
}
