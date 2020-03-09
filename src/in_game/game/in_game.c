/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"


// ? Init les éléments de jeu.

int init_in_game_elements(game_t *game)
{
    if (!(in_game_button(game)))
        return (0);
    if (!(ui_in_game(game)))
        return (0);
    if (!(create_entity(game)))
        return (0);
    resize_button(game);
    resize_ui_ig(game);
    return (1);
}


// ? Boucle de l'état de jeu : ACTIF.

int in_game(game_t *game)
{
    if (!(init_in_game_elements(game)))
        return (change_state_cause_of_error(game));
    sfClock_restart(game->clock.in_game[CLOCK_NEXT_WAVE].clock);
    while (game->menu.game_state[IN_GAME] == 1) {
        events_in_game(game);
        get_money(game);
        draw_in_game(game);
        if (is_everything_draw(game) == 0)
            is_ennemy_in_game(game);
        while (game->menu.game_state[PAUSE_MENU] == 1)
            pause_menu(game);
        if (game->player_data.life == 0) {
            game->menu.game_state[IN_GAME] = 0;
            game->menu.game_state[END_MENU] = 1;
        }
        sfRenderWindow_display(game->window->window);
    }
    destroy_in_game(game);
    return (1);
}

int resize_ui_ig(game_t *game)
{
    sfVector2f pos;
    sfVector2f s = game->window->scale;

    for (int i = 0; i < 4; i++) {
        pos = sfSprite_getPosition(game->menu.ui_in_game[i].sprite);
        pos.x = pos.x * s.x;
        pos.y = pos.y * s.y;
        sfSprite_setPosition(game->menu.ui_in_game[i].sprite, pos);
        sfSprite_scale(game->menu.ui_in_game[i].sprite, s);
    }
    for (int i = 0; i < 6; i++) {
        pos = sfText_getPosition(game->game_text.in_game[i].string);
        sfText_setScale(game->game_text.in_game[i].string, s);
        pos.x = pos.x * s.x;
        pos.y = pos.y * s.y;
        sfText_setPosition(game->game_text.in_game[i].string, pos);
    }
    return (1);
}

int resize_button(game_t *game)
{
    for (int i = 0; i < 17; i++) {
        sfSprite_setScale(game->button.in_game[i].sprite, game->window->scale);
    }
    return (1);
}
//12 BOUTONS A EVOLUER = MDR C'est pas des pokémon hein