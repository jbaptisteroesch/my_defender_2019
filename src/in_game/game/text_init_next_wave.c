/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** create text in game
*/

#include "../include/my.h"


// ? Crée le nombre de secondes restantes avant la prochaine wave.

int create_number_next_wave(game_t *game)
{
    sfVector2f position;
    sfVector2f s = game->window->scale;

    position.x = 1150 * s.x;
    position.y = 50 * s.y;

    create_text_in_game_pattern(game,
        my_nbrtoarray(game->player_data.next_wave_in), position,
                                                            WARNING_WAVE_NUMB);
    game->game_text.in_game[WARNING_WAVE_NUMB].color =
                                                sfColor_fromRGB(230, 0, 0);
    sfText_setColor(game->game_text.in_game[WARNING_WAVE_NUMB].string,
                            game->game_text.in_game[WARNING_WAVE_NUMB].color);
    sfText_setCharacterSize(
                    game->game_text.in_game[WARNING_WAVE_NUMB].string, 80);
    sfText_scale(game->game_text.in_game[WARNING_WAVE_NUMB].string, s);
    return (1);
}


// ? Crée le text du warning de la next wave.

int create_text_next_wave(game_t *game)
{
    sfVector2f position;
    sfVector2f s = game->window->scale;

    position.x = 770 * s.x;
    position.y = 50 * s.y;
    create_text_in_game_pattern(game, "Next wave in : ", position,
                                                            WARNING_WAVE_TEXT);
    game->game_text.in_game[WARNING_WAVE_TEXT].color =
                                                sfColor_fromRGB(230, 0, 0);
    sfText_setColor(game->game_text.in_game[WARNING_WAVE_TEXT].string,
                            game->game_text.in_game[WARNING_WAVE_TEXT].color);
    sfText_setCharacterSize(
                    game->game_text.in_game[WARNING_WAVE_TEXT].string, 80);
    sfText_scale(game->game_text.in_game[WARNING_WAVE_TEXT].string, s);
    create_number_next_wave(game);
    return (1);
}