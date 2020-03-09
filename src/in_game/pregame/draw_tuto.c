/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"


// ? draw les boutons du tuto.

void draw_tuto_buttons(game_t *game)
{
    if (game->button.state_tuto[TUTO_QUIT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.tuto[TUTO_QUIT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.tuto[TUTO_QUIT].sprite, NULL);
    if (game->button.state_tuto[TUTO_PREV] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.tuto[TUTO_PREV_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.tuto[TUTO_PREV].sprite, NULL);
    if (game->button.state_tuto[TUTO_NEXT] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.tuto[TUTO_NEXT_HOV].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.tuto[TUTO_NEXT].sprite, NULL);
    return;
}


// ? draw le tuto.

void draw_tuto(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    if (game->tuto.tuto_page == 1)
        sfRenderWindow_drawSprite(game->window->window,
                                        game->menu.ui_tuto[BACK].sprite, NULL);
    else if (game->tuto.tuto_page == 2)
        sfRenderWindow_drawSprite(game->window->window,
                                        game->menu.ui_tuto[1].sprite, NULL);
    draw_tuto_buttons(game);
    return;
}