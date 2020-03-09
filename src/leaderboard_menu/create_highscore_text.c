/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create title highscore menu
*/

#include "../include/my.h"


// ? Fonction de création de string du Highscore.

int create_text_highscore(game_t *game, char *str)
{
    sfText_setString(game->game_text.score[HS_SEVEN].string, str);
    game->game_text.score[HS_SEVEN].font = sfFont_createFromFile(
                                                "png/font/DimboRegular.ttf");
    sfText_setFont(game->game_text.score[HS_SEVEN].string,
                                        game->game_text.score[HS_SEVEN].font);
    game->game_text.score[HS_SEVEN].color = sfColor_fromRGB(219, 200, 152);
    sfText_setColor(game->game_text.score[HS_SEVEN].string,
                                    game->game_text.score[HS_SEVEN].color);
    sfText_setCharacterSize(game->game_text.score[HS_SEVEN].string, 60);
    game->game_text.score[HS_SEVEN].place_string.x = 710.0;
    game->game_text.score[HS_SEVEN].place_string.y = 375.0;
    sfText_setPosition(game->game_text.score[HS_SEVEN].string,
                                game->game_text.score[HS_SEVEN].place_string);
    return (1);
}