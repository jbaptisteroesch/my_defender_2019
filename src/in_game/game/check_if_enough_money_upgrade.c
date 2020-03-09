/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui in game
*/

#include "../include/my.h"


// ? check si le joueur a assez de money lors de l'upgrade d'une tour.

int condition_money_is_enough_for_upgrade(game_t *game, int is_enough)
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


// ? Check si le joueur a assez de money pour upgrade la tour.

int check_money_when_upgrade(game_t *game, add_tower_t *current)
{
    int is_enough = 0;

    switch (current->tower.type_for_upgrade)
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
    if (!(condition_money_is_enough_for_upgrade(game, is_enough)))
        return (0);
    return (1);
}

// ? Check la monnaie pour l'upgrade et set le texte.

int check_money_for_upgrade(game_t *game, add_tower_t *current)
{
    if (!(check_money_when_upgrade(game, current)))
        return (0);
    current->tower.level += 1;
    current->tower.damage += 5;
    current->tower.rect.left += switch_rect(current);
    sfSprite_setTextureRect(current->tower.sprite, current->tower.rect);
    current->tower.set_position.x = moove_sprite_after_upgrade(current);
    sfSprite_setPosition(current->tower.sprite, current->tower.set_position);
    game->player_data.tower_is_click = 0;
    return (1);
}