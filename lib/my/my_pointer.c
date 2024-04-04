/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_pointer.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static int hexadecimal_maloc(unsigned int nbr)
{
    int i = 1;

    for (; nbr != 0; i++)
        nbr /= 16;
    return i;
}

int hexadecimal2(unsigned long long nbr, int letter)
{
    char *t = malloc(sizeof(char) * hexadecimal_maloc(nbr));
    int k = 0;
    int j = 0;

    if (nbr == 0)
        my_put_nbr(0);
    for (; nbr != 0; k++){
        j = nbr % 16;
        if (j >= 10)
            t[k] = j + 87;
        if (j >= 0 && j <= 9)
            t[k] = j + 48;
        nbr = nbr / 16;
    }
    for (int x = k - 1; x >= 0; x--)
        my_putchar(t[x]);
    free(t);
}

int my_pointer(unsigned long long nbr, const char *format, int i)
{
    for (; format[i] != '%'; i--);
    for (; format[i] != '+' && format[i] != 'p'; i++);
    if (format[i] == '+')
        my_putchar('+');
    else {
        for (; format[i] != '%'; i--);
        for (; format[i] != ' ' && format[i] != 'p'; i++);
        if (format[i] == ' ')
            my_putchar(' ');
    }
    my_putchar('0');
    my_putchar('x');
    hexadecimal2(nbr, format);
    return;
}
