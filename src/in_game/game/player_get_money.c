/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** destroy in game elements
*/

#include "../include/my.h"

int get_money(game_t *game)
{
    if (game->head_ennemy == NULL)
        return (1);
    char *money;
    add_ennemy_t *tmp = game->head_ennemy;
    while (tmp != NULL) {
        if (tmp->ennemy.gave_money == 0 && tmp->ennemy.ennemy_life <= 0 &&
                                        tmp->ennemy.set_position.x <= 1920) {
            tmp->ennemy.gave_money++;
            game->player_data.money += 10;
            game->player_data.score += 5;
            money = my_nbrtoarray(game->player_data.money);
            sfText_setString(
                    game->game_text.in_game[PLAYER_MONEY_NUMBER].string, money);
            money = my_nbrtoarray(game->player_data.score);
            sfText_setString(game->game_text.in_game[PLAYER_LEVEL_NUMBER].
            string, money);
        }
        tmp = tmp->next;
    }
    return (1);
}