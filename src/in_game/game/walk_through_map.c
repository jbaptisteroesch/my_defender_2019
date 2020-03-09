/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"


// ? Check le state de chacun des ennemy dans le début de map.

sfVector2f change_state_begin_map(game_t *game, add_ennemy_t *ennemy)
{
    int i = ennemy->ennemy.state;

    if (i > 13)
        i = 13;
    if (i % 2 != 0) {
        if (ennemy->ennemy.set_position.x < (game->map_path[i]))
            ennemy->ennemy.set_position.x += 2 * game->window->scale.x;
        if (ennemy->ennemy.set_position.x >= (game->map_path[i]))
            ennemy->ennemy.state++;
    }
    else if (i % 2 == 0) {
        if (ennemy->ennemy.set_position.y < (
                            game->map_path[i] - ennemy->ennemy.rect.height))
            ennemy->ennemy.set_position.y += 2 * game->window->scale.y;
        if (ennemy->ennemy.set_position.y >= (
                            game->map_path[i] - ennemy->ennemy.rect.height))
            ++ennemy->ennemy.state;
    }
    return (ennemy->ennemy.set_position);
}


// ? Fait avancer les ennemy.

int walk_through_map(game_t *game)
{
    add_ennemy_t *current = game->head_ennemy;
    sfVector2f pos;

    while (current != NULL) {
        pos = sfSprite_getPosition(current->ennemy.sprite);
        if (pos.y >= 10 * game->window->scale.y) {
            current->ennemy.set_position = change_state_begin_map(game,
                                                                    current);
            sfSprite_setPosition(current->ennemy.sprite,
                                            current->ennemy.set_position);
        } else if (pos.y < 10 * game->window->scale.y) {
            current->ennemy.set_position.y += 2 * game->window->scale.y;
            sfSprite_setPosition(current->ennemy.sprite,
                                            current->ennemy.set_position);
        }
        current = current->next;
    }
    return (1);
}