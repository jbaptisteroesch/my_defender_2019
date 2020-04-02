/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw leaderboard menu
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"

void draw_leaderboard_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                game->menu.ui_leaderboard_menu.sprite, NULL);
    if (game->button.state_leaderboard_menu == 1)
        sfRenderWindow_drawSprite(game->window->window,
                                game->button.leaderboard[1].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                                game->button.leaderboard[0].sprite, NULL);
    for (int i = 0; i < 7; ++i) {
        sfRenderWindow_drawText(game->window->window,
                                    game->game_text.score[i].string, NULL);
    }
    return;
}