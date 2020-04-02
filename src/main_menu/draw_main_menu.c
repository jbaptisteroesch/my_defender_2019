/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw main menu
*/

#include "../include/my.h"

void draw_main_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                game->menu.ui_main_menu[BACK].sprite, NULL);
    draw_play_button_main_menu(game);
    draw_leaderboard_button_main_menu(game);
    draw_settings_button_main_menu(game);
    draw_quit_button_main_menu(game);
    return;
}