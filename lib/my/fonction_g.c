/*
** EPITECH PROJECT, 2023
** fonction_g.c
** File description:
** fonction_g
*/
#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>

struct info_managament_g {
    long double comp;
    int j;
    int comp_j;
}
var_managament_g;

long int f_cont(const char *format, int i)
{
    long int cont = 0;

    for (; format[i] != '%'; i--);
    for (; format[i] != '.' && format[i] != 'g' && format[i] != 'G'; i++);
    if (format[i] == '.') {
        i++;
        for (; format[i] >= '0' && format[i] <= '9'; i++)
            cont = (cont * 10) + (format[i] - 48);
    } else
        cont = 6;
    if (cont == 0)
        cont = 1;
    return cont;
}

static int sign_number(long double nbr)
{
    int sign = 1;

    if (nbr < 0)
        sign *= -1;
    return sign;
}

static int forough(long double comp, long int cont, int j)
{
    long double compar = comp;
    long double compar2 = comp;
    long double borough_nbr = 1;

    comp *= 10;
    if (cont > 1) {
        for (int a = 1; a < cont; a++) {
            comp -= (int) comp;
            comp *= 10;
            borough_nbr /= 10;
        }
    }
    comp = (int)comp % 10;
    if (5 <= (int) comp && 10 > (int) comp)
        compar2 += borough_nbr;
    for (; (int) compar > 9; compar /= 10);
    for (; (int) compar2 > 9; compar2 /= 10);
    if ((int) compar2 < (int) compar)
        j++;
    return j;
}

static int management_g2(int sign)
{
    for (; var_managament_g.comp > 10; var_managament_g.j++)
        var_managament_g.comp /= 10;
    for (; var_managament_g.comp < 1; var_managament_g.j--)
        var_managament_g.comp *= 10;
    if (sign < 0)
        my_putchar('-');
}

static int management_g3(long double nbr, const char *format, int i,
    long int cont)
{
    if ((var_managament_g.j < -4 || var_managament_g.j >= cont)) {
        if (var_managament_g.j > var_managament_g.comp_j)
            var_managament_g.j = var_managament_g.comp_j;
        f_g_scientic(nbr, format, i, var_managament_g.j);
    } else
        f_g_decimal(nbr, format, i, cont);
}

int management_g(long double nbr, const char *format, int i)
{
    int sign = sign_number(nbr);
    long int cont = 0;

    var_managament_g.j = 0;
    var_managament_g.comp = nbr * sign;
    var_managament_g.comp_j = 0;
    if (nbr == 0) {
        my_putchar('0');
        return 0;
    }
    nbr *= sign;
    management_g2(sign);
    cont = f_cont(format, i);
    var_managament_g.comp_j = var_managament_g.j;
    var_managament_g.j = forough(var_managament_g.comp, cont,
    var_managament_g.j);
    management_g3(nbr, format, i, cont);
    return 0;
}
