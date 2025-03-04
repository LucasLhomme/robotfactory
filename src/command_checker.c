/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** find command and redirect it to his file
*/

#include "my.h"
#include "lib.h"

const command_t command[] = {
    {"live", command_live},
    {"ld", command_ld},
    {"st", command_st},
    {"add", command_add},
    {"sub", command_sub},
    {"and", command_and},
    {"or", command_or},
    {"xor", command_xor},
    {"zjmp", command_zjmp},
    {"ldi", command_ldi},
    {"sti", command_sti},
    {"fork", command_fork},
    {"lld", command_lld},
    {"lldi", command_lldi},
    {"lfork", command_lfork},
    {"aff", command_aff},
    {'\0', NULL},
};
