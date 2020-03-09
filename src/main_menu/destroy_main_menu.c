/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** destroy main menu
*/

#include "../../include/my.h"


// ? Détruit les sprites des boutons du menu principal.

int destroy_main_menu_buttons_sprite(game_t *game)
{
    sfSprite_destroy(game->button.main_menu[MM_PLAY_BUTTON].sprite);
    sfSprite_destroy(game->button.main_menu[MM_LEADERBOARD_BUTTON].sprite);
    sfSprite_destroy(game->button.main_menu[MM_SETTINGS_BUTTON].sprite);
    sfSprite_destroy(game->button.main_menu[MM_QUIT_BUTTON].sprite);
    sfSprite_destroy(game->button.main_menu[MM_PLAY_BUTTON_HOVERING].sprite);
    sfSprite_destroy(
            game->button.main_menu[MM_LEADERBOARD_BUTTON_HOVERING].sprite);
    sfSprite_destroy(
            game->button.main_menu[MM_SETTINGS_BUTTON_HOVERING].sprite);
    sfSprite_destroy(game->button.main_menu[MM_QUIT_BUTTON_HOVERING].sprite);
    sfSprite_destroy(game->button.main_menu[MM_PLAY_BUTTON_ONCLICK].sprite);
    sfSprite_destroy(
            game->button.main_menu[MM_LEADERBOARD_BUTTON_ONCLICK].sprite);
    sfSprite_destroy(game->button.main_menu[MM_SETTINGS_BUTTON_ONCLICK].sprite);
    sfSprite_destroy(game->button.main_menu[MM_QUIT_BUTTON_ONCLICK].sprite);
    return (1);
}


// ? Détruit les textures des bouttons du menu principal.

int destroy_main_menu_buttons_texture(game_t *game)
{
    sfTexture_destroy(game->button.main_menu[MM_PLAY_BUTTON].texture);
    sfTexture_destroy(game->button.main_menu[MM_LEADERBOARD_BUTTON].texture);
    sfTexture_destroy(game->button.main_menu[MM_SETTINGS_BUTTON].texture);
    sfTexture_destroy(game->button.main_menu[MM_QUIT_BUTTON].texture);
    sfTexture_destroy(game->button.main_menu[MM_PLAY_BUTTON_HOVERING].texture);
    sfTexture_destroy(
            game->button.main_menu[MM_LEADERBOARD_BUTTON_HOVERING].texture);
    sfTexture_destroy(
            game->button.main_menu[MM_SETTINGS_BUTTON_HOVERING].texture);
    sfTexture_destroy(game->button.main_menu[MM_QUIT_BUTTON_HOVERING].texture);
    sfTexture_destroy(game->button.main_menu[MM_PLAY_BUTTON_ONCLICK].texture);
    sfTexture_destroy(
            game->button.main_menu[MM_LEADERBOARD_BUTTON_ONCLICK].texture);
    sfTexture_destroy(
            game->button.main_menu[MM_SETTINGS_BUTTON_ONCLICK].texture);
    sfTexture_destroy(game->button.main_menu[MM_QUIT_BUTTON_ONCLICK].texture);
    return (1);
}


// ? Détruit les éléments du menu principal.

int destroy_main_menu_elements(game_t *game)
{
    destroy_main_menu_buttons_sprite(game);
    destroy_main_menu_buttons_texture(game);
    sfSprite_destroy(game->menu.ui_main_menu[BACK].sprite);
    sfTexture_destroy(game->menu.ui_main_menu[BACK].texture);
    return (1);
}