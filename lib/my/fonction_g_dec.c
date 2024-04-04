/*
** EPITECH PROJECT, 2023
** fonction_g_dec.c
** File description:
** fonction_g_dec
*/
#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>

struct info_nbO_dec {
    long int nbO;
    int last_a;
}
var_nbO_dec;

static long double gestion_0(long double nbr)
{
    if ((int) nbr == 0) {
        var_nbO_dec.nbO++;
        nbr -= (int) nbr;
        nbr *= 10;
    } else {
        for (int a = 0; a != var_nbO_dec.nbO; a++)
            my_putchar('0');
        my_put_nbr((int) nbr);
        nbr -= (int) nbr;
        nbr *= 10;
        var_nbO_dec.nbO = 0;
    }
    return nbr;
}

static long double decimal_number_print_2(long double nbr, long int cont)
{
    for (; (int)nbr == 0 && var_nbO_dec.last_a < cont;) {
        var_nbO_dec.nbO++;
        nbr -= (int) nbr;
        nbr *= 10;
        var_nbO_dec.last_a++;
    }
    if ((int) nbr != 0 && var_nbO_dec.last_a < cont - 1)
        my_putchar('.');
    var_nbO_dec.last_a++;
    return nbr;
}

static long double decimal_number_print(long double nbr, long int cont)
{
    long double comp = nbr;

    var_nbO_dec.nbO = 0;
    for (; var_nbO_dec.last_a <= cont;
    var_nbO_dec.last_a++) {
        if (var_nbO_dec.last_a == 1 && cont > 1) {
            nbr = decimal_number_print_2(nbr, cont);
        }
        if (var_nbO_dec.last_a > 1 && var_nbO_dec.last_a <= cont)
            nbr = gestion_0(nbr);
    }
    return 0;
}

static long double point_number_print_dec(long double nbr, long int cont,
    const char *format, int i)
{
    my_put_nbr((int) nbr);
    var_nbO_dec.last_a = 0;
    if ((int) nbr > 0)
        var_nbO_dec.last_a++;
    nbr -= (int) nbr;
    nbr *= 10;
    if (cont == 1) {
        for (; format[i] != '%'; i--);
        if (format[i + 1] == '#')
            my_putchar('.');
        return 0;
    }
    decimal_number_print(nbr, cont);
}

static long double f_borough_decimal(long double borough, long int cont,
    long double nbr)
{
    long double borough_nbr = 1;

    borough *= 10;
    if (cont > 0) {
        for (; (int) borough == 0;) {
            borough -= (int) borough;
            borough *= 10;
            borough_nbr /= 10;
        }
        for (int a = 1; a < cont; a++) {
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

double f_g_decimal(long double nbr, const char *format, int i, long int cont)
{
    long double borough = nbr;
    long double comp = (int) nbr;
    long double comp2 = nbr;
    long int nb_comp = 0;

    for (; (int) comp > 0; nb_comp++)
        comp /= 10;
    cont -= nb_comp - 1;
    nbr = f_borough_decimal(borough, cont, nbr);
    comp = nbr;
    for (; (int) comp > 9; comp /= 10);
    for (; (int) comp2 > 9; comp2 /= 10);
    if ((int) comp < (int) comp2)
        cont -= 1;
    point_number_print_dec(nbr, cont, format, i);
    return 0;
}
