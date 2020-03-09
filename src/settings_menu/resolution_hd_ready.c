/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** set hd ready res
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"

int set_hd_ready_resolution(game_t *game)
{
    game->window->pos = 610;
    sfVector2f second_vector = {0.666667, 0.666667};
    sfVideoMode mode = {1280, 720, 32};
    sfVector2u last_size = sfRenderWindow_getSize(game->window->window);
    float last_size_x = last_size.x;
    float last_size_y = last_size.y;
    float ratio_x = 1280 / last_size_x;
    float ratio_y = 720 / last_size_y;
    game->window->scale = second_vector;
    sfRenderWindow_destroy(game->window->window);
    game->window->window = sfRenderWindow_create(mode,
    "my_defender", sfDefaultStyle, NULL);
    set_sprite_position(game, ratio_x, ratio_y);
    set_sprite_size(game, ratio_x, ratio_y);
    set_text_position(game, ratio_x, ratio_y);
    sfRenderWindow_clear(game->window->window, sfBlack);
    return (1);
}

int set_sprite_size(game_t *game, float ratio_x, float ratio_y)
{
    sfVector2f vector = {ratio_x, ratio_y};
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
    sfSprite_scale(game->window->sprite, vector);
    return (1);
}

int set_sprite_positiontwo(game_t *game, sfVector2f vector,
sfVector2f actual_position)
{
    for (int i = 0; i < 4; i++) {
        actual_position =
        sfSprite_getPosition(game->button.settings_menu[i].sprite);
        actual_position.x = actual_position.x * vector.x;
        actual_position.y = actual_position.y * vector.y;
        sfSprite_setPosition
        (game->button.settings_menu[i].sprite, actual_position);
    }
    for (int i = 0; i < 2; i++) {
        actual_position
        = sfSprite_getPosition(game->menu.ui_settings_menu[i].sprite);
            actual_position.y = actual_position.y * vector.y;
        if (i == 0)
            actual_position.x = actual_position.x * vector.x;
        else
            actual_position.x = game->window->pos;
        sfSprite_setPosition
        (game->menu.ui_settings_menu[i].sprite, actual_position);
    }
    return (1);
}

int set_sprite_position(game_t *game, float ratio_x, float ratio_y)
{
    sfVector2f vector = {ratio_x, ratio_y};
    sfVector2f actual_position;
    for (int i = 0; i < 3; i++) {
        sfVector2f position;
        position = sfRectangleShape_getPosition
        (game->game_text.rect_settings_text[i].rect);
        float x = position.x * vector.x;
        float y = position.y * vector.y;
        position.x = x;
        position.y = y;
        sfRectangleShape_setPosition
        (game->game_text.rect_settings_text[i].rect, position);
    }
    set_sprite_positiontwo(game, vector, actual_position);
    return (1);
}

int set_text_position(game_t *game, float ratio_x, float ratio_y)
{
    sfVector2f vector = {ratio_x, ratio_y};
    sfVector2f actual_position;
    for (int i = 0; i < 5; i++) {
        actual_position =
        sfText_getPosition(game->game_text.settings_text[i].string);
        float x = actual_position.x * vector.x;
        float y = actual_position.y * vector.y;
        actual_position.x = x;
        actual_position.y = y;
        sfText_setPosition
        (game->game_text.settings_text[i].string, actual_position);
    }
    return (1);
}