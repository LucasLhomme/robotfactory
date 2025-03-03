/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** error handling
*/

#include "my.h"
#include "lib.h"
#include <string.h>

int error_handling(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (my_strncmp(my_revstr(argv[1]), "s.", 2) != 0)
        return 84;
    return 0;
}

int error_champion_handling(FILE *file, champion_t *champion)
{
    if (!file)
    return 84;
    if (!champion) {
        fclose(file);
        free(champion);
        return 84;
    }
    return 0;
}
