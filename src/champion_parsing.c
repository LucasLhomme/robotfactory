/*
** EPITECH PROJECT, 2025
** robot factory
** File description:
** parse champion
*/

#include "my.h"
#include "lib.h"

void add_command(node_t **head, char *command, char *value, int id)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        return;
    new_node->command = strdup(command);
    new_node->value = value ? strdup(value) : NULL;
    new_node->id = id;
    new_node->next = *head;
    *head = new_node;
}

champion_t *get_comment(FILE *file, champion_t *champion)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    char **tab = NULL;

    read = getline(&line, &len, file);
    read = getline(&line, &len, file);
    if (read == -1)
        return NULL;
    tab = my_str_to_word_array(line);
    if (!tab)
        return NULL;
    if (my_strcmp(tab[0], "name") != 0)
        return NULL;
    champion->name = extract_str(line, '"');
    return champion;
}

champion_t *get_name(FILE *file, champion_t *champion)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    char **tab = NULL;

    read = getline(&line, &len, file);
    if (read == -1)
        return NULL;
    tab = my_str_to_word_array(line);
    if (!tab)
        return NULL;
    if (my_strcmp(tab[0], "name") != 0)
        return NULL;
    champion->name = extract_str(line, '"');
    return champion;
}

void parse_command(champion_t *champion, char *line)
{
    char *cmd = NULL;
    char *val = NULL;
    static int id = 0;

    cmd = NULL;
    val = NULL;
    add_command(&champion->next, cmd, val, id);
    id++;
    free(cmd);
    free(val);
}
