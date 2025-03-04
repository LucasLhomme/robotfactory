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
    {NULL, NULL},
};

int find_command(champion_t *champion, node_t *cmd)
{
    for (int i = 0; command[i].command != NULL; i++) {
        if (command[i].command == cmd->command)
            return command[i].command_name(cmd->command, cmd->value);
    }
    return 84;
}

int command_checker(champion_t *champion)
{
    node_t *cmd = champion->next;

    for (node_t *cmd = champion->next; cmd; cmd = cmd->next) {
        if (find_command(champion, cmd) == 84)
            return 84;
    }
    return 0;
}
