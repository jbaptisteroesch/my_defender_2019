/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

// ? Check la possibilité de poser une tour.

int posing_tower(game_t *game, int i)
{
    if (game->menu.placing_tower[i].is_hover &&
                game->window->event.type == sfEvtMouseButtonPressed &&
        game->player_data.has_posed == 0 && game->player_data.last_hold != 0) {
        add_node_towers(game, i);
        game->player_data.has_posed = 1;
    } else
        return (0);
    return (1);
}

// ? Check les conditions si on veut upgrade une tour.

int check_mouse_upgrade_tower(game_t *game, int i)
{
    if (game->menu.placing_tower[i].is_hover &&
            game->player_data.place_is_fill[i] == 1 &&
            game->window->event.type == sfEvtMouseButtonPressed)
        display_or_not_sprite_upgrade(game, i);
    return (1);
}

// ? Check les conditions pour poser ou upgrade une tour.

int posing_or_upgrade_tower(game_t *game)
{
    sfFloatRect rect_rect;
    int i = 0;

    for (i = 0; i < 7; ++i) {
    rect_rect = sfRectangleShape_getGlobalBounds(
                                        game->menu.placing_tower[i].rect);
        game->menu.placing_tower[i].is_hover =
                            sfFloatRect_contains(&(rect_rect),
                            game->mouse_position.x, game->mouse_position.y);
        if (!(posing_tower(game, i)))
            check_mouse_upgrade_tower(game, i);
    }
    return (1);
}

int has_upgrade_tower(game_t *game)
{
    sfFloatRect rect_rect;

    if (game->player_data.tower_is_click == 1) {
        rect_rect = sfSprite_getGlobalBounds(
                                game->button.in_game[IG_UPGRADE_TOWER].sprite);
        game->button.in_game[IG_UPGRADE_TOWER].is_hover =
                            sfFloatRect_contains(&(rect_rect),
                            game->mouse_position.x, game->mouse_position.y);
        if (game->button.in_game[IG_UPGRADE_TOWER].is_hover &&
                        game->window->event.type == sfEvtMouseButtonPressed)
            do_upgrade_tower(game);
    }
    return (1);
}