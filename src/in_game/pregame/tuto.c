/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"

int create_button_tuto(game_t *game, sfVector2f s)
{
    game->button.tuto[TUTO_QUIT] = create_button (
                game->button.tuto[TUTO_QUIT],
                "png/settingsbuttons/button_close.png", 1575 * s.x, 7 * s.y);
    game->button.tuto[TUTO_QUIT_HOV] = create_button (
        game->button.tuto[TUTO_QUIT_HOV],
        "png/settingsbuttons/button_close_shadow.png", 1575 * s.x, 7 * s.y);
    game->button.tuto[TUTO_PREV] = create_button (
                game->button.tuto[TUTO_PREV],
                "png/settingsbuttons/button_left.png", 103 * s.x, 468.5 * s.y);
    game->button.tuto[TUTO_PREV_HOV] = create_button (
        game->button.tuto[TUTO_PREV_HOV],
        "png/settingsbuttons/button_left_hov.png", 103 * s.x, 468.5 * s.y);
    game->button.tuto[TUTO_NEXT] = create_button (
                game->button.tuto[TUTO_NEXT],
                "png/settingsbuttons/button_right.png",
                                                    1692 * s.x, 468.5 * s.y);
    game->button.tuto[TUTO_NEXT_HOV] = create_button (
        game->button.tuto[TUTO_NEXT_HOV],
        "png/settingsbuttons/button_right_hov.png", 1692 * s.x, 468.5 * s.y);
    return (1);
}

int ui_tuto(game_t *game)
{
    if (!(game->menu.ui_tuto = malloc(sizeof(elem_t) * 2)))
        return (0);
    game->menu.ui_tuto[0] = create_element(game->menu.ui_tuto[0],
                            "png/pregame/tuto_one.png", 365, 35);
    game->menu.ui_tuto[1] = create_element(game->menu.ui_tuto[1],
                            "png/pregame/tuto_two.png", 365, 35);
    if (!(game->button.tuto = malloc(sizeof(create_button_t) * 6)))
        return (0);
    if (!(game->button.state_tuto = malloc(sizeof(int) * 6)))
        return (0);
    for (int i = 0; i < 6; ++i)
        game->button.state_tuto[i] = 0;
    game->tuto.tuto_page = 1;
    sfVector2f s = game->window->scale;
    create_button_tuto(game, s);
    scale_tuto(game);
    game->tuto.quit_tuto = false;
    return (1);
}

int scale_tuto(game_t *game)
{
    sfVector2f pos;

    for (int i = 0; i < 6; i++) {
        sfSprite_setScale(game->button.tuto[i].sprite, game->window->scale);
    }
    for (int i = 0; i < 2; i++) {
        sfSprite_setScale(game->menu.ui_tuto[i].sprite, game->window->scale);
        pos = sfSprite_getPosition(game->menu.ui_tuto[i].sprite);
        pos.x = pos.x * game->window->scale.x;
        pos.y = pos.y * game->window->scale.y;
        sfSprite_setPosition(game->menu.ui_tuto[i].sprite, pos);
    }
    return (1);
}

void destroy_tuto(game_t *game)
{
    for (int i = 0; i < 6; ++i) {
        sfTexture_destroy(game->button.tuto[i].texture);
        sfSprite_destroy(game->button.tuto[i].sprite);
    }
    for (int i = 0; i < 2; ++i) {
        sfTexture_destroy(game->menu.ui_tuto[i].texture);
        sfSprite_destroy(game->menu.ui_tuto[i].sprite);
    }
    return;
}

int player_is_in_tuto(game_t *game)
{
    if (!(ui_tuto(game)))
        return (0);
    while (game->tuto.quit_tuto == false)
    {
        draw_tuto(game);
        events_tuto(game);
        sfRenderWindow_display(game->window->window);
    }

    destroy_tuto(game);
    return (1);
}