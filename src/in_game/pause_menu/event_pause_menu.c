/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** pause menu
*/

#include "../include/my.h"

int choose_menu_pause_menu_button(game_t *game, int pos)
{
    switch (pos) {
        case 0:
            game->menu.game_state[PAUSE_MENU] = 0;
            for (int i = 1; i < 4; ++i)
                sfClock_restart(game->clock.in_game[i].clock);
            break;
        case 1:
            game->menu.game_state[PAUSE_MENU] = 0;
            game->menu.game_state[IN_GAME] = 0;
            game->menu.game_state[MAIN_MENU] = 1;
            break;
        case 2:
            game->menu.game_state[PAUSE_MENU] = 0;
            game->menu.game_state[IN_GAME] = 0;
            game->menu.game_is_up = 0;
            break;
    }
    return (1);
}

void check_mouse_position_pause_menu(game_t *game)
{
    for (int pos = 0; pos < 3; ++pos) {
        game->button.pause_menu[pos].button_rect =
            sfSprite_getGlobalBounds(game->button.pause_menu[pos].sprite);
        game->button.pause_menu[pos].is_hover =
            sfFloatRect_contains(
            &(game->button.pause_menu[pos].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
        if (game->button.pause_menu[pos].is_hover) {
            game->button.state_pause_menu[pos] = 1;
                if (game->window->event.type == sfEvtMouseButtonReleased) {
                    game->menu.game_state[PAUSE_MENU] = 0;
                    choose_menu_pause_menu_button(game, pos);
                }
        } else
            game->button.state_pause_menu[pos] = 0;
    }
    return;
}

void events_pause_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[PAUSE_MENU] = 0;
            game->menu.game_state[IN_GAME] = 0;
            game->menu.game_is_up = 0;
        }
        if (game->window->event.type == sfEvtKeyReleased &&
                                game->window->event.key.code == sfKeyEscape) {
            game->menu.game_state[PAUSE_MENU] = 0;
            for (int i = 1; i < 4; ++i)
                sfClock_restart(game->clock.in_game[i].clock);
        }
    game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_mouse_position_pause_menu(game);
    }
    return;
}