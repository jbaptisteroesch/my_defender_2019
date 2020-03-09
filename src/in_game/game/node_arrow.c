/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

int add_node_arrow(game_t *game, arrow_info_t info)
{
    add_arrow_t *node = NULL;

    if (!(node = malloc(sizeof(add_arrow_t))))
        return (change_state_cause_of_error(game));
    game->head_arrow = create_node_arrow(game, node, info);
    return (1);
}

add_arrow_t *create_node_arrow(game_t *game, add_arrow_t *node,
                                                        arrow_info_t info)
{
    add_arrow_t *last = game->head_arrow;

    node->arrow = create_arrow_generic_function(game, info);
    node->next = NULL;
    if (game->head_arrow == NULL) {
        game->head_arrow = node;
        return (game->head_arrow);
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node;
    return (game->head_arrow);
}

create_arrow_t create_arrow_generic_function(game_t *game, arrow_info_t info)
{
    create_arrow_t arrow;
    sfVector2f scale = {0.4 * game->window->scale.x,
    0.4 * game->window->scale.y};

    arrow.texture = sfTexture_createFromFile("png/ingame/35.png", NULL);
    arrow.sprite = sfSprite_create();
    info.pos_tower.x += 30 * game->window->scale.x;
    if (info.second == 1)
        info.pos_tower.x += 30 * game->window->scale.x;
    info.pos_tower.y += 50 * game->window->scale.y;
    sfSprite_setTexture(arrow.sprite, arrow.texture, sfTrue);
    sfSprite_setPosition(arrow.sprite, info.pos_tower);
    sfSprite_setRotation(arrow.sprite, info.rotate);
    sfSprite_setScale(arrow.sprite, scale);
    arrow.position = info.pos_ennemy;
    arrow.hit = 0;
    arrow.loop = 0;
    arrow.type = 1;
    arrow.damage = info.damage;
    return (arrow);
}

int add_magic_arrow(game_t *game, arrow_info_t info, int i)
{
    add_arrow_t *node = NULL;

    if (!(node = malloc(sizeof(add_arrow_t))))
        return (change_state_cause_of_error(game));
    game->head_arrow = create_magic_arrow(game, node, info, i);
    return (1);
}