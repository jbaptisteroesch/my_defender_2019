/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** score string struct
*/

#include "my.h"

#ifndef SCORE_LEADERBOARD_MENU_H_
#define SCORE_LEADERBOARD_MENU_H_

enum highscore {HS_ONE,
    HS_TWO,
    HS_THREE,
    HS_FOUR,
    HS_FIVE,
    HS_SIX,
    HS_SEVEN
};

typedef struct s_string
{
    sfText *string;
    sfFont *font;
    sfColor color;
    sfVector2f place_string;
} string_t;

#endif /* !SCORE_LEADERBOARD_MENU_H_ */
