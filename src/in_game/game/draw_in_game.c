/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** draw in game elements
*/

#include "../include/my.h"

void draw_text_player_data(game_t *game)
{
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_LEVEL_TEXT].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_LEVEL_NUMBER].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_LIFE_TEXT].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_LIFE_NUMBER].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_MONEY_TEXT].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_MONEY_NUMBER].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_WAVE_TEXT].string, NULL);
    sfRenderWindow_drawText(game->window->window,
                    game->game_text.in_game[PLAYER_WAVE_NUMB].string, NULL);
    return;
}

void draw_upgrade_sprite_st_rt(game_t *game)
{
    if (game->shop.tower_to_upgrade == 3) {
        game->button.in_game[IG_UPGRADE_ST].position.x =
                                    game->shop.pos_tower_to_upgrade.x + 30;
        game->button.in_game[IG_UPGRADE_ST].position.y =
                                    game->shop.pos_tower_to_upgrade.y;
        sfSprite_setPosition(game->button.in_game[IG_UPGRADE_ST].sprite,
                        game->button.in_game[IG_UPGRADE_ST].position);
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_UPGRADE_ST].sprite, NULL);
    }
    if (game->shop.tower_to_upgrade == 4) {
        game->button.in_game[IG_UPGRADE_RT].position.x =
                                    game->shop.pos_tower_to_upgrade.x + 30;
        game->button.in_game[IG_UPGRADE_RT].position.y =
                                    game->shop.pos_tower_to_upgrade.y - 25;
        sfSprite_setPosition(game->button.in_game[IG_UPGRADE_RT].sprite,
                        game->button.in_game[IG_UPGRADE_RT].position);
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_UPGRADE_RT].sprite, NULL);
    }
    return;
}

void draw_upgrade_sprite(game_t *game)
{
    if (game->shop.tower_to_upgrade == 1) {
        game->button.in_game[IG_UPGRADE_BT].position.x =
                                    game->shop.pos_tower_to_upgrade.x + 35;
        game->button.in_game[IG_UPGRADE_BT].position.y =
                                    game->shop.pos_tower_to_upgrade.y;
        sfSprite_setPosition(game->button.in_game[IG_UPGRADE_BT].sprite,
                        game->button.in_game[IG_UPGRADE_BT].position);
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_UPGRADE_BT].sprite, NULL);
    }
    if (game->shop.tower_to_upgrade == 2) {
        game->button.in_game[IG_UPGRADE_YT].position.x =
                                    game->shop.pos_tower_to_upgrade.x + 35;
        game->button.in_game[IG_UPGRADE_YT].position.y =
                                    game->shop.pos_tower_to_upgrade.y;
        sfSprite_setPosition(game->button.in_game[IG_UPGRADE_YT].sprite,
                        game->button.in_game[IG_UPGRADE_YT].position);
        sfRenderWindow_drawSprite(game->window->window,
                        game->button.in_game[IG_UPGRADE_YT].sprite, NULL);
    }
    return;
}

void draw_in_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    draw_map_ig(game);
    sfRenderWindow_drawSprite(game->window->window,
                        game->menu.ui_in_game[IG_PLAYER_TABLE].sprite, NULL);
    draw_text_player_data(game);
    draw_pause_button_ig(game);
    draw_placed_towers(game);
    if (game->player_data.next_wave_in > -1)
        draw_warning_wave(game);
    if (game->player_data.next_wave_in == -1)
        draw_ennemy_wave(game);
    draw_false_threed(game);
    draw_sprite_shot(game);
    draw_tree(game);
    if (game->player_data.tower_is_click) {
        draw_upgrade_sprite(game);
        draw_upgrade_sprite_st_rt(game);
    }
    draw_shop_elements(game);
    return;
}

int is_everything_draw(game_t *game)
{
    int i = 0;
    add_arrow_t *tmp = game->head_arrow;

    while (tmp != NULL) {
        if (tmp->arrow.type == 0 && tmp->arrow.loop <= 15)
            i++;
        tmp = tmp->next;
    }
    return (i);
}
