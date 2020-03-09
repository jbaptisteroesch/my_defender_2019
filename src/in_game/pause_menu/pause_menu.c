/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** pause menu
*/

#include "../include/my.h"

int resize_pause_menu(game_t *game)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_setScale(game->menu.ui_pause_menu[i].sprite,
                                                        game->window->scale);
    }
    for (int i = 0; i < 6; i++) {
        sfSprite_setScale(game->button.pause_menu[i].sprite,
                                                        game->window->scale);
    }
    return (1);
}

// ? Détruit les élément du menu de pause.

void destroy_pause_menu(game_t *game)
{
    for (int i = 0; i < 6; ++i) {
        sfTexture_destroy(game->button.pause_menu[i].texture);
        sfSprite_destroy(game->button.pause_menu[i].sprite);
    }
    sfTexture_destroy(game->menu.ui_pause_menu[BACK].texture);
    sfSprite_destroy(game->menu.ui_pause_menu[BACK].sprite);
    return;
}


// ? Boucle de l'état de jeu : MENU PAUSE.

int pause_menu(game_t *game)
{
    if (!(ui_pause_menu(game)))
        return (change_state_cause_of_error(game));
    while (game->menu.game_state[PAUSE_MENU] == 1) {
        events_pause_menu(game);
        draw_pause_menu(game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_pause_menu(game);
    return (1);
}