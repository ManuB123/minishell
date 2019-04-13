/*
** EPITECH PROJECT, 2019
** navy
** File description:
** issou
*/

#include "my.h"

static int is_a_space(char *line, int count)
{
    if ((line[count] == ' ' && line[count + 1] == ' ') ||
        (line[count] == '\t' && line[count + 1] == ' ') ||
        (line[count] == ' ' && line[count + 1] == '\t'))
        return (1);
    return (0);
}

char *my_strclean(char *line)
{
    int count = 0;
    int i = 0;
    char *result = my_calloc(sizeof(char) * my_strlen(line) + 10);
    for (; line[count] == ' ' || line[count] == '\t'; count++);
    for (; line[count] != '\0'; count++) {
        if (is_a_space(line, count));
        else if (line[count] == '\t' && line[count + 1] != '\t' &&
                line[count + 1] != ' ') {
            result[i] = ' ';
            i++;
        }
        else {
            result[i] = line[count];
            i++;
        }
    }
    if (i == 0);
    else if (result[i - 1] == ' ' || result[i - 1] == '\t')
        result[i - 1] = '\0';
    return (result);
}
