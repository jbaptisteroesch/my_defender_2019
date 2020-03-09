/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** leaderboard menu
*/

#include "../../include/my.h"
#include "../../include/score_leaderboard_menu.h"


// ? changement d'état à cause d'erreur. Retour au menu principal.

int change_state_cause_of_error(game_t *game)
{
    int check_tab = 0;

    while (game->menu.game_state[check_tab] != 1 &&
                                    game->menu.game_state[check_tab] != 2)
        ++check_tab;
    game->menu.game_state[check_tab] = 0;
    game->menu.game_state[MAIN_MENU] = 1;
    return (0);
}


// ? Fonction d'affichage du manque d'high score (fichier vide ou non présent).

int no_best_highscore(game_t *game)
{
    return (change_state_cause_of_error(game));
}


// ? Création du menu : TABLEAU DES SCORES.

int leaderboard_menu(game_t *game)
{
    if (!(create_leaderboard_menu_buttons(game)))
        return (no_best_highscore(game));
    if (!(create_ui_leaderboard_menu(game)))
        return (no_best_highscore(game));
    if (!(create_score(game)))
        return (no_best_highscore(game));
    resize_leaderboard_menu(game);
    resize_leaderboard_ui(game);
    while (game->menu.game_state[LEADERBOARD_MENU] == 1) {
        events_leaderboard_menu(game);
        draw_leaderboard_menu(game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_leaderboard_menu(game);
    return (1);
}

int resize_leaderboard_menu(game_t *game)
{
    sfVector2f vector = game->window->scale;
    for (int i = 0; i < 7; i++) {
        sfVector2f actual_position;
        actual_position = sfText_getPosition(game->game_text.score[i].string);
        float x = actual_position.x * vector.x;
        float y = actual_position.y * vector.y;
        actual_position.x = x;
        actual_position.y = y;
        sfText_setPosition(game->game_text.score[i].string, actual_position);
    }
    for (int i = 0; i < 7; i++) {
        sfText_scale(game->game_text.score[i].string, vector);
    }
    return (1);
}

int resize_leaderboard_ui(game_t *game)
{
    sfVector2f vector = game->window->scale;
    sfVector2f actual_position = sfSprite_getPosition(
                                    game->menu.ui_leaderboard_menu.sprite);
    actual_position.x = actual_position.x * vector.x;
    actual_position.y = actual_position.y * vector.y;
    sfSprite_setPosition(
                    game->menu.ui_leaderboard_menu.sprite, actual_position);
    sfSprite_scale(game->menu.ui_leaderboard_menu.sprite, vector);
    resize_leaderboard_two(game);
    return (1);
}