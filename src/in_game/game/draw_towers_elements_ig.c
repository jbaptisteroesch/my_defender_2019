/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"


// ? Draw les tours posées.

void draw_placed_towers(game_t *game)
{
    add_tower_t *current = game->head_tower;

    while (current != NULL) {
        sfRenderWindow_drawSprite(game->window->window,
                                current->tower.sprite, NULL);
        current = current->next;
    }
    return;
}


// ? Draw les projectiles des tours.

void draw_sprite_shot(game_t *game)
{
    add_arrow_t *tmp = game->head_arrow;

    while (tmp != NULL) {
        if (tmp->arrow.hit == 0 && tmp->arrow.type == 1)
        sfRenderWindow_drawSprite(game->window->window, tmp->arrow.sprite, NULL
        );
        else if (tmp->arrow.hit == 1 && tmp->arrow.loop <= 1 &&
            tmp->arrow.type == 1) {
            sfRenderWindow_drawSprite(game->window->window, tmp->arrow.sprite,
            NULL);
            tmp->arrow.loop++;
        }
        else if (tmp->arrow.type == 0 && tmp->arrow.loop <= 15) {
            sfRenderWindow_drawSprite(game->window->window, tmp->arrow.sprite,
            NULL);
            tmp->arrow.loop++;
        }
        tmp = tmp->next;
    }
}