/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main menu
*/

#include "../../include/my.h"

int main_menu(game_t *game)
{
    if (!(game->button.main_menu = malloc(sizeof(create_button_t) * 12)))
        return (0);
    if (!(create_main_menu_buttons(game)))
        return (0);
    if (!(initiate_state_button_tab(game)))
        return (0);
    if (!(create_ui_main_menu(game)))
        return (0);
    resize_buttons_menu(game);
    while (game->menu.game_state[MAIN_MENU] == 1) {
        draw_main_menu(game);
        events_main_menu(game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_main_menu_elements(game);
    return (1);
}

int resize_buttons_menu(game_t *game)
{
    sfVector2f vector = game->window->scale;
    for (int i = 0; i < 12; i++) {
        sfSprite_scale(game->button.main_menu[i].sprite, vector);
    }
    sfVector2f actual_position;
    for (int i = 0; i < 12; i++) {
        actual_position = sfSprite_getPosition(
                                            game->button.main_menu[i].sprite);
        actual_position.x = actual_position.x * vector.x;
        actual_position.y = actual_position.y * vector.y;
        sfSprite_setPosition(game->button.main_menu[i].sprite, actual_position);
    }
    actual_position = sfSprite_getPosition(game->menu.ui_main_menu->sprite);
    actual_position.x = actual_position.x * vector.x;
    actual_position.y = actual_position.y * vector.y;
    sfSprite_setPosition(game->menu.ui_main_menu->sprite, actual_position);
    sfSprite_scale(game->menu.ui_main_menu->sprite, vector);
    return (1);
}