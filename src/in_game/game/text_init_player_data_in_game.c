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
                                                sfColor_fromRGB(255, 204, 0);
    sfText_setColor(game->game_text.in_game[pos_tab].string,
                                game->game_text.in_game[pos_tab].color);
    sfText_setCharacterSize(game->game_text.in_game[pos_tab].string, 50);
    sfText_setPosition(game->game_text.in_game[pos_tab].string,
                                                                position);
    sfText_setString(game->game_text.in_game[pos_tab].string, string);
    return (1);
}

int init_player_money(game_t *game, sfVector2f position)
{
    char *money;

    money = my_nbrtoarray(game->player_data.money);
    position.x = 1550;
    position.y = 156;
    create_text_in_game_pattern(game, money, position, PLAYER_MONEY_NUMBER);
    return (1);
}

int create_text_player_data(game_t *game, sfVector2f position)
{
    position.x = 1410;
    position.y = 56;
    create_text_in_game_pattern(game, "Score : ", position, PLAYER_LEVEL_TEXT);
    position.x = 1550;
    position.y = 56;
    create_text_in_game_pattern(game, "0", position, PLAYER_LEVEL_NUMBER);
    position.x = 1410;
    position.y = 106;
    create_text_in_game_pattern(game, "Life : ", position, PLAYER_LIFE_TEXT);
    position.x = 1550;
    position.y = 106;
    create_text_in_game_pattern(game, "100", position, PLAYER_LIFE_NUMBER);
    position.x = 1410;
    position.y = 156;
    create_text_in_game_pattern(game, "Money : ", position, PLAYER_MONEY_TEXT);
    init_player_money(game, position);
    return (1);
}

int create_text_wave_number(game_t *game)
{
    sfVector2f position;
    char *str = NULL;

    str = my_nbrtoarray(game->player_data.wave_all_time);
    position.x = 1410;
    position.y = 206;
    create_text_in_game_pattern(game, "Wave : ", position, PLAYER_WAVE_TEXT);
    position.x = 1550;
    position.y = 206;
    create_text_in_game_pattern(game, str, position, PLAYER_WAVE_NUMB);
    return (1);
}

int create_text_ig(game_t *game)
{
    sfVector2f position;

    if (!(game->game_text.in_game = malloc(sizeof(string_t) * 10)))
        return (0);
    game->menu.ui_in_game[IG_PLAYER_TABLE] = create_element(
        game->menu.ui_in_game[IG_PLAYER_TABLE], "png/ingame/player_table.png",
                                                                1390, 40);
    create_text_player_data(game, position);
    create_text_wave_number(game);
    create_text_next_wave(game);
    return (1);
}