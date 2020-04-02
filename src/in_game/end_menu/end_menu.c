/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"

int init_end_menu(game_t *game)
{
    if (!(init_ui_end_menu(game)))
        return (0);
    if (!(init_text_end_menu(game)))
        return (0);
    return (1);
}

int end_menu(game_t *game)
{
    char *name = NULL;

    if (!(name = malloc(sizeof(char) * 11)))
        return (change_state_cause_of_error(game));
    name[0] = '\0';
    if (!(init_end_menu(game)))
        return (change_state_cause_of_error(game));
    while (game->menu.game_state[END_MENU] == 1) {
        events_end_menu(game, name);
        draw_end_menu(game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_end_menu(game);
    return (1);
}