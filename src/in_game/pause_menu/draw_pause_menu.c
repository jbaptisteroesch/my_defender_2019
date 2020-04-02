/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** pause menu
*/

#include "../include/my.h"

void draw_pause_menu_buttons(game_t *game)
{
    if (game->button.state_pause_menu[PM_PLAY_BUTTON] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.pause_menu[PM_PLAY_BUTTON_HOVER].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.pause_menu[PM_PLAY_BUTTON].sprite, NULL);
    if (game->button.state_pause_menu[PM_MM_BUTTON] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.pause_menu[PM_MM_BUTTON_HOVER].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.pause_menu[PM_MM_BUTTON].sprite, NULL);
    if (game->button.state_pause_menu[PM_QUIT_BUTTON] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.pause_menu[PM_QUIT_BUTTON_HOVER].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.pause_menu[PM_QUIT_BUTTON].sprite, NULL);
    return;
}

void draw_pause_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                    game->menu.ui_pause_menu[0].sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                    game->menu.ui_pause_menu[1].sprite, NULL);
    draw_pause_menu_buttons(game);
    return;
}