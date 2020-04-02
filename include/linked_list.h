/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** linked list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "my.h"

typedef struct create_ennemy_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f set_position;
    sfIntRect rect;
    int walk_state;
    int ennemy_life;
    int nbr_of_image;
    int is_on_image;
    int rect_to_moove;
    int state;
    int gave_money;
} create_ennemy_t;

typedef struct add_ennemy_s
{
    create_ennemy_t ennemy;
    struct add_ennemy_s *next;
} add_ennemy_t;

typedef struct create_tower_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f set_position;
    sfIntRect rect;
    int tower_type;
    int type_for_upgrade;
    int level;
    int tower_position;
    int damage;
} create_tower_t;

typedef struct add_tower_s
{
    create_tower_t tower;
    struct add_tower_s *next;
} add_tower_t;


typedef struct create_arrow_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f tower_position;
    int hit;
    int loop;
    int type;
    int damage;
} create_arrow_t;

typedef struct add_arrow_s
{
    create_arrow_t arrow;
    struct add_arrow_s *next;
} add_arrow_t;

#endif /* !LINKED_LIST_H_ */
