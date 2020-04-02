/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

int close_shop_ig(game_t *game)
{
    if (game->button.in_game[IG_SHOP_BUT].is_click &&
                                                game->menu.shop_is_open) {
        sfClock_restart(game->clock.in_game[CLOCK_SHOP].clock);
        game->button.in_game[IG_SHOP_BUT].is_click = false;
        game->menu.shop_is_open = false;
        game->menu.shop_is_close = false;
        return (1);
    }
    return (1);
}

int open_or_close_shop(game_t *game)
{
    if (!(game->button.in_game[IG_SHOP_BUT].is_click) &&
                                            !(game->menu.shop_is_open)) {
        for (int i = 4; i < 12; ++i) {
            game->button.in_game[i].position.x =
                            game->button.in_game[IG_SHOP_BUT].position.x + 25 *
                                                        game->window->scale.x;
            game->button.in_game[i].position.y =
                            game->button.in_game[IG_SHOP_BUT].position.y + 80 *
                                                        game->window->scale.y;
            sfSprite_setPosition(game->button.in_game[i].sprite,
                                            game->button.in_game[i].position);
    }
        game->button.in_game[IG_SHOP_BUT].is_click = true;
        sfClock_restart(game->clock.in_game[CLOCK_SHOP].clock);
        return (1);
    }
    close_shop_ig(game);
    return (1);
}

int is_on_shop_button(game_t *game)
{
    game->button.in_game[IG_SHOP_BUT].button_rect =
        sfSprite_getGlobalBounds(game->button.in_game[IG_SHOP_BUT].sprite);
    game->button.in_game[IG_SHOP_BUT].is_hover =
        sfFloatRect_contains(
            &(game->button.in_game[IG_SHOP_BUT].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.in_game[IG_SHOP_BUT].is_hover) {
        game->button.state_in_game[IG_SHOP_BUT] = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            open_or_close_shop(game);
        }
    }
    else
        game->button.state_in_game[IG_SHOP_BUT] = 0;
    return (1);
}