/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui in game
*/

#include "../include/my.h"


// ? Update du sprite de la tour upgrade.

int switch_rect(add_tower_t *current)
{
    int rect = 0;

    switch (current->tower.type_for_upgrade) {
        case 1:
            rect = 202;
            break;
        case 2:
            rect = 202;
            break;
        case 3:
            rect = 197;
            break;
        case 4:
            rect = 197;
            break;
    }
    return (rect);
}


// ? Déplace le sprite après l'upgrade pour qu'il reste sur la position.

int moove_sprite_after_upgrade(add_tower_t *current)
{
    int x = current->tower.set_position.x;

    if (current->tower.level == 2)
        x -= 8;
    if (current->tower.level == 3)
        x -= 18;
    return (x);
}