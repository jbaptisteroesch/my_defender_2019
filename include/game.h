/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** game struct
*/

#ifndef GAME_H_
#define GAME_H_

#include "my.h"
#include <SFML/System/Clock.h>
#include "button.h"
#include "elements.h"
#include "score_leaderboard_menu.h"
#include "in_game_state.h"
#include "linked_list.h"


// ? enum pour  les différents ETATS_DE_JEU

enum game_state {
    MAIN_MENU,
    PREGAME,
    LEADERBOARD_MENU,
    SETTINGS_MENU,
    QUIT,
    IN_GAME,
    PAUSE_MENU,
    END_MENU,
};


// ? #define UI main menu

enum ui_mm {
    BACK
};


// ? Enum des clock pour le in game state.

enum clock_ig {
    CLOCK_SHOP,
    CLOCK_NEXT_WAVE,
    CLOCK_WALK_ENNEMY,
    CLOCK_POS_ENNEMY
};


// ? Struct pour catch les textes comme des boutons.

typedef struct rectangle_s
{
    sfRectangleShape *rect;
    sfVector2f rect_size;
    sfVector2f rect_position;
    sfColor color;
    bool is_hover;
} rectangle_t;


// ? Structure de check d'état de jeu.

typedef struct game_state_s
{
    int *game_state;
    elem_t *ui_main_menu;
    elem_t ui_leaderboard_menu;
    elem_t *ui_settings_menu;
    elem_t *ui_pregame;
    elem_t *ui_tuto;
    elem_t *ui_in_game;
    rectangle_t *placing_tower;
    bool shop_is_open;
    bool shop_is_close;
    elem_t *ui_pause_menu;
    elem_t *ui_end_menu;
    bool game_is_up;
} game_state_t;


// ? Structure des textes.

typedef struct text_s
{
    string_t *score;
    string_t *settings_text;
    rectangle_t *rect_settings_text;
    string_t *pregame;
    string_t *in_game;
    string_t *end_menu;
} text_t;



// ? Struct de création de clock.

typedef struct clocks_s
{
    sfClock *clock;
    sfTime time;
    float seconds;
} clocks_t;


// ? Struct listage clock.

typedef struct clock_list_s
{
    clocks_t *in_game;
} clock_list_t;


// ? Struct de création d'entité de jeu.

typedef struct entity_s
{
    elem_t *towers;
    sfColor color_towers;
} entity_t;


// ? Sturcture regroupant les condition dans le tuto.

typedef struct tuto_s
{
    bool is_in_tuto;
    bool quit_tuto;
    int tuto_page;
} tuto_t;


// ? Stucture contenant les conditions du shop.

typedef struct shop_s
{
    bool bt_description;
    bool yt_description;
    bool st_description;
    bool rt_description;
    int tower_to_upgrade;
    sfVector2f pos_tower_to_upgrade;
} shop_t;


// ? Struture du menu de fin de jeu

typedef struct end_game_s
{
    bool press_enter;
    bool find_place;
    char *username;
    char **read_highscore;
    int lign_to_write;
} end_game_t;


// ? Structure pour les stats des ennemy

typedef struct ennemy_info_s
{
    int ennemy_life;
} ennemy_info_t;

// ? Structure de cheat code.

typedef struct cheat_s
{
    bool money;
} cheat_t;


// ? Structure principal de jeu.

typedef struct game_s
{
    window_t *window;
    game_state_t menu;
    button_list_t button;
    text_t game_text;
    clock_list_t clock;
    player_t player_data;
    tuto_t tuto;
    entity_t entity;
    sfVector2i mouse_position;
    add_tower_t *head_tower;
    add_ennemy_t *head_ennemy;
    add_arrow_t *head_arrow;
    shop_t shop;
    end_game_t end_game;
    ennemy_info_t ennemy;
    float *map_path;
    cheat_t code;
} game_t;
#endif /* !GAME_H_ */
