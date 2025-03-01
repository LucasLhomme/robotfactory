/*
** EPITECH PROJECT, 2025
** robot factory
** File description:
** parse the file
*/

#include "my.h"
#include "lib.h"
#include <string.h>

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

void initialize_champion(champion_t *champion)
{
    champion->name = NULL;
    champion->comment = NULL;
    champion->next = NULL;
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

void free_champion(FILE *file, char *line, char **tab)
{
    fclose(file);
    free(line);
    free(tab);
}

void parse_command(champion_t *champion, char *line)
{
    char *cmd = NULL;
    char *val = NULL;
    static int id = 0;

    cmd = strtok(line, " ");
    val = strtok(NULL, "\n");
    add_command(&champion->next, cmd, val, id);
    id++;
    free(cmd);
    free(val);
}

champion_t *parse_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    champion_t *champion = malloc(sizeof(champion_t));
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **tab = NULL;

    if (error_champion_handling(file, champion) == 84)
        return NULL;
    if (!get_comment(file, champion) || !get_name(file, champion))
        return NULL;
    while ((read = getline(&line, &len, file)) != -1)
        parse_command(champion, line);
    free_champion(file, line, tab);
    return champion;
}

champion_t *create_champions(char *filename)
{
    champion_t *champion = parse_file(filename);

    if (champion == NULL)
        return NULL;
    return champion;
}
