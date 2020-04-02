/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"

int init_rect_towers(game_t *game)
{
    game->entity.towers[BLUE_TOWER].rect = (sfIntRect){0, 0, 202, 228};
    game->entity.towers[YELLOW_TOWER].rect = (sfIntRect){0, 0, 202, 226};
    game->entity.towers[STRAW_TOWER].rect = (sfIntRect){0, 0, 197, 233};
    game->entity.towers[ROCK_TOWER].rect = (sfIntRect){0, 0, 197, 206};
    sfSprite_setTextureRect(game->entity.towers[BLUE_TOWER].sprite,
                                        game->entity.towers[BLUE_TOWER].rect);
    sfSprite_setTextureRect(game->entity.towers[YELLOW_TOWER].sprite,
                                        game->entity.towers[YELLOW_TOWER].rect);
    sfSprite_setTextureRect(game->entity.towers[STRAW_TOWER].sprite,
                                        game->entity.towers[STRAW_TOWER].rect);
    sfSprite_setTextureRect(game->entity.towers[ROCK_TOWER].sprite,
                                        game->entity.towers[ROCK_TOWER].rect);
    return (1);
}

int create_towers(game_t *game)
{
    if (!(game->entity.towers = malloc(sizeof(elem_t) * 4)))
        return (0);
    game->head_tower = NULL;
    game->head_arrow = NULL;
    game->entity.towers[BLUE_TOWER] = create_element(
            game->entity.towers[BLUE_TOWER], "png/towers/blue_tower.png", 0, 0);
    game->entity.towers[YELLOW_TOWER] = create_element(
        game->entity.towers[YELLOW_TOWER], "png/towers/yellow_tower.png", 0, 0);
    game->entity.towers[STRAW_TOWER] = create_element(
        game->entity.towers[STRAW_TOWER], "png/towers/straw_tower.png", 0, 0);
    game->entity.towers[ROCK_TOWER] = create_element(
            game->entity.towers[ROCK_TOWER], "png/towers/rock_tower.png", 0, 0);
    init_rect_towers(game);
    return (1);
}

int alloc_path(game_t *game, float *tab)
{
    if (!(game->map_path = malloc(sizeof(float) * 14)))
        return (0);
    for (int i = 0; i < 14; ++i)
        game->map_path[i] = tab[i];
    return (1);
}

int init_path(game_t *game)
{
    sfVector2f s = game->window->scale;
    float tab[14] = {135 * s.y, 450 * s.x, 185 * s.y, 530 * s.x, 445 * s.y, 645
    * s.x, 504 * s.y, 850 * s.x, 565 * s.y, 900 * s.x, 830 * s.y, 1450 * s.x,
    920 * s.y, 2000 * s.x};
    if (s.x > 0.666666 && s.x < 0.666668) {
        tab[4] = 390;
        tab[10] = 630;
        tab[12] = 680;
    }
    if (s.x > 0.36 && s.x < 0.38) {
        tab[1] = tab[1] + 30;
        tab[3] = tab[3] - 50;
        tab[2] = 320;
        tab[4] = tab[4] + 50;
        tab[5] = tab[5] - 60;
        tab[6] = tab[6] - 60;
        tab[10] = tab[10] + 110;
    }
    if (alloc_path(game, tab) == 0) return (0);
    return (1);
}

int create_entity(game_t *game)
{
    if (!(create_towers(game)))
        return (0);
    game->ennemy.ennemy_life = 50;
    if (!(create_ennemy(game)))
        return (0);
    if (!(init_path(game)))
        return (0);
    game->clock.in_game[CLOCK_NEXT_WAVE].clock = sfClock_create();
    game->clock.in_game[CLOCK_WALK_ENNEMY].clock = sfClock_create();
    game->clock.in_game[CLOCK_POS_ENNEMY].clock = sfClock_create();
    return (1);
}