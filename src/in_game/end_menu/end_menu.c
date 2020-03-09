/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"


// ? Init les éléments du menu de fin.

int init_end_menu(game_t *game)
{
    if (!(init_ui_end_menu(game)))
        return (0);
    if (!(init_text_end_menu(game)))
        return (0);
    return (1);
}


// ? Boucle de l'état de jeu : MENU DE FIN.

int end_menu(game_t *game)
{
    if (!(init_end_menu(game)))
        return (change_state_cause_of_error(game));
    while (game->menu.game_state[END_MENU] == 1) {
        events_end_menu(game);
        draw_end_menu(game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_end_menu(game);
    return (1);
}