/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"

void draw_st_and_rt_towers(game_t *game)
{
    if (game->button.state_in_game[IG_ST_BUT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_ST_BUT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_ST_BUT].sprite, NULL);
    if (game->button.state_in_game[IG_RT_BUT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_RT_BUT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_RT_BUT].sprite, NULL);
    return;
}

void draw_bt_and_yt_towers(game_t *game)
{
    if (game->button.state_in_game[IG_BT_BUT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_BT_BUT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_BT_BUT].sprite, NULL);
    if (game->button.state_in_game[IG_YT_BUT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_YT_BUT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_YT_BUT].sprite, NULL);
    return;
}