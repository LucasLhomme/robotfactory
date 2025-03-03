/*
** EPITECH PROJECT, 2025
** lib
** File description:
** my_getenv
*/

#include <unistd.h>
#include "lib.h"

char *my_getenv(char **env, char *name)
{
    size_t name_len = strlen(name);

    if (!env || !name)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
            return env[i] + name_len + 1;
    }
    return NULL;
}
