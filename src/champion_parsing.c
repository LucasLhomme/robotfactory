/*
** EPITECH PROJECT, 2025
** robot factory
** File description:
** parse champion
*/

#include "my.h"
#include "lib.h"
#include <stdio.h>

/*

int error_name_handling(char **tab)
{
    (void)tab;
    return 0;
}
 */

void add_command(node_t **head, char *command, char *value, int id)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        return;
    new_node->command = my_strdup(command);
    new_node->value = value ? my_strdup(value) : NULL;
    new_node->id = id;
    new_node->next = *head;
    *head = new_node;
}

char *get_comment(FILE *file)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    char **tab = NULL;
    char *comment = NULL;

    read = getline(&line, &len, file);
    if (read == -1)
        return NULL;
    tab = my_str_to_word_array_advanced(line, ".");
    if (!tab)
        return NULL;
    if (my_strcmp(tab[0], ".comment") != 0)
        return NULL;
    comment = extract_str(line, '"');
    return comment;
}

char *my_get_name(FILE *file)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    char **tab = NULL;
    char *name = NULL;

    read = getline(&line, &len, file);
    if (read == -1)
        return NULL;
    tab = my_str_to_word_array_advanced(line, ".\"");
    if (!tab[0])
        return NULL;
    if (my_strcmp(tab[0], ".name") != 0)
        return NULL;
    name = extract_str(line, '"');
    return name;
}

void get_command_list(FILE *file, champion_t *champion)
{
    size_t len = 0;
    char *line = NULL;
    ssize_t read = getline(&line, &len, file);
    static int id = 0;
    char *cmd = NULL;
    char *val = NULL;

    if (!champion || !file)
        return;
    for (; read != -1; read = getline(&line, &len, file)) {
        if (line[0] != '.' && my_strlen(line) > 1) {
            cmd = my_strtok(line, " ");
            val = my_strtok(NULL, "\n");
            add_command(&champion->next, cmd, val, id++);
        }
    }
}
