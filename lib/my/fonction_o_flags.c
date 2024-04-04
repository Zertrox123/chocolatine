/*
** EPITECH PROJECT, 2023
** fonction_o_flags.c
** File description:
** fonction_o_flags
*/
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

struct info_flags_o {
    int space;
    int sign;
    unsigned int nb_test;
    int nb_cr;
    int nb_print;
    int nb_print_dec;
    long int compt;
    long int compt_dec;
    int dièse;
    int nb_ref;
}
flags_o;

static int f_flags_o3_1(const char *format, int i, unsigned int nb)
{
    for (; flags_o.nb_print_dec > 0; flags_o.nb_print_dec--)
        my_putchar('0');
    if (flags_o.dièse == 1)
        my_putchar('0');
    octale(nb);
    if (flags_o.space == 48)
        flags_o.space = 32;
    for (; flags_o.nb_print >= 0; flags_o.nb_print--)
        my_putchar(flags_o.space);
}

static int f_flags_o3_2(const char *format, int i, unsigned int nb)
{
    for (; flags_o.nb_print > 0; flags_o.nb_print--)
        my_putchar(flags_o.space);
    for (; flags_o.nb_print_dec > 0; flags_o.nb_print_dec--)
        my_putchar('0');
    if (flags_o.dièse == 1)
        my_putchar('0');
    octale(nb);
}

static int f_flags_o3(const char *format, int i, unsigned int nb)
{
    if (flags_o.sign < 0)
        f_flags_o3_1(format, i, nb);
    else
        f_flags_o3_2(format, i, nb);
}

static int f_flags_o2_2(const char *format, int i, unsigned int nb)
{
    for (; format[i] != '.' && format[i] != 'o'; i++);
    for (i--; format[i] >= '0' && format[i] <= '9'; i--);
    for (i++; format[i] >= '0' && format[i] <= '9'; i++)
        flags_o.compt = (flags_o.compt * 10) + (format[i] - 48);
    for (; format[i] != '.' && format[i] != 'o'; i++);
    if (format[i] == '.') {
        for (i++; format[i] >= '0' && format[i] <= '9'; i++)
            flags_o.compt_dec = (flags_o.compt_dec * 10) + (format[i] - 48);
    }
    return nb;
}

static int f_flags_o2(const char *format, int i, unsigned int nb)
{
    for (; format[i] != '%'; i--);
    for (i++; format[i] == '-' || format[i] == '+'; i++) {
        if (format[i] == '-') {
            flags_o.sign = -1;
            flags_o.nb_cr++;
        }
    }
    for (; format[i] == '0' || format[i] == '#'; i++) {
        if (format[i] == '#' && flags_o.nb_ref == 1) {
            flags_o.dièse = 1;
            flags_o.nb_cr++;
        }
        if (format[i] == '0')
            flags_o.space = 48;
    }
    nb = f_flags_o2_2(format, i, nb);
    return nb;
}

int f_flags_o_initialize(unsigned int nb)
{
    flags_o.space = 32;
    flags_o.sign = 1;
    flags_o.nb_test = nb;
    flags_o.nb_cr = 0;
    flags_o.nb_print = 0;
    flags_o.nb_print_dec = 0;
    flags_o.compt = 0;
    flags_o.compt_dec = 0;
    flags_o.dièse = 0;
    flags_o.nb_ref = 0;
}

void f_flags_o(unsigned int nb, const char *format, int i)
{
    f_flags_o_initialize(nb);
    if (flags_o.nb_test == 0)
        flags_o.nb_cr++;
    for (; flags_o.nb_test > 0; flags_o.nb_test /= 8) {
        flags_o.nb_ref = 1;
        flags_o.nb_cr++;
    }
    nb = f_flags_o2(format, i, nb);
    flags_o.nb_print_dec = flags_o.compt_dec - flags_o.nb_cr;
    if (flags_o.nb_print_dec < 0)
        flags_o.nb_print_dec = 0;
    flags_o.nb_print = (flags_o.compt - flags_o.nb_cr) - flags_o.nb_print_dec;
    f_flags_o3(format, i, nb);
}
