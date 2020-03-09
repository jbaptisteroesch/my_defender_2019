/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create buttons settings menu
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"


// ? Création du bouton quitter dans le settings menu.

int create_quit_button_settings_menu(game_t *game)
{
    game->button.settings_menu[SM_CLOSE] =
                    create_button(game->button.settings_menu[SM_CLOSE],
                "png/settingsbuttons/button_close.png", 1400.0, 200.0);
    game->button.settings_menu[SM_CLOSE_HOVER] =
                    create_button(game->button.settings_menu[SM_CLOSE_HOVER],
                "png/settingsbuttons/button_close_shadow.png", 1400.0, 200.0);
    game->button.settings_menu[SM_SOUND] =
                    create_button(game->button.settings_menu[SM_SOUND],
                "png/settingsbuttons/on_button.png", 1040, 420);
    game->button.settings_menu[SM_NO_SOUND] =
                    create_button(game->button.settings_menu[SM_NO_SOUND],
                "png/settingsbuttons/off_button.png", 1040, 420);
    return (1);
}


// ? Création du bouton du menu : menu des options.

int create_settings_menu_buttons(game_t *game)
{
    if (!(game->button.settings_menu = malloc(sizeof(create_button_t) * 4)))
        return (0);
    if (!(game->button.settings_menu_tab = malloc(sizeof(float *) * 3)))
        return (0);
    for (int z = 0; z < 3; ++z) {
        if (!(game->button.settings_menu_tab[z] = malloc(sizeof(float) * 2)))
            return (0);
    }
    if (!(game->button.state_settings_menu = malloc(sizeof(int) * 3)))
        return (0);
    game->button.state_settings_menu[0] = 0;
    game->button.state_settings_menu[1] = 0;
    game->button.state_settings_menu[2] = 0;
    create_quit_button_settings_menu(game);
    return (1);
}