/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"

void draw_tree(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
                        game->menu.ui_in_game[IG_TREE].sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                        game->menu.ui_in_game[IG_TREE_SEC].sprite, NULL);
    return;
}

void draw_shop_buttons(game_t *game)
{
    if (game->button.state_in_game[IG_SHOP_BUT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_SHOP_BUT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_SHOP_BUT].sprite, NULL);
    if (game->button.in_game[IG_SHOP_BUT].is_click == true) {
        draw_bt_and_yt_towers(game);
        draw_st_and_rt_towers(game);
    }
    return;
}

void draw_description(game_t *game)
{
    if (game->shop.bt_description == 1)
        sfRenderWindow_drawSprite(game->window->window,
            game->menu.ui_in_game[IG_BT_DESCRIPTION].sprite, NULL);
    if (game->shop.yt_description == 1)
        sfRenderWindow_drawSprite(game->window->window,
            game->menu.ui_in_game[IG_YT_DESCRIPTION].sprite, NULL);
    if (game->shop.st_description == 1)
        sfRenderWindow_drawSprite(game->window->window,
            game->menu.ui_in_game[IG_ST_DESCRIPTION].sprite, NULL);
    if (game->shop.rt_description == 1)
        sfRenderWindow_drawSprite(game->window->window,
            game->menu.ui_in_game[IG_RT_DESCRIPTION].sprite, NULL);
    return;
}

void draw_shop_elements(game_t *game)
{
    if (game->button.in_game[IG_SHOP_BUT].is_click == true &&
                                            !(game->menu.shop_is_open))
        open_animation_shop(game);
    if (!(game->button.in_game[IG_SHOP_BUT].is_click) &&
                    !(game->menu.shop_is_open) && !(game->menu.shop_is_close))
        close_animation_shop(game);
    draw_shop_buttons(game);
    draw_description(game);
    hold_blue_tower(game);
    hold_yellow_tower(game);
    hold_straw_tower(game);
    hold_rock_tower(game);
    return;
}