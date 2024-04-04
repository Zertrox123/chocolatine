/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-omar.joudi
** File description:
** cd.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

char **remove_space(char **arg)
{
    int j = 0;
    char **tab = malloc(sizeof(char *) * 10);

    for (int i = 0; arg[i] != NULL; i++) {
        if (my_strcmp(arg[i], " ") != 0) {
            tab[j] = arg[i];
            j++;
        }
    }
    tab[j] = NULL;
    return tab;
}

char **actu_command(char **arg, int i)
{
    char **stock = strtoc(arg[i], ' ');

    return remove_n(remove_space(stock));
}

int my_strlen(char const *str)
{
    int count = 0;

    while (*str != '\0') {
        count++;
        *str++;
    }
    return count;
}

int set_cd(char **arg, char **env)
{
    char **temp = strtoc(arg[1], '\n');

    if (temp[0][0] == '~' && chdir("/home") == 0)
        return 0;
    if (chdir(temp[0]) == 0)
        return 0;
    else
        perror("cd");
    return 0;
}
