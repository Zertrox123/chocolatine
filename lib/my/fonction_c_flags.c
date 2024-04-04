/*
** EPITECH PROJECT, 2023
** fonction_c_flags.c
** File description:
** fonction_c_flags
*/
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

struct info_flags_c {
    int sign;
    int nb_print;
    long int compt;
    long int compt_dec;
}
flags_c;

static void f_flags_c3(const char *format, int i, char caractère)
{
    if (flags_c.sign < 0) {
        my_putchar(caractère);
        for (; flags_c.nb_print > 0; flags_c.nb_print--)
            my_putchar(' ');
    } else {
        for (; flags_c.nb_print > 0; flags_c.nb_print--)
            my_putchar(' ');
        my_putchar(caractère);
    }
}

static void f_flags_c2(const char *format, int i, char caractère)
{
    for (; format[i] != '%'; i--);
    i++;
    for (; format[i] == '-' || format[i] == '+'; i++) {
        if (format[i] == '-')
            flags_c.sign = -1;
    }
    for (; format[i] != '.' && format[i] != 'c'; i++);
    for (i--; format[i] >= '0' && format[i] <= '9'; i--);
    for (i++; format[i] >= '0' && format[i] <= '9'; i++)
        flags_c.compt = (flags_c.compt * 10) + (format[i] - 48);
}

void f_flags_c_initialize(void)
{
    flags_c.sign = 1;
    flags_c.nb_print = 0;
    flags_c.compt = 0;
    flags_c.compt_dec = 0;
}

void f_flags_c(int caractère, const char *format, int i)
{
    f_flags_c_initialize();
    f_flags_c2(format, i, caractère);
    flags_c.nb_print = flags_c.compt - 1;
    f_flags_c3(format, i, caractère);
}
