/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"

int open_set_shop_buttons_pos_after_animation(game_t *game)
{

    sfSprite_setPosition(game->button.in_game[IG_BT_BUT].sprite,
                                    game->button.in_game[IG_BT_BUT].position);
    sfSprite_setPosition(game->button.in_game[IG_YT_BUT].sprite,
                                    game->button.in_game[IG_YT_BUT].position);
    sfSprite_setPosition(game->button.in_game[IG_ST_BUT].sprite,
                                    game->button.in_game[IG_ST_BUT].position);
    sfSprite_setPosition(game->button.in_game[IG_RT_BUT].sprite,
                                    game->button.in_game[IG_RT_BUT].position);
    return (1);
}

int set_hover_buttons(game_t *game)
{
    game->button.in_game[IG_BT_BUT_HOV].position.y = 291 *
                                                        game->window->scale.y;
    game->button.in_game[IG_YT_BUT_HOV].position.y = 438 *
                                                        game->window->scale.y;
    game->button.in_game[IG_ST_BUT_HOV].position.y = 585 *
                                                        game->window->scale.y;
    game->button.in_game[IG_RT_BUT_HOV].position.y = 732 *
                                                        game->window->scale.y;
    sfSprite_setPosition(game->button.in_game[IG_BT_BUT_HOV].sprite,
                                game->button.in_game[IG_BT_BUT_HOV].position);
    sfSprite_setPosition(game->button.in_game[IG_YT_BUT_HOV].sprite,
                                game->button.in_game[IG_YT_BUT_HOV].position);
    sfSprite_setPosition(game->button.in_game[IG_ST_BUT_HOV].sprite,
                                game->button.in_game[IG_ST_BUT_HOV].position);
    sfSprite_setPosition(game->button.in_game[IG_RT_BUT_HOV].sprite,
                                game->button.in_game[IG_RT_BUT_HOV].position);
    return (1);
}