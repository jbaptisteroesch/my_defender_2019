/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"

void draw_ennemy_wave(game_t *game)
{
    if (game->head_ennemy == NULL)
        return;
    add_ennemy_t *current = game->head_ennemy;

    walk_ennemy(game);
    while (current != NULL) {
        if (current->ennemy.ennemy_life > 0)
            sfRenderWindow_drawSprite(game->window->window,
                                        current->ennemy.sprite, NULL);
        current = current->next;
    }
    return;
}