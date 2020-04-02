/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../include/my.h"

int create_music(game_t *game)
{
    game->music = sfMusic_createFromFile("png/music.ogg");
    sfMusic_setVolume(game->music, 100.0);
    sfMusic_setLoop(game->music, true);
    sfMusic_play(game->music);
    return (1);
}