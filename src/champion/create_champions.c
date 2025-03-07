/*
** EPITECH PROJECT, 2025
** robot factory
** File description:
** parse the file
*/

#include "my.h"
#include "lib.h"
#include <string.h>

void free_champion(FILE *file, char **tab)
{
    fclose(file);
    free(tab);
}

void initialize_champion(champion_t *champion)
{
    champion->name = NULL;
    champion->comment = NULL;
    champion->commandsList = NULL;
}

champion_t *parse_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    champion_t *champion = malloc(sizeof(champion_t));
    char **tab = NULL;

    if (error_champion_handling(file, champion) == 84)
        return NULL;
    champion->name = my_get_name(file);
    champion->comment = get_comment(file);
    if (!champion->name || !champion->comment)
        return NULL;
    get_command_list(file, champion);
    free_champion(file, tab);
    return champion;
}

char *find_filename(char *filename)
{
    char **tab = my_str_to_word_array_advanced(filename, "_-");
    int i = 0;
    char *result;

    if (!tab || !filename || filename[0] == '\0')
        return NULL;
    for (; tab[i] != NULL; i++);
    if (i < 2) {
        my_free_word_array(tab);
        return NULL;
    }
    result = my_strdup(tab[i - 2]);
    my_free_word_array(tab);
    return result;
}

champion_t *create_champions(char *filename)
{
    champion_t *champion = malloc(sizeof(champion_t));
    char *name = NULL;

    if (!champion)
        return NULL;
    champion = parse_file(filename);
    if (!champion) {
        free(champion);
        return NULL;
    }
    name = find_filename(filename);
    if (!name) {
        free(champion);
        return NULL;
    }
    champion->filename = my_strdup(name);
    free(name);
    if (!champion->filename) {
        free(champion);
        return NULL;
    }
    return champion;
}


