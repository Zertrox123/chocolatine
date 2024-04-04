/*
** EPITECH PROJECT, 2023
** my_put_nbr_unsigned.c
** File description:
** my_put_nbr_unsigned
*/
#include "include/my.h"

struct info_flags_u {
    int space;
    int sign;
    unsigned int nb_test;
    int nb_cr;
    int nb_print;
    int nb_print_dec;
    long int compt;
    long int compt_dec;
}
flags_u;

static int f_flags_u3_1(const char *format, int i, unsigned int nb)
{
    for (; flags_u.nb_print_dec > 0; flags_u.nb_print_dec--)
        my_putchar('0');
    my_put_nbr_unsigned(nb);
    if (flags_u.space == 48)
        flags_u.space = 32;
    for (; flags_u.nb_print > 0; flags_u.nb_print--)
        my_putchar(flags_u.space);
}

static int f_flags_u3_2(const char *format, int i, unsigned int nb)
{
    if (flags_u.space == 48) {
        for (; flags_u.nb_print > 0; flags_u.nb_print--)
            my_putchar(flags_u.space);
    } else {
        for (; flags_u.nb_print > 0; flags_u.nb_print--)
            my_putchar(flags_u.space);
    }
    for (; flags_u.nb_print_dec > 0; flags_u.nb_print_dec--)
        my_putchar('0');
    my_put_nbr_unsigned(nb);
}

static int f_flags_u3(const char *format, int i, unsigned int nb)
{
    if (flags_u.sign < 0) {
    f_flags_u3_1(format, i, nb);
    } else {
    f_flags_u3_2(format, i, nb);
    }
}

static int f_flags_u2_2(const char *format, int i, unsigned int nb)
{
    for (i--; format[i] >= '0' && format[i] <= '9'; i--);
    i++;
    if (format[i] == '0') {
        flags_u.space = 48;
        i++;
    }
    for (; format[i] >= '0' && format[i] <= '9'; i++)
        flags_u.compt = (flags_u.compt * 10) + (format[i] - 48);
    for (; format[i] != '.' && format[i] != 'u'; i++);
    if (format[i] == '.') {
        for (i++; format[i] >= '0' && format[i] <= '9'; i++)
            flags_u.compt_dec = (flags_u.compt_dec * 10) + (format[i] - 48);
    }
    return nb;
}

static int f_flags_u2(const char *format, int i, unsigned int nb)
{
    if (flags_u.nb_test < 0) {
        nb *= -1;
        flags_u.nb_test *= -1;
    }
    for (; format[i] != '%'; i--);
    for (i++; format[i] == '-' || format[i] == '+'; i++) {
        if (format[i] == '-')
            flags_u.sign = -1;
    }
    for (; format[i] != '.' && format[i] != 'u'; i++);
    nb = f_flags_u2_2(format, i, nb);
    return nb;
}

int f_flags_u_initialize(unsigned int nb)
{
    flags_u.space = 32;
    flags_u.sign = 1;
    flags_u.nb_test = nb;
    flags_u.nb_cr = 0;
    flags_u.nb_print = 0;
    flags_u.nb_print_dec = 0;
    flags_u.compt = 0;
    flags_u.compt_dec = 0;
}

void f_flags_u(unsigned int nb, const char *format, int i)
{
    f_flags_u_initialize(nb);
    nb = f_flags_u2(format, i, nb);
    if (flags_u.nb_test == 0)
        flags_u.nb_cr++;
    for (; flags_u.nb_test > 0; flags_u.nb_test /= 10)
        flags_u.nb_cr++;
    flags_u.nb_print_dec = flags_u.compt_dec - flags_u.nb_cr;
    if (flags_u.nb_print_dec < 0)
        flags_u.nb_print_dec = 0;
    flags_u.nb_print = (flags_u.compt - flags_u.nb_cr) - flags_u.nb_print_dec;
    f_flags_u3(format, i, nb);
}

int my_put_nbr_unsigned(unsigned int nb)
{
    int val = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb / 10) {
        my_put_nbr_unsigned(nb / 10);
    }
    my_putchar((nb % 10) + 48);
}
