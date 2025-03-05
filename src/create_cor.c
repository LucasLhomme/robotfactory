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
    int instruction_code = 0x0b;
    int param1_type = 1;
    int param2_type = 2;
    int param3_type = 3;

    if (champ == NULL || champ->name == NULL || champ->comment == NULL)
        return 84;
    my_strcpy(namefile, champ->name);
    my_strcat(namefile, ".cor");
    new_file = fopen(namefile, "w+");
    if (new_file == NULL)
        return 84;
    if (write_header(new_file, champ) == 84) {
        fclose(new_file);
        return 84;
    }
    fclose(new_file);
    return 0;
}
