/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** a function that concatenates two strings
*/

#include "lib.h"

char *my_strcat(char *dest, const char *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}
