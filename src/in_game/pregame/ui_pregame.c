/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"


// ? Remplit le tableau des coordonnées des petites fenetres.

int fill_pregame_tab(game_t *game)
{
    if (!(game->button.state_pregame = malloc(sizeof(int) * 3)))
        return (0);
    game->button.state_pregame[0] = 0;
    game->button.state_pregame[1] = 0;
    game->button.state_pregame[2] = 0;
    return (1);
}


// ? Crée le texte du pregame.

int create_text_pregame(game_t *game)
{
    sfVector2f position;

    if (!(game->game_text.pregame = malloc(sizeof(string_t) * 2)))
        return (0);
    position.x = 652;
    position.y = 497;
    create_text_pregame_pattern(game, "TUTORIAL", position, 0);
    position.x = 1122;
    position.y = 497;
    create_text_pregame_pattern(game, "PLAY", position, 1);
    if (!(fill_pregame_tab(game)))
        return (0);
    return (1);
}


// ? Crée boutons pregame state.

int create_button_pregame(game_t *game)
{
    if (!(game->button.pregame = malloc(sizeof(create_button_t) * 4)))
        return (0);
    game->button.pregame[0] = create_button (game->button.pregame[0],
                            "png/pregame/window.png", 562, 339);
    game->button.pregame[1] = create_button(game->button.pregame[1],
                            "png/pregame/window.png", 982, 339);
    game->button.pregame[2] = create_button(game->button.pregame[2],
                "png/settingsbuttons/button_close.png", 1370.0, 193.0);
    game->button.pregame[3] = create_button(game->button.pregame[3],
                "png/settingsbuttons/button_close_shadow.png", 1370.0, 193.0);
    return (1);
}


// ? Crée l'UI du pregame.

int ui_pregame(game_t *game)
{
    if (!(game->menu.ui_pregame = malloc(sizeof(elem_t))))
        return (0);
    game->menu.ui_pregame[0] = create_element(game->menu.ui_pregame[0],
                            "png/pregame/table.png", 477, 226.5);
    game->tuto.is_in_tuto = false;
    if (!(create_text_pregame(game)))
        return (0);
    if (!(create_button_pregame(game)))
        return (0);
    return (1);
}