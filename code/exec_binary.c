/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-omar.joudi
** File description:
** exec_binary.c
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include "../include/my.h"

char **remove_n(char **arg)
{
    int i = 0;
    char **tab = malloc(sizeof(char *) * 10);
    char **stock;

    for (; arg[i] != NULL; i++) {
        stock = strtoc(arg[i], '\n');
        tab[i] = stock[0];
    }
    tab[i] = NULL;
    return tab;
}

int exec_bin2(char *one_path, char **arg, char **env, char **all)
{
    pid_t pid;
    int wait = 0;

    pid = fork();
    if (pid == -1)
        return 0;
    if (pid == 0) {
        if (is_pipe(one_path, arg, env) == 0) {
            execve(one_path, arg, env);
            exit(EXIT_SUCCESS);
        } else {
            do_pipes(one_path, all, env, found_pipe(one_path, all, env));
            exit(EXIT_SUCCESS);
        }
    } else {
        waitpid(pid, &wait, 0);
        if (WIFEXITED(wait) && WEXITSTATUS(wait) == 0)
            return 1;
    }
    return 0;
}

int exec_bin(char **arg, char **stock, char **all)
{
    char *ac = path_get_env(stock);
    char **path = strtoc(ac, '=');
    char *st = path[1];
    char **real_path = strtoc(st, ':');
    char *one_path;
    int i;

    for (int i = 0; real_path[i] != NULL; i++) {
        if (my_strcmp("/usr/bin", real_path[i]) == 0) {
            one_path = my_strcat(real_path[i], "/");
            one_path = my_strcat(one_path, arg[0]);
            exec_bin2(one_path, arg, stock, all);
        }
    }
    return 0;
}
