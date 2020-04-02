/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

int is_on_pause_button(game_t *game)
{
    game->button.in_game[IG_PAUSE_BUT].button_rect =
        sfSprite_getGlobalBounds(game->button.in_game[IG_PAUSE_BUT].sprite);
    game->button.in_game[IG_PAUSE_BUT].is_hover =
        sfFloatRect_contains(
            &(game->button.in_game[IG_PAUSE_BUT].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.in_game[IG_PAUSE_BUT].is_hover) {
        game->button.state_in_game[IG_PAUSE_BUT] = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->menu.game_state[PAUSE_MENU] = 1;
        }
    }
    else
        game->button.state_in_game[IG_PAUSE_BUT] = 0;
    return (1);
}

int is_on_button_in_game(game_t *game)
{
    is_on_pause_button(game);
    is_on_shop_button(game);
    if (game->menu.shop_is_open == true) {
        is_on_bt_button(game);
        is_on_yt_button(game);
        is_on_st_button(game);
        is_on_rt_button(game);
    }
    posing_or_upgrade_tower(game);
    has_upgrade_tower(game);
    return (1);
}

int events_in_game(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[IN_GAME] = 0;
            game->menu.game_is_up = 0;
        }
        if (game->window->event.type == sfEvtKeyReleased &&
                                    game->window->event.key.code == sfKeyEscape)
            game->menu.game_state[PAUSE_MENU] = 1;
        game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_tower_holding(game);
        is_on_button_in_game(game);
    }
    return (1);
}