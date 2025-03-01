/*
** EPITECH PROJECT, 2025
** mini_shell 1
** File description:
** main file
*/

#include "my.h"
#include "lib.h"

int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == 84)
        return 84;
    if (create_champions(argv[1]) == NULL)
        return 84;
    return 0;
}
