/*
** EPITECH PROJECT, 2025
** lib
** File description:
** rev_list
*/

#include "my.h"

void rev_list(champion_t *champion)
{
    node_t *previous = NULL;
    node_t *actual = NULL;
    node_t *next = NULL;

    if (!champion || !champion->commandsList)
        return;
    actual = champion->commandsList;
    while (actual != NULL) {
        next = actual->next;
        actual->next = previous;
        previous = actual;
        actual = next;
    }
    champion->commandsList = previous;
}
