/*
** EPITECH PROJECT, 2023
** fonction_x_flags.c
** File description:
** fonction_x_flags
*/
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

struct info_flags_x {
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
    int car_dièse;
}
flags_x;

static int f_flags_x3_1(const char *format, int i, unsigned int nb)
{
    for (; flags_x.nb_print_dec > 0; flags_x.nb_print_dec--)
        my_putchar('0');
    if (flags_x.dièse == 1) {
        my_putchar('0');
        my_putchar(flags_x.car_dièse);
    }
    hexadecimal(nb, flags_x.car_dièse);
    if (flags_x.space == 48)
        flags_x.space = 32;
    for (; flags_x.nb_print >= 0; flags_x.nb_print--)
        my_putchar(flags_x.space);
}

static int f_flags_x3_2(const char *format, int i, unsigned int nb)
{
    for (; flags_x.nb_print > 0; flags_x.nb_print--)
        my_putchar(flags_x.space);
    for (; flags_x.nb_print_dec > 0; flags_x.nb_print_dec--)
        my_putchar('0');
    if (flags_x.dièse == 1) {
        my_putchar('0');
        my_putchar(flags_x.car_dièse);
    }
    hexadecimal(nb, flags_x.car_dièse);
}

static int f_flags_x3(const char *format, int i, unsigned int nb)
{
    if (flags_x.sign < 0)
        f_flags_x3_1(format, i, nb);
    else
        f_flags_x3_2(format, i, nb);
}

static int f_flags_x2_2(const char *format, int i, unsigned int nb)
{
    for (; format[i] != '.' && format[i] != 'x' && format[i] != 'X'; i++);
    for (i--; format[i] >= '0' && format[i] <= '9'; i--);
    for (i++; format[i] >= '0' && format[i] <= '9'; i++)
        flags_x.compt = (flags_x.compt * 10) + (format[i] - 48);
    for (; format[i] != '.' && format[i] != 'x' && format[i] != 'X'; i++);
    if (format[i] == '.') {
        for (i++; format[i] >= '0' && format[i] <= '9'; i++)
            flags_x.compt_dec = (flags_x.compt_dec * 10) + (format[i] - 48);
    }
    if (format[i] == 'x')
        flags_x.car_dièse = 'x';
    else
        flags_x.car_dièse = 'X';
    return nb;
}

static int f_flags_x2(const char *format, int i, unsigned int nb)
{
    for (; format[i] != '%'; i--);
    for (i++; format[i] == '-' || format[i] == '+'; i++) {
        if (format[i] == '-') {
            flags_x.sign = -1;
            flags_x.nb_cr++;
        }
    }
    for (; format[i] == '0' || format[i] == '#'; i++) {
        if (format[i] == '#' && flags_x.nb_ref == 1) {
            flags_x.dièse = 1;
            flags_x.nb_cr += 2;
        }
        if (format[i] == '0')
            flags_x.space = 48;
    }
    nb = f_flags_x2_2(format, i, nb);
    return nb;
}

int f_flags_x_initialize(unsigned int nb)
{
    flags_x.space = 32;
    flags_x.sign = 1;
    flags_x.nb_test = nb;
    flags_x.nb_cr = 0;
    flags_x.nb_print = 0;
    flags_x.nb_print_dec = 0;
    flags_x.compt = 0;
    flags_x.compt_dec = 0;
    flags_x.dièse = 0;
    flags_x.nb_ref = 0;
    flags_x.car_dièse = 0;
}

void f_flags_x(unsigned int nb, const char *format, int i)
{
    f_flags_x_initialize(nb);
    if (flags_x.nb_test == 0)
        flags_x.nb_cr++;
    for (; flags_x.nb_test > 0; flags_x.nb_test /= 16) {
        flags_x.nb_ref = 1;
        flags_x.nb_cr++;
    }
    nb = f_flags_x2(format, i, nb);
    flags_x.nb_print_dec = flags_x.compt_dec - flags_x.nb_cr;
    if (flags_x.nb_print_dec < 0)
        flags_x.nb_print_dec = 0;
    flags_x.nb_print = (flags_x.compt - flags_x.nb_cr) - flags_x.nb_print_dec;
    f_flags_x3(format, i, nb);
}
