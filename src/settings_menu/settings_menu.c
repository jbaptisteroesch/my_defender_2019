/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** settings menu
*/

#include "../../include/my.h"


// ? Boucle de l'état de jeu : MENU REGLAGES.

int settings_menu(game_t *game)
{
    if (!(create_settings_menu_buttons(game)))
        return (change_state_cause_of_error(game));
    if (!(create_ui_settings_menu(game)))
        return (change_state_cause_of_error(game));
    set_sprite_size_settings(game);
    set_sprite_position_settings(game);
    set_text_position_settings(game);
    while (game->menu.game_state[SETTINGS_MENU] == 1) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        draw_settings_menu(game);
        events_settings_menu(game);
        sfRenderWindow_display(game->window->window);
    }
    return (1);
}

int set_sprite_size_settings(game_t *game)
{
    sfVector2f vector = game->window->scale;
    for (int i = 0; i < 2; i++) {
        sfSprite_scale(game->menu.ui_settings_menu[i].sprite, vector);
    }
    for (int i = 0; i < 4; i++) {
        sfSprite_scale(game->button.settings_menu[i].sprite, vector);
    }
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_scale(game->game_text.rect_settings_text[i].rect,
        vector);
    }
    for (int i = 0; i < 5; i++) {
        sfText_scale(game->game_text.settings_text[i].string, vector);
    }
    return (1);
}

int set_sprite_position_two(sfVector2f vector, game_t *game)
{
    for (int i = 0; i < 3; i++) {
        sfVector2f position;
        position = sfRectangleShape_getPosition(game->game_text.
        rect_settings_text[i].rect);
        float x = position.x * vector.x;
        float y = position.y * vector.y;
        position.x = x;
        position.y = y;
        sfRectangleShape_setPosition(game->game_text.rect_settings_text[i].rect
        , position);
    }
    return (1);
}

int set_sprite_position_settings(game_t *game)
{
    sfVector2f vector = game->window->scale;
    sfVector2f actual_position;
    for (int i = 0; i < 4; i++) {
        actual_position = sfSprite_getPosition(game->button.settings_menu[i].
        sprite);
        actual_position.x = actual_position.x * vector.x;
        actual_position.y = actual_position.y * vector.y;
        sfSprite_setPosition(game->button.settings_menu[i].sprite,
        actual_position);
    }
    set_sprite_position_settings_two(game, vector, actual_position);
    set_sprite_position_two(vector, game);
    return (1);
}

int set_text_position_settings(game_t *game)
{
    sfVector2f vector = game->window->scale;
    sfVector2f actual_position;
    for (int i = 0; i < 5; i++) {
        actual_position = sfText_getPosition(game->game_text.settings_text[i]
        .string);
        float x = actual_position.x * vector.x;
        float y = actual_position.y * vector.y;
        actual_position.x = x;
        actual_position.y = y;
        sfText_setPosition(game->game_text.settings_text[i].string,
        actual_position);
    }
    return (1);
}