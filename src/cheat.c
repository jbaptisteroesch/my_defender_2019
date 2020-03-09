/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../include/my.h"

int check_if_cheat(game_t *game, char **av)
{
    if (av [1] && av[1][1] == 'm')
        game->code.money = 1;
    return (1);
}