/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"


// ? Cherche le bon png au choix de la tour.

char *choose_tower_file(int tower_type)
{
    char *file;

    switch (tower_type) {
        case 1:
            file = "png/towers/blue_tower.png";
            break;
        case 2:
            file = "png/towers/yellow_tower.png";
            break;
        case 3:
            file = "png/towers/straw_tower.png";
            break;
        case 4:
            file = "png/towers/rock_tower.png";
            break;
        default:
            file = NULL;
    }
    return (file);
}


// ? Applique le rect à la tour posée par le player.

sfIntRect choose_tower_rect_when_placing(game_t *game, create_tower_t tower)
{
    switch (game->player_data.last_hold) {
        case 1:
            tower.rect = (sfIntRect){0, 0, 202, 228};
            break;
        case 2:
            tower.rect = (sfIntRect){0, 0, 202, 226};
            break;
        case 3:
            tower.rect = (sfIntRect){0, 0, 197, 233};
            break;
        case 4:
            tower.rect = (sfIntRect){0, 0, 197, 206};
            break;
    }
    return (tower.rect);
}


// ? Choisit le type de tour, archer ou magic.

int wich_tower_type(game_t *game)
{
    int tower_type = 0;

    if (game->player_data.last_hold == 3 || game->player_data.last_hold == 4)
        tower_type = 1;
    else if (game->player_data.last_hold == 1)
        tower_type = 0;
    else if (game->player_data.last_hold == 2)
        tower_type = 2;
    return (tower_type);
}


// ? Tower type for upgrade.

int tower_type_for_upgrade(game_t *game)
{
    int type = 0;

    switch (game->player_data.last_hold) {
        case 1:
            type = 1;
            break;
        case 2:
            type = 2;
            break;
        case 3:
            type = 3;
            break;
        case 4:
            type = 4;
            break;
    }
    return (type);
}


// ? crée les damages des tours.

int create_damage_tower(create_tower_t tower)
{
    switch (tower.type_for_upgrade)
    {
    case 1:
        return (10);
    case 2:
        return (15);
    case 3:
        return (20);
    case 4:
        return (30);
    }
    return (1);
}