/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"


// ? Fait cignoter le texte de warning wave.

void blinking_wave_warning(game_t *game)
{
    if (game->clock.in_game[CLOCK_NEXT_WAVE].seconds > 0.6 &&
                                    game->player_data.next_wave_in <= 10) {
        sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[WARNING_WAVE_TEXT].string, NULL);
        sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[WARNING_WAVE_NUMB].string, NULL);
    }
    return;
}


// ? Dessine le text de warning wave.

void draw_warning_wave(game_t *game)
{
    game->clock.in_game[CLOCK_NEXT_WAVE].time =
            sfClock_getElapsedTime(game->clock.in_game[CLOCK_NEXT_WAVE].clock);
    game->clock.in_game[CLOCK_NEXT_WAVE].seconds =
            game->clock.in_game[CLOCK_NEXT_WAVE].time.microseconds / 1000000.0;
    blinking_wave_warning(game);
    if (game->clock.in_game[CLOCK_NEXT_WAVE].seconds > 1) {
        game->player_data.next_wave_in -= 1;
        game->player_data.clock_wave =
                            my_nbrtoarray(game->player_data.next_wave_in);
        sfText_setString(game->game_text.in_game[WARNING_WAVE_NUMB].string,
                                            game->player_data.clock_wave);
        sfClock_restart(game->clock.in_game[CLOCK_NEXT_WAVE].clock);
    }
    if (game->player_data.next_wave_in == -1)
            sfClock_restart(game->clock.in_game[CLOCK_POS_ENNEMY].clock);
    return;
}