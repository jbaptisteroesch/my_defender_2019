/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"

int do_tuto_action(game_t *game, int i)
{
    switch (i) {
        case 0:
            game->tuto.quit_tuto = true;
            game->tuto.is_in_tuto = false;
            break;
        case 1:
            game->tuto.tuto_page = 1;
            break;
        case 2:
            game->tuto.tuto_page = 2;
            break;
    }
    return (1);
}

int check_mouse_position_tuto(game_t *game)
{
    for (int i = 0; i < 3; ++i) {
        game->button.tuto[i].button_rect =
            sfSprite_getGlobalBounds(game->button.tuto[i].sprite);
        game->button.tuto[i].is_hover = sfFloatRect_contains(
            &(game->button.tuto[i].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
        if (game->button.tuto[i].is_hover) {
            game->button.state_tuto[i] = 1;
                if (game->window->event.type == sfEvtMouseButtonPressed)
                    do_tuto_action(game, i);
        } else
            game->button.state_tuto[i] = 0;
    }
    return (1);
}

void events_tuto(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->tuto.quit_tuto = true;
            game->tuto.is_in_tuto = false;
            game->menu.game_state[PREGAME] = 0;
            game->menu.game_is_up = 0;
        }
    game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_mouse_position_tuto(game);
    }
    return;
}