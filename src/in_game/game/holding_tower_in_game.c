/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"


// ? Check si le joueur hold une tour et qu'il clic.

int check_tower_holding(game_t *game)
{
    if ((game->player_data.holding_bt || game->player_data.holding_yt ||
            game->player_data.holding_st || game->player_data.holding_rt) &&
                        (game->window->event.type == sfEvtMouseButtonPressed)) {
        sfRenderWindow_setMouseCursorVisible(game->window->window, sfTrue);
        game->player_data.holding_bt = false;
        game->player_data.holding_yt = false;
        game->player_data.holding_st = false;
        game->player_data.holding_rt = false;
    }
    return (1);
}


// ? Check_si la souris est sur le bouton du shop rock tower.

int is_on_rt_button(game_t *game)
{
    game->button.in_game[IG_RT_BUT].button_rect =
        sfSprite_getGlobalBounds(game->button.in_game[IG_RT_BUT].sprite);
    game->button.in_game[IG_RT_BUT].is_hover =
        sfFloatRect_contains(
            &(game->button.in_game[IG_RT_BUT].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.in_game[IG_RT_BUT].is_hover) {
        game->button.state_in_game[IG_RT_BUT] = 1;
        game->shop.rt_description = true;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->player_data.holding_rt = true;
            game->player_data.last_hold = 4;
            game->player_data.has_posed = 0;
        }
    } else {
        game->button.state_in_game[IG_RT_BUT] = 0;
        game->shop.rt_description = false;
    }
    return (1);
}


// ? Check_si la souris est sur le bouton du shop straw tower.

int is_on_st_button(game_t *game)
{
    game->button.in_game[IG_ST_BUT].button_rect =
        sfSprite_getGlobalBounds(game->button.in_game[IG_ST_BUT].sprite);
    game->button.in_game[IG_ST_BUT].is_hover =
        sfFloatRect_contains(
            &(game->button.in_game[IG_ST_BUT].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.in_game[IG_ST_BUT].is_hover) {
        game->button.state_in_game[IG_ST_BUT] = 1;
        game->shop.st_description = true;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->player_data.holding_st = true;
            game->player_data.last_hold = 3;
            game->player_data.has_posed = 0;
        }
    } else {
        game->button.state_in_game[IG_ST_BUT] = 0;
        game->shop.st_description = false;
    }
    return (1);
}


// ? Check_si la souris est sur le bouton du shop yellow tower.

int is_on_yt_button(game_t *game)
{
    game->button.in_game[IG_YT_BUT].button_rect =
        sfSprite_getGlobalBounds(game->button.in_game[IG_YT_BUT].sprite);
    game->button.in_game[IG_YT_BUT].is_hover =
        sfFloatRect_contains(
            &(game->button.in_game[IG_YT_BUT].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.in_game[IG_YT_BUT].is_hover) {
        game->button.state_in_game[IG_YT_BUT] = 1;
        game->shop.yt_description = true;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->player_data.holding_yt = true;
            game->player_data.last_hold = 2;
            game->player_data.has_posed = 0;
        }
    }
    else {
        game->button.state_in_game[IG_YT_BUT] = 0;
        game->shop.yt_description = false;
    }
    return (1);
}


// ? Check_si la souris est sur le bouton du shop blue tower.

int is_on_bt_button(game_t *game)
{
    game->button.in_game[IG_BT_BUT].button_rect =
        sfSprite_getGlobalBounds(game->button.in_game[IG_BT_BUT].sprite);
    game->button.in_game[IG_BT_BUT].is_hover =
        sfFloatRect_contains(
            &(game->button.in_game[IG_BT_BUT].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.in_game[IG_BT_BUT].is_hover) {
        game->button.state_in_game[IG_BT_BUT] = 1;
        game->shop.bt_description = true;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->player_data.holding_bt = true;
            game->player_data.last_hold = 1;
            game->player_data.has_posed = 0;
        }
    } else {
        game->button.state_in_game[IG_BT_BUT] = 0;
        game->shop.bt_description = false;
    }
    return (1);
}