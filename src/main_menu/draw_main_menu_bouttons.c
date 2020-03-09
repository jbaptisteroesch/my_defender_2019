/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw main menu buttons
*/

#include "../../include/my.h"


// ? Dessine le bouton PLAY en prenant en compte son état

void draw_play_button_main_menu(game_t *game)
{

    if (game->button.state_main_menu[MM_PLAY_BUTTON] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                game->button.main_menu[MM_PLAY_BUTTON_HOVERING].sprite, NULL);
    else if (game->button.state_main_menu[MM_PLAY_BUTTON] == 2)
        sfRenderWindow_drawSprite(game->window->window,
                game->button.main_menu[MM_PLAY_BUTTON_ONCLICK].sprite, NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.main_menu[MM_PLAY_BUTTON].sprite, NULL);
}


// ? Dessine le bouton LEADERBOARD en prenant en compte son état

void draw_leaderboard_button_main_menu(game_t *game)
{

    if (game->button.state_main_menu[MM_LEADERBOARD_BUTTON] == 1)
        sfRenderWindow_drawSprite(game->window->window,
                game->button.main_menu[MM_LEADERBOARD_BUTTON_HOVERING].sprite,
                                                                        NULL);
    else if (game->button.state_main_menu[MM_LEADERBOARD_BUTTON] == 2)
        sfRenderWindow_drawSprite(game->window->window,
                game->button.main_menu[MM_LEADERBOARD_BUTTON_ONCLICK].sprite,
                                                                        NULL);
    else
        sfRenderWindow_drawSprite(game->window->window,
            game->button.main_menu[MM_LEADERBOARD_BUTTON].sprite, NULL);
}


// ? Dessine le bouton SETTINGS en prenant en compte son état

void draw_settings_button_main_menu(game_t *game)
{

    if (game->button.state_main_menu[MM_SETTINGS_BUTTON] == 1)
    sfRenderWindow_drawSprite(game->window->window,
            game->button.main_menu[MM_SETTINGS_BUTTON_HOVERING].sprite, NULL);
    else if (game->button.state_main_menu[MM_SETTINGS_BUTTON] == 2)
    sfRenderWindow_drawSprite(game->window->window,
            game->button.main_menu[MM_SETTINGS_BUTTON_ONCLICK].sprite, NULL);
    else
    sfRenderWindow_drawSprite(game->window->window,
            game->button.main_menu[MM_SETTINGS_BUTTON].sprite, NULL);
}


// ? Dessine le bouton QUIT en prenant en compte son état

void draw_quit_button_main_menu(game_t *game)
{

    if (game->button.state_main_menu[MM_QUIT_BUTTON] == 1)
    sfRenderWindow_drawSprite(game->window->window,
                game->button.main_menu[MM_QUIT_BUTTON_HOVERING].sprite, NULL);
    else if (game->button.state_main_menu[MM_QUIT_BUTTON] == 2)
    sfRenderWindow_drawSprite(game->window->window,
                game->button.main_menu[MM_QUIT_BUTTON_ONCLICK].sprite, NULL);
    else
    sfRenderWindow_drawSprite(game->window->window,
                        game->button.main_menu[MM_QUIT_BUTTON].sprite, NULL);
}