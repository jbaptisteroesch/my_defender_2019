/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create ui in game
*/

#include "../include/my.h"


int create_text_in_game_pattern(game_t *game, char *string,
                                            sfVector2f position, int pos_tab)
{
    game->game_text.in_game[pos_tab].string = sfText_create();
    game->game_text.in_game[pos_tab].font = sfFont_createFromFile(
                                                "png/font/DimboRegular.ttf");
    sfText_setFont(game->game_text.in_game[pos_tab].string,
                                game->game_text.in_game[pos_tab].font);
    game->game_text.in_game[pos_tab].color =
                                                sfColor_fromRGB(219, 200, 152);
    sfText_setColor(game->game_text.in_game[pos_tab].string,
                                game->game_text.in_game[pos_tab].color);
    sfText_setCharacterSize(game->game_text.in_game[pos_tab].string, 50);
    sfText_setPosition(game->game_text.in_game[pos_tab].string,
                                                                position);
    sfText_setString(game->game_text.in_game[pos_tab].string, string);
    return (1);
}


// ? Check if cheat for player money at the beginning.

int init_player_money(game_t *game, sfVector2f position)
{
    char *money;

    money = my_nbrtoarray(game->player_data.money);
    position.x = 170;
    position.y = 1000;
    create_text_in_game_pattern(game, money, position, PLAYER_MONEY_NUMBER);
    return (1);
}


// ? création du texte, player data.

int create_text_player_data(game_t *game, sfVector2f position)
{
    position.x = 30;
    position.y = 900;
    create_text_in_game_pattern(game, "Score : ", position, PLAYER_LEVEL_TEXT);
    position.x = 170;
    position.y = 900;
    create_text_in_game_pattern(game, "0", position, PLAYER_LEVEL_NUMBER);
    position.x = 30;
    position.y = 950;
    create_text_in_game_pattern(game, "Life : ", position, PLAYER_LIFE_TEXT);
    position.x = 140;
    position.y = 950;
    create_text_in_game_pattern(game, "100", position, PLAYER_LIFE_NUMBER);
    position.x = 30;
    position.y = 1000;
    create_text_in_game_pattern(game, "Money : ", position, PLAYER_MONEY_TEXT);
    init_player_money(game, position);
    return (1);
}


// ? Création du text in game.
// ? Player data : 6 + next wave warning 2.

int create_text_ig(game_t *game)
{
    sfVector2f position;

    if (!(game->game_text.in_game = malloc(sizeof(string_t) * 8)))
        return (0);
    game->menu.ui_in_game[IG_PLAYER_TABLE] = create_element(
        game->menu.ui_in_game[IG_PLAYER_TABLE], "png/ingame/player_table.png",
                                                                20, 900);
    create_text_player_data(game, position);
    create_text_next_wave(game);
    return (1);
}