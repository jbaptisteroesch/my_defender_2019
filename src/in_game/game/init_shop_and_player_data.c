/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui in game
*/

#include "../include/my.h"


// ? Init data du joueur.

int init_player_data(game_t *game)
{
    game->player_data.score = 0;
    game->player_data.life = 100;
    if (game->code.money == true)
        game->player_data.money = 5000;
    else
        game->player_data.money = 70;
    game->player_data.last_hold = 0;
    game->player_data.wave_number = 1;
    game->player_data.next_wave_in = 1;
    game->player_data.holding_bt = false;
    game->player_data.holding_yt = false;
    game->player_data.holding_st = false;
    game->player_data.holding_rt = false;
    game->player_data.tower_is_click = false;
    if (!(game->player_data.place_is_fill = malloc(sizeof(int) * 7)))
        return (0);
    for (int i = 0; i < 7; ++i)
        game->player_data.place_is_fill[i] = 0;
    return (1);
}


// ? Init data du shop.

int init_shop_data(game_t *game)
{
    game->button.in_game[IG_SHOP_BUT].is_click = false;
    game->menu.shop_is_open = false;
    game->menu.shop_is_close = false;
    game->clock.in_game[CLOCK_SHOP].clock = sfClock_create();
    return (1);
}