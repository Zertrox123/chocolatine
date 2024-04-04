/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** my_putstr
*/
#include "include/my.h"
#include <stdio.h>

int my_putstr(char const *str)
{
    int adr = 0;

    while (str[adr] != '\0') {
        my_putchar(str[adr]);
        adr++;
    }
}
