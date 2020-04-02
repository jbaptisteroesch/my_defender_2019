/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** pause menu
*/

#include "../include/my.h"

int create_quit_button_pause_menu(game_t *game)
{
    sfVector2f s = game->window->scale;
    game->button.pause_menu[PM_QUIT_BUTTON] = create_button (
                        game->button.pause_menu[PM_QUIT_BUTTON],
                        "png/mainmenu_buttons/quit.png", 763 * s.x, 699 * s.y);
    game->button.pause_menu[PM_QUIT_BUTTON_HOVER] = create_button (
            game->button.pause_menu[PM_QUIT_BUTTON_HOVER],
            "png/mainmenu_buttons/quit_hovering.png", 764.55 * s.x, 700 * s.y);
    return (1);
}

int create_button_pause_menu(game_t *game)
{
    sfVector2f s = game->window->scale;
    game->button.pause_menu[PM_PLAY_BUTTON] = create_button (
                    game->button.pause_menu[PM_PLAY_BUTTON],
                        "png/mainmenu_buttons/play.png", 763 * s.x, 319 * s.y);
    game->button.pause_menu[PM_PLAY_BUTTON_HOVER] = create_button (
            game->button.pause_menu[PM_PLAY_BUTTON_HOVER],
            "png/mainmenu_buttons/play_hovering.png", 763.5 * s.x, 319 * s.y);
    game->button.pause_menu[PM_MM_BUTTON] = create_button (
                game->button.pause_menu[PM_MM_BUTTON],
                        "png/pausemenu/main_menu.png", 763 * s.x, 509 * s.y);
    game->button.pause_menu[PM_MM_BUTTON_HOVER] = create_button (
                game->button.pause_menu[PM_MM_BUTTON_HOVER],
                    "png/pausemenu/main_menu_hov.png", 763.5 * s.x, 509 * s.y);
    create_quit_button_pause_menu(game);
    return (1);
}

int create_table_pause_menu(game_t *game)
{
    sfVector2f s = game->window->scale;
    game->menu.ui_pause_menu[BACK] = create_element(
        game->menu.ui_pause_menu[BACK], "png/mainmenu/table.png", 640.5 *
                                                        s.x, 139.5 * s.y);
    game->menu.ui_pause_menu[1] = create_element(
                            game->menu.ui_pause_menu[1],
                            "png/pausemenu/pause_title.png", 760.5 *
                                                        s.x, 139.5 * s.y);
    return (1);
}

int ui_pause_menu(game_t *game)
{
    if (!(game->button.pause_menu = malloc(sizeof(create_button_t) * 6)))
        return (0);
    if (!(game->menu.ui_pause_menu = malloc(sizeof(elem_t) * 2)))
        return (0);
    if (!(game->button.state_pause_menu = malloc(sizeof(int) * 3)))
        return (0);
    for (int i = 0; i < 3; ++i)
        game->button.state_in_game[i] = 0;
    create_button_pause_menu(game);
    create_table_pause_menu(game);
    resize_pause_menu(game);
    return (1);
}