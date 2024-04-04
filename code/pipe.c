/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-omar.joudi
** File description:
** pipe.c
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

static int annexe2(char **arg, int i)
{
    for (int j = 0; arg[i][j] != '\0'; j++) {
        if (arg[i][j] == '|')
            return i;
    }
    return 0;
}

static int annexe(char c)
{
    if (c == '|')
        return 1;
    return 0;
}

static int redirect_output(int fd)
{
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        return -1;
    }
    return 0;
}

static char *function_path(char **env, char **arg1)
{
    char *ac = path_get_env(env);
    char **path = strtoc(ac, '=');
    char *st = path[1];
    char **real_path = strtoc(st, ':');
    char *one_path;

    for (int i = 0; real_path[i] != NULL; i++) {
        if (my_strcmp("/usr/bin", real_path[i]) == 0) {
            one_path = my_strcat(real_path[i], "/");
            one_path = my_strcat(one_path, arg1[0]);
            return one_path;
        }
    }
}

int do_pipe(char *one_path, char **arg0, char **arg1, char **env)
{
    char *second_path = function_path(env, arg1);
    int pipes[2];
    pid_t pid;

    pipe(pipes);
    pid = fork();
    if (pid == 0) {
        close(pipes[0]);
        dup2(pipes[1], STDOUT_FILENO);
        close(pipes[1]);
        execve(one_path, arg0, env);
        exit(EXIT_SUCCESS);
    } else {
        close(pipes[1]);
        dup2(pipes[0], STDIN_FILENO);
        close(pipes[0]);
        execve(second_path, arg1, env);
        exit(EXIT_SUCCESS);
    }
}

int do_pipes(char *one_path, char **arg, char **env, int pos)
{
    char **tab = strtoc(arg[pos], '|');
    char **arg0;
    char **arg1;

    arg0 = strtoc(tab[0], ' ');
    arg1 = strtoc(tab[1], ' ');
    arg0 = remove_n(remove_space(arg0));
    arg1 = remove_n(remove_space(arg1));
    do_pipe(one_path, arg0, arg1, env);
    return 0;
}

int is_pipe(char *one_path, char **arg, char **env)
{
    int st = 0;

    for (int i = 0; arg[i] != NULL; i++) {
        for (int j = 0; arg[i][j] != '\0'; j++) {
            st += annexe(arg[i][j]);
        }
    }
    return st;
}

int found_pipe(char *one_path, char **arg, char **env)
{
    int st = 0;

    for (int i = 0; arg[i] != NULL; i++) {
        st = annexe2(arg, i);
        if (st != 0) {
            return i;
        }
    }
    return 0;
}
