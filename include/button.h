/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** button h
*/

#include "my.h"

#ifndef BUTTON_H_
#define BUTTON_H_


// ? enum pour les MAIN_MENU buttons.

enum mm_button {
    MM_PLAY_BUTTON,
    MM_LEADERBOARD_BUTTON,
    MM_SETTINGS_BUTTON,
    MM_QUIT_BUTTON,
    MM_PLAY_BUTTON_HOVERING,
    MM_LEADERBOARD_BUTTON_HOVERING,
    MM_SETTINGS_BUTTON_HOVERING,
    MM_QUIT_BUTTON_HOVERING,
    MM_PLAY_BUTTON_ONCLICK,
    MM_LEADERBOARD_BUTTON_ONCLICK,
    MM_SETTINGS_BUTTON_ONCLICK,
    MM_QUIT_BUTTON_ONCLICK
};


// ? enum pour les boutons de PAUSE MENU.

enum pm_buttons {
    PM_PLAY_BUTTON,
    PM_MM_BUTTON,
    PM_QUIT_BUTTON,
    PM_PLAY_BUTTON_HOVER,
    PM_MM_BUTTON_HOVER,
    PM_QUIT_BUTTON_HOVER,
};


// ? enum pos X et Y

enum coord {
    X,
    Y
};


// ? struct button contenant.

typedef struct create_button_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfFloatRect button_rect;
    bool is_hover;
    bool is_click;
} create_button_t;


// ? liste des boutons, le tableau save les coordonnées des boutons
// ? Les int check l'état des boutons au passage de la souris.

typedef struct button_list_s
{
    create_button_t *main_menu;
    int *state_main_menu;
    create_button_t *leaderboard;
    int state_leaderboard_menu;
    create_button_t *settings_menu;
    float **settings_menu_tab;
    int *state_settings_menu;
    create_button_t *pregame;
    int *state_pregame;
    create_button_t *tuto;
    int *state_tuto;
    create_button_t *in_game;
    float **in_game_tab;
    int *state_in_game;
    create_button_t *pause_menu;
    int *state_pause_menu;
    create_button_t *end_menu;
    int *end_menu_state;
} button_list_t;



#endif /* !BUTTON_H_ */
