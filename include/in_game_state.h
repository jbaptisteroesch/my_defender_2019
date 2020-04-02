/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game state
*/

#include "../include/my.h"

#ifndef IN_GAME_STATE_H_
#define IN_GAME_STATE_H_

enum ig_buttons {
    IG_PAUSE_BUT,
    IG_PAUSE_BUT_HOV,
    IG_SHOP_BUT,
    IG_SHOP_BUT_HOV,
    IG_BT_BUT,
    IG_BT_BUT_HOV,
    IG_YT_BUT,
    IG_YT_BUT_HOV,
    IG_ST_BUT,
    IG_ST_BUT_HOV,
    IG_RT_BUT,
    IG_RT_BUT_HOV,
    IG_UPGRADE_TOWER,
    IG_UPGRADE_BT,
    IG_UPGRADE_YT,
    IG_UPGRADE_ST,
    IG_UPGRADE_RT
};

enum tuto_butt {
    TUTO_QUIT,
    TUTO_PREV,
    TUTO_NEXT,
    TUTO_QUIT_HOV,
    TUTO_PREV_HOV,
    TUTO_NEXT_HOV
};

enum ig_text {
    PLAYER_LEVEL_TEXT,
    PLAYER_LEVEL_NUMBER,
    PLAYER_LIFE_TEXT,
    PLAYER_LIFE_NUMBER,
    PLAYER_MONEY_TEXT,
    PLAYER_MONEY_NUMBER,
    WARNING_WAVE_TEXT,
    WARNING_WAVE_NUMB,
    PLAYER_WAVE_TEXT,
    PLAYER_WAVE_NUMB
};

enum ig_ui {
    IG_MAP_LEVEL_ONE,
    IG_PLAYER_TABLE,
    IG_BT_DESCRIPTION,
    IG_YT_DESCRIPTION,
    IG_ST_DESCRIPTION,
    IG_RT_DESCRIPTION,
    IG_TREE,
    IG_TREE_SEC,
    IG_BLACK_RECT
};

enum ig_towers {
    BLUE_TOWER,
    YELLOW_TOWER,
    STRAW_TOWER,
    ROCK_TOWER
};

enum ig_ennemy {
    ENNEMY_ONE,
    ENNEMY_TWO,
    ENNEMY_THREE
};

typedef struct player_s
{
    int score;
    int life;
    int money;
    int wave_number;
    int last_hold;
    int *place_is_fill;
    int next_wave_in;
    int to_upgrade;
    int wave_all_time;
    char *clock_wave;
    bool tower_is_click;
    bool holding_bt;
    bool holding_yt;
    bool holding_st;
    bool holding_rt;
    bool has_posed;
} player_t;

typedef struct arrow_info_s
{
    sfVector2f pos_tower;
    sfVector2f pos_ennemy;
    float rotate;
    int type;
    int damage;
    int level;
    int second;
} arrow_info_t;

#endif /* !IN_GAME_STATE_H_ */
