/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** set hd res
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"

int set_hd_two(game_t *game, float ratio_x, float ratio_y)
{
    set_sprite_position(game, ratio_x, ratio_y);
    set_sprite_size(game, ratio_x, ratio_y);
    set_text_position(game, ratio_x, ratio_y);
    sfRenderWindow_clear(game->window->window, sfBlack);
    game->window->scale.x = 1;
    game->window->scale.y = 1;
    return (1);
}

int set_hd_resolution(game_t *game)
{
    game->window->pos = 1180;
    sfVector2f second_vector = {1, 1};
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2u last_size = sfRenderWindow_getSize(game->window->window);
    float last_size_x = last_size.x;
    float last_size_y = last_size.y;
    float ratio_x = 1920 / last_size_x;
    float ratio_y = 1080 / last_size_y;
    game->window->scale = second_vector;
    sfRenderWindow_destroy(game->window->window);
    game->window->window = sfRenderWindow_create(mode,
                                            "my_defender",
                                            sfFullscreen,
                                            NULL);
    set_hd_two(game, ratio_x, ratio_y);
    return (1);
}

int set_sprite_position_settings_two(game_t *game,
sfVector2f vector, sfVector2f actual_position)
{
    for (int i = 0; i < 2; i++) {
        actual_position = sfSprite_getPosition(game->menu.ui_settings_menu[i].
        sprite);
        if (i == 0)
            actual_position.x = actual_position.x * vector.x;
        else
            actual_position.x = game->window->pos;
        actual_position.y = actual_position.y * vector.y;
        sfSprite_setPosition(game->menu.ui_settings_menu[i].sprite,
        actual_position);
    }
    return (1);
}