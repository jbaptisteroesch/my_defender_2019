/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** win menu
*/

#include "../include/my.h"

int insert_lign_in_file(game_t *game)
{
    char *buffer = to_buffer(game);
    FILE *fp;

    fp = fopen("src/leaderboard_menu/.highscore.txt", "w+");

    if (buffer == NULL)
        return (change_state_cause_of_error(game));
    size_t n = my_strlen(buffer);
    fwrite(buffer, 1, n, fp);
    fclose(fp);
    game->menu.game_state[END_MENU] = 0;
    game->menu.game_state[LEADERBOARD_MENU] = 1;
    return (1);
}

int events_end_menu(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
                                                    &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->menu.game_state[END_MENU] = 0;
            game->menu.game_is_up = 0;
        }
        if (game->end_game.press_enter == false)
            analyse_username(game);
        else {
            game->menu.game_state[END_MENU] = 0;
            game->menu.game_state[LEADERBOARD_MENU] = 1;
        }
    }
    return (1);
}