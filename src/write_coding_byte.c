/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
** File description:
** write_coding_byte
*/
#include "my.h"
#include "lib.h"
#include "op.h"
#include <stdint.h>

int write_header(FILE *new_file, champion_t *champ)
{
    int name_len = 0;
    int comment_len = 0;
    int magic_number = COREWAR_EXEC_MAGIC;

    if (!new_file || !champ || !champ->name || !champ->comment)
        return 84;
    name_len = my_strlen(champ->name);
    comment_len = my_strlen(champ->comment);
    fwrite(&magic_number, sizeof(int), 1, new_file);
    fwrite(champ->name, sizeof(char), name_len, new_file);
    fseek(new_file, PROG_NAME_LENGTH - name_len, SEEK_CUR);
    fwrite("\0", sizeof(char), 1, new_file);
    fwrite(champ->comment, sizeof(char), comment_len, new_file);
    fseek(new_file, COMMENT_LENGTH - comment_len, SEEK_CUR);
    fwrite("\0", sizeof(char), 1, new_file);
    return 0;
}

int write_instruction_code(FILE *new_file, int instruction_code)
{
    fwrite(&instruction_code, sizeof(char), 1, new_file);
    return 0;
}

int write_coding_byte(FILE *new_file, int param1_type,
    int param2_type, int param3_type)
{
    uint8_t coding_byte;

    coding_byte = create_coding_byte(param1_type, param2_type, param3_type);
    fwrite(&coding_byte, sizeof(uint8_t), 1, new_file);
    return 0;
}

int write_parameters(FILE *new_file, char *param1,
    char *param2, char *param3)
{
    int dummy_value = 0x12345678;

    (void)param1;
    (void)param2;
    (void)param3;
    fwrite(&dummy_value, sizeof(int), 1, new_file);
    return 0;
}
