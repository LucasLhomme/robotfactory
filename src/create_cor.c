/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
** File description:
** temp
*/
#include "my.h"
#include "lib.h"

#include "my.h"
#include "lib.h"

int create_cor(champion_t *champ) {
    char namefile[256];
    FILE *new_file = NULL;

    if (champ == NULL || champ->name == NULL || champ->comment == NULL)
        return 84;
    my_strcpy(namefile, champ->name);
    my_strcat(namefile, ".cor");
    printf("name of the file: %s\n", namefile);
    printf("champ name: %s\n", champ->name);
    printf("champ comment: %s\n", champ->comment);
    new_file = fopen(namefile, "w+");
    if (new_file == NULL)
        return 84;
    fwrite(champ, sizeof(champion_t), 1, new_file);
    fclose(new_file);
    return 0;
}
