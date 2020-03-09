/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"

char *create_file_lign(game_t *game, char *line, int k)
{
    int i = 0;
    char *score;

    if (!(line = malloc(sizeof(char) * 20)))
        return (NULL);
    if (!(score = malloc(sizeof(char) * 6)))
        return (NULL);
    for (i = 0; i < (my_strlen(game->end_game.username)); ++i)
        line[i] = game->end_game.username[i];
    line [i++] = ' ';
    line [i++] = '-';
    line[i++] = '>';
    line[i++] = ' ';
    score = my_nbrtoarray(game->player_data.score);
    while (score[k]) {
        line[i++] = score[k];
        ++k;
    }
    line[i] = '\0';
    return (line);
}

char *to_buffer(game_t *game)
{
    char *buffer = NULL;
    int k = 0;

    if (!(buffer = malloc(sizeof(char) * 100)))
        return (NULL);
    for (int i = 0; game->end_game.read_highscore[i] != NULL; ++i) {
        for (int j = 0; game->end_game.read_highscore[i][j] != '\0'; ++j) {
            buffer[k] = game->end_game.read_highscore[i][j];
            ++k;
        }
        buffer[k] = '\n';
        ++k;
    }
    buffer[k] = '\0';
    return (buffer);
}

int compare_score(game_t *game, int analysed, int wich_lign)
{
    int k = 0;
    char *line = NULL;

    if (analysed >= game->player_data.score)
        return (1);
    else {
        game->end_game.find_place = true;
        line = create_file_lign(game, line, k);
        if (line == NULL)
            return (change_state_cause_of_error(game));
        game->end_game.read_highscore[wich_lign] = line;
        insert_lign_in_file(game);
    }
    return (1);
}

int check_score(game_t *game, int i, int j)
{
    char *comp = NULL;
    int analysed = 0;
    int z = 0;

    if (!(comp = malloc(sizeof(char) * 10)))
        return (change_state_cause_of_error(game));
    while (game->end_game.read_highscore[i][j] >= '0' &&
                            game->end_game.read_highscore[i][j] <= '9')
        --j;
    ++j;
    while (game->end_game.read_highscore[i][j] >= '0' &&
                            game->end_game.read_highscore[i][j] <= '9') {
        comp[z] = game->end_game.read_highscore[i][j];
        ++z;
        ++j;
    }
    comp[z] = '\0';
    analysed = my_getnbr(comp);
    compare_score(game, analysed, i);
    return (1);
}

int analyse_high_score_file(game_t *game)
{
    int j = 0;

    for (int i = 0; game->end_game.read_highscore[i] != NULL; ++i) {
        for (j = 0; game->end_game.read_highscore[i][j] != '\0'; ++j);
        check_score(game, i, --j);
        if (game->end_game.find_place)
            break;
    }
    return (1);
}