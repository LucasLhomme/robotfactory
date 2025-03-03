/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare string
*/

#include "lib.h"

int my_strncmp(char *const str1, char *const str2, int n)
{
    for (int i = 0; i < n || str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    }
    return 0;
}
