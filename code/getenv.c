/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-omar.joudi
** File description:
** cd.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include "../include/my.h"

char *pwd_get_env(char **env)
{
    char *buffer = malloc(sizeof(char) * PATH_MAX);

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'W'
        && env[i][2] == 'D' && env[i][3] == '='){
            getcwd(buffer, PATH_MAX);
            env[i] = my_strcat("PWD=", buffer);
        }
    }
}

char *home_get_env(char **env)
{
    char *buffer = malloc(sizeof(char) * PATH_MAX);

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
        && env[i][3] == 'E' && env[i][4] == '='){
            buffer = env[i];
            return buffer;
        }
    }
}

char *home_set_env(char **env)
{
    char *buffer = malloc(sizeof(char) * PATH_MAX);

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
        && env[i][3] == 'E' && env[i][4] == '='){
            getcwd(buffer, PATH_MAX);
            env[i] = my_strcat("HOME=", buffer);
        }
    }
}

char *path_get_env(char **env)
{
    char *buffer = malloc(sizeof(char) * PATH_MAX);

    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H' && env[i][4] == '='){
            buffer = env[i];
            return buffer;
        }
    }
}

char *redirect(char *obj, char **env)
{
    char *result;

    if (my_strlen(obj) == 3) {
        if (obj[0] == 'P' && obj[1] == 'W' && obj[2] == 'D') {
            result = pwd_get_env(env);
        }
    }
}
