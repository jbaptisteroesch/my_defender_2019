/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

int move_every_arrows(game_t *game)
{
    add_arrow_t *tmp = game->head_arrow;
    sfVector2f vec;

    while (tmp != NULL) {
        if (tmp->arrow.type == 1) {
            vec = tmp->arrow.position;
            vec.x = vec.x / 5;
            vec.y = vec.y / 5;
            sfSprite_move(tmp->arrow.sprite, vec);
        }
            tmp = tmp->next;
    }
    return (1);
}

int hit_box_arrow(game_t *game)
{
    sfBool hit = false;
    add_ennemy_t *tmp2 = game->head_ennemy;
    add_arrow_t *tmp = game->head_arrow;
    sfFloatRect hitbox;
    sfVector2f arrow;
    for (; tmp != NULL; tmp = tmp->next) {
        for (; tmp2 != NULL; tmp2 = tmp2->next) {
            hitbox = sfSprite_getGlobalBounds(tmp2->ennemy.sprite);
            arrow = sfSprite_getPosition(tmp->arrow.sprite);
            hit = sfFloatRect_contains(&hitbox, arrow.x, arrow.y);
            if (hit == true && tmp->arrow.type == 1 && tmp->arrow.hit != 1) {
                tmp->arrow.hit = 1;
                tmp2->ennemy.ennemy_life -= tmp->arrow.damage;
                hit = false;
                break;
            }
        }
        tmp2 = game->head_ennemy;
    }
    return (1);
}