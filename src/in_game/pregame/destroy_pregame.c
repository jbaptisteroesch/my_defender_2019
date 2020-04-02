/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"

void destroy_pregame(game_t *game)
{
    sfSprite_destroy(game->menu.ui_pregame[0].sprite);
    sfSprite_destroy(game->button.pregame[0].sprite);
    sfSprite_destroy(game->button.pregame[1].sprite);
    sfText_destroy(game->game_text.pregame[0].string);
    sfText_destroy(game->game_text.pregame[1].string);
    sfFont_destroy(game->game_text.pregame[0].font);
    sfFont_destroy(game->game_text.pregame[1].font);
    return;
}