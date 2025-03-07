/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
** File description:
** get_name
*/
#include "my.h"
#include "lib.h"

char *my_get_name(FILE *file)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    char **tab = NULL;
    char *name = NULL;

    read = getline(&line, &len, file);
    if (read == -1)
        return NULL;
    tab = my_str_to_word_array_advanced(line, ".\"");
    if (!tab[0])
        return NULL;
    if (my_strcmp(tab[0], ".name") != 0)
        return NULL;
    name = extract_str(line, '"');
    return name;
}
