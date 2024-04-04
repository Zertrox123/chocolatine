/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-omar.joudi
** File description:
** my_strcmp.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] != s2[i]){
            return 1;
        }
        i++;
    }
    return 0;
}
