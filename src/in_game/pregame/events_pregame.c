/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"

int check_pos_play_pregame(game_t *game)
{
    game->button.pregame[1].button_rect =
        sfSprite_getGlobalBounds(game->button.pregame[1].sprite);
    game->button.pregame[1].is_hover = sfFloatRect_contains(
            &(game->button.pregame[1].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.pregame[1].is_hover) {
        game->button.state_pregame[1] = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->menu.game_state[PREGAME] = 0;
            game->menu.game_state[IN_GAME] = 1;
        }
    } else
        game->button.state_pregame[1] = 0;
    return (1);
}

int check_pos_tuto_pregame(game_t *game)
{
    game->button.pregame[0].button_rect =
        sfSprite_getGlobalBounds(game->button.pregame[0].sprite);
    game->button.pregame[0].is_hover = sfFloatRect_contains(
            &(game->button.pregame[0].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.pregame[0].is_hover) {
        game->button.state_pregame[0] = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed)
            game->tuto.is_in_tuto = true;
    } else
        game->button.state_pregame[0] = 0;
    return (1);
}

int check_pos_close_pregame(game_t *game)
{
    game->button.pregame[2].button_rect =
        sfSprite_getGlobalBounds(game->button.pregame[2].sprite);
    game->button.pregame[2].is_hover =
        sfFloatRect_contains(
            &(game->button.pregame[2].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.pregame[2].is_hover) {
                game->button.state_pregame[2] = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->menu.game_state[PREGAME] = 0;
            game->menu.game_state[MAIN_MENU] = 1;
        }
    }
    else
        game->button.state_pregame[2] = 0;
    return (1);
}

int check_mouse_position_pregame(game_t *game)
{
    check_pos_tuto_pregame(game);
    check_pos_play_pregame(game);
    check_pos_close_pregame(game);
    return (1);
}

void events_pregame(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[PREGAME] = 0;
            game->menu.game_is_up = 0;
        }
    game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_mouse_position_pregame(game);
    }
    return;
}