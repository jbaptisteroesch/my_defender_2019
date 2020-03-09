/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create score on leaderboard menu
*/

#include "../../include/my.h"
#include "../../include/score_leaderboard_menu.h"


// ? Analyse du fichier highscore et set des strings d'highscore.

int read_buffer(game_t *game, char *buffer)
{
    int score_index = 0;
    int in_str_index = 0;
    char *temp_str = NULL;

    if (!(temp_str = malloc(sizeof(char) * 15)))
        return (no_best_highscore(game));
    for (int buff_index = 0; buffer[buff_index] != '\0'; ++buff_index) {
        if (buffer[buff_index] == '\n') {
            temp_str[in_str_index] = '\0';
            sfText_setString(game->game_text.score[score_index].string,
                                                                    temp_str);
            ++score_index;
            in_str_index = 0;
            continue;
        }
        temp_str[in_str_index] = buffer[buff_index];
        ++in_str_index;
    }
    return (1);
}


// ? Création des strings du tableau des scores.

int create_highscore_string(game_t *game)
{
    int fd = 0;
    int size_file = 0;
    char *buffer = NULL;

    size_file = my_getline("src/leaderboard_menu/.highscore.txt");
    if (size_file == 0)
        return (0);
    if (!(buffer = malloc(sizeof(char) * (size_file + 1))))
        return (0);
    fd = open_file("src/leaderboard_menu/.highscore.txt");
    if ((read(fd, buffer, size_file)) == -1)
        return (0);
    else
        buffer[size_file] = '\0';
    if (!(read_buffer(game, buffer)))
        return (0);
    close (fd);
    return (1);
}


// ? Création du tableau des scores.

int create_score(game_t *game)
{
    if (!(game->game_text.score = malloc(sizeof(string_t) * 7)))
        return (0);
    for (int i = 0; i < 7; ++i)
        game->game_text.score[i].string = sfText_create();
    if (!(create_highscore_string(game)))
        return (0);
    for (int i = 0; i < 6; ++i) {
        game->game_text.score[i].font = sfFont_createFromFile(
                                                "png/font/DimboRegular.ttf");
        sfText_setFont(game->game_text.score[i].string,
                                        game->game_text.score[i].font);
        game->game_text.score[i].color = sfColor_fromRGB(219, 200, 152);
        sfText_setColor(game->game_text.score[i].string,
                                            game->game_text.score[i].color);
        sfText_setCharacterSize(game->game_text.score[i].string, 50);
    }
    place_highscore_leaderboard_menu(game);
    create_text_highscore(game, "TOP HIGHSCORE OF ALL TIME");
    return (1);
}


// ? Set position des strings du leaderboard.

int set_string_position(game_t *game)
{
    sfText_setPosition(game->game_text.score[HS_ONE].string,
                                game->game_text.score[HS_ONE].place_string);
    sfText_setPosition(game->game_text.score[HS_TWO].string,
                                game->game_text.score[HS_TWO].place_string);
    sfText_setPosition(game->game_text.score[HS_THREE].string,
                                game->game_text.score[HS_THREE].place_string);
    sfText_setPosition(game->game_text.score[HS_FOUR].string,
                                game->game_text.score[HS_FOUR].place_string);
    sfText_setPosition(game->game_text.score[HS_FIVE].string,
                                game->game_text.score[HS_FIVE].place_string);
    sfText_setPosition(game->game_text.score[HS_SIX].string,
                                game->game_text.score[HS_SIX].place_string);
    return (1);
}


// ? Place les strings dans le leaderboard menu.

int place_highscore_leaderboard_menu(game_t *game)
{
    game->game_text.score[HS_ONE].place_string.x = 600.0;
    game->game_text.score[HS_ONE].place_string.y = 490.0;
    game->game_text.score[HS_TWO].place_string.x = 600.0;
    game->game_text.score[HS_TWO].place_string.y = 600.0;
    game->game_text.score[HS_THREE].place_string.x = 600.0;
    game->game_text.score[HS_THREE].place_string.y = 715.0;
    game->game_text.score[HS_FOUR].place_string.x = 1050.0;
    game->game_text.score[HS_FOUR].place_string.y = 490.0;
    game->game_text.score[HS_FIVE].place_string.x = 1050.0;
    game->game_text.score[HS_FIVE].place_string.y = 600.0;
    game->game_text.score[HS_SIX].place_string.x = 1050.0;
    game->game_text.score[HS_SIX].place_string.y = 715.0;
    set_string_position(game);
    return (1);
}