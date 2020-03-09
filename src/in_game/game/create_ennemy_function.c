/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in_game
*/

#include "../include/my.h"


// ? Cherche le bon png au choix de la tour.

char *choose_ennemy_file(int ennemy_type)
{
    char *file;

    switch (ennemy_type) {
        case 1:
            file = "png/ennemy/ennemy_one.png";
            break;
        case 2:
            file = "png/ennemy/ennemy_two.png";
            break;
        case 3:
            file = "png/ennemy/ennemy_three.png";
            break;
    }
    return (file);
}


// ? Applique le rect à l'ennemy posé par le player.

sfIntRect choose_ennemy_rect(game_t *game, create_ennemy_t ennemy)
{
    switch (game->player_data.wave_number) {
        case 1:
            ennemy.rect = (sfIntRect){0, 0, 110, 160};
            break;
        case 2:
            ennemy.rect = (sfIntRect){0, 0, 118, 168};
            break;
        case 3:
            ennemy.rect = (sfIntRect){0, 0, 102, 163};
            break;
    }
    return (ennemy.rect);
}


// ? Init les ennemy en fonction des map.

sfVector2f init_ennemy_position(game_t *game, sfVector2f position)
{
    position.x = 0;
    position.y = 0;
    sfVector2f s = game->window->scale;
    position.x = 245 * s.x;
    position.y = -130 * s.y;
    if (s.x > 0.666666 && s.x < 0.666668) {
        position.x = 200;
    }
    else if (s.x > 0.36 && s.x < 0.38) {
        position.x = 200;
    }
    return (position);
}

// ? Fonction générique de création d'ennemy.

create_ennemy_t create_ennemy_generic_function(game_t *game)
{
    char *png_file; sfVector2f position; create_ennemy_t ennemy;
    png_file = choose_ennemy_file(game->player_data.wave_number);
    ennemy.texture = sfTexture_createFromFile(png_file, NULL);
    ennemy.sprite = sfSprite_create();
    ennemy.rect = choose_ennemy_rect(game, ennemy);
    sfSprite_setTexture(ennemy.sprite, ennemy.texture, sfTrue);
    sfSprite_setTextureRect(ennemy.sprite, ennemy.rect);
    position = init_ennemy_position(game, position);
    ennemy.set_position.x = position.x * game->window->scale.x;
    ennemy.set_position.y = position.y * game->window->scale.y;
    sfSprite_setPosition(ennemy.sprite, ennemy.set_position);
    sfSprite_setScale(ennemy.sprite, game->window->scale);
    ennemy.rect_to_moove = choose_wich_rect_to_change(game);
    ennemy.nbr_of_image = check_nbr_of_img_for_ennemy(game);
    ennemy.is_on_image = 0;
    ennemy.walk_state = 0;
    ennemy.ennemy_life = game->ennemy.ennemy_life;
    ennemy.state = 0;
    ennemy.gave_money = 0;
    return (ennemy);
}