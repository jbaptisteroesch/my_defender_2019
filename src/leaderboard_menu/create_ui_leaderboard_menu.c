/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui leaderboard menu
*/

#include "../../include/my.h"

int create_ui_leaderboard_menu(game_t *game)
{
    game->menu.ui_leaderboard_menu = create_element(
                    game->menu.ui_leaderboard_menu,
                    "png/leaderboard_menu/highscore_table.png", 506.5, 218.5);
    return (1);
}