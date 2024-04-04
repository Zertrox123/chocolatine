/*
** EPITECH PROJECT, 2023
** myprintf.c
** File description:
** myprintf
*/
#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>

int management(const char *format, int i, va_list parameters)
{
    char params[22] = ".1234567890 hljztL#-+";
    int point = 0;

    i++;
    for (int j = 0; params[j] != '\0'; j++) {
        if (format[i] == '.')
            point++;
        if (format[i] == ' ' && format[i - 1] == '.' || point >= 2)
            return i;
        if (format[i] == params[j]) {
            i++;
            j = -1;
        }
    }
    indicator_1_1(format, i, parameters);
    return i;
}

long long int my_printf(const char *format, ...)
{
    va_list parameters;

    my_printf_start();
    va_start(parameters, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%')
            i = management(format, i, parameters);
        else
            my_putchar(format[i]);
    }
    va_end(parameters);
    return my_printf_return();
}
