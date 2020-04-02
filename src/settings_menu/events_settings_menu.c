/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** settings menu events
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"

int check_mouse_pos_dvd_res(game_t *game)
{
    sfFloatRect rect_rect;

    rect_rect = sfRectangleShape_getGlobalBounds(
                            game->game_text.rect_settings_text[0].rect);
    game->game_text.rect_settings_text[0].is_hover =
        sfFloatRect_contains(
            &(rect_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->game_text.rect_settings_text[0].is_hover &&
                game->window->event.type == sfEvtMouseButtonPressed) {
        set_dvd_resolution(game);
    }
    return (1);
}

int check_mouse_pos_hd_ready_res(game_t *game)
{
    sfFloatRect rect_rect;

    rect_rect = sfRectangleShape_getGlobalBounds(
                            game->game_text.rect_settings_text[1].rect);
    game->game_text.rect_settings_text[1].is_hover =
        sfFloatRect_contains(
            &(rect_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->game_text.rect_settings_text[1].is_hover &&
                game->window->event.type == sfEvtMouseButtonPressed) {
        set_hd_ready_resolution(game);
    }
    return (1);
}

int check_mouse_pos_hd_res(game_t *game)
{
    sfFloatRect rect_rect;

    rect_rect = sfRectangleShape_getGlobalBounds(
                            game->game_text.rect_settings_text[2].rect);
    game->game_text.rect_settings_text[2].is_hover =
        sfFloatRect_contains(
            &(rect_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->game_text.rect_settings_text[2].is_hover &&
                game->window->event.type == sfEvtMouseButtonPressed) {
        set_hd_resolution(game);
    }
    return (1);
}

int check_mouse_position_settings_menu(game_t *game)
{
    check_mouse_pos_close_button_settings_menu(game);
    check_mouse_pos_sound_button(game);
    check_mouse_pos_dvd_res(game);
    check_mouse_pos_hd_ready_res(game);
    check_mouse_pos_hd_res(game);
    return (1);
}

int events_settings_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[SETTINGS_MENU] = 0;
            game->menu.game_is_up = 0;
        }
    game->mouse_position =
                        sfMouse_getPositionRenderWindow(game->window->window);
        check_mouse_position_settings_menu(game);
    }
    return (1);
}