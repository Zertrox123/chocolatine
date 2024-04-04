/*
** EPITECH PROJECT, 2023
** my_hexa.c
** File description:
** my_hexa
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

int hexadecimal(unsigned int nbr, int letter)
{
    char *t = malloc(sizeof(char) * hexadecimal_maloc(nbr));
    int k = 0;
    int j = 0;

    if (nbr == 0)
        my_put_nbr(0);
    for (; nbr != 0; k++){
        j = nbr % 16;
        if (j >= 10 && letter == 'X')
            t[k] = j + 55;
        if (j >= 10 && letter == 'x')
            t[k] = j + 87;
        if (j >= 0 && j <= 9)
            t[k] = j + 48;
        nbr = nbr / 16;
    }
    for (int x = k - 1; x >= 0; x--)
        my_putchar(t[x]);
    free(t);
}
