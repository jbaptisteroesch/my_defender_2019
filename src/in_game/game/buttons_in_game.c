/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create in game buttons
*/

#include "../include/my.h"
#include "../include/in_game_state.h"

int create_in_game_button_tab(game_t *game, int buttons_ig)
{
    if (!(game->button.state_in_game = malloc(sizeof(int) * buttons_ig)))
        return (0);
    for (int z = 0; z < buttons_ig; ++z)
        game->button.state_in_game[z] = 0;
    return (1);
}

int create_shop_button_hover(game_t *game)
{
    sfVector2f s = game->window->scale;
    game->button.in_game[IG_BT_BUT_HOV] = create_button(
        game->button.in_game[IG_BT_BUT_HOV], "png/ingame/shop_bt_hov.png",
            1730 * s.x, 180 * s.y);
    game->button.in_game[IG_YT_BUT_HOV] = create_button(
        game->button.in_game[IG_YT_BUT_HOV], "png/ingame/shop_yt_hov.png",
            1730 * s.x, 180 * s.y);
    game->button.in_game[IG_ST_BUT_HOV] = create_button(
        game->button.in_game[IG_ST_BUT_HOV], "png/ingame/shop_st_hov.png",
            1730 * s.x, 180 * s.y);
    game->button.in_game[IG_RT_BUT_HOV] = create_button(
        game->button.in_game[IG_RT_BUT_HOV], "png/ingame/shop_rt_hov.png",
            1730 * s.x, 180 * s.y);
    return (1);
}

int create_upgrade_button(game_t *game, sfVector2f s)
{
    game->button.in_game[IG_UPGRADE_TOWER] = create_button(
        game->button.in_game[IG_UPGRADE_TOWER], "png/ingame/test.png",
            0 * s.x, 0 * s.y);
    game->button.in_game[IG_UPGRADE_BT] = create_button(
        game->button.in_game[IG_UPGRADE_BT], "png/ingame/thirty_lit.png",
            0 * s.x, 0 * s.y);
    game->button.in_game[IG_UPGRADE_YT] = create_button(
        game->button.in_game[IG_UPGRADE_YT], "png/ingame/eighty_lit.png",
            0 * s.x, 0 * s.y);
    game->button.in_game[IG_UPGRADE_ST] = create_button(
        game->button.in_game[IG_UPGRADE_ST], "png/ingame/fourty_lit.png",
            0 * s.x, 0 * s.y);
    game->button.in_game[IG_UPGRADE_RT] = create_button(
        game->button.in_game[IG_UPGRADE_RT], "png/ingame/hundred_lit.png",
            0 * s.x, 0 * s.y);
    return (1);
}

int create_shop_button(game_t *game)
{
    sfVector2f s = game->window->scale;

    game->button.in_game[IG_BT_BUT] = create_button(
        game->button.in_game[IG_BT_BUT], "png/ingame/shop_bt.png",
            1730 * s.x, 180 * s.y);
    game->button.in_game[IG_YT_BUT] = create_button(
        game->button.in_game[IG_YT_BUT], "png/ingame/shop_yt.png",
            1730 * s.x, 180 * s.y);
    game->button.in_game[IG_ST_BUT] = create_button(
        game->button.in_game[IG_ST_BUT], "png/ingame/shop_st.png",
            1730 * s.x, 180 * s.y);
    game->button.in_game[IG_RT_BUT] = create_button(
        game->button.in_game[IG_RT_BUT], "png/ingame/shop_rt.png",
            1730 * s.x, 180 * s.y);
    create_upgrade_button(game, s);
    create_shop_button_hover(game);
    return (1);
}

int in_game_button(game_t *game)
{
    int buttons_ig = 18;
    sfVector2f s = game->window->scale;

    if (!(game->button.in_game = malloc(sizeof(create_button_t) * buttons_ig)))
        return (0);
    game->button.in_game[IG_PAUSE_BUT] = create_button(
        game->button.in_game[IG_PAUSE_BUT], "png/ingame/pause_button.png",
            1731 * s.x, 30 * s.y);
    game->button.in_game[IG_PAUSE_BUT_HOV] = create_button(
                        game->button.in_game[IG_PAUSE_BUT_HOV],
                    "png/ingame/pause_button_hov.png", 1731 * s.x, 30 * s.y);
    game->button.in_game[IG_SHOP_BUT] = create_button(
        game->button.in_game[IG_SHOP_BUT], "png/ingame/shop.png",
            1705 * s.x, 180 * s.y);
    game->button.in_game[IG_SHOP_BUT_HOV] = create_button(
        game->button.in_game[IG_SHOP_BUT_HOV], "png/ingame/shop_hov.png",
            1707 * s.x, 177 * s.y);
    create_shop_button(game);
    if (!(create_in_game_button_tab(game, buttons_ig)))
        return (0);
    return (1);
}