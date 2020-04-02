/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"

int check_nbr_of_img_for_ennemy(game_t *game)
{
    int image = 0;

    switch (game->player_data.wave_number) {
        case 1:
            image = 10;
            break;
        case 2:
            image = 10;
            break;
        case 3:
            image = 10;
            break;
    }
    return (image);
}

int choose_wich_rect_to_change(game_t *game)
{
    int left = 0;

    switch (game->player_data.wave_number) {
        case 1:
            left = 160;
            break;
        case 2:
            left = 168;
            break;
        case 3:
            left = 163;
            break;
    }
    return (left);
}

int change_ennemy_rect(game_t *game)
{
    add_ennemy_t *current = game->head_ennemy;

    while (current != NULL) {
        if (current->ennemy.is_on_image == current->ennemy.nbr_of_image - 1) {
            current->ennemy.rect.top = 0;
            current->ennemy.is_on_image = 0;
        }
        current->ennemy.rect.top += current->ennemy.rect_to_moove;
        ++current->ennemy.is_on_image;
        sfSprite_setTextureRect(current->ennemy.sprite, current->ennemy.rect);
        current = current->next;
    }
    return (1);
}