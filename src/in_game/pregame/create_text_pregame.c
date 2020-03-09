/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../../../include/my.h"

int create_text_pregame_pattern(game_t *game, char *string,
                                            sfVector2f position, int pos_tab)
{
    game->game_text.pregame[pos_tab].string = sfText_create();
    game->game_text.pregame[pos_tab].font = sfFont_createFromFile(
                                                "png/font/DimboRegular.ttf");
    sfText_setFont(game->game_text.pregame[pos_tab].string,
                                game->game_text.pregame[pos_tab].font);
    game->game_text.pregame[pos_tab].color =
                                                sfColor_fromRGB(219, 200, 152);
    sfText_setColor(game->game_text.pregame[pos_tab].string,
                                game->game_text.pregame[pos_tab].color);
    sfText_setCharacterSize(game->game_text.pregame[pos_tab].string, 60);
    sfText_setPosition(game->game_text.pregame[pos_tab].string,
                                                                position);
    sfText_setString(game->game_text.pregame[pos_tab].string, string);
    return (1);
}