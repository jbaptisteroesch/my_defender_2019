
/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

int hold_blue_tower(game_t *game)
{
    if (game->player_data.holding_bt == true) {
        sfRenderWindow_setMouseCursorVisible(game->window->window, sfFalse);
        game->entity.towers[BLUE_TOWER].set_position.x =
                        game->mouse_position.x - 81 * game->window->scale.x;
        game->entity.towers[BLUE_TOWER].set_position.y =
                        game->mouse_position.y - 114 * game->window->scale.y;
        sfSprite_setPosition(game->entity.towers[BLUE_TOWER].sprite,
                                game->entity.towers[BLUE_TOWER].set_position);
        sfSprite_setScale(game->entity.towers[BLUE_TOWER].sprite,
        game->window->scale);
        game->entity.color_towers = sfColor_fromRGBA(0, 0, 0, 225);
        sfSprite_setColor(game->entity.towers[BLUE_TOWER].sprite,
                                        game->entity.color_towers);
        sfRenderWindow_drawSprite(game->window->window,
                                game->entity.towers[BLUE_TOWER].sprite, NULL);
    } else
        return (1);
    return (1);
}

int hold_yellow_tower(game_t *game)
{
    if (game->player_data.holding_yt == true) {
        sfRenderWindow_setMouseCursorVisible(game->window->window, sfFalse);
        game->entity.towers[YELLOW_TOWER].set_position.x =
                        game->mouse_position.x - 81 * game->window->scale.x;
        game->entity.towers[YELLOW_TOWER].set_position.y =
                        game->mouse_position.y - 114 * game->window->scale.y;
        sfSprite_setPosition(game->entity.towers[YELLOW_TOWER].sprite,
                                game->entity.towers[YELLOW_TOWER].set_position);
        sfSprite_setScale(game->entity.towers[YELLOW_TOWER].sprite,
        game->window->scale);
        game->entity.color_towers = sfColor_fromRGBA(0, 0, 0, 225);
        sfSprite_setColor(game->entity.towers[YELLOW_TOWER].sprite,
                                        game->entity.color_towers);
        sfRenderWindow_drawSprite(game->window->window,
                            game->entity.towers[YELLOW_TOWER].sprite, NULL);
    } else
        return (1);
    return (1);
}

int hold_straw_tower(game_t *game)
{
    if (game->player_data.holding_st == true) {
        sfRenderWindow_setMouseCursorVisible(game->window->window, sfFalse);
        game->entity.towers[STRAW_TOWER].set_position.x =
                        game->mouse_position.x - 69 * game->window->scale.x;
        game->entity.towers[STRAW_TOWER].set_position.y =
                        game->mouse_position.y - 116.5 * game->window->scale.y;
        sfSprite_setPosition(game->entity.towers[STRAW_TOWER].sprite,
                            game->entity.towers[STRAW_TOWER].set_position);
        sfSprite_setScale(game->entity.towers[STRAW_TOWER].sprite,
        game->window->scale);
        game->entity.color_towers = sfColor_fromRGBA(0, 0, 0, 225);
        sfSprite_setColor(game->entity.towers[STRAW_TOWER].sprite,
                                        game->entity.color_towers);
        sfRenderWindow_drawSprite(game->window->window,
                            game->entity.towers[STRAW_TOWER].sprite, NULL);
    } else
        return (1);
    return (1);
}

int hold_rock_tower(game_t *game)
{
    if (game->player_data.holding_rt == true) {
        sfRenderWindow_setMouseCursorVisible(game->window->window, sfFalse);
        game->entity.towers[ROCK_TOWER].set_position.x =
                        game->mouse_position.x - 69 * game->window->scale.x;
        game->entity.towers[ROCK_TOWER].set_position.y =
                        game->mouse_position.y - 83 * game->window->scale.y;
        sfSprite_setPosition(game->entity.towers[ROCK_TOWER].sprite,
                                game->entity.towers[ROCK_TOWER].set_position);
        sfSprite_setScale(game->entity.towers[ROCK_TOWER].sprite,
        game->window->scale);
        game->entity.color_towers = sfColor_fromRGBA(0, 0, 0, 225);
        sfSprite_setColor(game->entity.towers[ROCK_TOWER].sprite,
                                        game->entity.color_towers);
        sfRenderWindow_drawSprite(game->window->window,
                            game->entity.towers[ROCK_TOWER].sprite, NULL);
    } else
        return (1);
    return (1);
}