/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"


// ? Change la position des ennemy (parcours de la map).

int change_ennemy_position(game_t *game)
{
    static float i;

    game->clock.in_game[CLOCK_POS_ENNEMY].time = sfClock_getElapsedTime(
                                game->clock.in_game[CLOCK_POS_ENNEMY].clock);
    game->clock.in_game[CLOCK_POS_ENNEMY].seconds =
        game->clock.in_game[CLOCK_POS_ENNEMY].time.microseconds / 1000000.0;
    if (game->clock.in_game[CLOCK_POS_ENNEMY].seconds > 1 / 60) {
        while (i >= 0.02) {
            walk_through_map(game);
            i -= 0.02;
        }
        i += game->clock.in_game[CLOCK_POS_ENNEMY].seconds;
        sfClock_restart(game->clock.in_game[CLOCK_POS_ENNEMY].clock);
    }
    return (1);
}


// ? Fait bouger les ennemy et les flèches.

int moove_ennemy_and_arrows(game_t *game)
{
    change_ennemy_rect(game);
    change_ennemy_position(game);
    hit_box_arrow(game);
    is_he_out_map(game);
    move_every_arrows(game);
    return (1);
}


// ? Fait avancer les ennemy.

int walk_ennemy(game_t *game)
{
    static float i;
    static float test;

    game->clock.in_game[CLOCK_WALK_ENNEMY].time = sfClock_getElapsedTime(
                                game->clock.in_game[CLOCK_WALK_ENNEMY].clock);
    game->clock.in_game[CLOCK_WALK_ENNEMY].seconds =
        game->clock.in_game[CLOCK_WALK_ENNEMY].time.microseconds / 1000000.0;
    if (game->clock.in_game[CLOCK_WALK_ENNEMY].seconds > 1 / 60) {
        while (i >= 0.04) {
            moove_ennemy_and_arrows(game);
            i -= 0.04;
        }
        while (test >= 1) {
            ennemy_is_on_range(game);
            test -= 1;
        }
        test += game->clock.in_game[CLOCK_WALK_ENNEMY].seconds;
        i += game->clock.in_game[CLOCK_WALK_ENNEMY].seconds;
        sfClock_restart(game->clock.in_game[CLOCK_WALK_ENNEMY].clock);
    }
    return (1);
}