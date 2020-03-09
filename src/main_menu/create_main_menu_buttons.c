/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create mm buttons
*/

#include "../../include/my.h"


// ? Fonction de création des boutons du menu pricncipal, comportement au clic.

int create_main_menu_onclick_buttons(game_t *game)
{
    game->button.main_menu[MM_PLAY_BUTTON_ONCLICK] =
        create_button(game->button.main_menu[MM_PLAY_BUTTON_ONCLICK],
        "png/mainmenu_buttons/play_click.png", 764.0, 220.5);
    game->button.main_menu[MM_LEADERBOARD_BUTTON_ONCLICK] =
        create_button(game->button.main_menu[MM_LEADERBOARD_BUTTON_ONCLICK],
        "png/mainmenu_buttons/leaderboard_click.png", 764.0, 385.5);
    game->button.main_menu[MM_SETTINGS_BUTTON_ONCLICK] =
        create_button(game->button.main_menu[MM_SETTINGS_BUTTON_ONCLICK],
        "png/mainmenu_buttons/settings_click.png", 764.0, 550.5);
    game->button.main_menu[MM_QUIT_BUTTON_ONCLICK] =
        create_button(game->button.main_menu[MM_QUIT_BUTTON_ONCLICK],
        "png/mainmenu_buttons/quit_click.png", 764.0, 716.5);
    return (1);
}


// ? Fonction de création des boutons du menu principal, comportement au survol.

int create_main_menu_hovering_buttons(game_t *game)
{
    game->button.main_menu[MM_PLAY_BUTTON_HOVERING] =
        create_button(game->button.main_menu[MM_PLAY_BUTTON_HOVERING],
        "png/mainmenu_buttons/play_hovering.png", 764.5, 220.5);
    game->button.main_menu[MM_LEADERBOARD_BUTTON_HOVERING] =
        create_button(game->button.main_menu[MM_LEADERBOARD_BUTTON_HOVERING],
        "png/mainmenu_buttons/leaderboard_hovering.png", 764.5, 385.5);
    game->button.main_menu[MM_SETTINGS_BUTTON_HOVERING] =
        create_button(game->button.main_menu[MM_SETTINGS_BUTTON_HOVERING],
        "png/mainmenu_buttons/settings_hovering.png", 764.5, 550.5);
    game->button.main_menu[MM_QUIT_BUTTON_HOVERING] =
        create_button(game->button.main_menu[MM_QUIT_BUTTON_HOVERING],
        "png/mainmenu_buttons/quit_hovering.png", 765.5, 717.5);
    if (!(create_main_menu_onclick_buttons(game)))
        return (0);
    return (1);
}


// ? Fonction de création des boutons du menu principal.

int create_main_menu_buttons(game_t *game)
{
    game->button.main_menu[MM_PLAY_BUTTON] =
                    create_button(game->button.main_menu[MM_PLAY_BUTTON],
        "png/mainmenu_buttons/play.png", 764.0, 220.5);
    game->button.main_menu[MM_LEADERBOARD_BUTTON] =
                    create_button(game->button.main_menu[MM_LEADERBOARD_BUTTON],
        "png/mainmenu_buttons/leaderboard.png", 764.0, 385.5);
    game->button.main_menu[MM_SETTINGS_BUTTON] =
                    create_button(game->button.main_menu[MM_SETTINGS_BUTTON],
        "png/mainmenu_buttons/settings.png", 764.0, 550.5);
    game->button.main_menu[MM_QUIT_BUTTON] =
                    create_button(game->button.main_menu[MM_QUIT_BUTTON],
        "png/mainmenu_buttons/quit.png", 764, 716.5);
    if (!(create_main_menu_hovering_buttons(game)))
        return (0);
    return (1);
}


// ? Initialisation du tableau d'état des boutons.

int initiate_state_button_tab(game_t *game)
{
    if (!(game->button.state_main_menu = malloc(sizeof(int) * 4)))
        return (0);
    game->button.state_main_menu[0] = 0;
    game->button.state_main_menu[1] = 0;
    game->button.state_main_menu[2] = 0;
    game->button.state_main_menu[3] = 0;
    return (1);
}