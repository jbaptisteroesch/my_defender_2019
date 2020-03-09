/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"


// ? Vitesse d'animation des différents boutons du shop.

int open_speed_shop_buttons_animation(game_t *game)
{
    game->button.in_game[IG_BT_BUT].position.y +=
                game->clock.in_game[CLOCK_SHOP].seconds * 150 *
                                                        game->window->scale.y;
    game->button.in_game[IG_YT_BUT].position.y +=
                game->clock.in_game[CLOCK_SHOP].seconds * 250 *
                                                        game->window->scale.y;
    game->button.in_game[IG_ST_BUT].position.y +=
                game->clock.in_game[CLOCK_SHOP].seconds * 350 *
                                                        game->window->scale.y;
    game->button.in_game[IG_RT_BUT].position.y +=
                game->clock.in_game[CLOCK_SHOP].seconds * 450 *
                                                        game->window->scale.y;
    return (1);
}


// ? Split de la fonction open_stop_condition_shop_animation.

int open_shop(game_t *game)
{
    if (game->button.in_game[IG_ST_BUT].position.y > 579 *
                                                    game->window->scale.y) {
        game->button.in_game[IG_ST_BUT].position.y = 584 *
                                                        game->window->scale.y;
        sfSprite_setPosition(game->button.in_game[IG_ST_BUT].sprite,
                                    game->button.in_game[IG_ST_BUT].position);
    }
    if (game->button.in_game[IG_RT_BUT].position.y > 726 *
                                                    game->window->scale.y) {
        game->button.in_game[IG_RT_BUT].position.y = 731 *
                                                    game->window->scale.y;
        sfSprite_setPosition(game->button.in_game[IG_RT_BUT].sprite,
                                    game->button.in_game[IG_RT_BUT].position);
        set_hover_buttons(game);
        game->menu.shop_is_open = true;
        return (1);
    }
    return (1);
}


// ? Condition d'arrêt de l'animation du shop.

int open_stop_condition_shop_animation(game_t *game)
{
    if (game->button.in_game[IG_BT_BUT].position.y > 285 *
                                                    game->window->scale.y) {
        game->button.in_game[IG_BT_BUT].position.y = 290 *
                                                    game->window->scale.y;
    sfSprite_setPosition(game->button.in_game[IG_BT_BUT].sprite,
                                    game->button.in_game[IG_BT_BUT].position);
    }
    if (game->button.in_game[IG_YT_BUT].position.y > 432 *
                                                    game->window->scale.y) {
        game->button.in_game[IG_YT_BUT].position.y = 437 *
                                                    game->window->scale.y;
        sfSprite_setPosition(game->button.in_game[IG_YT_BUT].sprite,
                                    game->button.in_game[IG_YT_BUT].position);
    }

    open_shop(game);
    return (1);
}


// ? Crée l'animation de menu déroulant pour le shop.

int open_animation_shop(game_t *game)
{
    game->clock.in_game[CLOCK_SHOP].time =
            sfClock_getElapsedTime(game->clock.in_game[CLOCK_SHOP].clock);
    game->clock.in_game[CLOCK_SHOP].seconds =
            game->clock.in_game[CLOCK_SHOP].time.microseconds / 1000000.0;
    if (game->clock.in_game[CLOCK_SHOP].seconds > 1 / 30) {
        open_speed_shop_buttons_animation(game);
        open_set_shop_buttons_pos_after_animation(game);
        sfClock_restart(game->clock.in_game[CLOCK_SHOP].clock);
    }
    open_stop_condition_shop_animation(game);
    return (1);
}