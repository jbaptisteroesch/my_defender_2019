/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"

// ? Fonction principale du menu pregame.

int pregame(game_t *game)
{
    if (!(ui_pregame(game)))
        return (change_state_cause_of_error(game));
    resize_pregame(game);
    resize_text_pregame(game);
    resize_pregame_ui(game);
    while (game->menu.game_state[PREGAME] == 1) {
        draw_pregame(game);
        events_pregame(game);
        while (game->tuto.is_in_tuto == true) {
            if (!(player_is_in_tuto(game)))
                return (change_state_cause_of_error(game));
        }
        sfRenderWindow_display(game->window->window);
    }
    destroy_pregame(game);
    return (1);
}

int resize_pregame(game_t *game)
{
    sfVector2f vector = game->window->scale;
    for (int i = 0; i < 2; i++) {
        sfVector2f actual_position;
        actual_position = sfSprite_getPosition(game->button.pregame[i].sprite);
        float x = actual_position.x * vector.x;
        float y = actual_position.y * vector.y;
        actual_position.x = x;
        actual_position.y = y;
        sfSprite_setPosition(game->button.pregame[i].sprite, actual_position);
        sfSprite_scale(game->button.pregame[i].sprite, vector);
    }
    return (1);
}

int resize_text_pregame(game_t *game)
{
    sfVector2f vector = game->window->scale;
    for (int i = 0; i < 2; i++) {
        sfVector2f actual_position;
        actual_position = sfText_getPosition(game->game_text.pregame[i].string);
        float x = actual_position.x * vector.x;
        float y = actual_position.y * vector.y;
        actual_position.x = x;
        actual_position.y = y;
        sfText_setPosition(game->game_text.pregame[i].string, actual_position);
    }
    for (int i = 0; i < 2; i++) {
        sfText_scale(game->game_text.pregame[i].string, vector);
    }
    return (1);
}

int resize_pregame_ui(game_t *game)
{
    sfVector2f vector = game->window->scale;
    sfVector2f actual_position = sfSprite_getPosition(
                                            game->menu.ui_pregame->sprite);
    actual_position.x = actual_position.x * vector.x;
    actual_position.y = actual_position.y * vector.y;
    sfSprite_setPosition(game->menu.ui_pregame->sprite, actual_position);
    sfSprite_scale(game->menu.ui_pregame->sprite, vector);
    return (1);
}