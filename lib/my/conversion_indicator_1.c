/*
** EPITECH PROJECT, 2023
** conversion_indicator_1.c
** File description:
** conversion_indicator_1
*/
#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>

void indicator_1_5(const char *format, int i, va_list parameters)
{
    switch (format[i]) {
    case 'g':
    case 'G':
        if (format[i - 1] == 'L')
            management_g(va_arg(parameters, long double), format, i);
        if (format[i - 1] != 'L')
            management_g(va_arg(parameters, double), format, i);
        break;
    case 'p':
        my_pointer(va_arg(parameters, unsigned long long), format, i);
        break;
    default:
        my_putchar('%');
        my_putchar(format[i]);
        break;
    }
}

void indicator_1_4(const char *format, int i, va_list parameters)
{
    switch (format[i]) {
    case 'n':
        f_conteur_nbr_caract(format, i, parameters);
        break;
    default:
        indicator_1_5(format, i, parameters);
        break;
    }
}

void indicator_1_3(const char *format, int i, va_list parameters)
{
    switch (format[i]) {
    case 'u':
        f_flags_u(va_arg(parameters, unsigned int), format, i);
        break;
    case 'f':
    case 'F':
        if (format[i - 1] == 'L')
            decimal_number(va_arg(parameters, long double), format, i);
        if (format[i - 1] != 'L')
            decimal_number(va_arg(parameters, double), format, i);
        break;
    default:
        indicator_1_4(format, i, parameters);
        break;
    }
}

void indicator_1_2(const char *format, int i, va_list parameters)
{
    switch (format[i]) {
    case 'o':
        f_flags_o(va_arg(parameters, unsigned int), format, i);
        break;
    case 'x':
    case 'X':
        f_flags_x(va_arg(parameters, unsigned int), format, i);
        break;
    case 'e':
    case 'E':
        if (format[i - 1] == 'L')
            scientific_number(va_arg(parameters, long double), format, i);
        if (format[i - 1] != 'L')
            scientific_number(va_arg(parameters, double), format, i);
        break;
    default:
        indicator_1_3(format, i, parameters);
        break;
    }
}

void indicator_1_1(const char *format, int i, va_list parameters)
{
    switch (format[i]) {
    case 'd':
    case 'i':
        f_flags_d(va_arg(parameters, int), format, i);
        break;
    case 's':
        my_put_str(va_arg(parameters, char *), format, i);
        break;
    case 'c':
        f_flags_c(va_arg(parameters, int), format, i);
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        indicator_1_2(format, i, parameters);
        break;
    }
}
