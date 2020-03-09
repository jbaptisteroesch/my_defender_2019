/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"


// ? Crée le texte du menu de fin.

int init_text_end_menu(game_t *game)
{
    sfVector2f position;

    if (!(game->game_text.end_menu = malloc(sizeof(string_t) * 2)))
        return (0);
    position.x = 875;
    position.y = 400;
    create_text_end_menu_pattern(game, "Explication", position, 0);
    position.x = 775;
    position.y = 505;
    create_text_end_menu_pattern(game, "", position, 1);
    sfText_setCharacterSize(game->game_text.end_menu[1].string, 70);
    return (1);
}


int create_text_end_menu_pattern(game_t *game, char *string,
                                            sfVector2f position, int pos_tab)
{
    game->game_text.end_menu[pos_tab].string = sfText_create();
    game->game_text.end_menu[pos_tab].font = sfFont_createFromFile(
                                                "png/font/DimboRegular.ttf");
    sfText_setFont(game->game_text.end_menu[pos_tab].string,
                                game->game_text.end_menu[pos_tab].font);
    game->game_text.end_menu[pos_tab].color =
                                                sfColor_fromRGB(219, 200, 152);
    sfText_setColor(game->game_text.end_menu[pos_tab].string,
                                game->game_text.end_menu[pos_tab].color);
    sfText_setCharacterSize(game->game_text.end_menu[pos_tab].string, 50);
    sfText_setPosition(game->game_text.end_menu[pos_tab].string,
                                                                position);
    sfText_setString(game->game_text.end_menu[pos_tab].string, string);
    return (1);
}


// ? Crée l'UI du menu de fin.

int init_ui_end_menu(game_t *game)
{
    if (!(game->menu.ui_end_menu = malloc(sizeof(elem_t) * 2)))
        return (0);
    game->menu.ui_end_menu[BACK] = create_element(
            game->menu.ui_end_menu[BACK], "png/pregame/table.png", 477, 226.5);
    game->menu.ui_end_menu[1] = create_element(
            game->menu.ui_end_menu[1], "png/entry.png", 750, 500);
    game->end_game.press_enter = false;
    if (!(game->end_game.username = malloc(sizeof(char) * 10)))
        return (0);
    for (int i = 0; i < 10; ++i)
        game->end_game.username[i] = '\0';
    if (!(game->end_game.read_highscore = malloc(sizeof(char *) * 7)))
        return (0);
    for (int z = 0; z < 7; ++z) {
        if (!(game->end_game.read_highscore[z] = malloc(sizeof(char) * 20)))
            return (0);
    }
    game->end_game.find_place = false;
    return (1);
}