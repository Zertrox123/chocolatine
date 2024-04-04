/*
** EPITECH PROJECT, 2023
** scientific_number.c
** File description:
** scientific_number
*/
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static long double decimal_number_print(long double nbr, long int cont, int a)
{
    if (a == 0 && cont >= 1)
        my_putchar('.');
    else {
        my_put_nbr((int) nbr);
        nbr -= (int) nbr;
        nbr *= 10;
    }
    return nbr;
}

static long double point_number_print_dec(long double nbr, long int cont,
    const char *format, int i)
{
    int x = 0;

    for (; nbr > 10; x++)
        nbr /= 10;
    for (int b = 0; b <= x; b++) {
        my_put_nbr((int) nbr % 10);
        nbr -= (int) nbr;
        nbr *= 10;
    }
    if (cont == 0) {
        for (; format[i] != '%'; i--);
        if (format[i + 1] == '#')
            my_putchar('.');
        return 0;
    }
    for (int a = 0; a <= cont; a++)
        nbr = decimal_number_print(nbr, cont, a);
}

static long double f_borough_decimal(long double borough, long int cont,
    long double nbr)
{
    long double borough_nbr = 1;

    borough -= (int)borough;
    borough *= 10;
    if (cont != 0) {
        for (int a = 0; a < cont; a++) {
            borough -= (int) borough;
            borough *= 10;
            borough_nbr /= 10;
        }
    }
    borough = (int)borough % 10;
    if (5 <= borough && 10 > borough)
        nbr += borough_nbr;
    return nbr;
}

static int point_number(long double nbr, const char *format, int i)
{
    long int cont = 0;
    long double borough = nbr;

    for (; format[i] != '.' && format[i] != 'f' && format[i] != 'F'; i++);
    if (format[i] == '.') {
        i++;
        for (; format[i] >= '0' && format[i] <= '9'; i++)
            cont = (cont * 10) + (format[i] - 48);
    } else
        cont = 6;
    nbr = f_borough_decimal(borough, cont, nbr);
    point_number_print_dec(nbr, cont, format, i);
}

static int sign_number(long double nbr)
{
    int sign = 1;

    if (nbr < 0)
        sign *= -1;
    return sign;
}

int decimal_number(long double nbr, const char *format, int i)
{
    int sign = sign_number(nbr);

    nbr *= sign;
    if (sign < 0)
        my_putchar('-');
    for (; format[i] != '%'; i--);
    point_number(nbr, format, i);
}
