/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"

int close_speed_shop_buttons_animation(game_t *game)
{
    game->button.in_game[IG_BT_BUT].position.y -=
                game->clock.in_game[CLOCK_SHOP].seconds * 150 *
                                                        game->window->scale.y;
    game->button.in_game[IG_YT_BUT].position.y -=
                game->clock.in_game[CLOCK_SHOP].seconds * 250 *
                                                        game->window->scale.y;
    game->button.in_game[IG_ST_BUT].position.y -=
                game->clock.in_game[CLOCK_SHOP].seconds * 350 *
                                                        game->window->scale.y;
    game->button.in_game[IG_RT_BUT].position.y -=
                game->clock.in_game[CLOCK_SHOP].seconds * 450 *
                                                        game->window->scale.y;
    return (1);
}

int close_set_shop_buttons_pos_after_animation(game_t *game)
{
    sfSprite_setPosition(game->button.in_game[IG_BT_BUT].sprite,
                                    game->button.in_game[IG_BT_BUT].position);
    sfSprite_setPosition(game->button.in_game[IG_YT_BUT].sprite,
                                    game->button.in_game[IG_YT_BUT].position);
    sfSprite_setPosition(game->button.in_game[IG_ST_BUT].sprite,
                                    game->button.in_game[IG_ST_BUT].position);
    sfSprite_setPosition(game->button.in_game[IG_RT_BUT].sprite,
                                    game->button.in_game[IG_RT_BUT].position);
    return (1);
}

int close_stop_condition_shop_animation_st_rt(game_t *game)
{
    if (game->button.in_game[IG_BT_BUT].position.y >
                    game->button.in_game[IG_SHOP_BUT].position.y + 10 *
                                                    game->window->scale.y)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_BT_BUT].sprite, NULL);
    if (game->button.in_game[IG_YT_BUT].position.y >
                    game->button.in_game[IG_SHOP_BUT].position.y + 10 *
                                                    game->window->scale.y)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_YT_BUT].sprite, NULL);
    return (1);
}

int close_stop_condition_shop_animation(game_t *game)
{
    close_stop_condition_shop_animation_st_rt(game);
    if (game->button.in_game[IG_ST_BUT].position.y >
                    game->button.in_game[IG_SHOP_BUT].position.y + 10 *
                                                    game->window->scale.y)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_ST_BUT].sprite, NULL);
    if (game->button.in_game[IG_RT_BUT].position.y >
                    game->button.in_game[IG_SHOP_BUT].position.y + 10 *
                                                    game->window->scale.y) {
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_RT_BUT].sprite, NULL);
    }
    if (game->button.in_game[IG_RT_BUT].position.y <=
                    game->button.in_game[IG_SHOP_BUT].position.y + 10 *
                                                    game->window->scale.y) {
        game->menu.shop_is_close = true;
        return (1);
    }
    return (1);
}

int close_animation_shop(game_t *game)
{
    game->clock.in_game[CLOCK_SHOP].time =
            sfClock_getElapsedTime(game->clock.in_game[CLOCK_SHOP].clock);
    game->clock.in_game[CLOCK_SHOP].seconds =
            game->clock.in_game[CLOCK_SHOP].time.microseconds / 1000000.0;
    if (game->clock.in_game[CLOCK_SHOP].seconds > 1 / 30) {
        close_speed_shop_buttons_animation(game);
        close_set_shop_buttons_pos_after_animation(game);
        sfClock_restart(game->clock.in_game[CLOCK_SHOP].clock);
    }
    close_stop_condition_shop_animation(game);
    return (1);
}

