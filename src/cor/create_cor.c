/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
** File description:
** temp
*/
#include "my.h"
#include "lib.h"

int create_cor(champion_t *champ)
{
    char namefile[256];
    FILE *new_file = NULL;

    if (champ == NULL || champ->name == NULL || champ->comment == NULL)
        return 84;
    my_strcpy(namefile, champ->name);
    my_str_tolower(namefile);
    my_strcat(champ->filename, ".cor");
    new_file = fopen(champ->filename, "w+");
    if (new_file == NULL)
        return 84;
    if (write_header(new_file, champ) == 84) {
        fclose(new_file);
        return 84;
    }
    fclose(new_file);
    return 0;
}
