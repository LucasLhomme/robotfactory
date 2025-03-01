/*
** EPITECH PROJECT, 2025
** robot factory
** File description:
** parse the file
*/

#include "my.h"
#include "lib.h"
#include <string.h>

void free_champion(FILE *file, char *line, char **tab)
{
    fclose(file);
    free(line);
    free(tab);
}

void initialize_champion(champion_t *champion)
{
    champion->name = NULL;
    champion->comment = NULL;
    champion->next = NULL;
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
    read = getline(&line, &len, file);
    while ((getline(&line, &len, file)) != -1) {
        parse_command(champion, line);
        read = getline(&line, &len, file);
    }
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
