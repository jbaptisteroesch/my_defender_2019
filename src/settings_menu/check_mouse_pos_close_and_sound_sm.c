/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** settings menu events
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"

int check_mouse_pos_close_button_settings_menu(game_t *game)
{
    game->button.settings_menu[SM_CLOSE].button_rect =
        sfSprite_getGlobalBounds(game->button.settings_menu[SM_CLOSE].sprite);
    game->button.settings_menu[SM_CLOSE].is_hover =
        sfFloatRect_contains(
            &(game->button.settings_menu[SM_CLOSE].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.settings_menu[SM_CLOSE].is_hover) {
                game->button.state_settings_menu[SM_STATE_CLOSE] = 1;
        if (game->window->event.type == sfEvtMouseButtonPressed) {
            game->menu.game_state[SETTINGS_MENU] = 0;
            game->menu.game_state[MAIN_MENU] = 1;
        }
    }
    else
        game->button.state_settings_menu[SM_STATE_CLOSE] = 0;
    return (1);
}

int check_state_when_press_sound_button(game_t *game)
{
    if (game->button.state_settings_menu[SM_STATE_SOUND] == 0) {
        game->button.state_settings_menu[SM_STATE_SOUND] = 1;
        sfMusic_stop(game->music);
    }
    else if (game->button.state_settings_menu[SM_STATE_SOUND] == 1) {
        game->button.state_settings_menu[SM_STATE_SOUND] = 0;
        sfMusic_play(game->music);
    }
    return (1);
}

int check_mouse_pos_sound_button(game_t *game)
{
    game->button.settings_menu[SM_SOUND].button_rect =
        sfSprite_getGlobalBounds(game->button.settings_menu[SM_SOUND].sprite);
    game->button.settings_menu[SM_SOUND].is_hover =
        sfFloatRect_contains(
            &(game->button.settings_menu[SM_SOUND].button_rect),
                    game->mouse_position.x, game->mouse_position.y);
    if (game->button.settings_menu[SM_SOUND].is_hover &&
        game->window->event.type == sfEvtMouseButtonPressed)
            check_state_when_press_sound_button(game);
    return (1);
}