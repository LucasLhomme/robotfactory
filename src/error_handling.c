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
    char *str = my_revstr(argv[1]);

    if (argc != 2)
        return 84;
    if (my_strncmp(str, "s.", 2) != 0) {
        return 84;
    }
    str = my_revstr(argv[1]);
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

int error_name_handling(char **tab)
{
    int i = 0;

    if (tab[2])
        return 84;
    for (;tab[1][i] != '\0'; i++);
    if (tab[1][i - 1] != '"' || tab[1][0] != '"')
        return 84;
    return 0;
}
