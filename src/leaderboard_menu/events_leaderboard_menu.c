/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** leaderboard menu events
*/

#include "../../include/my.h"


// ? Check de la position de la souris pour le bouton.

int check_mouse_position_leaderboard_menu(game_t *game)
{
    game->button.leaderboard[0].button_rect =
        sfSprite_getGlobalBounds(game->button.leaderboard[0].sprite);
    game->button.leaderboard[0].is_hover =
        sfFloatRect_contains(
            &(game->button.leaderboard[0].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.leaderboard[0].is_hover) {
                game->button.state_leaderboard_menu = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->menu.game_state[LEADERBOARD_MENU] = 0;
            game->menu.game_state[MAIN_MENU] = 1;
        }
    }
    else
        game->button.state_leaderboard_menu = 0;
    return (1);
}


// ? Events de l'interface leaderboard.

int events_leaderboard_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[LEADERBOARD_MENU] = 0;
            game->menu.game_is_up = 0;
        }
    game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_mouse_position_leaderboard_menu(game);
    }
    return (1);
}

int resize_leaderboard_two(game_t *game)
{
    sfVector2f vector = game->window->scale;
    sfVector2f actual_position;
    for (int i = 0; i < 2; i++) {
        actual_position = sfSprite_getPosition(
                                        game->button.leaderboard[i].sprite);
        actual_position.x = actual_position.x * vector.x;
        actual_position.y = actual_position.y * vector.y;
        sfSprite_setPosition(
                        game->button.leaderboard[i].sprite, actual_position);
        sfSprite_scale(game->button.leaderboard[i].sprite, vector);
    }
    return (1);
}