/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main menu events
*/

#include "../../include/my.h"

int check_mouse_position_main_menu(game_t *game)
{
    for (int pos = 0; pos < 4; ++pos) {
        game->button.main_menu[pos].button_rect =
            sfSprite_getGlobalBounds(game->button.main_menu[pos].sprite);
        game->button.main_menu[pos].is_hover =
            sfFloatRect_contains(
            &(game->button.main_menu[pos].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
        if (game->button.main_menu[pos].is_hover) {
            game->button.state_main_menu[pos] = 1;
                if (game->window->event.type == sfEvtMouseButtonPressed)
                    game->button.state_main_menu[pos] = 2;
                if (game->window->event.type == sfEvtMouseButtonReleased) {
                    game->menu.game_state[MAIN_MENU] = 0;
                    game->menu.game_state[pos + 1] = 1;
                }
            } else
            game->button.state_main_menu[pos] = 0;
    }
    return (1);
}

void events_main_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[MAIN_MENU] = 0;
            game->menu.game_is_up = 0;
        }
    game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_mouse_position_main_menu(game);
    }
    return;
}