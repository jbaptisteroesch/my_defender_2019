/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"

int create_node_ennemy(game_t *game, add_ennemy_t **head)
{
    add_ennemy_t *node;

    if (!(node = malloc(sizeof(add_ennemy_t))))
        return (0);
    node->ennemy = create_ennemy_generic_function(game);
    node->next = *head;
    *head = node;
    return (1);
}

int create_wave_one(game_t *game)
{
    int ennemy = 10;
    game->head_ennemy = NULL;

    while (ennemy > 0) {
        if (!(create_node_ennemy(game, &(game->head_ennemy))))
            return (change_state_cause_of_error(game));
        --ennemy;
    }
    move_ennemy_at_start(game);
    return (1);
}

int move_ennemy_at_start(game_t *game)
{
    add_ennemy_t *tmp = game->head_ennemy;
    int gap = 0;

    while (tmp != NULL) {
        tmp->ennemy.set_position.y -= gap;
        gap += 150 * game->window->scale.y;
        sfSprite_setPosition(tmp->ennemy.sprite, tmp->ennemy.set_position);
        tmp = tmp->next;
    }
    return (1);
}

int create_ennemy(game_t *game)
{
    char *string = NULL;

    if (game->player_data.wave_number > 3)
        game->player_data.wave_number = 1;
    game->player_data.wave_all_time += 1;
    string = my_nbrtoarray(game->player_data.wave_all_time);
    sfText_setString(game->game_text.in_game[PLAYER_WAVE_NUMB].string, string);
    game->ennemy.ennemy_life += 50;
    create_wave_one(game);
    return (1);
}