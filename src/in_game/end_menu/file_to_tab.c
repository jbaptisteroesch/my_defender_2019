/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"

int read_highscore_file(game_t *game, char *buffer, int fd)
{
    int j = 0;
    int i = 0;
    int k = 0;

    for (i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n') {
            game->end_game.read_highscore[k][j] = '\0';
            j = 0;
            ++k;
            continue;
        }
        game->end_game.read_highscore[k][j] = buffer[i];
        ++j;
    }
    game->end_game.read_highscore[k] = NULL;
    close (fd);
    analyse_high_score_file(game);
    return (1);
}

int read_file_score(game_t *game)
{
    int fd = 0;
    int size_file = 0;
    char *buffer = NULL;

    size_file = my_getline("src/leaderboard_menu/.highscore.txt");
    if (size_file == 0) {
        game->end_game.lign_to_write = 1;
        return (1);
    }
    if (!(buffer = malloc(sizeof(char) * (size_file + 1))))
        return (0);
    fd = open_file("src/leaderboard_menu/.highscore.txt");
    if ((read(fd, buffer, size_file)) == -1)
        return (0);
    else
        buffer[size_file] = '\0';
    if (!(read_highscore_file(game, buffer, fd)))
        return (0);
    close (fd);
    return (1);
}

int place_in_file(game_t *game, char *name)
{
    int i = 0;

    while (name[i]) {
        game->end_game.username[i] = name[i];
        ++i;
    }
    game->end_game.username[i] = '\0';
    if (!(read_file_score(game)))
        return (change_state_cause_of_error(game));
    return (1);
}

int set_to_string(game_t *game, char *name)
{
    static int i;
    static int letters;

    if (letters == 10)
        return (1);
    name[i] = game->window->event.key.code + 65;
    ++i;
    ++letters;
    name[i] = '\0';
    sfText_setString(game->game_text.end_menu[1].string, name);
    return (1);
}

int analyse_username(game_t *game)
{
    static char *name = NULL;

    if (name == NULL) {
        if (!(name = malloc(sizeof(char) * 11)))
            return (0);
    }
    if (game->window->event.type == sfEvtKeyPressed) {
        if (game->window->event.key.code == sfKeyEnter) {
            place_in_file(game, name);
            free (name);
            game->end_game.press_enter = true;
            return (1);
        }
        if (game->window->event.key.code >= 0 &&
                                        game->window->event.key.code <= 25)
            set_to_string(game, name);
        else
            return (1);
        }
    return (1);
}