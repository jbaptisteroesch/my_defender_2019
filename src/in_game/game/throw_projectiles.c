/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

int throw_magic(add_ennemy_t *tmp1, add_tower_t *tmp2, game_t *game)
{
    int type = tmp2->tower.tower_type;
    arrow_info_t arrow;
    sfVector2f pos1 = sfSprite_getPosition(tmp1->ennemy.sprite);
    arrow.type = type;
    tmp1->ennemy.ennemy_life -= tmp2->tower.damage;
    arrow.pos_ennemy = pos1;
    add_magic_arrow(game, arrow, 0);
    pos1 = sfSprite_getPosition(tmp2->tower.sprite);
    arrow.pos_ennemy = pos1;
    add_magic_arrow(game, arrow, 1);
    return (1);
}

int throw_arrow(add_ennemy_t *tmp_ennemy, add_tower_t *tmp_tower, game_t *game)
{
    arrow_info_t info; sfVector2f vec;
    info.level = tmp_tower->tower.level;
    sfVector2f pos = sfSprite_getPosition(tmp_tower->tower.sprite);
    sfVector2f pos2 = sfSprite_getPosition(tmp_ennemy->ennemy.sprite);
    float f1 = pos.x - pos2.x + 40 * game->window->scale.x;
    float f2 = pos.y - pos2.y + 40 * game->window->scale.y;
    float rotate = atan2f(f2, f1) * 180 / 3.14159265359 - 40;
    info.damage = tmp_tower->tower.damage;
    info.rotate = rotate;
    info.pos_tower = pos;
    f1 = pos2.x - pos.x + 30 * game->window->scale.x;
    f2 = pos2.y - pos.y + 30 * game->window->scale.y;
    vec.x = f1;
    vec.y = f2;
    info.pos_ennemy = vec;
    add_node_arrow(game, info);
    if (info.level == 3) {
        info.second = 1;
        add_node_arrow(game, info);
    }
    return (1);
}