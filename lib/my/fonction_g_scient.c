/*
** EPITECH PROJECT, 2023
** fonction_g_scient.c
** File description:
** fonction_g_scient
*/
#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>

struct info_nbO_scienc {
    long int nbO;
    int last_a;
}
var_nbO_scienc;

static long double gestion_0(long double nbr)
{
    if ((int) nbr == 0) {
        var_nbO_scienc.nbO++;
        nbr -= (int) nbr;
        nbr *= 10;
    } else {
        for (int a = 0; a != var_nbO_scienc.nbO; a++)
            my_putchar('0');
        my_put_nbr((int) nbr);
        nbr -= (int) nbr;
        nbr *= 10;
        var_nbO_scienc.nbO = 0;
    }
    return nbr;
}

long double scientific_number_print_2(long double nbr, long int cont)
{
    for (; (int)nbr == 0 && var_nbO_scienc.last_a < cont - 1;
    var_nbO_scienc.last_a++) {
        var_nbO_scienc.nbO++;
        nbr -= (int) nbr;
        nbr *= 10;
    }
    if ((int) nbr != 0 && var_nbO_scienc.last_a < cont - 1)
        my_putchar('.');
        var_nbO_scienc.last_a++;
    return nbr;
}

static long double decimal_number_print(long double nbr, long int cont)
{
    var_nbO_scienc.nbO = 0;
    for (var_nbO_scienc.last_a = 0; var_nbO_scienc.last_a < cont;
    var_nbO_scienc.last_a++) {
        if (var_nbO_scienc.last_a == 0 && cont > 1)
            nbr = scientific_number_print_2(nbr, cont);
        if (var_nbO_scienc.last_a != 0 && cont > 1)
            nbr = gestion_0(nbr);
    }
}

static int point_number_print_scienc(long double nbr, long int cont,
    const char *format, int i)
{
    for (; (int)nbr > 9; nbr /= 10);
    my_put_nbr((int)nbr);
    nbr -= (int)nbr;
    nbr *= 10;
    if (cont == 1) {
        for (; format[i] != '%'; i--);
        if (format[i + 1] == '#')
            my_putchar('.');
        return 0;
    }
    decimal_number_print(nbr, cont);
}

static long double f_borough_scientific(long int cont, long double nbr)
{
    long double borough_nbr = 1;
    long double borough = 0;

    for (; nbr > 9; nbr /= 10);
    for (; nbr < 1; nbr *= 10);
    borough = nbr;
    for (int a = 0; a < cont - 1; borough_nbr /= 10) {
        borough *= 10;
        a++;
    }
    borough *= 10;
    if (5 <= (int)borough % 10 && (int)borough % 10){
        nbr += borough_nbr;
    }
    return nbr;
}

static int print_letter(const char *format, int i, int j)
{
    for (; format[i] != 'g' && format[i] != 'G'; i++);
    my_putchar(format[i] - 2);
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

double f_g_scientic(long double nbr, const char *format, int i, int j)
{
    long int cont = f_cont(format, i);

    nbr = f_borough_scientific(cont, nbr);
    if (nbr > 10)
        j++;
    point_number_print_scienc(nbr, cont, format, i);
    print_letter(format, i, j);
    return 0;
}
