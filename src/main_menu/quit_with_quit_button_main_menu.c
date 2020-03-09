/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** quit game with quit button main menu
*/

#include "../../include/my.h"


// ? Quitter le jeu avec le bouton quitter du menu principal.

int quit_game(game_t *game)
{
    game->menu.game_state[QUIT] = 0;
    game->menu.game_is_up = 0;
    return (1);
}