/*
** EPITECH PROJECT, 2023
** octale.c
** File description:
** octale
*/
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static int octal_maloc(unsigned int nbr)
{
    int a = 0;

    for (; nbr != 0; a++)
        nbr /= 8;
    return a + 1;
}

void octale(unsigned int nbr)
{
    int *t;
    int f = 0;
    int k = 0;

    t = malloc(sizeof(char) * octal_maloc(nbr));
    if (nbr == 0)
        my_put_nbr(0);
    while (nbr != 0) {
        t[f] = nbr % 8;
        nbr = nbr / 8;
        f++;
        k++;
    }
    for (f = k - 1; f >= 0; f--) {
        my_put_nbr(t[f]);
    }
    free(t);
}
