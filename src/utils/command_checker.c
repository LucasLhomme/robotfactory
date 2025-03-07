/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** find command and redirect it to his file
*/

#include "my.h"
#include "lib.h"
#include "op.h"

static int count_number_array(char **tab)
{
    int i = 0;

    for (;tab[i] != NULL; i++);
    return i;
}

static char *find_number(char *str)
{
    for (;*str && my_isdigit(*str) != 0; str++);
    return str;
}

int my_isnumber(const char *str)
{
    if (!str || *str == '\0')
        return 0;
    if (*str == '-' || *str == '+')
        str++;
    for (; *str; str++) {
        if (!my_isdigit(*str))
            return 0;
    }
    return 1;
}

int extract_number_str(char *str)
{
    while (*str) {
        if (my_isalpha(*str) == 0) {
            str++;
            str = find_number(str);
            return my_atoi(str);
        }
        str++;
    }
    return 0;
}

int check_type(char *args, int expected_type)
{
    int actual_type = 0;

    switch (args[0]) {
    case 'r':
        if (extract_number_str(args) >= 1 && extract_number_str(args) <= REG_NUMBER)
            actual_type = T_REG;
        break;
    case '%':
        if (args[1] == ':') {
            actual_type = T_LAB;
            break;
        } else {
            actual_type = T_DIR;
            break;
        }
    default:
        if (my_isnumber(args))
            actual_type = T_IND;
        break;
    }
    if (!(expected_type & actual_type))
        return 84;
    return 0;
} 

int command_error_handling(node_t *cmd, int index)
{
    char **tab = my_str_to_word_array_advanced(cmd->value, "%:");

    if (op_tab[index].nbr_args != count_number_array(tab))
        return 84;
    for (int i = 0; tab[i] != NULL; i++)
        if (check_type(tab[i], op_tab[index].type[i]) == 84)
            return 84;
    return 0;
}

int find_command(node_t *cmd)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (op_tab[i].mnemonique == cmd->command) {
            return command_error_handling(cmd, i);
        }
    }
    return 84;
}

int command_checker(champion_t *champion)
{
    if (!champion)
        return 84;
    for (node_t *cmd = champion->commandsList; cmd; cmd = cmd->next) {
        if (find_command(cmd) == 84) {
            return 84;
        }
    }
    return 0;
}
