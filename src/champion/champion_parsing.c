/*
** EPITECH PROJECT, 2025
** robot factory
** File description:
** parse champion
*/

#include "my.h"
#include "lib.h"
#include <stdio.h>

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

static char *choose_command(char **tab)
{
    for (int i = 0; tab[0][i] != '\0'; i++) {
        if (tab[0][i] == ':' && tab[0][i + 1] == '\0')
            return tab[1];
    }
    return tab[0];
}

char *create_value(char **tab)
{
    int command = 0;
    char *value = NULL;

    for (int i = 0; tab[0][i] != '\0'; i++) {
        if (tab[0][i] == ':' && tab[0][i + 1] == '\0')
            command = 1;
    }
    if (tab[command + 1]) {
        value = my_strdup(tab[command + 1]);
        command++;
    }
    for (int i = command + 1; tab[i] != NULL; i++) {
        my_strcat(value, " ");
        my_strcat(value, tab[i]);
    }
    return value;
}

void get_command_list(FILE *file, champion_t *champion)
{
    size_t len = 0;
    char *line = NULL;
    ssize_t read = getline(&line, &len, file);
    static int id = 0;
    char *cmd = NULL;
    char *val = NULL;
    char **tab = NULL;

    if (!champion || !file)
        return;
    for (; read != -1; read = getline(&line, &len, file)) {
        if (line[0] != '.' && my_strlen(line) > 1) {
            tab = my_str_to_word_array_advanced(line, "%:");
            cmd = my_strdup(choose_command(tab));
            val = my_strdup(create_value(tab));
            add_command(&champion->commandsList, cmd, val, id++);
        }
    }
}
