/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_strcat.c
*/

int my_strlen_cat(char const *str)
{
    int count = 0;

    while (*str != '\0') {
        count ++;
        *str++;
    }
    return count;
}

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen_cat(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
