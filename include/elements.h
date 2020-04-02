/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** elements
*/

#include "my.h"

#ifndef ELEMENTS_H_
#define ELEMENTS_H_

typedef struct elem_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f set_position;
    sfVector2f get_position;
    sfIntRect rect;
} elem_t;

#endif /* !ELEMENTS_H_ */
