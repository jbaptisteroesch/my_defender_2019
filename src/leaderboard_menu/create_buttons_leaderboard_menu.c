/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create button leaderboard menu
*/

#include "../../include/my.h"

int create_leaderboard_menu_buttons(game_t *game)
{
    if (!(game->button.leaderboard = malloc(sizeof(create_button_t) * 2)))
        return (0);
    game->button.leaderboard[0] = create_button(game->button.leaderboard[0],
                "png/settingsbuttons/button_close.png", 1400.0, 200.0);
    game->button.leaderboard[1] = create_button(game->button.leaderboard[1],
                "png/settingsbuttons/button_close_shadow.png", 1400.0, 200.0);
    game->button.state_leaderboard_menu = 0;
    return (1);
}