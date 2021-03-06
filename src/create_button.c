/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create button
*/

#include "../include/my.h"

create_button_t create_button(create_button_t button, char *button_name,
                                                    float pos_x, float pos_y)
{
    button.texture = sfTexture_createFromFile(button_name, NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    button.position.x = pos_x;
    button.position.y = pos_y;
    sfSprite_setPosition(button.sprite, button.position);
    return (button);
}