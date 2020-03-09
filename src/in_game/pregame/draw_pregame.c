/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"


// ? Draw les élements pregame menu.

void draw_pregame(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                        game->menu.ui_pregame[0].sprite, NULL);
    if (game->button.state_pregame[0] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                                        game->button.pregame[0].sprite, NULL);
    if (game->button.state_pregame[1] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                                        game->button.pregame[1].sprite, NULL);
    sfRenderWindow_drawText(game->window->window,
                                    game->game_text.pregame[0].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                                    game->game_text.pregame[1].string, NULL);
    if (game->button.state_pregame[2] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                                game->button.pregame[3].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                                game->button.pregame[2].sprite, NULL);
    return;
}