/*
** EPITECH PROJECT, 2023
** my_put_str.c
** File description:
** my_put_str
*/
#include "include/my.h"
#include <stdio.h>

int my_put_str(char *str, const char *format, int i)
{
    int cont = 0;

    for (; format[i] != '%'; i--);
    for (; format[i] != '.' && format[i] != 's'; i++);
    if (format[i] == '.') {
        i++;
        for (; format[i] >= '0' && format[i] <= '9'; i++)
            cont = (cont * 10) + (format[i] - 48);
    } else
        cont = -1;
    for (int x = 0; x != cont && str[x] != '\0'; x++)
        my_putchar(str[x]);
    return 0;
}
