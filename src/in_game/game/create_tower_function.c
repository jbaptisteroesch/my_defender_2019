/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game events
*/

#include "../include/my.h"

sfVector2f create_towers_generic_function_next(game_t *game,
                                                        create_tower_t tower)
{
    if (game->player_data.last_hold == 4) {
        tower.set_position.x += 10 * game->window->scale.x;
        tower.set_position.y += 20 * game->window->scale.y;
    }
    return (tower.set_position);
}

create_tower_t create_towers_generic_function(game_t *game, int rect)
{
    char *png_file;
    create_tower_t tower;

    png_file = choose_tower_file(game->player_data.last_hold);
    tower.texture = sfTexture_createFromFile(png_file, NULL);
    tower.sprite = sfSprite_create();
    tower.tower_type = wich_tower_type(game);
    tower.type_for_upgrade = tower_type_for_upgrade(game);
    tower.level = 1;
    tower.tower_position = rect;
    tower.rect = choose_tower_rect_when_placing(game, tower);
    sfSprite_setTexture(tower.sprite, tower.texture, sfTrue);
    sfSprite_setTextureRect(tower.sprite, tower.rect);
    tower.set_position.x = game->menu.placing_tower[rect].rect_position.x;
    tower.set_position.y = game->menu.placing_tower[rect].rect_position.y;
    sfSprite_setScale(tower.sprite, game->window->scale);
    tower.set_position = create_towers_generic_function_next(game, tower);
    sfSprite_setPosition(tower.sprite, tower.set_position);
    tower.damage = create_damage_tower(tower);
    return (tower);
}