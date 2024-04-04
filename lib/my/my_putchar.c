/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** my_putchar
*/
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

struct info_nb_car {
    long long int conteur_nbr_caract;
}
var_nb_char = {0};

void my_putchar(char c)
{
    var_nb_char.conteur_nbr_caract++;
    write(1, &c, 1);
}

long long int my_printf_start(void)
{
    var_nb_char.conteur_nbr_caract = 0;
}

long long int my_printf_return(void)
{
    return var_nb_char.conteur_nbr_caract;
}

static void f_conteur_nbr_caract_s(int *val)
{
    *val = var_nb_char.conteur_nbr_caract;
    return;
}

static void f_conteur_nbr_caract_hh(signed char *val)
{
    *val = var_nb_char.conteur_nbr_caract;
    return;
}

static void f_conteur_nbr_caract_h(short int *val)
{
    *val = var_nb_char.conteur_nbr_caract;
    return;
}

static void f_conteur_nbr_caract_l(long int *val)
{
    *val = var_nb_char.conteur_nbr_caract;
    return;
}

static void f_conteur_nbr_caract_ll(long long int *val)
{
    *val = var_nb_char.conteur_nbr_caract;
    return;
}

void f_conteur_nbr_caract(const char *format, int i, va_list parameters)
{
    if (format[i - 1] != 'l' && format[i - 1] != 'h')
        f_conteur_nbr_caract_s(va_arg(parameters, int *));
    if (format[i - 1] == 'h' && format[i - 2] == 'h')
        f_conteur_nbr_caract_hh(va_arg(parameters, signed char *));
    if (format[i - 1] == 'h' && format[i - 2] != 'h')
        f_conteur_nbr_caract_h(va_arg(parameters, short int *));
    if (format[i - 1] == 'l' && format[i - 2] != 'l')
        f_conteur_nbr_caract_l(va_arg(parameters, long int *));
    if (format[i - 1] == 'l' && format[i - 2] == 'l')
        f_conteur_nbr_caract_ll(va_arg(parameters, long long int *));
    return;
}
