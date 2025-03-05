/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-robotfactory-lucas.lhomme
** File description:
** coding_byte
*/
#include "my.h"
#include <stdint.h>

uint8_t create_coding_byte(int param1_type, int param2_type, int param3_type)
{
    uint8_t coding_byte = 0;

    coding_byte |= (param1_type << 6);
    coding_byte |= (param2_type << 4);
    coding_byte |= (param3_type << 2);
    return coding_byte;
}
