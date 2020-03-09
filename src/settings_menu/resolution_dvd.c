/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** set dvd res
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"

int set_dvd_resolution(game_t *game)
{
    game->window->pos = 240;
    sfVector2f second_vector = {0.375000, 0.444444};
    sfVideoMode mode = {720, 480, 32};
    sfVector2u last_size = sfRenderWindow_getSize(game->window->window);
    float last_size_x = last_size.x;
    float last_size_y = last_size.y;
    float ratio_x = 720 / last_size_x;
    float ratio_y = 480 / last_size_y;
    game->window->scale = second_vector;
    sfRenderWindow_destroy(game->window->window);
    game->window->window = sfRenderWindow_create(mode,
                                            "my_defender",
                                            sfDefaultStyle,
                                            NULL);
    set_sprite_position(game, ratio_x, ratio_y);
    set_text_position(game, ratio_x, ratio_y);
    set_sprite_size(game, ratio_x, ratio_y);
    sfRenderWindow_clear(game->window->window, sfBlack);
    return (1);
}