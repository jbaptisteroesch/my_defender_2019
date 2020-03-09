/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"

void draw_end_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                    game->menu.ui_end_menu[BACK].sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                    game->menu.ui_end_menu[1].sprite, NULL);
    sfRenderWindow_drawText(game->window->window,
                                    game->game_text.end_menu[0].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                                    game->game_text.end_menu[1].string, NULL);
    return;
}