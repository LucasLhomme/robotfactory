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

    if (!champ || !champ->name || !champ->comment)
        return 84;
    my_strcpy(namefile, champ->name);
    my_strncat(namefile, ".cor", sizeof(namefile) - my_strlen(namefile) - 1);
    new_file = fopen(namefile, "w+");
    if (!new_file)
        return 84;
    if (write_header(new_file, champ) == 84) {
        fclose(new_file);
        return 84;
    }
    fclose(new_file);
    return 0;
}
