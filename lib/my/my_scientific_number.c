/*
** EPITECH PROJECT, 2023
** scientific_number.c
** File description:
** scientific_number
*/
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

static int point_number_print_scienc(long double nbr, long int cont,
    const char *format, int i)
{
    for (; (int)nbr > 9; nbr /= 10);
    my_put_nbr((int)nbr);
    nbr -= (int)nbr;
    nbr *= 10;
    if (cont == 0) {
        for (; format[i] != '%'; i--);
        if (format[i + 1] == '#')
            my_putchar('.');
        return 0;
    }
    for (int a = 0; a <= cont; a++) {
        if (a == 0 && cont >= 1)
            my_putchar('.');
        else {
            my_put_nbr((int) nbr);
            nbr -= (int) nbr;
            nbr *= 10;
        }
    }
}

static long double f_borough_scientific(long int cont, long double nbr)
{
    long double borough_nbr = 1;
    long double borough = 0;

    for (; nbr > 9; nbr /= 10);
    for (; nbr < 1; nbr *= 10);
    borough = nbr;
    for (int a = 0; a < cont; borough_nbr /= 10) {
        borough *= 10;
        a++;
    }
    borough *= 10;
    if (5 <= (int)borough % 10 && (int)borough % 10){
        nbr += borough_nbr;
    }
    return nbr;
}

static int point_number(long double nbr, const char *format, int i, int j)
{
    long int cont = 0;

    for (; format[i] != '.' && format[i] != 'e' && format[i] != 'E'; i++);
    if (format[i] == '.') {
        i++;
        for (; format[i] >= '0' && format[i] <= '9'; i++)
            cont = (cont * 10) + (format[i] - 48);
    } else
        cont = 6;
    nbr = f_borough_scientific(cont, nbr);
    if (nbr > 10)
        j++;
    point_number_print_scienc(nbr, cont, format, i);
    return j;
}

static int sign_number(long double nbr)
{
    int sign = 1;

    if (nbr < 0)
        sign *= -1;
    return sign;
}

static int print_letter(const char *format, int i, int j)
{
    for (; format[i] != 'e' && format[i] != 'E'; i++);
    my_putchar(format[i]);
    if (j >= 0)
        my_putchar('+');
    else {
        my_putchar('-');
        j *= -1;
    }
    if (j > - 10 && j < 10)
        my_putchar('0');
    my_put_nbr(j);
}

int scientific_number(long double nbr, const char *format, int i)
{
    int sign = sign_number(nbr);
    int j = 0;
    long double comp = nbr;

    nbr *= sign;
    comp *= sign;
    for (; comp > 10; j++)
        comp /= 10;
    for (; comp < 1; j--)
        comp *= 10;
    if (sign < 0)
        my_putchar('-');
    for (; format[i] != '%'; i--);
    j = point_number(nbr, format, i, j);
    print_letter(format, i, j);
}
