/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/
#include <stdarg.h>


#ifndef MY_H_
    #define MY_H_

void indicator_1_1(const char *format, int i, va_list parameters);
void f_flags_c(int caractère, const char *format, int i);
long int f_cont(const char *format, int i);
int management_g(long double nbr, const char *format, int i);
double f_g_decimal(long double nbr, const char *format, int i, long int cont);
double f_g_scientic(long double nbr, const char *format, int i, int j);
void f_flags_o(unsigned int nb, const char *format, int i);
void f_flags_x(unsigned int nb, const char *format, int i);
int decimal_number(long double nbr, const char *format, int i);
int hexadecimal(unsigned int nbr, int letter);
void octale(unsigned int nbr);
long long int my_printf(const char *format, ...);
int my_pointer(unsigned long long nb, const char *format, int i);
void my_putchar(char c);
long long int my_printf_start(void);
long long int my_printf_return(void);
void f_conteur_nbr_caract(const char *format, int i, va_list parameters);
void f_flags_d(int nb, const char *format, int i);
int my_put_nbr(int nb);
void f_flags_u(unsigned int nb, const char *format, int i);
int my_put_nbr_unsigned(unsigned int nb);
int my_put_str(char *str, const char *format, int i);
int my_putstr(char const *str);
int scientific_number(long double nbr, const char *format, int i);

#endif /* !MY_H_ */
