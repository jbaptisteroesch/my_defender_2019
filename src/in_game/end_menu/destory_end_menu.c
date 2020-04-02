/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"

void destroy_end_menu(game_t *game)
{
    for (int i = 0; i < 2; ++i) {
        sfTexture_destroy(game->menu.ui_end_menu[i].texture);
        sfSprite_destroy(game->menu.ui_end_menu[i].sprite);
        sfText_destroy(game->game_text.end_menu[i].string);
        sfFont_destroy(game->game_text.end_menu[i].font);
    }
    return;
}