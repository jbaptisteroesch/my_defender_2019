/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** destroy in game elements
*/

#include "../include/my.h"

void destroy_tower_in_game(game_t *game)
{
    add_tower_t *current = game->head_tower;

    for (int i = 0; i < 7; ++i)
        sfRectangleShape_destroy(game->menu.placing_tower[i].rect);
    while (current != NULL) {
        sfTexture_destroy(current->tower.texture);
        sfSprite_destroy(current->tower.sprite);
        current = current->next;
    }
    return;
}

void destroy_in_game_button(game_t *game)
{
    for (int i = 0; i < 17; ++i) {
        sfTexture_destroy(game->button.in_game[i].texture);
        sfSprite_destroy(game->button.in_game[i].sprite);
    }
    return;
}

void destroy_ui_in_game(game_t *game)
{
    for (int i = 0; i < 6; ++i) {
        sfTexture_destroy(game->menu.ui_in_game[i].texture);
        sfSprite_destroy(game->menu.ui_in_game[i].sprite);
    }
    for (int i = 0; i < 8; ++i) {
        sfText_destroy(game->game_text.in_game[i].string);
        sfFont_destroy(game->game_text.in_game[i].font);
    }
    return;
}

void destroy_ennemy_in_game(game_t *game)
{
    add_ennemy_t *current = game->head_ennemy;

    while (current != NULL) {
        sfTexture_destroy(current->ennemy.texture);
        sfSprite_destroy(current->ennemy.sprite);
        current = current->next;
    }
    return;
}

void destroy_in_game(game_t *game)
{
    for (int i = 0; i < 2; i++) {
        sfSound_destroy(game->sounds[i]);
        sfSoundBuffer_destroy(game->sbuffer[i]);
    }
    destroy_in_game_button(game);
    destroy_tower_in_game(game);
    destroy_ennemy_in_game(game);
    destroy_ui_in_game(game);
    return;
}