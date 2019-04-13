/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1's header
*/

#ifndef my_h
#define my_h

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "macros.h"

typedef struct shell {
    char **b_envp;
    char **env_dup;
    char **path;
    char *home;
    char *base_line;
    int skip;
    int return_value;
    int n_read;
    int command_lenght;
    int dir_error;
    int errno_value;
} shell_t;

#include "tree.h"

    /* src */

        /* commands */

        int check_redirections(char **, shell_t *, char *);
        int handle_pipe(char **, shell_t *);
        void exec_functions(shell_t *);
        int get_semis(char *);
        char **get_commands_from_input(char *, shell_t *);
        int execute_command(char *, char **, shell_t *, char *);
        int get_spaces(char *);
        char *get_bin(char *);
        char **get_args(char *);
        char *getnewline(shell_t *);
        int is_a_wave(char *, char **, shell_t *);
        void check_status(int, shell_t *);
        char *get_home(char **);
        void print_error(char *, shell_t *);
        int is_valid_input(char *, shell_t *, char **, char *);
        char *check_aliases(char *);
        int is_completed(char *, char **, shell_t *);
        int handle_redirections(char **, shell_t *);
        char ***get_arguments(char **);
        int list_functions(char **, char **, shell_t *);
        int seek_command(char *, char **, shell_t *);

        /* built_in */

        int check_other_functions(char *, shell_t *, char **);
        int my_echo(shell_t *, char **);
        int functions(char *, shell_t *, char **);
        char *update_wave(char *, shell_t *);
        int is_a_binary(char *, char **, shell_t *);
        char **remove_index(char *, shell_t *);
        char **fill_env(char **, char *, char *, shell_t *);
        void my_exit(char **, shell_t *);
        char *get_name(char *);
        char *find_old_pwd(shell_t *);
        int my_cd(shell_t *, char **);
        int my_unsetenv(shell_t *, char **);

        /* infos */

        void update_shell(shell_t *, char *);
        char **malloc_args(char **, char *, char *, int);
        char **get_replacement_env(shell_t *);
        char **malloc_array(char **, int);
        void free_tab(char **);
        void free_utility(char *, char **);
        void free_shell(shell_t *);
        void update_path(char *, char *, shell_t *);
        int check_strings(char **);
        int setenv_err(void);
        char *my_calloc(int);
        int get_exit_value(char *, shell_t *);
        char *get_pwd(void);
        int update_env_by_str(shell_t *, char *, char *);
        char **realloc_tab(char **, char *);

        /* setup */

        shell_t *get_struct(char **);
        int get_indexes(char **);
        void fill_path(shell_t *, char **);
        void remove_oldpwd(shell_t *);

        /* unused */

        char **add_ls_color(char **);
        char **add_endline(char **);

    /* lib */

int my_strcmp(char *const str, char *const cmp);
int my_getnbr(char *str);
void my_putchar_err(char c);
int my_putstr_err(char const *str);
int my_strcmpn(char *const str, char *const cmp, int n);
char *my_strcat(char *dest, char const *src);
int my_putstr_octal(char const *str);
char *my_strcat_env(char *dest, char const *src);
char *my_binary_convertor(unsigned int nb);
int my_printf(const char *str, ...);
void get_addr_ptr(char *str);
char *my_revstr(char *str);
char *my_strclean(char *line);
void my_put_nbr(int nb);
char *my_memset(char *res, char c, int size);
short *decimal_to_binary(int number);
int my_strlen(char const *str);
int my_getnbr(char *const str);
char *my_itoa(int number);
char *my_replace(char *str, char target, char replace);
void my_octal_convertor(unsigned int nb);
void my_hex_convertor(unsigned int nb);
void my_hex_convertor_min(unsigned int nb);
void get_addr_ptr(char *str);
int check_null_ptr(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif /* !my.h */
