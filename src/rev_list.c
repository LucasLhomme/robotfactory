/*
** EPITECH PROJECT, 2025
** lib
** File description:
** rev_list
*/

#include "../../include/my.h"

void rev_list(champion_t *champion)
{
    node_t *previous = NULL;
    node_t *actual = champion->commandsList;
    node_t *next = NULL;

    while (actual != NULL) {
        next = actual->next;
        actual->next = previous;
        previous = actual;
        actual = next;
    }
}