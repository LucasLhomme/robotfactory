/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
** File description:
** write_coding_byte
*/
#include "my.h"
#include "lib.h"
#include "op.h"
#include <stdio.h>

int write_header(FILE *new_file, champion_t *champ)
{
    header_t header;

    if (!new_file || !champ || !champ->name || !champ->comment)
        return 84;
    memset(&header, 0, sizeof(header_t));
    header.magic = my_revbyte_32(COREWAR_EXEC_MAGIC);
    my_strncpy(header.prog_name, champ->name, PROG_NAME_LENGTH);
    header.prog_name[PROG_NAME_LENGTH] = '\0'; 
    header.prog_size = my_revbyte_32(champ->prog_size);
    my_strncpy(header.comment, champ->comment, COMMENT_LENGTH);
    header.comment[COMMENT_LENGTH] = '\0';
    if (fwrite(&header, sizeof(header_t), 1, new_file) != 1)
        return 84;
    return 0;
}

