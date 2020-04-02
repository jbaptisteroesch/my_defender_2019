/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** settings menu
*/

#include "../../include/my.h"

int destroy_settings_menu(game_t *game)
{
    for (int i = 0; i < 2; ++i) {
        sfSprite_destroy(game->menu.ui_settings_menu[i].sprite);
        sfTexture_destroy(game->menu.ui_settings_menu[i].texture);
    }
    for (int i = 0; i < 2; ++i) {
        sfSprite_destroy(game->button.settings_menu[i].sprite);
        sfTexture_destroy(game->button.settings_menu[i].texture);
    }
    return (1);
}