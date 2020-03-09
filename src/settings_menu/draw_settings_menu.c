/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** settings menu draw
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"


// ? Dessine la bar de séléction de la résolution.

int draw_selection_bar_resolution(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
                                game->menu.ui_settings_menu[1].sprite, NULL);
    return (1);
}


// ? Dessine les boutons close et musique.

int draw_close_and_music_button(game_t *game)
{
    if (game->button.state_settings_menu[SM_STATE_CLOSE] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                    game->button.settings_menu[SM_CLOSE_HOVER].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.settings_menu[SM_CLOSE].sprite, NULL);
    if (game->button.state_settings_menu[SM_STATE_SOUND] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.settings_menu[SM_NO_SOUND].sprite, NULL);
    else if (game->button.state_settings_menu[SM_STATE_SOUND] == 0)
        sfRenderWindow_drawSprite(game->window->window,
                            game->button.settings_menu[SM_SOUND].sprite, NULL);
    return (1);
}


// ? Dessine le menu des options.

void draw_settings_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
                                game->menu.ui_settings_menu[0].sprite, NULL);
    draw_close_and_music_button(game);
    for (int i = 0; i < 5; ++i) {
        sfRenderWindow_drawText(game->window->window,
                                game->game_text.settings_text[i].string, NULL);
    }
    draw_selection_bar_resolution(game);
    return;
}