/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"


// ? check si le joueur a assez de money.

int condition_money_is_enough(game_t *game, int is_enough)
{
    char *money = NULL;

    if (game->player_data.money >= is_enough) {
        game->player_data.money -= is_enough;
        money = my_nbrtoarray(game->player_data.money);
        sfText_setString(
                game->game_text.in_game[PLAYER_MONEY_NUMBER].string, money);
        return (1);
    } else
        return (0);
}


// ? Check si le joueur a assez de money pour poser la tour.

int check_money_when_posing(game_t *game)
{
    int is_enough = 0;

    switch (game->player_data.last_hold)
    {
    case 1:
        is_enough = 30;
        break;
    case 2:
        is_enough = 80;
        break;
    case 3:
        is_enough = 40;
        break;
    case 4:
        is_enough = 100;
        break;
    }
    if (!(condition_money_is_enough(game, is_enough)))
        return (0);
    return (1);
}


// ? Add une towers si assez de money.

int add_node_towers(game_t *game, int wich_rect)
{
    add_tower_t *node = NULL;
    if (game->player_data.place_is_fill[wich_rect] == 1)
        return (0);
    else {
        if (!(check_money_when_posing(game)))
            return (0);
        if (!(node = malloc(sizeof(add_tower_t))))
            return (change_state_cause_of_error(game));
        game->player_data.place_is_fill[wich_rect] = 1;
        game->head_tower = create_node_tower(game, wich_rect, node);
    }
    return (1);
}


// ? Ajoute une node à la liste tower (qui ne soit pas la première).

add_tower_t *create_node_tower(game_t *game, int wich_rect, add_tower_t *node)
{
    add_tower_t *last = game->head_tower;

    node->tower = create_towers_generic_function(game, wich_rect);
    node->next = NULL;
    if (game->head_tower == NULL) {
        game->head_tower = node;
        return (game->head_tower);
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node;
    return (game->head_tower);
}