/*
** EPITECH PROJECT, 2025
** mini_shell 1
** File description:
** main file
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "lib.h"

void flag_h(void)
{
    my_printf("USAGE ./asm file_name[.s]\nDESCRIPTION\n"
        "file_name file in assembly language"
        " to be converted into file_name.cor,"
        " an executable in the Virtual Machine.\n");
}

int main(int argc, char **argv)
{
    champion_t *champion = malloc(sizeof(champion_t) * 1);

    if (argc <= 1)
        my_printf("Usage: ./asm file_name[.s] ....\n");
    else if (my_strcmp(argv[1], "-h") == 0)
        flag_h();
    if (error_handling(argc, argv) == 84)
        return 84;
    champion = create_champions(argv[1]);
    if (!champion)
        return 84;
    return 0;
}
