/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"


// ? Event de check de la range pour le draw du sprite.

int ennemy_is_on_range(game_t *game)
{
    if (game->head_tower != NULL && game->head_ennemy != NULL)
        is_he_on_range(game);
    return (1);
}


// ? Boucle sur les tour et les ennemis pour savoir si il y en a dans la range.

int is_he_on_range(game_t *game)
{
    add_ennemy_t *tmp1 = game->head_ennemy;
    add_tower_t *tmp2 = game->head_tower;
    for (tmp2 = game->head_tower; tmp2 != NULL; tmp2 = tmp2->next) {
        for (tmp1 = game->head_ennemy; tmp1 != NULL; tmp1 = tmp1->next) {
            if (check_range(tmp1, tmp2, game->window->scale) == 1
            && tmp2->tower.tower_type == 1) {
                throw_arrow(tmp1, tmp2, game);
                tmp1 = game->head_ennemy;
                break;
            }
            else if (check_range(tmp1, tmp2, game->window->scale) == 1
            && (tmp2->tower.tower_type == 0 || tmp2->tower.tower_type == 2)) {
                throw_magic(tmp1, tmp2, game);
            }
        }
    tmp1 = game->head_ennemy;
    }
    return (1);
}


// ? Check la range selon la distance d'une tour et d'un ennemi

int check_range(add_ennemy_t *tmp_ennemy, add_tower_t *tmp_tower,
                                                        sfVector2f scale)
{
    if (tmp_ennemy->ennemy.ennemy_life <= 0)
        return (0);
    sfVector2f pos_ennemy = sfSprite_getPosition(tmp_ennemy->ennemy.sprite);
    sfVector2f pos_tower = sfSprite_getPosition(tmp_tower->tower.sprite);
    float dist_x = pow(pos_tower.x - pos_ennemy.x, 2);
    float dist_y = pow(pos_tower.y - pos_ennemy.y, 2);
    float final_dist = sqrt(dist_x + dist_y);
    float range = 350 * scale.x;
    if (tmp_tower->tower.tower_type == 0 || tmp_tower->tower.tower_type == 2)
        range = 250 * scale.x;
    if (final_dist < range) {
        return (1);
    }
    return (0);
}


// ? Check si un ennemi est en dehors de la map

int is_he_out_map(game_t *game)
{
    add_ennemy_t *tmp = game->head_ennemy;
    sfVector2f pos;
    char *life;

    while (tmp != NULL) {
        pos = sfSprite_getPosition(tmp->ennemy.sprite);
        if (pos.x > 1920 && tmp->ennemy.ennemy_life > 0) {
            tmp->ennemy.ennemy_life = 0;
            game->player_data.life -= 10;
            life = my_nbrtoarray(game->player_data.life);
            sfText_setString(
                    game->game_text.in_game[PLAYER_LIFE_NUMBER].string, life);
        }
        tmp = tmp->next;
    }
    return (1);
}