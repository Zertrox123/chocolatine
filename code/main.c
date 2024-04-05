/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-omar.joudi
** File description:
** main.c
*/

#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/my.h"

static int detect_space(char *str, char tab)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == tab)
            x++;
    }
    return x;
}

static int get_longueur(char *buffer, int i, char tab)
{
    int p = i;
    int acc = 0;

    for (; buffer[p] != tab && buffer[p] != '\0'; p++)
        acc++;
    return acc;
}

char **strtoc(char *buffer, char del)
{
    char **tab = malloc(sizeof(char *) * (detect_space(buffer, del) + 2));
    int x = 0;
    int j = 0;

    if ((detect_space(buffer, del) + 1) == 1) {
        tab[0] = buffer;
        return tab;
    }
    buffer[my_strlen(buffer) + 1] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++) {
        tab[x] = malloc(sizeof(char) * my_strlen(buffer));
        for (; buffer[i] != del && buffer[i] != '\0'; j++){
            tab[x][j] = buffer[i];
            i++;
        }
        tab[x][j] = '\0';
        j = 0;
        x++;
    }
    return tab;
}

static void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
}

static int verif_command(char **arg, char **stock)
{
    char **temp;

    for (int i = 0; arg[i] != NULL; i++) {
        temp = actu_command(arg, i);
        if (my_strncmp(temp[0], "env\n", 3) == 0)
            print_env(stock);
        if (my_strncmp(temp[0], "cd", 2) == 0)
            set_cd(temp, stock);
        else
            exec_bin(temp, stock, arg);
    }
}

int main(int argc, char **argv, char **env)
{
    char *str = NULL;
    char **arg;
    ssize_t reading = 0;
    ssize_t input;

    while (1) {
        if (isatty(0) == 0) {
            input = getline(&str, &reading, stdin);
            arg = strtoc(str, ';');
            verif_command(arg, env);
            return 0;
        }
        my_putstr("$> ");
        input = getline(&str, &reading, stdin);
        arg = strtoc(str, ';');
        if (my_strcmp(arg[0], "exit\n") == 0)
            return 0;
        else
            verif_command(arg, env);
    }
}
