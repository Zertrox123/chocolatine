/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr
*/
#include "include/my.h"

struct info_flags_d {
    int space;
    int sign;
    int nb_test;
    int nb_cr;
    int nb_print;
    int nb_print_dec;
    long int compt;
    long int compt_dec;
    int sign_nb;
}
flags_d;

static int f_flags_d3_1(const char *format, int i, int nb)
{
    if (flags_d.sign_nb != 0)
        my_putchar(flags_d.sign_nb);
    for (; flags_d.nb_print_dec > 0; flags_d.nb_print_dec--)
        my_putchar('0');
    my_put_nbr(nb);
    if (flags_d.space == 48)
        flags_d.space = 32;
    for (; flags_d.nb_print > 0; flags_d.nb_print--)
        my_putchar(flags_d.space);
}

static int f_flags_d3_2(const char *format, int i, int nb)
{
    if (flags_d.space == 48) {
        if (flags_d.sign_nb != 0)
            my_putchar(flags_d.sign_nb);
        for (; flags_d.nb_print > 0; flags_d.nb_print--)
            my_putchar(flags_d.space);
    } else {
        for (; flags_d.nb_print > 0; flags_d.nb_print--)
            my_putchar(flags_d.space);
        if (flags_d.sign_nb != 0)
            my_putchar(flags_d.sign_nb);
    }
    for (; flags_d.nb_print_dec > 0; flags_d.nb_print_dec--)
        my_putchar('0');
    my_put_nbr(nb);
}

static int f_flags_d3(const char *format, int i, int nb)
{
    if (flags_d.sign < 0) {
    f_flags_d3_1(format, i, nb);
    } else {
    f_flags_d3_2(format, i, nb);
    }
}

static int f_flags_d2_2(const char *format, int i, int nb)
{
    for (; format[i] != '.' && format[i] != 'd'; i++);
    for (i--; format[i] >= '0' && format[i] <= '9'; i--);
    i++;
    if (format[i] == '0') {
        flags_d.space = 48;
        i++;
    }
    for (; format[i] >= '0' && format[i] <= '9'; i++)
        flags_d.compt = (flags_d.compt * 10) + (format[i] - 48);
    for (; format[i] != '.' && format[i] != 'd'; i++);
    if (format[i] == '.') {
        for (i++; format[i] >= '0' && format[i] <= '9'; i++)
            flags_d.compt_dec = (flags_d.compt_dec * 10) + (format[i] - 48);
    }
    return nb;
}

static int f_flags_d2(const char *format, int i, int nb)
{
    if (flags_d.nb_test < 0) {
        nb *= -1;
        flags_d.sign_nb = '-';
        flags_d.nb_test *= -1;
    }
    for (; format[i] != '%'; i--);
    for (i++; format[i] == '-' || format[i] == '+'; i++) {
        if (format[i] == '-')
            flags_d.sign = -1;
        if (format[i] == '+' && flags_d.sign_nb != '-')
            flags_d.sign_nb = '+';
    }
    for (; format[i] != ' ' && format[i] != '.' && format[i] != 'd'; i++);
    if (format[i] == ' ' && flags_d.sign_nb != '-')
        my_putchar(' ');
    nb = f_flags_d2_2(format, i, nb);
    return nb;
}

int f_flags_d_initialize(int nb)
{
    flags_d.space = 32;
    flags_d.sign = 1;
    flags_d.nb_test = nb;
    flags_d.nb_cr = 0;
    flags_d.nb_print = 0;
    flags_d.nb_print_dec = 0;
    flags_d.compt = 0;
    flags_d.compt_dec = 0;
    flags_d.sign_nb = 0;
}

void f_flags_d(int nb, const char *format, int i)
{
    f_flags_d_initialize(nb);
    nb = f_flags_d2(format, i, nb);
    if (flags_d.sign_nb != 0)
        flags_d.nb_cr++;
    for (; flags_d.nb_test > 0; flags_d.nb_test /= 10)
        flags_d.nb_cr++;
    flags_d.nb_print_dec = flags_d.compt_dec - flags_d.nb_cr;
    if (flags_d.sign_nb != 0)
        flags_d.nb_print_dec++;
    if (flags_d.nb_print_dec < 0)
        flags_d.nb_print_dec = 0;
    flags_d.nb_print = (flags_d.compt - flags_d.nb_cr) - flags_d.nb_print_dec;
    f_flags_d3(format, i, nb);
}

int my_put_nbr(int nb)
{
    int val = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb / 10) {
        val++;
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + 48);
    return val;
}
