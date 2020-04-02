/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

void destroy_node_ennemy(add_ennemy_t **head)
{
    add_ennemy_t *current = *head;
    add_ennemy_t *next;

    while (current->next != NULL) {
        next = current->next;
        free_node_ennemy(current);
        current = next;
    }
    *head = NULL;
    return;
}

int is_ennemy_in_game(game_t *game)
{
    add_ennemy_t *current = game->head_ennemy;
    int i = 0;

    while (current != NULL) {
        if (current->ennemy.ennemy_life <= 0)
            ++i;
        current = current->next;
    }
    if (i == 10) {
        destroy_node_ennemy(&(game->head_ennemy));
        destroy_node_arrow(&(game->head_arrow), game);
    game->player_data.next_wave_in = 11;
    game->player_data.wave_number += 1;
    create_ennemy(game);
    game->player_data.clock_wave = NULL;
    }
    return (1);
}

void destroy_node_arrow(add_arrow_t **head, game_t *game)
{
    if (game->head_arrow == NULL)
        return;
    add_arrow_t *current = *head;
    add_arrow_t *next;

    while (current->next != NULL) {
        next = current->next;
        free_node_arrow(current);
        current = next;
    }
    *head = NULL;
    return;
}

int free_node_ennemy(add_ennemy_t *tmp)
{
    if (tmp) {
        sfTexture_destroy(tmp->ennemy.texture);
        sfSprite_destroy(tmp->ennemy.sprite);
        free(tmp);
    }
    return (1);
}

int free_node_arrow(add_arrow_t *tmp)
{
    if (tmp) {
        sfTexture_destroy(tmp->arrow.texture);
        sfSprite_destroy(tmp->arrow.sprite);
        free(tmp);
    }
    return (1);
}