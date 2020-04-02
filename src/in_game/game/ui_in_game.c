/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui in game
*/

#include "../include/my.h"

int create_map(game_t *game)
{
    game->menu.ui_in_game[IG_MAP_LEVEL_ONE] =
                    create_element(game->menu.ui_in_game[IG_MAP_LEVEL_ONE],
                    "png/maps/map_one.png", 0, 0);
    game->menu.ui_in_game[IG_TREE] =
                    create_element(game->menu.ui_in_game[IG_TREE],
                    "png/ingame/tree.png", 896, 689);
    game->menu.ui_in_game[IG_TREE_SEC] =
                    create_element(game->menu.ui_in_game[IG_TREE_SEC],
                    "png/ingame/tree.png", 132, -12);
    game->menu.ui_in_game[IG_BLACK_RECT] =
                    create_element(game->menu.ui_in_game[IG_BLACK_RECT],
                    "png/ingame/black.png", 725, 45);
    return (1);
}

int create_rectangle_placing(game_t *game, int x, int y, int i)
{
    game->menu.placing_tower[i].rect_position.x = x;
    game->menu.placing_tower[i].rect_position.y = y;
    game->menu.placing_tower[i].color = sfWhite;
    game->menu.placing_tower[i].rect_size.x = 202 * game->window->scale.x;
    game->menu.placing_tower[i].rect_size.y = 233 * game->window->scale.y;
    game->menu.placing_tower[i].rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->menu.placing_tower[i].rect,
                        game->menu.placing_tower[i].rect_size);
    sfRectangleShape_setFillColor(game->menu.placing_tower[i].rect,
                        game->menu.placing_tower[i].color);
    sfRectangleShape_setPosition(game->menu.placing_tower[i].rect,
                                game->menu.placing_tower[i].rect_position);
    return (1);
}

int create_towers_place(game_t *game)
{
    sfVector2f s = game->window->scale;
    if (!(game->menu.placing_tower = malloc(sizeof(rectangle_t) * 7)))
        return (0);
    create_rectangle_placing(game, s.x * 260, s.y * 90, 0);
    create_rectangle_placing(game, s.x * 460, s.y * 390, 1);
    create_rectangle_placing(game, s.x * 668, s.y * 150, 2);
    create_rectangle_placing(game, s.x * 890, s.y * 200, 3);
    create_rectangle_placing(game, s.x * 1060, s.y * 500, 4);
    create_rectangle_placing(game, s.x * 1000, s.y * 810, 5);
    create_rectangle_placing(game, s.x * 1350, s.y * 520, 6);
    return (1);
}

int init_shop_tower_desciption(game_t *game)
{
    sfVector2f s = game->window->scale;
    game->menu.ui_in_game[IG_BT_DESCRIPTION] =
                    create_element(game->menu.ui_in_game[IG_BT_DESCRIPTION],
                    "png/ingame/thirty.png", 1580 , 303);
    game->menu.ui_in_game[IG_YT_DESCRIPTION] =
                    create_element(game->menu.ui_in_game[IG_YT_DESCRIPTION],
                    "png/ingame/eighty.png", 1580, 450);
    game->menu.ui_in_game[IG_ST_DESCRIPTION] =
                    create_element(game->menu.ui_in_game[IG_ST_DESCRIPTION],
                    "png/ingame/fourty.png", 1580 * s.x, 597 * s.y);
    game->menu.ui_in_game[IG_RT_DESCRIPTION] =
                    create_element(game->menu.ui_in_game[IG_RT_DESCRIPTION],
                    "png/ingame/hundred.png", 1580 * s.x, 740 * s.y);
    for (int i = 4; i < 6; i++)
        sfSprite_setScale(game->menu.ui_in_game[i].sprite, s);
    game->shop.bt_description = false;
    game->shop.yt_description = false;
    game->shop.st_description = false;
    game->shop.rt_description = false;
    return (1);
}

int ui_in_game (game_t *game)
{
    if (!(game->clock.in_game = malloc(sizeof(clocks_t) * 4)))
        return (0);
    if (!(game->menu.ui_in_game = malloc(sizeof(elem_t) * 9)))
        return (0);
    if (!(game->player_data.clock_wave = malloc(sizeof(char) * 3)))
        return (0);
    game->player_data.clock_wave = NULL;
    init_shop_data(game);
    init_shop_tower_desciption(game);
    if (!(init_player_data(game)))
        return (0);
    if (!(create_towers_place(game)))
        return (0);
    create_map(game);
    if (!(create_text_ig(game)))
        return (0);
    return (1);
}