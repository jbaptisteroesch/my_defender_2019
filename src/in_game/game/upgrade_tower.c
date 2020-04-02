/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui in game
*/

#include "../include/my.h"

int do_upgrade_tower(game_t *game)
{
    add_tower_t *current = game->head_tower;

    while (current != NULL && current->tower.tower_position !=
                                            game->player_data.to_upgrade)
        current = current->next;
    if (current->tower.level == 3) {
        game->player_data.tower_is_click = 0;
        return (0);
    }
    else {
        if (!(check_money_for_upgrade(game, current))) {
            game->player_data.tower_is_click = 0;
            return (0);
        }
    }
    return (1);
}

int hide_sprite_upgrade(game_t *game, int i)
{
    sfFloatRect rect_rect;
    bool is_hover = false;

    rect_rect = sfSprite_getGlobalBounds(
                    game->button.in_game[IG_UPGRADE_TOWER].sprite);
    is_hover = sfFloatRect_contains(&(rect_rect),
                        game->mouse_position.x, game->mouse_position.y);
    if (!is_hover) {
        game->player_data.tower_is_click = 0;
        return (1);
    }
    return (1);
}

int display_sprite_upgrade(game_t *game, int i)
{
    add_tower_t *current = game->head_tower;

    game->player_data.tower_is_click = 1;
    game->button.in_game[IG_UPGRADE_TOWER].position.x =
        (game->menu.placing_tower[i].rect_position.x + 20);
    game->button.in_game[IG_UPGRADE_TOWER].position.y =
        (game->menu.placing_tower[i].rect_position.y + 30);
    sfSprite_setPosition(game->button.in_game[IG_UPGRADE_TOWER].sprite,
                        game->button.in_game[IG_UPGRADE_TOWER].position);
    game->player_data.to_upgrade = i;
    while (current != NULL && current->tower.tower_position !=
                                            game->player_data.to_upgrade)
        current = current->next;
    game->shop.tower_to_upgrade = current->tower.type_for_upgrade;
    if (current->tower.level == 3)
        game->player_data.tower_is_click = 0;
    game->shop.pos_tower_to_upgrade.x = current->tower.set_position.x;
    game->shop.pos_tower_to_upgrade.y = current->tower.set_position.y;
    return (1);
}

int display_or_not_sprite_upgrade(game_t *game, int i)
{
    if (!game->player_data.tower_is_click)
        display_sprite_upgrade(game, i);
    else if (game->player_data.tower_is_click)
        hide_sprite_upgrade(game, i);
    return (1);
}