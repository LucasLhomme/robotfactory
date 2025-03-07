/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** a function that concatenates two strings
*/

#include "lib.h"

char *my_strcat(char *dest, const char *src)
{
    size_t dest_len = my_strlen(dest);
    size_t src_len = my_strlen(src);
    size_t new_size = dest_len + src_len + 1;

    dest = realloc(dest, new_size);
    if (!dest)
        return NULL;
    strcat(dest, src);
    return dest;
}

