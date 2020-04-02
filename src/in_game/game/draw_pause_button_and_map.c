/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"

void draw_map_ig(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
                        game->menu.ui_in_game[IG_MAP_LEVEL_ONE].sprite, NULL);
    return;
}

void draw_pause_button_ig(game_t *game)
{
    if (game->button.state_in_game[IG_PAUSE_BUT] == 1)
    sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_PAUSE_BUT_HOV].sprite, NULL);
    else
    sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_PAUSE_BUT].sprite, NULL);
    return;
}