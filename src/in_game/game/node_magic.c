/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

add_arrow_t *create_magic_arrow(game_t *game, add_arrow_t *node,
                                                    arrow_info_t info, int i)
{
    add_arrow_t *last = game->head_arrow;

    if (i == 0)
        node->arrow = create_magic_generic_function(game, info);
    else if (i == 1)
        node->arrow = create_magic_generic_function_mini(game, info);
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

create_arrow_t create_magic_generic_function(game_t *game, arrow_info_t info)
{
    create_arrow_t arrow;
    sfVector2f scale = {1.3 * game->window->scale.x,
    1.3 * game->window->scale.y};
    if (info.type == 0)
        arrow.texture = sfTexture_createFromFile("png/ingame/24.png", NULL);
    else if (info.type == 2)
        arrow.texture = sfTexture_createFromFile("png/ingame/20.png", NULL);
    arrow.sprite = sfSprite_create();
    info.pos_ennemy.x += 30 * game->window->scale.x;
    if (info.type == 0)
        info.pos_ennemy.x += 10 * game->window->scale.x;
    info.pos_ennemy.y += -20 * game->window->scale.y;
    sfSprite_setTexture(arrow.sprite, arrow.texture, sfTrue);
    sfSprite_setPosition(arrow.sprite, info.pos_ennemy);
    sfSprite_setScale(arrow.sprite, scale);
    arrow.position = info.pos_ennemy;
    arrow.hit = 0;
    arrow.loop = 0;
    arrow.type = 0;
    return (arrow);
}

create_arrow_t create_magic_generic_function_mini(game_t *game,
                                                        arrow_info_t info)
{
    create_arrow_t arrow;
    sfVector2f scale = {0.8, 0.8};
    sfSound_play(game->sounds[1]);

    if (info.type == 0)
        arrow.texture = sfTexture_createFromFile("png/ingame/24.png", NULL);
    else if (info.type == 2)
        arrow.texture = sfTexture_createFromFile("png/ingame/20.png", NULL);
    arrow.sprite = sfSprite_create();
    info.pos_ennemy.x += 60 * game->window->scale.x;
    info.pos_ennemy.y += -20 * game->window->scale.y;
    sfSprite_setTexture(arrow.sprite, arrow.texture, sfTrue);
    sfSprite_setPosition(arrow.sprite, info.pos_ennemy);
    sfSprite_setScale(arrow.sprite, scale);
    arrow.position = info.pos_ennemy;
    arrow.hit = 0;
    arrow.loop = 0;
    arrow.type = 0;
    return (arrow);
}