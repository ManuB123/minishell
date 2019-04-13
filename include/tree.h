/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** binary_trees
*/

#ifndef tree_h
#define tree_h

typedef struct tree {
    struct tree *prev;
    struct tree *next;
    char *str;
} tree_t;

#endif /* !tree.h */
