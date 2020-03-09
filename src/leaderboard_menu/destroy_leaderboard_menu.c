/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** destroy leaderboard menu
*/

#include "../../include/my.h"


// ? Détruit les boutons et l'UI du leaderboard menu.

int destroy_buttons_and_ui_leaderboard_menu(game_t *game)
{
    sfSprite_destroy(game->button.leaderboard[0].sprite);
    sfTexture_destroy(game->button.leaderboard[0].texture);
    sfSprite_destroy(game->button.leaderboard[1].sprite);
    sfTexture_destroy(game->button.leaderboard[1].texture);
    sfSprite_destroy(game->menu.ui_leaderboard_menu.sprite);
    sfTexture_destroy(game->menu.ui_leaderboard_menu.texture);
    return (1);
}


// ? Détruit le text du leaderboard menu.

int destroy_text_leaderboard_menu(game_t *game)
{
    for (int i = 0; i < 7; ++i) {
        sfFont_destroy(game->game_text.score[i].font);
        sfText_destroy(game->game_text.score[i].string);
    }
    return (1);
}


// ? Détruit les éléments du menu leaderboard.

int destroy_leaderboard_menu(game_t *game)
{
    destroy_buttons_and_ui_leaderboard_menu(game);
    destroy_text_leaderboard_menu(game);
    return (1);
}
